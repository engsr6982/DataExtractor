/**
 * @file  InsideCactusBlockSystem.hpp
 *
 */
#pragma once
#define AUTO_GENERATED
#include "llapi/Global.h"

#define BEFORE_EXTRA

#undef BEFORE_EXTRA

/**
 * @brief MC class InsideCactusBlockSystem.
 *
 */
class InsideCactusBlockSystem {

#define AFTER_EXTRA

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_INSIDECACTUSBLOCKSYSTEM
public:
    class InsideCactusBlockSystem& operator=(class InsideCactusBlockSystem const &) = delete;
    InsideCactusBlockSystem(class InsideCactusBlockSystem const &) = delete;
    InsideCactusBlockSystem() = delete;
#endif

public:
    /**
     * @symbol ?createSystem\@InsideCactusBlockSystem\@\@SA?AUTickingSystemWithInfo\@\@XZ
     */
    MCAPI static struct TickingSystemWithInfo createSystem();
    /**
     * @symbol ?tick\@InsideCactusBlockSystem\@\@SAXV?$ViewT\@VStrictEntityContext\@\@VEntityRegistryBase\@\@$$CBU?$InsideBlockWithPosAndBlockComponent\@UCactusBlockFlag\@\@\@\@UInsideBlockComponent\@\@\@\@\@Z
     */
    MCAPI static void tick(class ViewT<class StrictEntityContext, class EntityRegistryBase, struct InsideBlockWithPosAndBlockComponent<struct CactusBlockFlag> const, struct InsideBlockComponent>);

};
