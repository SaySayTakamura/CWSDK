#ifndef CREATURE_H
#define CREATURE_H

#include "../IDA/types.h"
#include "../common/Vector3.h"
#include "../common/RGBA.h"
#include "../common/Matrix4.h"
#include "../plasma/Map.h"
#include <vector>
#include <list>
#include "ItemStack.h"
#include "Equipment.h"
#include "Interaction.h"
#include <windows.h>

namespace cube {
    class Creature {
	public:
		// Todo: Add enums to the correct variables
		// Todo: Add race enum
		// Todo: Move cube::Creature::EntityData and cube::Creature::Appearance to different files
		enum ClassType : int
		{
			Warrior = 1,
			Ranger,
			Mage,
			Rogue,
			Monk, // Not yet implemented
			Necromancer, // Not yet implemented
			ItemVendor = 128,
			WeaponVendor = 129,
			ArmorVendor = 130,
			Analyzer = 131,
			InnKeeper = 132,
			Smithy = 133,
			Carpenter = 134,
			Tailor = 135,
			Archeologist = 136,
			DONT_USE_WEIRD_DOUBLING,
			FlightMaster = 154,
			GuildReceptionist = 155,
			GemTrader = 156,
			ShopSupplier = 157,
			MasterSailor = 159,
			MasterGlider = 160,
			ArenaMaster = 161,
		};

		enum class InventoryTab
		{
			EquipmentTab = 0,
			SpecialsTab,
			ItemsTab,
			IngredientsTab,
			PetsTab,
			ArtifactsTab
		};


		enum EntityBehaviour : int
		{
			Player = 0,
			Hostile,
			Passive,
			NPC,
			NPCInteract,
			Unk_05,
			Pet,
			Inanimate,
			ExamineObject,
		};

		enum class CollisionFlags
		{
			Ground = 0,
			Water,
			Wall,
			Unk_03,
			Surfaced,
			Colliding,
			ClippingObject,
			Lava,
			Unk_08,
			Poison,
			Snow,
			Leaves,
			Unk_12,
			Road,
			Unk_14,
			Unk_15,
		};

		enum class AppearanceModifiers
		{
			IsFourFooted = 0,
			Unk_01,
			Unk_02,
			Unk_03, //Is checked when dropping items (maybe some kind of drop thingy?)
			Unk_04, //Is checked when dropping items (maybe some kind of drop thingy?)
			NeededForGemTrader,
			IsClassMaster,
			Unk_07,
			Unk_08,
			IsNamedBoss,
			HasGlowingHair,
			Unk_11, //Is checked when dropping items (maybe some kind of drop thingy?)
			Unk_12,
			IsNotTalking,
			CanPickup,
			IsFriendly,
			Unk_16,
			IsMiniBoss,
			IsBoss,
			Unk_19,
			IsGhost,
			IsUseable,
			IsPetrified,
			Unk_23,
			Unk_24,
			Unk_25,
			IsPossesed,
			Unk_27,
			Unk_28,
			Unk_29,
			Unk_30,
			Unk_31
		};

		enum class StateFlags
		{
			ActiveLantern = 0,
			Unk_01,
			Unk_02,
			Unk_03,
			Unk_04,
			Unk_05,
			IsRunning,
			Unk_07,
			VisibleOnMap,
			StayOnGround,
			IsSneaking,
			Unk_11,
			Unk_12,
			Unk_13,
			Unk_14,
			Unk_15
		};
        // cube::Creature::EntityData
        class EntityData {
		public:
            // cube::Creature::EntityData::Appearance
            class Appearance {
                public:
                __int16 field_78;
                ByteRGBA hair_color;
                char padding_7E;
                char padding_7F;
                unsigned int flags2;
                float graphics_scale;
                float hitbox_scale;
                float physics_scale;
                __int16 head_model;
                __int16 hair_model;
                __int16 hands_model;
                __int16 feet_model;
                __int16 chest_model;
                __int16 tail_model;
                __int16 shoulder_model;
                __int16 wings_model;
                float head_scale;
                float chest_scale;
                float hands_scale;
                float feet_scale;
                float unknown_scale;
                float weapon_scale;
                float tail_scale;
                float shoulder_scale;
                float wing_scale;
                float chest_rotation;
                FloatVector3 hands_rotation;
                float feet_rotation;
                float wings_rotation;
                float unknown_rotation;
                FloatVector3 chest_position;
                FloatVector3 head_position;
                FloatVector3 hands_position;
                FloatVector3 feet_position;
                FloatVector3 unknown_position;
                FloatVector3 wings_position;

				cube::Creature::EntityData::Appearance* Copy(cube::Creature::EntityData::Appearance* other);
            }; // end cube::Creature::EntityData::Appearance

