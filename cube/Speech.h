#ifndef SPEECH_H
#define SPEECH_H
#include "../IDA/types.h"
#include <map>
#include <string>

#include "SpeechText.h"

namespace cube {

class Item;
class Speech {
    public:
        virtual ~Speech();

        std::map<int32_t, std::wstring> entity_type_id_map;
        std::map<int32_t, std::wstring> skill_type_id_map;
        std::map<std::pair<uint32_t, uint32_t>, std::wstring> specialization_type_id_map;
        std::map<uint32_t, std::wstring> faction_type_id_map;
        std::map<uint32_t, std::wstring> ruler_type_id_map;
        std::map<std::pair<uint32_t, uint32_t>, std::wstring> item_identifier_map;
        std::map<void*, void*> unk_map_1;
        std::map<void*, void*> unk_map_2;
        std::map<void*, void*> unk_map_3;
        std::map<std::wstring, cube::SpeechText*> speech_node_map;
        std::map<std::wstring, cube::SpeechText*> macro_node_map;
        std::map<void*, void*> unk_map_4;

        std::wstring* GenerateItemName(std::wstring* string, cube::Item* item);
        std::wstring* GetRaceName(std::wstring* str, int race);
        std::wstring* GetBiomeName(std::wstring* str, int biome_type);
    };
}

static_assert(sizeof(cube::Speech) == 0xC8, "cube::Speech is not the correct size.");

#endif // SPEECH_H
