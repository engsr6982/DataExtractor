#pragma once

#include "mc/_HeaderOutputPredefine.h"

// auto generated inclusion list
#include "mc/world/level/block/utils/BlendingBlockType.h"
#include "mc/world/level/chunk/LevelChunk.h"

// auto generated forward declare list
// clang-format off
namespace BlendingDataFactoryUtil { struct BorderCellEntry; }
// clang-format on

namespace BlendingDataFactoryUtil {
    // NOLINTBEGIN
    // symbol: ?_deduceBlockTypeFromBlock@BlendingDataFactoryUtil@@YA?AW4BlendingBlockType@@AEBVBlock@@0@Z
    MCAPI ::BlendingBlockType _deduceBlockTypeFromBlock(class Block const &, class Block const &);

    // symbol: ?_processBlockTypeFromCellEntry@BlendingDataFactoryUtil@@YA?AW4BlendingBlockType@@AEAV?$vector@W4BlendingBlockType@@V?$allocator@W4BlendingBlockType@@@std@@@std@@@Z
    MCAPI ::BlendingBlockType _processBlockTypeFromCellEntry(std::vector<::BlendingBlockType> &);

    // symbol: ?calculateHeight@BlendingDataFactoryUtil@@YA?AVChunkLocalHeight@@AEAVBlendingData@@AEAV?$vector@UBorderCellEntry@BlendingDataFactoryUtil@@V?$allocator@UBorderCellEntry@BlendingDataFactoryUtil@@@std@@@std@@V2@V?$function@$$A6AAEAUSubChunk@@H@Z@5@@Z
    MCAPI class ChunkLocalHeight calculateHeight(class BlendingData &, std::vector<struct BlendingDataFactoryUtil::BorderCellEntry> &, class ChunkLocalHeight, std::function<struct SubChunk & (int32_t)>);

    // symbol: ?calculateSurfaceDensity@BlendingDataFactoryUtil@@YAXAEAVBlendingData@@_K@Z
    MCAPI void calculateSurfaceDensity(class BlendingData &, uint64_t);

    // symbol: ?iterateDownCellColumnUntil@BlendingDataFactoryUtil@@YAXVChunkLocalHeight@@AEAV?$vector@UBorderCellEntry@BlendingDataFactoryUtil@@V?$allocator@UBorderCellEntry@BlendingDataFactoryUtil@@@std@@@std@@HV?$function@$$A6AAEAUSubChunk@@H@Z@4@V?$function@$$A6A_NAEBUSubChunk@@AEAUBorderCellEntry@BlendingDataFactoryUtil@@VChunkLocalHeight@@GH@Z@4@@Z
    MCAPI void iterateDownCellColumnUntil(class ChunkLocalHeight, std::vector<struct BlendingDataFactoryUtil::BorderCellEntry> &, int32_t, std::function<struct SubChunk & (int32_t)>, std::function<bool (struct SubChunk const &, struct BlendingDataFactoryUtil::BorderCellEntry &, class ChunkLocalHeight, uint16_t, int32_t)>);

    // symbol: ?processBorderCells@BlendingDataFactoryUtil@@YAXVNeighbors@LevelChunk@@V?$function@$$A6AX_KHH0@Z@std@@@Z
    MCAPI void processBorderCells(class LevelChunk::Neighbors, std::function<void (uint64_t, int32_t, int32_t, uint64_t)>);

    // symbol: ?setBiome@BlendingDataFactoryUtil@@YAXAEAVBlendingData@@_KHE@Z
    MCAPI void setBiome(class BlendingData &, uint64_t, int32_t, uint8_t);

    // symbol: ?setDensity@BlendingDataFactoryUtil@@YAXAEAVBlendingData@@_KHM@Z
    MCAPI void setDensity(class BlendingData &, uint64_t, int32_t, float);
    // NOLINTEND

};