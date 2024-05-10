#ifndef ITEM_H
#define ITEM_H

#include "Spirit.h"
#include "../common/Vector2.h"

namespace cube {
class Creature;
class Item {
    public:

        // Todo: Make enums / constants for all item types.
        enum MaterialType : int
        {
            Iron = 1,
            Wood = 2,
            Steel = 4,
            Obsidian = 5,
            Cloth = 6,
            Bone = 7,
            Copper = 10,
            Gold = 11,
            Silver = 12,
            Platinum = 13,
            Emerald = 14,
            Sapphire = 15,
            Ruby = 16,
            Diamond = 17,
            Sandstone = 18,
            Saurian = 19,
            Parrot = 20,
            Mammoth = 21,
            Plant = 22,
            Ice = 23,
            Light = 24,
            Glass = 25,
            Silk = 26,
            Linnen = 27,
            Cotton = 28,
            Bronze = 29,
            Calcio = 30,
            Felt = 31,
            Flannell = 32,
            Mail = 33,
            Rivet = 34,
            Filament = 35,
            Spike = 36,
            Fiber = 37,
            Scale = 38,
            Web = 39,
            Shadow = 40,
            Dark = 41,
            Demon = 42,
            Fire = 43,
            Druid = 44,
            FireSpirit = 128,
            UnholySpirit = 129,
            IceSpirit = 130,
            WindSpirit = 131,
        };

        enum CategoryType : char {
            Consumable = 1,
            Formula = 2,
            Weapon = 3,
            Armor1 = 4,
            Armor2 = 5,
            Armor3 = 6,
            Armor4 = 7,
            Amulet = 8,
            Ring = 9,
            UnknownVoxel = 10,
            Collectible = 11,
            Coin = 12,
            PlatinumCoin = 13,
            ManaCube = 14,
            Leftover = 15,
            Beak = 16,
            Painting = 17,
            Vase = 18,
            Candle = 19,
            PetCage = 20,
            PetFood = 21,
            Quest = 22,
            Special = 23,
            Lamp = 24,
            EyePatch = 25,
            Building = 26,
            Potion = 27,
            Glyph = 28,
            Loot = 29,
            ManaSpirit = 30,
            Unknown = 31,
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
