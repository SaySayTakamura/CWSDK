#ifndef ITEM_H
#define ITEM_H

#include "Spirit.h"
#include "../common/Vector2.h"

namespace cube {
class Creature;
class Item {
    public:

        // Todo: Make enums / constants for all item types.
        enum class MaterialType
        {
            FireSpirit = 128,
            UnholySpirit,
            IceSpirit,
            WindSpirit,
        };

        char category;
        //3 bytes padding
        int id;
        unsigned int modifier;
        IntVector2 region;
        char rarity;
        //3 bytes padding
        int formula_category;
        char material;
        cube::Spirit spirits[32];
        char num_spirits;
        //2 bytes padding

        Item();
        Item(char category, int id);
        cube::Item* ctor();

        void Copy(cube::Item* src);

        float GetArmor(cube::Creature* creature);
        float GetHP(cube::Creature* creature);
        float GetRegeneration(cube::Creature* creature);
        float GetResistance(cube::Creature* creature);
        float GetHaste(cube::Creature* creature);
        float GetPower(cube::Creature* creature);
        float GetCritical(cube::Creature* creature);

        float GetGearRarityModifier(cube::Creature* creature, signed int spirits);
        float GetPowerOfSpirits(cube::Creature* creature);
        float GetPowerWithoutSpirits(cube::Creature* creature);

        int GetArtifactType();
        int GetEffectiveRarity(IntVector2* region);
        int GetBuyingPrice();
        int GetSellingPrice();

        bool ClassCanWearItem(int classType);
        bool IsValidEquipmentForCreature(cube::Creature* creature, int itemCategory);

        bool IsPlusItem();
        void ConvertToPlusItem();
        void ConvertToNormalWeapon();
        void UpgradeItem();
    };
}

static_assert(sizeof(cube::Item) == 0xA0, "cube::Creature is not the correct size.");

#endif // ITEM_H
