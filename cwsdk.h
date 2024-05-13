#ifndef CWMODS_H
#define CWMODS_H

//#define MODLOADER 1
#define EXPORT extern "C" __declspec(dllexport) __declspec(noinline)

//Default C++ Headers
#include <cstdint>
#include <dinput.h>
#include <d3d11.h>
#include <string>
#include <map>
#include <vector>

//IDA Software Types
#include "IDA/types.h"

//Cube Header File
#include "cube/cube.h"

//Common Header Files
#include "common/BytesIO.h"
#include "common/ColorRGB.h"
#include "common/math.h"
#include "common/Matrix4.h"
#include "common/RGBA.h"
#include "common/types.h"
#include "common/Vector2.h"
#include "common/Vector3.h"

//Cube World Header Files, associated with lots of things from Blocks to the Worl Map
#include "cube/AdaptionWidget.h"
#include "cube/AI.h"
#include "cube/BaseWidget.h"
#include "cube/Block.h"
#include "cube/BlockProperties.h"
#include "cube/CharacterPreviewWidget.h"
#include "cube/CharacterStyleWidget.h"
#include "cube/CharacterWidget.h"
#include "cube/ChatWidget.h"
#include "cube/Client.h"
#include "cube/Connection.h"
#include "cube/Controls.h"
#include "cube/ControlsWidget.h"
#include "cube/Creature.h"
#include "cube/Database.h"
#include "cube/Field.h"
#include "cube/FormulaDetailsWidget.h"
#include "cube/EnchantWidget.h"
#include "cube/Equipment.h"
#include "cube/Game.h"
#include "cube/GUI.h"
#include "cube/HelpWidget.h"
#include "cube/Host.h"
#include "cube/Interaction.h"
#include "cube/InventoryWidget.h"
#include "cube/Item.h"
#include "cube/ItemStack.h"
#include "cube/MapOverlayWidget.h"
#include "cube/MultiplayerWidget.h"
#include "cube/Music.h"
#include "cube/Options.h"
#include "cube/OptionsWidget.h"
#include "cube/PreviewWidget.h"
#include "cube/Projectile.h"
#include "cube/QuestionWidget.h"
#include "cube/ResolutionInfo.h"
#include "cube/SaveData.h"
#include "cube/ServerUpdates.h"
#include "cube/SpawnPoint.h"
#include "cube/SpawnPointFactory.h"
#include "cube/Speech.h"
#include "cube/SpeechText.h"
#include "cube/SpeechTextNode.h"
#include "cube/SpeechWidget.h"
#include "cube/Sprite.h"
#include "cube/SpriteManager.h"
#include "cube/SpriteWidget.h"
#include "cube/StartMenuWidget.h"
#include "cube/SystemWidget.h"
#include "cube/TextFX.h"
#include "cube/VoxelWidget.h"
#include "cube/World.h"
#include "cube/WorldMap.h"
#include "cube/XAudio2Engine.h"
#include "cube/Zone.h"
#include "cube/constants.h"

//Graphical Related Headers
#include "gfx/Chunk.h"
#include "gfx/ChunkBuffer.h"
#include "gfx/D3D11Graphics.h"
#include "gfx/D3D11Renderer.h"
#include "gfx/D3D11IndexBuffer.h"
#include "gfx/D3D11VertexBuffer.h"
#include "gfx/Graphics.h"
#include "gfx/IndexBuffer.h"
#include "gfx/Renderer.h"
#include "gfx/VertexBuffer.h"

//Note: Will attempt on making a MSVC port of the CWSDK and Mods
//Using CMAKE sucks TwT
#include "msvc/_Thrd_t.h"

//Plasma Engine Headers
#include "plasma/Attribute.h"
#include "plasma/ContinuousAttribute.h"
#include "plasma/D3D11Engine.h"
#include "plasma/DiscreteAttribute.h"
#include "plasma/Display.h"
#include "plasma/Engine.h"
#include "plasma/FontEngine.h"
#include "plasma/Keyable.h"
#include "plasma/NamedObject.h"
#include "plasma/Matrix.h"
#include "plasma/Map.h"
#include "plasma/Node.h"
#include "plasma/Object.h"
#include "plasma/ObjectManager.h"
#include "plasma/ScalableFont.h"
#include "plasma/Transformation.h"
#include "plasma/Vector.h"
#include "plasma/Widget.h"
#include "plasma/Shape.h"
#include "plasma/TextShape.h"

//Mod Helper Headers
#include "modhelper/Daytime/Daytime.h"
#include "modhelper/Utils/Utils.h"
#include "modhelper/Items/ModItem.h"
#include "modhelper/Items/ItemBuilder.h"
#include "modhelper/ModMetadata/ModMetadata.h"
#include "modhelper/SpriteLoader/SpriteLoader.h"



//Steam Headers
#include "steam/steam_api_common.h"

void* CWBase();
void* CWOffset(size_t offset);

EXPORT void ModPreInitialize();
EXPORT int ModMajorVersion();
EXPORT int ModMinorVersion();

void WriteByte(void* location, char val);

#ifndef MODLOADER
void WriteFarJMP(void* source, void* destination);

__declspec(noinline) void* operator new(size_t size);
__declspec(noinline) void* operator new[](size_t size);
__declspec(noinline) void operator delete(void* ptr) noexcept;
__declspec(noinline) void operator delete[](void* ptr) noexcept;
#endif

