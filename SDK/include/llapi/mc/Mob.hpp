/**
 * @file  Mob.hpp
 *
 */
#pragma once
#define AUTO_GENERATED
#include "llapi/Global.h"
#include "Actor.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here
class UserEntityIdentifierComponent;

#undef BEFORE_EXTRA

/**
 * @brief MC class Mob.
 *
 */
class Mob : public Actor {

#define AFTER_EXTRA
// Add Member There
public:
struct JumpPreventionResult {
    JumpPreventionResult() = delete;
    JumpPreventionResult(JumpPreventionResult const&) = delete;
    JumpPreventionResult(JumpPreventionResult const&&) = delete;
};

public:

    LIAPI bool refreshInventory();

#undef AFTER_EXTRA
#ifndef DISABLE_CONSTRUCTOR_PREVENTION_MOB
public:
    class Mob& operator=(class Mob const &) = delete;
    Mob(class Mob const &) = delete;
    Mob() = delete;
#endif

public:
    /**
     * @vftbl 2
     * @symbol ?hasComponent\@Mob\@\@UEBA_NAEBVHashedString\@\@\@Z
     */
    virtual bool hasComponent(class HashedString const &) const;
    /**
     * @vftbl 9
     * @symbol ?outOfWorld\@Mob\@\@MEAAXXZ
     */
    virtual void outOfWorld();
    /**
     * @vftbl 10
     * @symbol ?reloadHardcoded\@Mob\@\@UEAAXW4InitializationMethod\@Actor\@\@AEBVVariantParameterList\@\@\@Z
     */
    virtual void reloadHardcoded(enum class Actor::InitializationMethod, class VariantParameterList const &);
    /**
     * @vftbl 11
     * @symbol ?reloadHardcodedClient\@Mob\@\@UEAAXW4InitializationMethod\@Actor\@\@AEBVVariantParameterList\@\@\@Z
     */
    virtual void reloadHardcodedClient(enum class Actor::InitializationMethod, class VariantParameterList const &);
    /**
     * @vftbl 12
     * @symbol ?initializeComponents\@Mob\@\@UEAAXW4InitializationMethod\@Actor\@\@AEBVVariantParameterList\@\@\@Z
     */
    virtual void initializeComponents(enum class Actor::InitializationMethod, class VariantParameterList const &);
    /**
     * @vftbl 15
     * @symbol ?_doInitialMove\@Mob\@\@MEAAXXZ
     */
    virtual void _doInitialMove();
    /**
     * @vftbl 16
     * @symbol __unk_vfn_16
     */
    virtual void __unk_vfn_16();
    /**
     * @vftbl 31
     * @symbol ?getInterpolatedBodyRot\@Mob\@\@UEBAMM\@Z
     */
    virtual float getInterpolatedBodyRot(float) const;
    /**
     * @vftbl 32
     * @symbol ?getInterpolatedHeadRot\@Mob\@\@UEBAMM\@Z
     */
    virtual float getInterpolatedHeadRot(float) const;
    /**
     * @vftbl 33
     * @symbol ?getInterpolatedBodyYaw\@Mob\@\@UEBAMM\@Z
     */
    virtual float getInterpolatedBodyYaw(float) const;
    /**
     * @vftbl 34
     * @symbol ?getYawSpeedInDegreesPerSecond\@Mob\@\@UEBAMXZ
     */
    virtual float getYawSpeedInDegreesPerSecond() const;
    /**
     * @vftbl 37
     * @symbol ?resetInterpolated\@Mob\@\@UEAAXXZ
     */
    virtual void resetInterpolated();
    /**
     * @vftbl 41
     * @symbol __unk_vfn_41
     */
    virtual void __unk_vfn_41();
    /**
     * @vftbl 42
     * @symbol ?blockedByShield\@Mob\@\@UEAAXAEBVActorDamageSource\@\@AEAVActor\@\@\@Z
     */
    virtual void blockedByShield(class ActorDamageSource const &, class Actor &);
    /**
     * @vftbl 44
     * @symbol ?teleportTo\@Mob\@\@UEAAXAEBVVec3\@\@_NHH1\@Z
     */
    virtual void teleportTo(class Vec3 const &, bool, int, int, bool);
    /**
     * @vftbl 49
     * @symbol ?normalTick\@Mob\@\@UEAAXXZ
     */
    virtual void normalTick();
    /**
     * @vftbl 50
     * @symbol ?baseTick\@Mob\@\@UEAAXXZ
     */
    virtual void baseTick();
    /**
     * @vftbl 53
     * @symbol ?startRiding\@Mob\@\@UEAA_NAEAVActor\@\@\@Z
     */
    virtual bool startRiding(class Actor &);
    /**
     * @vftbl 54
     * @symbol ?addPassenger\@Mob\@\@UEAAXAEAVActor\@\@\@Z
     */
    virtual void addPassenger(class Actor &);
    /**
     * @vftbl 62
     * @symbol __unk_vfn_62
     */
    virtual void __unk_vfn_62();
    /**
     * @vftbl 69
     * @symbol __unk_vfn_69
     */
    virtual void __unk_vfn_69();
    /**
     * @vftbl 82
     * @symbol __unk_vfn_82
     */
    virtual void __unk_vfn_82();
    /**
     * @vftbl 85
     * @symbol __unk_vfn_85
     */
    virtual void __unk_vfn_85();
    /**
     * @vftbl 88
     * @symbol __unk_vfn_88
     */
    virtual void __unk_vfn_88();
    /**
     * @vftbl 92
     * @symbol ?isImmobile\@Mob\@\@UEBA_NXZ
     */
    virtual bool isImmobile() const;
    /**
     * @vftbl 95
     * @symbol ?isPickable\@Mob\@\@UEAA_NXZ
     */
    virtual bool isPickable();
    /**
     * @vftbl 96
     * @symbol __unk_vfn_96
     */
    virtual void __unk_vfn_96();
    /**
     * @vftbl 97
     * @symbol ?isSleeping\@Mob\@\@UEBA_NXZ
     */
    virtual bool isSleeping() const;
    /**
     * @vftbl 98
     * @symbol ?setSleeping\@Mob\@\@UEAAX_N\@Z
     */
    virtual void setSleeping(bool);
    /**
     * @vftbl 99
     * @symbol __unk_vfn_99
     */
    virtual void __unk_vfn_99();
    /**
     * @vftbl 101
     * @symbol ?isBlocking\@Mob\@\@UEBA_NXZ
     */
    virtual bool isBlocking() const;
    /**
     * @vftbl 103
     * @symbol ?isAlive\@Mob\@\@UEBA_NXZ
     */
    virtual bool isAlive() const;
    /**
     * @vftbl 106
     * @symbol __unk_vfn_106
     */
    virtual void __unk_vfn_106();
    /**
     * @vftbl 107
     * @symbol ?isSurfaceMob\@Mob\@\@UEBA_NXZ
     */
    virtual bool isSurfaceMob() const;
    /**
     * @vftbl 108
     * @symbol __unk_vfn_108
     */
    virtual void __unk_vfn_108();
    /**
     * @vftbl 109
     * @symbol __unk_vfn_109
     */
    virtual void __unk_vfn_109();
    /**
     * @vftbl 111
     * @symbol __unk_vfn_111
     */
    virtual void __unk_vfn_111();
    /**
     * @vftbl 114
     * @symbol ?setTarget\@Mob\@\@UEAAXPEAVActor\@\@\@Z
     */
    virtual void setTarget(class Actor *);
    /**
     * @vftbl 116
     * @symbol ?attack\@Mob\@\@UEAA_NAEAVActor\@\@AEBW4ActorDamageCause\@\@\@Z
     */
    virtual bool attack(class Actor &, enum class ActorDamageCause const &);
    /**
     * @vftbl 127
     * @symbol ?canPowerJump\@Mob\@\@UEBA_NXZ
     */
    virtual bool canPowerJump() const;
    /**
     * @vftbl 135
     * @symbol ?getBlockDamageCause\@Mob\@\@UEBA?AW4ActorDamageCause\@\@AEBVBlock\@\@\@Z
     */
    virtual enum class ActorDamageCause getBlockDamageCause(class Block const &) const;
    /**
     * @vftbl 136
     * @symbol ?animateHurt\@Mob\@\@UEAAXXZ
     */
    virtual void animateHurt();
    /**
     * @vftbl 137
     * @symbol ?doFireHurt\@Mob\@\@UEAA_NH\@Z
     */
    virtual bool doFireHurt(int);
    /**
     * @vftbl 141
     * @symbol ?handleEntityEvent\@Mob\@\@UEAAXW4ActorEvent\@\@H\@Z
     */
    virtual void handleEntityEvent(enum class ActorEvent, int);
    /**
     * @vftbl 153
     * @symbol ?getArmorMaterialTypeInSlot\@Mob\@\@UEBA?AW4ArmorMaterialType\@\@W4ArmorSlot\@\@\@Z
     */
    virtual enum class ArmorMaterialType getArmorMaterialTypeInSlot(enum class ArmorSlot) const;
    /**
     * @vftbl 154
     * @symbol ?getArmorMaterialTextureTypeInSlot\@Mob\@\@UEBA?AW4ArmorTextureType\@\@W4ArmorSlot\@\@\@Z
     */
    virtual enum class ArmorTextureType getArmorMaterialTextureTypeInSlot(enum class ArmorSlot) const;
    /**
     * @vftbl 155
     * @symbol ?getArmorColorInSlot\@Mob\@\@UEBAMW4ArmorSlot\@\@H\@Z
     */
    virtual float getArmorColorInSlot(enum class ArmorSlot, int) const;
    /**
     * @vftbl 157
     * @symbol ?setEquippedSlot\@Mob\@\@UEAAXW4EquipmentSlot\@\@AEBVItemStack\@\@\@Z
     */
    virtual void setEquippedSlot(enum class EquipmentSlot, class ItemStack const &);
    /**
     * @vftbl 171
     * @symbol ?canFreeze\@Mob\@\@UEBA_NXZ
     */
    virtual bool canFreeze() const;
    /**
     * @vftbl 177
     * @symbol ?canChangeDimensionsUsingPortal\@Mob\@\@UEBA_NXZ
     */
    virtual bool canChangeDimensionsUsingPortal() const;
    /**
     * @vftbl 178
     * @symbol __unk_vfn_178
     */
    virtual void __unk_vfn_178();
    /**
     * @vftbl 182
     * @symbol ?causeFallDamage\@Mob\@\@MEAAXMMVActorDamageSource\@\@\@Z
     */
    virtual void causeFallDamage(float, float, class ActorDamageSource);
    /**
     * @vftbl 190
     * @symbol ?canBePulledIntoVehicle\@Mob\@\@UEBA_NXZ
     */
    virtual bool canBePulledIntoVehicle() const;
    /**
     * @vftbl 191
     * @symbol ?inCaravan\@Mob\@\@UEBA_NXZ
     */
    virtual bool inCaravan() const;
    /**
     * @vftbl 192
     * @symbol __unk_vfn_192
     */
    virtual void __unk_vfn_192();
    /**
     * @vftbl 196
     * @symbol ?stopRiding\@Mob\@\@UEAAX_N00\@Z
     */
    virtual void stopRiding(bool, bool, bool);
    /**
     * @vftbl 199
     * @symbol ?buildDebugInfo\@Mob\@\@UEBAXAEAV?$basic_string\@DU?$char_traits\@D\@std\@\@V?$allocator\@D\@2\@\@std\@\@\@Z
     */
    virtual void buildDebugInfo(std::string &) const;
    /**
     * @vftbl 204
     * @symbol ?getDeathTime\@Mob\@\@UEBAHXZ
     */
    virtual int getDeathTime() const;
    /**
     * @vftbl 215
     * @symbol ?swing\@Mob\@\@UEAAXXZ
     */
    virtual void swing();
    /**
     * @vftbl 217
     * @symbol __unk_vfn_217
     */
    virtual void __unk_vfn_217();
    /**
     * @vftbl 218
     * @symbol __unk_vfn_218
     */
    virtual void __unk_vfn_218();
    /**
     * @vftbl 240
     * @symbol __unk_vfn_240
     */
    virtual void __unk_vfn_240();
    /**
     * @vftbl 243
     * @symbol __unk_vfn_243
     */
    virtual void __unk_vfn_243();
    /**
     * @vftbl 244
     * @symbol ?kill\@Mob\@\@UEAAXXZ
     */
    virtual void kill();
    /**
     * @vftbl 245
     * @symbol ?die\@Mob\@\@UEAAXAEBVActorDamageSource\@\@\@Z
     */
    virtual void die(class ActorDamageSource const &);
    /**
     * @vftbl 246
     * @symbol ?shouldDropDeathLoot\@Mob\@\@UEBA_NXZ
     */
    virtual bool shouldDropDeathLoot() const;
    /**
     * @vftbl 258
     * @symbol ?updateEntitySpecificMolangVariables\@Mob\@\@MEAAXAEAVRenderParams\@\@\@Z
     */
    virtual void updateEntitySpecificMolangVariables(class RenderParams &);
    /**
     * @vftbl 260
     * @symbol __unk_vfn_260
     */
    virtual void __unk_vfn_260();
    /**
     * @vftbl 261
     * @symbol ?_hurt\@Mob\@\@MEAA_NAEBVActorDamageSource\@\@M_N1\@Z
     */
    virtual bool _hurt(class ActorDamageSource const &, float, bool, bool);
    /**
     * @vftbl 264
     * @symbol ?readAdditionalSaveData\@Mob\@\@MEAAXAEBVCompoundTag\@\@AEAVDataLoadHelper\@\@\@Z
     */
    virtual void readAdditionalSaveData(class CompoundTag const &, class DataLoadHelper &);
    /**
     * @vftbl 265
     * @symbol ?addAdditionalSaveData\@Mob\@\@MEBAXAEAVCompoundTag\@\@\@Z
     */
    virtual void addAdditionalSaveData(class CompoundTag &) const;
    /**
     * @vftbl 266
     * @symbol ?_playStepSound\@Mob\@\@MEAAXAEBVBlockPos\@\@AEBVBlock\@\@\@Z
     */
    virtual void _playStepSound(class BlockPos const &, class Block const &);
    /**
     * @vftbl 268
     * @symbol __unk_vfn_268
     */
    virtual void __unk_vfn_268();
    /**
     * @vftbl 273
     * @symbol ?_removePassenger\@Mob\@\@MEAAXAEBUActorUniqueID\@\@_N11\@Z
     */
    virtual void _removePassenger(struct ActorUniqueID const &, bool, bool, bool);
    /**
     * @vftbl 274
     * @symbol ?_onSizeUpdated\@Mob\@\@MEAAXXZ
     */
    virtual void _onSizeUpdated();
    /**
     * @vftbl 275
     * @symbol __unk_vfn_275
     */
    virtual void __unk_vfn_275();
    /**
     * @vftbl 276
     * @symbol ?knockback\@Mob\@\@UEAAXPEAVActor\@\@HMMMMM\@Z
     */
    virtual void knockback(class Actor *, int, float, float, float, float, float);
    /**
     * @vftbl 277
     * @symbol ?spawnAnim\@Mob\@\@UEAAXXZ
     */
    virtual void spawnAnim();
    /**
     * @vftbl 278
     * @symbol ?setSprinting\@Mob\@\@UEAAX_N\@Z
     */
    virtual void setSprinting(bool);
    /**
     * @vftbl 279
     * @symbol ?getHurtSound\@Mob\@\@UEAA?AW4LevelSoundEvent\@\@XZ
     */
    virtual enum class LevelSoundEvent getHurtSound();
    /**
     * @vftbl 280
     * @symbol ?getDeathSound\@Mob\@\@UEAA?AW4LevelSoundEvent\@\@XZ
     */
    virtual enum class LevelSoundEvent getDeathSound();
    /**
     * @vftbl 281
     * @symbol ?getSpeed\@Mob\@\@UEBAMXZ
     */
    virtual float getSpeed() const;
    /**
     * @vftbl 282
     * @symbol ?setSpeed\@Mob\@\@UEAAXM\@Z
     */
    virtual void setSpeed(float);
    /**
     * @vftbl 283
     * @symbol ?hurtEffects\@Mob\@\@UEAAXAEBVActorDamageSource\@\@M_N1\@Z
     */
    virtual void hurtEffects(class ActorDamageSource const &, float, bool, bool);
    /**
     * @vftbl 284
     * @symbol ?getMeleeWeaponDamageBonus\@Mob\@\@UEAAMPEAV1\@\@Z
     */
    virtual float getMeleeWeaponDamageBonus(class Mob *);
    /**
     * @vftbl 285
     * @symbol ?getMeleeKnockbackBonus\@Mob\@\@UEAAHXZ
     */
    virtual int getMeleeKnockbackBonus();
    /**
     * @vftbl 286
     * @symbol ?travel\@Mob\@\@UEAAXMMM_N\@Z
     */
    virtual void travel(float, float, float, bool);
    /**
     * @vftbl 287
     * @symbol ?applyFinalFriction\@Mob\@\@UEAAXM_N\@Z
     */
    virtual void applyFinalFriction(float, bool);
    /**
     * @vftbl 288
     * @symbol ?aiStep\@Mob\@\@UEAAXXZ
     */
    virtual void aiStep();
    /**
     * @vftbl 289
     * @symbol ?aiStep\@Mob\@\@UEBAXAEAUIMobMovementProxy\@\@\@Z
     */
    virtual void aiStep(struct IMobMovementProxy &) const;
    /**
     * @vftbl 290
     * @symbol ?pushActors\@Mob\@\@UEAAXXZ
     */
    virtual void pushActors();
    /**
     * @vftbl 291
     * @symbol ?lookAt\@Mob\@\@UEAAXPEAVActor\@\@MM\@Z
     */
    virtual void lookAt(class Actor *, float, float);
    /**
     * @vftbl 292
     * @symbol ?isLookingAtAnEntity\@Mob\@\@UEAA_NXZ
     */
    virtual bool isLookingAtAnEntity();
    /**
     * @vftbl 293
     * @symbol ?checkSpawnRules\@Mob\@\@UEAA_N_N\@Z
     */
    virtual bool checkSpawnRules(bool);
    /**
     * @vftbl 294
     * @symbol ?checkSpawnObstruction\@Mob\@\@UEBA_NXZ
     */
    virtual bool checkSpawnObstruction() const;
    /**
     * @vftbl 295
     * @symbol ?getAttackAnim\@Mob\@\@UEAAMM\@Z
     */
    virtual float getAttackAnim(float);
    /**
     * @vftbl 296
     * @symbol ?getItemUseDuration\@Mob\@\@UEBAHXZ
     */
    virtual int getItemUseDuration() const;
    /**
     * @vftbl 297
     * @symbol ?getItemUseStartupProgress\@Mob\@\@UEBAMXZ
     */
    virtual float getItemUseStartupProgress() const;
    /**
     * @vftbl 298
     * @symbol ?getItemUseIntervalProgress\@Mob\@\@UEBAMXZ
     */
    virtual float getItemUseIntervalProgress() const;
    /**
     * @vftbl 299
     * @symbol ?getItemUseIntervalAxis\@Mob\@\@UEBAHXZ
     */
    virtual int getItemUseIntervalAxis() const;
    /**
     * @vftbl 300
     * @symbol ?getTimeAlongSwing\@Mob\@\@UEBAHXZ
     */
    virtual int getTimeAlongSwing() const;
    /**
     * @vftbl 301
     * @symbol __unk_vfn_301
     */
    virtual void __unk_vfn_301();
    /**
     * @vftbl 302
     * @symbol ?getMaxHeadXRot\@Mob\@\@UEAAMXZ
     */
    virtual float getMaxHeadXRot();
    /**
     * @vftbl 303
     * @symbol ?isAlliedTo\@Mob\@\@UEAA_NPEAV1\@\@Z
     */
    virtual bool isAlliedTo(class Mob *);
    /**
     * @vftbl 304
     * @symbol ?doHurtTarget\@Mob\@\@UEAA_NPEAVActor\@\@AEBW4ActorDamageCause\@\@\@Z
     */
    virtual bool doHurtTarget(class Actor *, enum class ActorDamageCause const &);
    /**
     * @vftbl 305
     * @symbol __unk_vfn_305
     */
    virtual void __unk_vfn_305();
    /**
     * @vftbl 306
     * @symbol ?leaveCaravan\@Mob\@\@UEAAXXZ
     */
    virtual void leaveCaravan();
    /**
     * @vftbl 307
     * @symbol ?joinCaravan\@Mob\@\@UEAAXPEAV1\@\@Z
     */
    virtual void joinCaravan(class Mob *);
    /**
     * @vftbl 308
     * @symbol ?hasCaravanTail\@Mob\@\@UEBA_NXZ
     */
    virtual bool hasCaravanTail() const;
    /**
     * @vftbl 309
     * @symbol ?getCaravanHead\@Mob\@\@UEBA?AUActorUniqueID\@\@XZ
     */
    virtual struct ActorUniqueID getCaravanHead() const;
    /**
     * @vftbl 310
     * @symbol ?getArmorValue\@Mob\@\@UEBAHXZ
     */
    virtual int getArmorValue() const;
    /**
     * @vftbl 311
     * @symbol ?getArmorCoverPercentage\@Mob\@\@UEBAMXZ
     */
    virtual float getArmorCoverPercentage() const;
    /**
     * @vftbl 312
     * @symbol ?getToughnessValue\@Mob\@\@UEBAHXZ
     */
    virtual int getToughnessValue() const;
    /**
     * @vftbl 313
     * @symbol ?hurtArmorSlots\@Mob\@\@UEAAXAEBVActorDamageSource\@\@HV?$bitset\@$03\@std\@\@\@Z
     */
    virtual void hurtArmorSlots(class ActorDamageSource const &, int, class std::bitset<4>);
    /**
     * @vftbl 314
     * @symbol ?setDamagedArmor\@Mob\@\@UEAAXW4ArmorSlot\@\@AEBVItemStack\@\@\@Z
     */
    virtual void setDamagedArmor(enum class ArmorSlot, class ItemStack const &);
    /**
     * @vftbl 315
     * @symbol ?sendArmorDamage\@Mob\@\@UEAAXV?$bitset\@$03\@std\@\@\@Z
     */
    virtual void sendArmorDamage(class std::bitset<4>);
    /**
     * @vftbl 316
     * @symbol ?sendArmor\@Mob\@\@UEAAXV?$bitset\@$03\@std\@\@\@Z
     */
    virtual void sendArmor(class std::bitset<4>);
    /**
     * @vftbl 317
     * @symbol ?containerChanged\@Mob\@\@UEAAXH\@Z
     */
    virtual void containerChanged(int);
    /**
     * @vftbl 318
     * @symbol ?updateEquipment\@Mob\@\@UEAAXXZ
     */
    virtual void updateEquipment();
    /**
     * @vftbl 319
     * @symbol ?clearEquipment\@Mob\@\@UEAAHXZ
     */
    virtual int clearEquipment();
    /**
     * @vftbl 320
     * @symbol ?getAllArmorID\@Mob\@\@UEBA?AV?$vector\@HV?$allocator\@H\@std\@\@\@std\@\@XZ
     */
    virtual std::vector<int> getAllArmorID() const;
    /**
     * @vftbl 321
     * @symbol ?getAllHand\@Mob\@\@UEBA?AV?$vector\@PEBVItemStack\@\@V?$allocator\@PEBVItemStack\@\@\@std\@\@\@std\@\@XZ
     */
    virtual std::vector<class ItemStack const *> getAllHand() const;
    /**
     * @vftbl 322
     * @symbol ?getAllEquipment\@Mob\@\@UEBA?AV?$vector\@PEBVItemStack\@\@V?$allocator\@PEBVItemStack\@\@\@std\@\@\@std\@\@XZ
     */
    virtual std::vector<class ItemStack const *> getAllEquipment() const;
    /**
     * @vftbl 323
     * @symbol ?getArmorTypeHash\@Mob\@\@UEAAHXZ
     */
    virtual int getArmorTypeHash();
    /**
     * @vftbl 324
     * @symbol ?dropEquipmentOnDeath\@Mob\@\@UEAAXAEBVActorDamageSource\@\@H\@Z
     */
    virtual void dropEquipmentOnDeath(class ActorDamageSource const &, int);
    /**
     * @vftbl 325
     * @symbol ?dropEquipmentOnDeath\@Mob\@\@UEAAXXZ
     */
    virtual void dropEquipmentOnDeath();
    /**
     * @vftbl 326
     * @symbol ?clearVanishEnchantedItemsOnDeath\@Mob\@\@UEAAXXZ
     */
    virtual void clearVanishEnchantedItemsOnDeath();
    /**
     * @vftbl 327
     * @symbol ?sendInventory\@Mob\@\@UEAAX_N\@Z
     */
    virtual void sendInventory(bool);
    /**
     * @vftbl 328
     * @symbol ?getDamageAfterEnchantReduction\@Mob\@\@UEBAMAEBVActorDamageSource\@\@M\@Z
     */
    virtual float getDamageAfterEnchantReduction(class ActorDamageSource const &, float) const;
    /**
     * @vftbl 329
     * @symbol ?getDamageAfterArmorReduction\@Mob\@\@UEBAMAEBVActorDamageSource\@\@M\@Z
     */
    virtual float getDamageAfterArmorReduction(class ActorDamageSource const &, float) const;
    /**
     * @vftbl 330
     * @symbol ?getDamageAfterResistanceEffect\@Mob\@\@UEBAMAEBVActorDamageSource\@\@M\@Z
     */
    virtual float getDamageAfterResistanceEffect(class ActorDamageSource const &, float) const;
    /**
     * @vftbl 331
     * @symbol ?createAIGoals\@Mob\@\@UEAA_NXZ
     */
    virtual bool createAIGoals();
    /**
     * @vftbl 332
     * @symbol ?onBorn\@Mob\@\@UEAAXAEAVActor\@\@0\@Z
     */
    virtual void onBorn(class Actor &, class Actor &);
    /**
     * @vftbl 333
     * @symbol ?setItemSlot\@Mob\@\@UEAA_NW4EquipmentSlot\@\@AEBVItemStack\@\@\@Z
     */
    virtual bool setItemSlot(enum class EquipmentSlot, class ItemStack const &);
    /**
     * @vftbl 334
     * @symbol ?setTransitioningSitting\@Mob\@\@UEAAX_N\@Z
     */
    virtual void setTransitioningSitting(bool);
    /**
     * @vftbl 335
     * @symbol ?attackAnimation\@Mob\@\@UEAAXPEAVActor\@\@M\@Z
     */
    virtual void attackAnimation(class Actor *, float);
    /**
     * @vftbl 336
     * @symbol ?getAttackTime\@Mob\@\@UEAAHXZ
     */
    virtual int getAttackTime();
    /**
     * @vftbl 337
     * @symbol ?_getWalkTargetValue\@Mob\@\@UEAAMAEBVBlockPos\@\@\@Z
     */
    virtual float _getWalkTargetValue(class BlockPos const &);
    /**
     * @vftbl 338
     * @symbol ?canExistWhenDisallowMob\@Mob\@\@UEBA_NXZ
     */
    virtual bool canExistWhenDisallowMob() const;
    /**
     * @vftbl 339
     * @symbol ?ascendLadder\@Mob\@\@UEAAXXZ
     */
    virtual void ascendLadder();
    /**
     * @vftbl 340
     * @symbol ?ascendBlockByJumping\@Mob\@\@UEAAXXZ
     */
    virtual void ascendBlockByJumping();
    /**
     * @vftbl 341
     * @symbol ?descendBlockByCrouching\@Mob\@\@UEAAXXZ
     */
    virtual void descendBlockByCrouching();
    /**
     * @vftbl 342
     * @symbol ?dropContainer\@Mob\@\@UEAAXXZ
     */
    virtual void dropContainer();
    /**
     * @vftbl 343
     * @symbol ?initBodyControl\@Mob\@\@MEAA?AV?$unique_ptr\@VBodyControl\@\@U?$default_delete\@VBodyControl\@\@\@std\@\@\@std\@\@XZ
     */
    virtual std::unique_ptr<class BodyControl> initBodyControl();
    /**
     * @vftbl 344
     * @symbol ?jumpFromGround\@Mob\@\@MEAAXAEBVIConstBlockSource\@\@\@Z
     */
    virtual void jumpFromGround(class IConstBlockSource const &);
    /**
     * @vftbl 345
     * @symbol ?jumpFromGround\@Mob\@\@MEBAXAEAUIMobMovementProxy\@\@AEBVIConstBlockSource\@\@\@Z
     */
    virtual void jumpFromGround(struct IMobMovementProxy &, class IConstBlockSource const &) const;
    /**
     * @vftbl 346
     * @symbol ?newServerAiStep\@Mob\@\@MEAAXXZ
     */
    virtual void newServerAiStep();
    /**
     * @vftbl 347
     * @symbol ?_serverAiMobStep\@Mob\@\@MEAAXXZ
     */
    virtual void _serverAiMobStep();
    /**
     * @vftbl 348
     * @symbol ?dropBags\@Mob\@\@MEAAXXZ
     */
    virtual void dropBags();
    /**
     * @vftbl 349
     * @symbol ?tickDeath\@Mob\@\@MEAAXXZ
     */
    virtual void tickDeath();
    /**
     * @vftbl 350
     * @symbol ?updateGliding\@Mob\@\@MEAAXXZ
     */
    virtual void updateGliding();
    /**
     * @vftbl 351
     * @symbol __unk_vfn_351
     */
    virtual void __unk_vfn_351();
    /**
     * @vftbl 352
     * @symbol ?_getAdjustedAABBForSpawnCheck\@Mob\@\@MEBA?AVAABB\@\@AEBV2\@AEBVVec3\@\@\@Z
     */
    virtual class AABB _getAdjustedAABBForSpawnCheck(class AABB const &, class Vec3 const &) const;
#ifdef ENABLE_VIRTUAL_FAKESYMBOL_MOB
    /**
     * @symbol ?_allowAscendingScaffolding\@Mob\@\@MEBA_NXZ
     */
    MCVAPI bool _allowAscendingScaffolding() const;
    /**
     * @symbol ?ate\@Mob\@\@UEAAXXZ
     */
    MCVAPI void ate();
    /**
     * @symbol ?canBeControlledByPassenger\@Mob\@\@UEAA_NXZ
     */
    MCVAPI bool canBeControlledByPassenger();
    /**
     * @symbol ?isShootable\@Mob\@\@UEAA_NXZ
     */
    MCVAPI bool isShootable();
    /**
     * @symbol ?renderDebugServerState\@Mob\@\@UEAAXAEBVOptions\@\@\@Z
     */
    MCVAPI void renderDebugServerState(class Options const &);
    /**
     * @symbol __unk_destructor_-1
     */
    MCVAPI ~Mob();
#endif
    /**
     * @symbol ??0Mob\@\@QEAA\@AEAVLevel\@\@AEAVEntityContext\@\@\@Z
     */
    MCAPI Mob(class Level &, class EntityContext &);
    /**
     * @symbol ??0Mob\@\@QEAA\@PEAVActorDefinitionGroup\@\@AEBUActorDefinitionIdentifier\@\@AEAVEntityContext\@\@\@Z
     */
    MCAPI Mob(class ActorDefinitionGroup *, struct ActorDefinitionIdentifier const &, class EntityContext &);
    /**
     * @symbol ?_endJump\@Mob\@\@QEAAXXZ
     */
    MCAPI void _endJump();
    /**
     * @symbol ?addSpeedModifier\@Mob\@\@QEAAXAEBVUUID\@mce\@\@AEBV?$basic_string\@DU?$char_traits\@D\@std\@\@V?$allocator\@D\@2\@\@std\@\@M\@Z
     */
    MCAPI void addSpeedModifier(class mce::UUID const &, std::string const &, float);
    /**
     * @symbol ?calcMoveRelativeSpeed\@Mob\@\@QEAAMW4TravelType\@\@\@Z
     */
    MCAPI float calcMoveRelativeSpeed(enum class TravelType);
    /**
     * @symbol ?checkForPostHitDamageImmunity\@Mob\@\@QEAA_NMAEBVActorDamageSource\@\@\@Z
     */
    MCAPI bool checkForPostHitDamageImmunity(float, class ActorDamageSource const &);
    /**
     * @symbol ?checkTotemDeathProtection\@Mob\@\@QEAA_NAEBVActorDamageSource\@\@\@Z
     */
    MCAPI bool checkTotemDeathProtection(class ActorDamageSource const &);
    /**
     * @symbol ?createAI\@Mob\@\@QEAAXV?$vector\@UGoalDefinition\@\@V?$allocator\@UGoalDefinition\@\@\@std\@\@\@std\@\@\@Z
     */
    MCAPI void createAI(std::vector<struct GoalDefinition>);
    /**
     * @symbol ?emitJumpPreventedEvent\@Mob\@\@QEAAXAEBVBlockPos\@\@\@Z
     */
    MCAPI void emitJumpPreventedEvent(class BlockPos const &);
    /**
     * @symbol ?frostWalk\@Mob\@\@QEAAXXZ
     */
    MCAPI void frostWalk();
    /**
     * @symbol ?getBoundOrigin\@Mob\@\@QEBA?AVBlockPos\@\@XZ
     */
    MCAPI class BlockPos getBoundOrigin() const;
    /**
     * @symbol ?getCaravanSize\@Mob\@\@QEBAHXZ
     */
    MCAPI int getCaravanSize() const;
    /**
     * @symbol ?getEatCounter\@Mob\@\@QEBAHXZ
     */
    MCAPI int getEatCounter() const;
    /**
     * @symbol ?getFirstCaravanHead\@Mob\@\@QEAAPEAV1\@XZ
     */
    MCAPI class Mob * getFirstCaravanHead();
    /**
     * @symbol ?getGlidingTicks\@Mob\@\@QEBAHXZ
     */
    MCAPI int getGlidingTicks() const;
    /**
     * @symbol ?getItemSlot\@Mob\@\@QEBAAEBVItemStack\@\@W4EquipmentSlot\@\@\@Z
     */
    MCAPI class ItemStack const & getItemSlot(enum class EquipmentSlot) const;
    /**
     * @symbol ?getJumpEffectAmplifierValue\@Mob\@\@QEAAMXZ
     */
    MCAPI float getJumpEffectAmplifierValue();
    /**
     * @symbol ?getJumpMultiplier\@Mob\@\@QEAAMXZ
     */
    MCAPI float getJumpMultiplier();
    /**
     * @symbol ?getJumpMultiplier\@Mob\@\@QEAAMAEBVIConstBlockSource\@\@\@Z
     */
    MCAPI float getJumpMultiplier(class IConstBlockSource const &);
    /**
     * @symbol ?getJumpPower\@Mob\@\@QEBAMXZ
     */
    MCAPI float getJumpPower() const;
    /**
     * @symbol ?getJumpPrevention\@Mob\@\@QEAA?AUJumpPreventionResult\@\@XZ
     */
    MCAPI struct JumpPreventionResult getJumpPrevention();
    /**
     * @symbol ?getJumpPrevention\@Mob\@\@QEAA?AUJumpPreventionResult\@\@AEBVIConstBlockSource\@\@\@Z
     */
    MCAPI struct JumpPreventionResult getJumpPrevention(class IConstBlockSource const &);
    /**
     * @symbol ?getJumpTicks\@Mob\@\@QEBAHXZ
     */
    MCAPI int getJumpTicks() const;
    /**
     * @symbol ?getMovementComponentCurrentSpeed\@Mob\@\@QEBAMXZ
     */
    MCAPI float getMovementComponentCurrentSpeed() const;
    /**
     * @symbol ?getNoActionTime\@Mob\@\@QEBAHXZ
     */
    MCAPI int getNoActionTime() const;
    /**
     * @symbol ?getRollCounter\@Mob\@\@QEBAHXZ
     */
    MCAPI int getRollCounter() const;
    /**
     * @symbol ?getSwimSpeedMultiplier\@Mob\@\@QEBAMXZ
     */
    MCAPI float getSwimSpeedMultiplier() const;
    /**
     * @symbol ?getTargetCaptain\@Mob\@\@QEBA?AUActorUniqueID\@\@XZ
     */
    MCAPI struct ActorUniqueID getTargetCaptain() const;
    /**
     * @symbol ?getTravelType\@Mob\@\@QEAA?AW4TravelType\@\@XZ
     */
    MCAPI enum class TravelType getTravelType();
    /**
     * @symbol ?getYBodyRotation\@Mob\@\@QEBAMXZ
     */
    MCAPI float getYBodyRotation() const;
    /**
     * @symbol ?hasBoundOrigin\@Mob\@\@QEBA_NXZ
     */
    MCAPI bool hasBoundOrigin() const;
    /**
     * @symbol ?hurtArmor\@Mob\@\@QEAAXAEBVActorDamageSource\@\@H\@Z
     */
    MCAPI void hurtArmor(class ActorDamageSource const &, int);
    /**
     * @symbol ?isAbleToMove\@Mob\@\@QEBA_NXZ
     */
    MCAPI bool isAbleToMove() const;
    /**
     * @symbol ?isEating\@Mob\@\@QEBA_NXZ
     */
    MCAPI bool isEating() const;
    /**
     * @symbol ?isFrostWalking\@Mob\@\@QEBA_NXZ
     */
    MCAPI bool isFrostWalking() const;
    /**
     * @symbol ?isGliding\@Mob\@\@QEBA_NXZ
     */
    MCAPI bool isGliding() const;
    /**
     * @symbol ?isLayingEgg\@Mob\@\@QEBA_NXZ
     */
    MCAPI bool isLayingEgg() const;
    /**
     * @symbol ?isPregnant\@Mob\@\@QEBA_NXZ
     */
    MCAPI bool isPregnant() const;
    /**
     * @symbol ?isRolling\@Mob\@\@QEBA_NXZ
     */
    MCAPI bool isRolling() const;
    /**
     * @symbol ?isSprinting\@Mob\@\@QEBA_NXZ
     */
    MCAPI bool isSprinting() const;
    /**
     * @symbol ?isTransitioningSitting\@Mob\@\@QEBA_NXZ
     */
    MCAPI bool isTransitioningSitting() const;
    /**
     * @symbol ?onPlayerDimensionChanged\@Mob\@\@QEAAXPEAVPlayer\@\@V?$AutomaticID\@VDimension\@\@H\@\@1\@Z
     */
    MCAPI void onPlayerDimensionChanged(class Player *, class AutomaticID<class Dimension, int>, class AutomaticID<class Dimension, int>);
    /**
     * @symbol ?onPlayerJump\@Mob\@\@QEAAXH\@Z
     */
    MCAPI void onPlayerJump(int);
    /**
     * @symbol ?removeSpeedModifier\@Mob\@\@QEAAXAEBVUUID\@mce\@\@\@Z
     */
    MCAPI void removeSpeedModifier(class mce::UUID const &);
    /**
     * @symbol ?resetAttributes\@Mob\@\@QEAAXXZ
     */
    MCAPI void resetAttributes();
    /**
     * @symbol ?resetNoActionTime\@Mob\@\@QEAAXXZ
     */
    MCAPI void resetNoActionTime();
    /**
     * @symbol ?sendArmorDamageSlot\@Mob\@\@QEAAXW4ArmorSlot\@\@\@Z
     */
    MCAPI void sendArmorDamageSlot(enum class ArmorSlot);
    /**
     * @symbol ?sendArmorSlot\@Mob\@\@QEAAXW4ArmorSlot\@\@\@Z
     */
    MCAPI void sendArmorSlot(enum class ArmorSlot);
    /**
     * @symbol ?setEatCounter\@Mob\@\@QEAAXH\@Z
     */
    MCAPI void setEatCounter(int);
    /**
     * @symbol ?setEating\@Mob\@\@QEAAX_N\@Z
     */
    MCAPI void setEating(bool);
    /**
     * @symbol ?setIsLayingEgg\@Mob\@\@QEAAX_N\@Z
     */
    MCAPI void setIsLayingEgg(bool);
    /**
     * @symbol ?setIsPregnant\@Mob\@\@QEAAX_N\@Z
     */
    MCAPI void setIsPregnant(bool);
    /**
     * @symbol ?setJumpTicks\@Mob\@\@QEAAXH\@Z
     */
    MCAPI void setJumpTicks(int);
    /**
     * @symbol ?setMovementComponentCurrentSpeed\@Mob\@\@QEAAXM\@Z
     */
    MCAPI void setMovementComponentCurrentSpeed(float);
    /**
     * @symbol ?setNaturallySpawned\@Mob\@\@QEAAX_N\@Z
     */
    MCAPI void setNaturallySpawned(bool);
    /**
     * @symbol ?setPassengerLockedBodyRot\@Mob\@\@QEAAXM\@Z
     */
    MCAPI void setPassengerLockedBodyRot(float);
    /**
     * @symbol ?setPassengerRotLimit\@Mob\@\@QEAAXM\@Z
     */
    MCAPI void setPassengerRotLimit(float);
    /**
     * @symbol ?setRolling\@Mob\@\@QEAAX_N\@Z
     */
    MCAPI void setRolling(bool);
    /**
     * @symbol ?setSpawnMethod\@Mob\@\@QEAAXW4MobSpawnMethod\@\@\@Z
     */
    MCAPI void setSpawnMethod(enum class MobSpawnMethod);
    /**
     * @symbol ?setSpeedModifier\@Mob\@\@QEAAXM\@Z
     */
    MCAPI void setSpeedModifier(float);
    /**
     * @symbol ?setSurfaceMob\@Mob\@\@QEAAX_N\@Z
     */
    MCAPI void setSurfaceMob(bool);
    /**
     * @symbol ?setSwimSpeedMultiplier\@Mob\@\@QEAAXM\@Z
     */
    MCAPI void setSwimSpeedMultiplier(float);
    /**
     * @symbol ?setTargetCaptain\@Mob\@\@QEAAXUActorUniqueID\@\@\@Z
     */
    MCAPI void setTargetCaptain(struct ActorUniqueID);
    /**
     * @symbol ?setYBodyRotation\@Mob\@\@QEAAXM\@Z
     */
    MCAPI void setYBodyRotation(float);
    /**
     * @symbol ?setYBodyRotations\@Mob\@\@QEAAXMM\@Z
     */
    MCAPI void setYBodyRotations(float, float);
    /**
     * @symbol ?snapToYBodyRot\@Mob\@\@QEAAXM\@Z
     */
    MCAPI void snapToYBodyRot(float);
    /**
     * @symbol ?snapToYHeadRot\@Mob\@\@QEAAXM\@Z
     */
    MCAPI void snapToYHeadRot(float);
    /**
     * @symbol ?tryFrostWalk\@Mob\@\@QEAAXXZ
     */
    MCAPI void tryFrostWalk();
    /**
     * @symbol ?tryProcessSoulSpeed\@Mob\@\@QEAAXXZ
     */
    MCAPI void tryProcessSoulSpeed();
    /**
     * @symbol ?tryUpdateAI\@Mob\@\@QEAAXXZ
     */
    MCAPI void tryUpdateAI();
    /**
     * @symbol ?ARMOR_DAMAGE_DIVISOR\@Mob\@\@2HB
     */
    MCAPI static int const ARMOR_DAMAGE_DIVISOR;
    /**
     * @symbol ?ARMOR_PROTECTION_DIVIDER\@Mob\@\@2MB
     */
    MCAPI static float const ARMOR_PROTECTION_DIVIDER;
    /**
     * @symbol ?ASCEND_BLOCK_BY_JUMPING_SPEED\@Mob\@\@2MB
     */
    MCAPI static float const ASCEND_BLOCK_BY_JUMPING_SPEED;
    /**
     * @symbol ?BASE_ARMOR_TOUGHNESS\@Mob\@\@2MB
     */
    MCAPI static float const BASE_ARMOR_TOUGHNESS;
    /**
     * @symbol ?DEFAULT_GRAVITY\@Mob\@\@2MB
     */
    MCAPI static float const DEFAULT_GRAVITY;
    /**
     * @symbol ?FRICTION_CONSTANT\@Mob\@\@2MB
     */
    MCAPI static float const FRICTION_CONSTANT;
    /**
     * @symbol ?FRICTION_CONSTANT_MODIFIED\@Mob\@\@2MB
     */
    MCAPI static float const FRICTION_CONSTANT_MODIFIED;
    /**
     * @symbol ?FRICTION_MODIFIER\@Mob\@\@2MB
     */
    MCAPI static float const FRICTION_MODIFIER;
    /**
     * @symbol ?GLIDING_FALL_RESET_DELTA\@Mob\@\@2MB
     */
    MCAPI static float const GLIDING_FALL_RESET_DELTA;
    /**
     * @symbol ?LADDER_CLIMB_SPEED\@Mob\@\@2MB
     */
    MCAPI static float const LADDER_CLIMB_SPEED;
    /**
     * @symbol ?MAX_ARMOR\@Mob\@\@2MB
     */
    MCAPI static float const MAX_ARMOR;
    /**
     * @symbol ?MIN_ARMOR_RATIO\@Mob\@\@2MB
     */
    MCAPI static float const MIN_ARMOR_RATIO;
    /**
     * @symbol ?NUM_ARMOR_ITEMS\@Mob\@\@2MB
     */
    MCAPI static float const NUM_ARMOR_ITEMS;
    /**
     * @symbol ?PLAYER_SWIMMING_SURFACE_OFFSET\@Mob\@\@2MB
     */
    MCAPI static float const PLAYER_SWIMMING_SURFACE_OFFSET;
    /**
     * @symbol ?REMOVE_PASSENGERS_DELAY\@Mob\@\@2HB
     */
    MCAPI static int const REMOVE_PASSENGERS_DELAY;
    /**
     * @symbol ?SLOW_FALL_GRAVITY\@Mob\@\@2MB
     */
    MCAPI static float const SLOW_FALL_GRAVITY;
    /**
     * @symbol ?SPAWN_XP_DELAY\@Mob\@\@2HB
     */
    MCAPI static int const SPAWN_XP_DELAY;
    /**
     * @symbol ?TOTAL_ROLL_STEPS\@Mob\@\@2HB
     */
    MCAPI static int const TOTAL_ROLL_STEPS;
    /**
     * @symbol ?_aiStep\@Mob\@\@SAXAEAUIMobMovementProxy\@\@\@Z
     */
    MCAPI static void _aiStep(struct IMobMovementProxy &);
    /**
     * @symbol ?_calcMoveRelativeSpeed\@Mob\@\@SAMAEAUIMobMovementProxy\@\@W4TravelType\@\@AEBVIConstBlockSource\@\@\@Z
     */
    MCAPI static float _calcMoveRelativeSpeed(struct IMobMovementProxy &, enum class TravelType, class IConstBlockSource const &);
    /**
     * @symbol ?_travel\@Mob\@\@SAXAEAUIMobMovementProxy\@\@MMM_N\@Z
     */
    MCAPI static void _travel(struct IMobMovementProxy &, float, float, float, bool);
    /**
     * @symbol ?_updateMobTravel\@Mob\@\@SAXAEAUIMobMovementProxy\@\@_N\@Z
     */
    MCAPI static void _updateMobTravel(struct IMobMovementProxy &, bool);
    /**
     * @symbol ?calculateJumpImpulse\@Mob\@\@SAMAEBUIMobMovementProxy\@\@AEBVIConstBlockSource\@\@\@Z
     */
    MCAPI static float calculateJumpImpulse(struct IMobMovementProxy const &, class IConstBlockSource const &);
    /**
     * @symbol ?getJumpEffectAmplifierValue\@Mob\@\@SAMAEBUIMobMovementProxy\@\@\@Z
     */
    MCAPI static float getJumpEffectAmplifierValue(struct IMobMovementProxy const &);
    /**
     * @symbol ?getJumpPrevention\@Mob\@\@SA?AUJumpPreventionResult\@\@AEBUIMobMovementProxy\@\@AEBVIConstBlockSource\@\@\@Z
     */
    MCAPI static struct JumpPreventionResult getJumpPrevention(struct IMobMovementProxy const &, class IConstBlockSource const &);
    /**
     * @symbol ?getTravelType\@Mob\@\@SA?AW4TravelType\@\@AEAUIMobMovementProxy\@\@AEBVIConstBlockSource\@\@\@Z
     */
    MCAPI static enum class TravelType getTravelType(struct IMobMovementProxy &, class IConstBlockSource const &);
    /**
     * @symbol ?isImmobile\@Mob\@\@SA_NAEBUIActorMovementProxy\@\@\@Z
     */
    MCAPI static bool isImmobile(struct IActorMovementProxy const &);
    /**
     * @symbol ?setSprinting\@Mob\@\@SAXAEAVBaseAttributeMap\@\@VSynchedActorDataWriter\@\@_N\@Z
     */
    MCAPI static void setSprinting(class BaseAttributeMap &, class SynchedActorDataWriter, bool);
    /**
     * @symbol ?shouldApplyWaterGravity\@Mob\@\@SA_NAEBUIActorMovementProxy\@\@AEBVIConstBlockSource\@\@\@Z
     */
    MCAPI static bool shouldApplyWaterGravity(struct IActorMovementProxy const &, class IConstBlockSource const &);
    /**
     * @symbol ?shouldApplyWaterGravity\@Mob\@\@SA_NAEBUIActorMovementProxy\@\@\@Z
     */
    MCAPI static bool shouldApplyWaterGravity(struct IActorMovementProxy const &);
    /**
     * @symbol ?tryGetFromEntity\@Mob\@\@SAPEAV1\@AEAVEntityContext\@\@_N\@Z
     */
    MCAPI static class Mob * tryGetFromEntity(class EntityContext &, bool);

//protected:
    /**
     * @symbol ?_addBuiltInMobComponents\@Mob\@\@IEAA?AUBuiltInMobComponents\@\@XZ
     */
    MCAPI struct BuiltInMobComponents _addBuiltInMobComponents();
    /**
     * @symbol ?_doSprintParticleEffect\@Mob\@\@IEAAXXZ
     */
    MCAPI void _doSprintParticleEffect();
    /**
     * @symbol ?_processSoulSpeed\@Mob\@\@IEAAXXZ
     */
    MCAPI void _processSoulSpeed();
    /**
     * @symbol ?_registerMobAttributes\@Mob\@\@IEAAXXZ
     */
    MCAPI void _registerMobAttributes();
    /**
     * @symbol ?getCurrentSwingDuration\@Mob\@\@IEAAHXZ
     */
    MCAPI int getCurrentSwingDuration();
    /**
     * @symbol ?saveOffhand\@Mob\@\@IEBA?AV?$unique_ptr\@VListTag\@\@U?$default_delete\@VListTag\@\@\@std\@\@\@std\@\@XZ
     */
    MCAPI std::unique_ptr<class ListTag> saveOffhand() const;
    /**
     * @symbol ?setNoActionTime\@Mob\@\@IEAAXH\@Z
     */
    MCAPI void setNoActionTime(int);
    /**
     * @symbol ?tickEffects\@Mob\@\@IEAAXXZ
     */
    MCAPI void tickEffects();
    /**
     * @symbol ?updateAttackAnim\@Mob\@\@IEAAXXZ
     */
    MCAPI void updateAttackAnim();
    /**
     * @symbol ?updateGlidingDurability\@Mob\@\@IEAA_NXZ
     */
    MCAPI bool updateGlidingDurability();
    /**
     * @symbol ?_jumpFromGround\@Mob\@\@KAXAEAUIMobMovementProxy\@\@AEBVIConstBlockSource\@\@\@Z
     */
    MCAPI static void _jumpFromGround(struct IMobMovementProxy &, class IConstBlockSource const &);

//private:
    /**
     * @symbol ?_initHardCodedComponents\@Mob\@\@AEAA_N_N\@Z
     */
    MCAPI bool _initHardCodedComponents(bool);
    /**
     * @symbol ?_initialize\@Mob\@\@AEAAXAEAVEntityContext\@\@_N\@Z
     */
    MCAPI void _initialize(class EntityContext &, bool);
    /**
     * @symbol ?_saveArmor\@Mob\@\@AEBA?AV?$unique_ptr\@VListTag\@\@U?$default_delete\@VListTag\@\@\@std\@\@\@std\@\@XZ
     */
    MCAPI std::unique_ptr<class ListTag> _saveArmor() const;
    /**
     * @symbol ?_updateSprintingState\@Mob\@\@AEAAXXZ
     */
    MCAPI void _updateSprintingState();
    /**
     * @symbol ?_verifyAttributes\@Mob\@\@AEAAXXZ
     */
    MCAPI void _verifyAttributes();
    /**
     * @symbol ?_executeDash\@Mob\@\@CAXAEAV1\@AEAUIMobMovementProxy\@\@AEBVIConstBlockSource\@\@\@Z
     */
    MCAPI static void _executeDash(class Mob &, struct IMobMovementProxy &, class IConstBlockSource const &);
    /**
     * @symbol ?_tryApplyingLevitation\@Mob\@\@CA_NAEBUIMobMovementProxy\@\@AEAVVec3\@\@\@Z
     */
    MCAPI static bool _tryApplyingLevitation(struct IMobMovementProxy const &, class Vec3 &);

protected:
    /**
     * @symbol ?MAX_INACTIVITY_TIMER\@Mob\@\@1HB
     */
    MCAPI static int const MAX_INACTIVITY_TIMER;

private:

};
