// Basic
#include <direct.h>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <memory>
#include <string_view>
#include <utility>
// Plugin
#include <Plugin.h>

// Json
#include <nlohmann/json.hpp>

// LL
#include "ll/api/plugin/RegisterHelper.h"
#include <ll/api/command/Command.h>
#include <ll/api/command/CommandHandle.h>
#include <ll/api/command/CommandRegistrar.h>
#include <ll/api/memory/Hook.h>
#include <ll/api/plugin/NativePlugin.h>
#include <ll/api/service/Bedrock.h>


// MC
#include <mc/world/Minecraft.h>
// Item
#include "mc/world/item/components/ComponentItem.h"
#include <mc/world/item/Item.h>
#include <mc/world/item/ItemDescriptor.h>
#include <mc/world/item/ItemInstance.h>
#include <mc/world/item/ItemTag.h>
#include <mc/world/item/VanillaItemTags.h>
#include <mc/world/item/registry/CreativeItemRegistry.h>
#include <mc/world/item/registry/ItemRegistryManager.h>
#include <mc/world/item/registry/ItemRegistryRef.h>
#include <mc/world/item/registry/ItemStack.h>

// Block
#include <mc/common/Brightness.h>
#include <mc/enums/MaterialType.h>
#include <mc/world/level/block/Block.h>
#include <mc/world/level/block/VanillaBlockTags.h>
#include <mc/world/level/block/registry/BlockTypeRegistry.h>
#include <mc/world/level/block/states/BlockState.h>


// Level
#include <mc/world/level/BlockPalette.h>
#include <mc/world/level/Level.h>
#include <mc/world/level/biome/Biome.h>
#include <mc/world/level/biome/registry/BiomeRegistry.h>
#include <mc/world/level/dimension/Dimension.h>
#include <mc/world/level/material/Material.h>
// Color
#include <mc/deps/core/mce/Color.h>
#include <mc/world/item/components/ItemColorUtil.h>
// Math
#include <mc/math/Vec3.h>
#include <mc/world/phys/AABB.h>
// Command
#include <mc/server/commands/CommandOrigin.h>
#include <mc/server/commands/CommandOutput.h>
#include <mc/server/commands/CommandRegistry.h>
#include <mc/server/commands/MinecraftCommands.h>
#include <mc/server/commands/shared/HelpCommand.h>

// NBT
#include <mc/nbt/CompoundTag.h>
#include <mc/nbt/CompoundTagVariant.h>
// Network
#include <mc/deps/core/utility/BinaryStream.h>
#include <mc/network/ServerNetworkHandler.h>
#include <mc/network/packet/AvailableCommandsPacket.h>
#include <mc/network/packet/BiomeDefinitionListPacket.h>
#include <mc/network/packet/CraftingDataPacket.h>
#include <mc/network/packet/TextPacket.h>


namespace plugin {

static std::unique_ptr<Plugin> instance;
Plugin&                        Plugin::getInstance() { return *instance; }
bool                           Plugin::load() { return true; }
bool                           Plugin::disable() { return true; }


using json = nlohmann::json;


bool folderExists(const std::string& folderName) {
    struct stat info {};
    if (stat(folderName.c_str(), &info) != 0) {
        return false;
    }
    return info.st_mode & S_IFDIR;
}

void createFolder(const ll::Logger& logger, const std::string& folderName) {
    if (const int result = _mkdir(folderName.c_str()); result != 0) {
        logger.error("Failed to create folder.");
    } else {
        logger.info("Folder " + std::string(folderName) + " created successfully.");
    }
}

void writeJSON(const std::string& fileName, json const& tag) {
    std::string compressed = tag.dump(4);
    auto        out        = std::ofstream(fileName, std::ofstream::out | std::ofstream::binary | std::ofstream::trunc);
    out << compressed;
    out.close();
}

void dumpItem(json& dest, const Item& item, const ll::Logger& logger) {
    logger.info("Dumping item - " + item.getFullItemName());
    json it = json::object();

    // MetaData - 基础属性
    it["id"]             = item.getId();             // 物品 ID
    it["name"]           = item.getFullItemName();   // 全名
    it["maxDamage"]      = item.getMaxDamage();      // 最大耐久度
    it["isDamageable"]   = item.isDamageable();      // 是否可损坏
    it["isFertilizer"]   = item.isFertilizer();      // 是否是肥料
    it["isThrowable"]    = item.isThrowable();       // 是否可投掷
    it["isUseable"]      = item.isUseable();         // 是否可使用
    it["armorValue"]     = item.getArmorValue();     // 护甲值
    it["attackDamage"]   = item.getAttackDamage();   // 攻击力
    it["toughnessValue"] = item.getToughnessValue(); // 防御值
    it["cooldownTime"]   = item.getCooldownTime();   // 冷却时间

    // MetaData - 特殊值
    json sub = json::array();
    for (int i = 0; i <= 256; ++i) { // 0 ~ 256 穷举特殊值
        try {
            if (item.isValidAuxValue(i)) {
                const auto st = ItemStack(item, 1, i);
                json       j  = json::object();

                // Item - 详细数据
                j["name"]            = st.getName();            // 物品名称
                j["typeName"]        = st.getTypeName();        // 物品类型名称
                j["aux"]             = st.getAuxValue();        // 特殊值
                j["categoryName"]    = st.getCategoryName();    // 组名称
                j["customName"]      = st.getCustomName();      // 自定义名称
                j["descriptionName"] = st.getDescriptionName(); // 描述名称
                j["effectName"]      = st.getEffectName();      // 效果名称
                // j["hoverName"]       = st.getHoverName();       // 鼠标悬停名称

                sub.push_back(j);
            }
        } catch (...) {}
    }

    it["auxs"] = sub; // 特殊值列表
    dest.push_back(it);
}

void dumpItemData(const ll::Logger& logger) {
    json list    = json::array(); // 全部物品数据
    int  counter = 0;
    for (const auto& item : ItemRegistryManager::getItemRegistry().getNameToItemMap() | std::views::values) {
        dumpItem(list, *item, logger);
        counter++;
    }
    logger.info("Dump " + std::to_string(counter) + " item data successfully!");

    // Pack data
    json dest     = json::object();
    dest["items"] = list;
    dest["tr"]    = json::object(); // TODO: 翻译数据

    writeJSON("data/item_data.json", dest);
    logger.info(R"(Items' data have is to "data/item_data.json")");
}


bool Plugin::enable() {
    auto& logger = getSelf().getLogger();
    logger.info("Enabling...");

    ll::command::CommandRegistrar::getInstance()
        .getOrCreateCommand("ext", "extract data", CommandPermissionLevel::GameDirectors, CommandFlagValue::None)
        .overload()
        .execute([&](CommandOrigin const&, CommandOutput& output) {
            if (!folderExists("data")) {
                createFolder(logger, "data");
            }
            dumpItemData(logger);
            output.success("Success!");
        });

    return true;
}

} // namespace plugin

LL_REGISTER_PLUGIN(plugin::Plugin, plugin::instance);