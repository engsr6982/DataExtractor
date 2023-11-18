#pragma once

#include "mc/_HeaderOutputPredefine.h"

// auto generated inclusion list
#include "mc/world/inventory/simulation/validation/ContainerValidationBase.h"

class Trade1Ingredient2ContainerValidation : public ::ContainerValidationBase {
public:
    // prevent constructor by default
    Trade1Ingredient2ContainerValidation& operator=(Trade1Ingredient2ContainerValidation const &) = delete;
    Trade1Ingredient2ContainerValidation(Trade1Ingredient2ContainerValidation const &) = delete;
    Trade1Ingredient2ContainerValidation() = delete;

public:
    // NOLINTBEGIN
    // vIndex: 0, symbol: __unk_vfn_0
    virtual void __unk_vfn_0();

    // vIndex: 1, symbol: ?isValidSlotForContainer@ContainerValidationBase@@UEBA_NAEBVContainerScreenContext@@AEBVContainer@@H@Z
    virtual bool isValidSlotForContainer(class ContainerScreenContext const &, class Container const &, int32_t) const;

    // vIndex: 2, symbol: ?isItemAllowedInSlot@Trade1Ingredient2ContainerValidation@@UEBA_NAEBVContainerScreenContext@@HAEBVItemStackBase@@H@Z
    virtual bool isItemAllowedInSlot(class ContainerScreenContext const &, int32_t, class ItemStackBase const &, int32_t) const;

    // vIndex: 3, symbol: ?getAvailableSetCount@ContainerValidationBase@@UEBAHHAEBVItemStackBase@@@Z
    virtual int32_t getAvailableSetCount(int32_t, class ItemStackBase const &) const;

    // vIndex: 4, symbol: __unk_vfn_4
    virtual void __unk_vfn_4();

    // vIndex: 5, symbol: __unk_vfn_5
    virtual void __unk_vfn_5();

    // vIndex: 6, symbol: ?canItemMoveToContainer@ContainerValidationBase@@UEBA_NAEBVItemStackBase@@@Z
    virtual bool canItemMoveToContainer(class ItemStackBase const &) const;

    // vIndex: 7, symbol: ?canDestroy@ContainerValidationBase@@UEBA_NAEBVContainerScreenContext@@@Z
    virtual bool canDestroy(class ContainerScreenContext const &) const;

    // vIndex: 8, symbol: ?getContainerOffset@Trade1Ingredient2ContainerValidation@@UEBAHAEBVContainerScreenContext@@@Z
    virtual int32_t getContainerOffset(class ContainerScreenContext const &) const;

    // vIndex: 9, symbol: ?getContainerSize@ContainerValidationBase@@UEBAHAEBVContainerScreenContext@@AEBVContainer@@@Z
    virtual int32_t getContainerSize(class ContainerScreenContext const &, class Container const &) const;

    // symbol: ??0Trade1Ingredient2ContainerValidation@@QEAA@_N@Z
    MCAPI Trade1Ingredient2ContainerValidation(bool);

    // NOLINTEND

};
