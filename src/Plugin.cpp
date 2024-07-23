#include "ll/api/plugin/RegisterHelper.h"
#include "mc/server/commands/ServerCommandOrigin.h"
#include "mc/world/item/components/ComponentItem.h"
#include "mc/world/item/enchanting/Enchant.h"
#include "mc/world/item/enchanting/EnchantUtils.h"
#include <Plugin.h>
#include <cstdlib>
#include <direct.h>
#include <filesystem>
#include <fstream>
#include <functional>
#include <iostream>
#include <ll/api/command/Command.h>
#include <ll/api/command/CommandHandle.h>
#include <ll/api/command/CommandRegistrar.h>
#include <ll/api/memory/Hook.h>
#include <ll/api/plugin/NativePlugin.h>
#include <ll/api/service/Bedrock.h>
#include <mc/common/Brightness.h>
#include <mc/enums/MaterialType.h>
#include <mc/math/Vec3.h>
#include <mc/server/commands/CommandOrigin.h>
#include <mc/server/commands/CommandOutput.h>
#include <mc/server/commands/CommandRegistry.h>
#include <mc/server/commands/MinecraftCommands.h>
#include <mc/server/commands/shared/HelpCommand.h>
#include <mc/world/Minecraft.h>
#include <mc/world/actor/player/Player.h>
#include <mc/world/item/Item.h>
#include <mc/world/item/ItemDescriptor.h>
#include <mc/world/item/ItemInstance.h>
#include <mc/world/item/ItemTag.h>
#include <mc/world/item/VanillaItemTags.h>
#include <mc/world/item/registry/CreativeItemRegistry.h>
#include <mc/world/item/registry/ItemRegistryManager.h>
#include <mc/world/item/registry/ItemRegistryRef.h>
#include <mc/world/item/registry/ItemStack.h>
#include <mc/world/level/BlockPalette.h>
#include <mc/world/level/Level.h>
#include <mc/world/level/biome/Biome.h>
#include <mc/world/level/biome/registry/BiomeRegistry.h>
#include <mc/world/level/block/Block.h>
#include <mc/world/level/block/VanillaBlockTags.h>
#include <mc/world/level/block/registry/BlockTypeRegistry.h>
#include <mc/world/level/block/states/BlockState.h>
#include <mc/world/level/dimension/Dimension.h>
#include <mc/world/level/material/Material.h>
#include <memory>
#include <nlohmann/json.hpp>
#include <string>
#include <string_view>
#include <unordered_set>
#include <utility>


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

size_t hash(ItemStack const& it) {
    return std::hash<std::string>()(
        it.getTypeName() + it.getEffectName() + it.getDescriptionName() + it.getName() + std::to_string(it.getId())
        + it.getRawNameId()
    );
}


void dumpItem(json& array, const Item& item, const ll::Logger& logger) {
    logger.info("Dumping item - " + item.getFullItemName());

    std::unordered_set<size_t> uniqueAuxs;
    for (int i = 0; i <= 256; ++i) { // 0 ~ 256 穷举特殊值
        try {
            if (item.isValidAuxValue(i)) {
                auto       _fakeItem = ItemStack(item, 1, i);
                auto const hashed    = hash(_fakeItem);
                if (uniqueAuxs.contains(hashed)) continue;
                uniqueAuxs.insert(hashed);

                json j = json::object();

                j["name"]            = _fakeItem.getName();            // 物品名称
                j["typeName"]        = _fakeItem.getTypeName();        // 物品类型名称
                j["fullName"]        = item.getFullItemName();         // 全名
                j["aux"]             = _fakeItem.getAuxValue();        // 特殊值
                j["id"]              = _fakeItem.getId();              // 物品ID
                j["categoryName"]    = _fakeItem.getCategoryName();    // 组名称
                j["descriptionName"] = _fakeItem.getDescriptionName(); // 描述名称
                j["effectName"]      = _fakeItem.getEffectName();      // 效果名称

                array.push_back(j);
            }
        } catch (...) {
            logger.error("Failed to dump item - " + item.getFullItemName());
        }
    }
}

void dumpItemData(const ll::Logger& logger) {
    json datas     = json::object();
    datas["items"] = json::array();

    // Dump item data
    auto& list    = datas["items"];
    int   counter = 0;
    for (const auto& item : ItemRegistryManager::getItemRegistry().getNameToItemMap() | std::views::values) {
        dumpItem(list, *item, logger);
        counter++;
    }

    // i18n
    datas["tr"] = {
        {"name",            "名称"      },
        {"typeName",        "命名空间"},
        {"fullName",        "全名"      },
        {"aux",             "特殊值"   },
        {"id",              "物品ID"    },
        {"categoryName",    "组名称"   },
        {"descriptionName", "描述名称"},
        {"effectName",      "效果名称"}
    };

    logger.info("Dump " + std::to_string(counter) + " item data successfully!");
    writeJSON("plugins/DataExtractor/item_data.json", datas);
    logger.info(R"(Items' data have is to "plugins/DataExtractor/item_data.json")");
}


bool Plugin::enable() {
    auto& logger = getSelf().getLogger();
    logger.info("Enabling...");

    if (!folderExists("data")) {
        createFolder(logger, "data");
    }
    dumpItemData(logger);
    logger.info("Success!");

    CommandContext ctx = CommandContext(
        "stop",
        std::make_unique<ServerCommandOrigin>(
            "Server",
            ll::service::getLevel()->asServer(),
            CommandPermissionLevel::Owner,
            0
        )
    );
    ll::service::getMinecraft()->getCommands().executeCommand(ctx);

    return true;
}

} // namespace plugin

LL_REGISTER_PLUGIN(plugin::Plugin, plugin::instance);