class GenericMod {
    public:
        enum Priority : u8 {
            VeryHighPriority = 0,
            HighPriority = 1,
            NormalPriority = 2,
            LowPriority = 3,
            VeryLowPriority = 4
        };

        modhelper::ModMetadata mod_metadata;

        // Used for registering to mod callbacks. The callbacks are defined in the CWSDK.
        virtual void Initialize() {}

        Priority OnChatPriority = NormalPriority;
        virtual int OnChat(std::wstring* message) { return 0; }

        Priority OnCheckInventoryFullPriority = NormalPriority;
        virtual int OnCheckInventoryFull(cube::Creature* player, cube::Item* item) { return 0; }

        Priority OnP2PRequestPriority = NormalPriority;
        virtual int OnP2PRequest(uint64_t steamID) { return 0; }

        Priority OnGameTickPriority = NormalPriority;
        virtual void OnGameTick(cube::Game* game) {}

        Priority OnZoneGeneratedPriority = NormalPriority;
        virtual void OnZoneGenerated(cube::Zone* zone) {}

        Priority OnZoneDestroyPriority = NormalPriority;
        virtual void OnZoneDestroy(cube::Zone* zone) {}

        Priority OnWindowProcPriority = NormalPriority;
        virtual int OnWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) { return 0; }

        Priority OnGetKeyboardStatePriority = NormalPriority;
        virtual void OnGetKeyboardState(BYTE* diKeys) {}

        Priority OnGetMouseStatePriority = NormalPriority;
        virtual void OnGetMouseState(DIMOUSESTATE* diMouse) {}

        Priority OnPresentPriority = NormalPriority;
        virtual void OnPresent(IDXGISwapChain* SwapChain, UINT SyncInterval, UINT Flags) {}

        Priority OnCreatureArmorCalculatedPriority = NormalPriority;
        virtual void OnCreatureArmorCalculated(cube::Creature* creature, float* armor) {}

        Priority OnCreatureCriticalCalculatedPriority = NormalPriority;
        virtual void OnCreatureCriticalCalculated(cube::Creature* creature, float* critical) {}

        Priority OnCreatureAttackPowerCalculatedPriority = NormalPriority;
        virtual void OnCreatureAttackPowerCalculated(cube::Creature* creature, float* power) {}

        Priority OnCreatureSpellPowerCalculatedPriority = NormalPriority;
        virtual void OnCreatureSpellPowerCalculated(cube::Creature* creature, float* power) {}

        Priority OnCreatureHasteCalculatedPriority = NormalPriority;
        virtual void OnCreatureHasteCalculated(cube::Creature* creature, float* haste) {}

        Priority OnCreatureHPCalculatedPriority = NormalPriority;
        virtual void OnCreatureHPCalculated(cube::Creature* creature, float* hp) {}

        Priority OnCreatureResistanceCalculatedPriority = NormalPriority;
        virtual void OnCreatureResistanceCalculated(cube::Creature* creature, float* resistance) {}

        Priority OnCreatureRegenerationCalculatedPriority = NormalPriority;
        virtual void OnCreatureRegenerationCalculated(cube::Creature* creature, float* regeneration) {}

        Priority OnCreatureManaGenerationCalculatedPriority = NormalPriority;
        virtual void OnCreatureManaGenerationCalculated(cube::Creature* creature, float* manaGeneration) {}

        Priority OnChunkRemeshPriority = NormalPriority;
        virtual void OnChunkRemesh(cube::Zone* zone) {}

        Priority OnChunkRemeshedPriority = NormalPriority;
        virtual void OnChunkRemeshed(cube::Zone* zone) {}

        enum DeathType : __int32 {
            COMBAT = 0,
            DROWN,
            FALL
        };

        Priority OnPlayerDeathPriority = NormalPriority;
        virtual void OnPlayerDeath(cube::Game* game, cube::Creature* player, DeathType type) {}

        Priority OnCreatureDeathPriority = NormalPriority;
        virtual void OnCreatureDeath(cube::Game* game, cube::Creature* creature, cube::Creature* attacker) {}

        Priority OnGameUpdatePriority = NormalPriority;
        virtual void OnGameUpdate(cube::Game* game) {}

        Priority OnGetItemBuyingPricePriority = NormalPriority;
        virtual void OnGetItemBuyingPrice(cube::Item* item, int* price) {}

        Priority OnGetItemSellingPricePriority = NormalPriority;
        virtual void OnGetItemSellingPrice(cube::Item* item, int* price) {}

        Priority OnCreatureCanEquipItemPriority = NormalPriority;
        virtual void OnCreatureCanEquipItem(cube::Creature* creature, cube::Item* item, bool* equipable) {}

        Priority OnItemGetGoldBagValuePriority = NormalPriority;
        virtual void OnItemGetGoldBagValue(cube::Item* item, int* gold) {}

        Priority OnClassCanWearItemPriority = NormalPriority;
        virtual void OnClassCanWearItem(cube::Item* item, int classType, bool* wearable) {}
        
        //Priority OnGetItemRarityModifierPriority = NormalPriority;
        //virtual void OnGetItemRarityModifier(cube::Item* item, cube::Creature* creature, int spirits, float* modifier) {}

        #include "VtablePadding.h"
};

#endif // CWMODS_H
