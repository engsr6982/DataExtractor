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

void writeJSON(const std::string& fileName, const CompoundTag& tag) {
    std::string compressed = tag.toSnbt();
    auto        out        = std::ofstream(fileName, std::ofstream::out | std::ofstream::binary | std::ofstream::trunc);
    out << compressed;
    out.close();
}

void dumpItem(ListTag& dest, const Item& item, const ll::Logger& logger) {
    auto nbt = CompoundTag();
    logger.info("Dumping item - " + item.getFullItemName());
    nbt.putShort("id", item.getId());
    try {
        if (!item.getLegacyBlock().expired() && item.getLegacyBlock().get() != nullptr)
            nbt.putString(
                "blockId",
                item.getLegacyBlock()->getNamespace() + ":" + item.getLegacyBlock()->getRawNameId()
            );
    } catch (std::exception& e) {
        logger.warn("Exception occur when trying to get block for item " + item.getFullItemName());
    }
    nbt.putBoolean("isComponentBased", item.isComponentBased());
    nbt.putString("name", item.getFullItemName());
    nbt.putShort("maxDamage", item.getMaxDamage());
    nbt.putBoolean("isBlockPlanterItem", item.isBlockPlanterItem());
    nbt.putBoolean("isDamageable", item.isDamageable());
    nbt.putBoolean("isDye", item.isDye());
    nbt.putString("itemColorName", ItemColorUtil::getName(item.getItemColor()));
    nbt.putInt("itemColorRGB", ItemColorUtil::getRGBColor(item.getItemColor()));
    nbt.putBoolean("isFertilizer", item.isFertilizer());
    nbt.putBoolean("isThrowable", item.isThrowable());
    nbt.putBoolean("isUseable", item.isUseable());
    nbt.putBoolean("isElytra", item.isElytra());
    nbt.putBoolean("canBeDepleted", item.canBeDepleted());
    nbt.putBoolean("canDestroyInCreative", item.canDestroyInCreative());
    nbt.putBoolean("canUseOnSimTick", item.canUseOnSimTick());
    nbt.putBoolean("canBeCharged", item.canBeCharged());
    nbt.putString("creativeGroup", item.getCreativeGroup());
    nbt.putInt("creativeCategory", static_cast<int>(item.getCreativeCategory()));
    nbt.putInt("armorValue", item.getArmorValue());
    nbt.putInt("attackDamage", item.getAttackDamage());
    nbt.putInt("toughnessValue", item.getToughnessValue());
    nbt.putFloat("viewDamping", item.getViewDamping());
    nbt.putInt("cooldownTime", item.getCooldownTime());
    nbt.putString("cooldownType", item.getCooldownType().getString());
    nbt.putInt("maxStackSize", item.getMaxStackSize(item.buildDescriptor(0, nullptr)));
    CompoundTag           descriptionId;
    std::set<std::string> uniqueStr;
    for (int i = 0; i <= 256; ++i) {
        try {
            if (item.isValidAuxValue(i)) {
                if (const auto itemStack = ItemStack(item, 1, i); !uniqueStr.contains(itemStack.getDescriptionId())) {
                    uniqueStr.insert(itemStack.getDescriptionId());
                    descriptionId.putString(std::to_string(i), itemStack.getDescriptionId());
                }
            }
        } catch (...) {}
    }
    nbt.putCompound("descriptionId", descriptionId);
    dest.add(nbt);
}

void dumpItemData(const ll::Logger& logger) {
    auto  tag     = CompoundTag();
    auto  list    = ListTag();
    short counter = 0;
    for (const auto& item : ItemRegistryManager::getItemRegistry().getNameToItemMap() | std::views::values) {
        dumpItem(list, *item, logger);
        counter++;
    }
    tag.put("item", list);
    logger.info("Dump " + std::to_string(counter) + " item data successfully!");
    writeJSON("data/item_data.snbt", tag);
    logger.info(R"(Items' data have is to "data/item_data.snbt")");
}

void ext(const ll::Logger& logger) {
    if (!folderExists("data")) {
        createFolder(logger, "data");
    }
    dumpItemData(logger);
}

Plugin& Plugin::getInstance() { return *instance; }

bool Plugin::load() {
    getSelf().getLogger().info("Loading...");
    return true;
}

bool Plugin::enable() {
    auto& logger = getSelf().getLogger();
    logger.info("Enabling...");

    // TODO: It seems not works, replaced with TextPacket hook. Need to fix it in the future
    ll::command::CommandRegistrar::getInstance()
        .getOrCreateCommand("ext", "extract data", CommandPermissionLevel::GameDirectors, CommandFlagValue::None)
        .overload()
        .execute([&](CommandOrigin const&, CommandOutput& output) {
            ext(logger);
            output.success("Success!");
        });

    return true;
}

bool Plugin::disable() {
    getSelf().getLogger().info("Disabling...");
    return true;
}
} // namespace plugin

LL_REGISTER_PLUGIN(plugin::Plugin, plugin::instance);