#include "Speech.h"
#include "Speech.h"

#include "cwsdk.h"

std::wstring* cube::Speech::GenerateItemName(std::wstring* string, cube::Item* item)
{
    return ((std::wstring * (*)(cube::Speech*, std::wstring*, cube::Item*))CWOffset(0x1628B0))(this, string, item);
}

std::wstring* cube::Speech::GetRaceName(std::wstring* str, int race)
{
    return ((std::wstring * (*)(cube::Speech*, std::wstring*, int))CWOffset(0x164760))(this, str, race);
}

std::wstring* cube::Speech::GetBiomeName(std::wstring* str, int biome_type)
{
    return ((std::wstring* (*)(cube::Speech*, std::wstring*, int))CWOffset(0x16B210))(this, str, biome_type);
}