			LongVector3 position;
			float pitch;
			float roll;
			float yaw;
			FloatVector3 velocity;
			FloatVector3 acceleration;
			FloatVector3 retreat;
			float head_rotation;
			unsigned int flags;
			char hostility_type; // EntityBehaviour
			// Todo: Change to 3 bytes padding if possible
			char field_61;
			char field_62;
			char field_63;
			unsigned int race;
			BYTE current_ability;
			// Todo: Change to 3 bytes padding if possible
			char field_59;
			char field_5A;
			char field_5B;
			float time_since_ability;
			int hit_combo;
			float time_since_hit;
			cube::Creature::EntityData::Appearance appearance;
			__int16 binary_toggles;
			// Todo: Change to 2 bytes padding if possible
			char field_11A;
			char field_11B;
			float roll_time;
			float stun_time;
			float unknown_time;
			float slowed_time;
			float sprint_time;
			int field_140;
			unsigned int level;
			int XP;
			unsigned __int8 classType; // ClassType
			char specialization;
			// 2 bytes padding
			IntVector2 current_region;
			char charge;
			_BYTE gap149[27];
			FloatVector3 attack_rotation;
			float HP;
			float float_184;
			float MP;
			float stealth;
			float float_180;
			char field_184;
			//_BYTE gap185[7];
			int field_188;
			char interaction_state;
			//_BYTE gap18D[59];
			long long paired_entity_id;
			long long some_creature_id;
			IntVector2 some_zone_position; // Maybe last spawned zone position
			LongVector3 some_position;
			IntVector2 some_other_position; // Maybe region position??
			cube::Item last_special_item;
			cube::Equipment equipment;
			char name[16];
			long long steam_id;
			char cult_group;
			// 3 bytes padding (most likely)
			char field_961;
			char field_962;
			char field_963;
			int field_964;
			__int64 field_968;
        }; // end cube::Creature::EntityData

		class Buff { // start cube::Creature::Buff
		public:
			enum BuffType
			{
				AuraBulwark = 0x1,
				AuraWarFrenzy = 0x2,
				AuraCamouflage = 0x3,
				AuraPoisoned = 0x4,
				AuraManaShield = 0x6,
				AuraInstantFire = 0x9,
				AuraInstantShoot = 0xA,
				AuraDodge = 0xB,
				AuraSwiftness = 0xC,
				AuraNinjutsu = 0xD,
				AuraShadowClone = 0xF,
				AuraFlameRush = 0x10,
				AuraRegeneration = 0x11,
				AuraSpiritWorld = 0x13,
				AuraLifeFlask = 0x17,
				AuraArmorFlask = 0x18,
				AuraResistanceFlask = 0x19,
				AuraHeatResistance = 0x1A,
				AuraColdFlask = 0x1B,
				AuraPlagueResistance = 0x1C,
				AuraFrozen = 0x1D,
				AuraAncientPower = 0x21,
				AuraManaAbsorption = 0x22,
			};

		public:
			cube::Creature::Buff::BuffType type;
			float unk;
			float time_remaining;
			int32_t field_10;
			int32_t field_14;
			int32_t field_18;
		}; // end cube::Creature::Buff

		class AnimationState { // start cube::Creature::AnimationState
		public:
			cube::Creature* creature;
			int32_t current_animation_state_timer;
			int32_t current_animation_state_id;
			int32_t field_10;
			int32_t field_14;
			int64_t field_18;
			FloatVector3 left_hand_shifted_by;
			FloatVector3 right_hand_shifted_by;
			FloatVector3 left_hand_rot;
			FloatVector3 right_hand_rot;
			int64_t field_50;
			int64_t field_58;
			int64_t field_60;
			FloatVector3 body_rot;
			FloatVector3 entire_creature_rot;
			FloatVector3 body_shifted_by;
			FloatVector3 head_shifted_by;
			FloatVector3 head_rot;
			FloatVector3 something_that_rounds_to_360_multiples;
			float some_decreasing_timer_0;
			float some_hands_rot;
			float some_decreasing_timer_1;
			float some_body_with_feet_rot;
			FloatVector3 entire_creature_shifted_by;
			float some_feet_rot;
			int32_t field_D0;
			int32_t field_D4;
			int64_t face_sprite;
			int64_t hair_sprite;
			int64_t chest_sprite;
			int64_t unk_sprite;
			int64_t hands_sprite;
			int64_t wings_sprite;
			int64_t tail_sprite;
			int64_t feet_sprite;
			int64_t weapon_right_sprite;
			int64_t weapon_left_sprite;
			int64_t shoulder_sprite;
			int64_t neck_sprite;
			Matrix4 body_with_head_matrix;
			Matrix4 hands_matrix;
			Matrix4 body_matrix;
			Matrix4 head_matrix;
			Matrix4 hair_matrix;
			Matrix4 unk_matrix_278;
			Matrix4 unk_matrix_2B8;
			Matrix4 weapon_in_right_hand_matrix;
			Matrix4 weapon_in_left_hand_matrix;
			Matrix4 left_hand_matrix;
			Matrix4 right_hand_matrix;
			Matrix4 unk_matrix_3F8;
			Matrix4 unk_matrix_438;
			Matrix4 unk_matrix_478;
			Matrix4 unk_matrix_4B8;
			Matrix4 left_root_matrix;
			Matrix4 right_foot_matrix;
			Matrix4 field_578;
			Matrix4 field_5B8;
			Matrix4 field_5F8;
			Matrix4 field_638;
			Matrix4 field_678;
			Matrix4 field_6B8;
			Matrix4 field_6F8;
			Matrix4 field_738;
			Matrix4 field_778;
			Matrix4 field_7B8;
			Matrix4 field_7F8;
			Matrix4 field_838;
			Matrix4 field_878;
			int64_t field_8B8;
			int64_t field_8C0;
			uint8_t field_8C8;
			uint8_t field_8C9;
			uint8_t field_8CA;
			uint8_t field_8CB;
			int32_t field_8CC;
			int64_t field_8D0;
			int64_t field_8D8;
			int64_t field_8E0;
		}; // end cube::Creature::AnimationState


		// start cube::Creature
        public:
			void* vtable;
			__int64 id;
			cube::Creature::EntityData entity_data;
			std::list<cube::Creature::Buff> buffs;
			void* field_990;
			float float_998;
			float float_99C;
			float stamina;
			float field_9A4;
			float field_9A8;
			_BYTE gap9AC[12];
			std::list<void*> list_9B8;
			std::list<void*> list_9C8;
			long long pet_id;
			void* field_9E0;
			int field_9E8;
			_BYTE gap9E0[4]; // Padding probably
			std::vector<std::vector<cube::ItemStack>> inventory_tabs;
			int field_A08;
			cube::Item unk_item;
			int gold;
			_BYTE gapAB0[8];
			std::list<cube::Interaction> interactions;
			std::map<void*, void*> map_AC8;
			__int64 field_AD8;
			_BYTE gapAE0[40];
			__int64 field_B08;
			__int64 field_B10;
			__int64 field_B18;
			__int64 field_B20;
			_BYTE gapB28[12];
			int field_B34;
			int field_B38;
			float float_B3C;
			_BYTE gapB40[12];
			int field_B4C;
			int field_B50;
			int field_B54;
			int field_B58;
			int climbing_speed;
			int swimming_speed;
			int diving_skill;
			int riding_speed;
			int hang_gliding_speed;
			int sailing_speed;
			int lamp_diameter;
			std::list<void*> list_B78;
			std::list<void*> list_B88;
			std::list<void*> list_B98;
			int int_BA8;
			bool bool_BAC;
			// 3 bytes padding
			__int64 field_BB0;
			bool bool_BB8;
			// 3 bytes padding
			int field_BBC;
			int field_BC0;
			int field_BC4;
			int field_BC8;
			int field_BCC;
			__int64 field_BD0;
			__int64 field_BD8;
			__int64 field_BE0;
			int int_BE8;
			// 4 bytes padding
			__int64 field_BF0;
			__int64 field_BF8;
			__int64 field_C00;
			std::list<void*> list_C08;
			__int64 field_C18;
			__int64 field_C20;
			__int64 field_C28;
			__int64 field_C30;
			cube::Creature::AnimationState animation_state;
			__int64 field_1520;
			__int64 field_1528;
			float float_1530;
			_BYTE gap1534[12];
			bool bool_1540;
			// 3 bytes padding
			cube::Item some_item;
			std::list<void*> list_15E8;


            static cube::Creature* Create(__int64 id);
            cube::Creature* ctor(__int64* id);
			float GetArmor();
			float GetCritical(cube::Creature* other_creature = nullptr, bool other_creature_based_on_resistance = true);
			float GetAttackPower(bool unk_bool = true);
			float GetSpellPower(bool unk_bool = true);
			float GetHaste();
			float GetMaxHP();
			float GetResistance();
			float GetRegeneration();
			float GetManaGeneration();

			float GetDamage();
			int GetCastingDelay(int ability_id = -1);
			int GetCastingDuration(int ability_id = -1);

			int GetTotalXPEarned();
			int GetXPForLevelup();

			bool CanDoDamage(cube::Creature* other);
			bool CanTakeDamage();

			bool IsBlocking();

			void UpdateLevelAndSkills();

			void DropItem(cube::Item* item);

			void ClearInventoryGear();
    };
}

static_assert(sizeof(cube::Creature) == 0x15F8, "cube::Creature is not the correct size.");

#endif // CREATURE_H
