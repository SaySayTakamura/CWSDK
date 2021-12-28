#include "World.h"
#include "World.h"
#include "Zone.h"
#include "constants.h"
#include "../common/Vector3.h"
#include "../cwsdk.h"

cube::Zone* cube::World::GetZone(IntVector2 position) {
    try {
        return this->zones.at(position);
    }
    catch (const std::out_of_range & oor) {
        return nullptr;
    }
    
}
cube::Zone* cube::World::GetZone(int x, int y) {
    IntVector2 position(x, y);
    return this->GetZone(position);
}

cube::Zone* cube::World::GetCurrentZone()
{
    LongVector3 playerPosition = cube::GetGame()->GetPlayer()->entity_data.position;
    LongVector3 blockPosition;
    blockPosition.x = pydiv(playerPosition.x, cube::DOTS_PER_BLOCK);
    blockPosition.y = pydiv(playerPosition.y, cube::DOTS_PER_BLOCK);
    blockPosition.z = pydiv(playerPosition.z, cube::DOTS_PER_BLOCK);
    IntVector2 zonePos = cube::Zone::ZoneCoordsFromBlocks(blockPosition.x, blockPosition.y);
    cube::Zone* zone = this->GetZone(zonePos);
    return zone;
}

IntVector2* cube::World::GetRegion(IntVector2* region, int x, int y)
{
    ((IntVector2 * (*)(cube::World*, IntVector2*, int, int))CWOffset(0x2ADA20))(this, region, x, y);
}

void cube::World::SetBlock(LongVector3 block_pos, Block block, bool update) {
    IntVector2 zonePos = cube::Zone::ZoneCoordsFromBlocks(block_pos.x, block_pos.y);
    cube::Zone* zone = this->GetZone(zonePos);
    if (!zone) return;
    IntVector3 zoneBlockPos(pymod(block_pos.x, cube::BLOCKS_PER_ZONE), pymod(block_pos.y, cube::BLOCKS_PER_ZONE), block_pos.z);
    zone->SetBlock(zoneBlockPos, block, update);

    LongVector3 blockInZonePos = LongVector3(pymod(block_pos.x, cube::BLOCKS_PER_ZONE), pymod(block_pos.y, cube::BLOCKS_PER_ZONE), block_pos.z);

    if (update) {
        //Update adjacent chunks if needed
        if (blockInZonePos.x == 0) {
            zone = this->GetZone(IntVector2(zonePos.x - 1, zonePos.y));
            if (zone) zone->chunk.Remesh();
        } else if (blockInZonePos.x == cube::BLOCKS_PER_ZONE - 1) {
            zone = this->GetZone(IntVector2(zonePos.x + 1, zonePos.y));
            if (zone) zone->chunk.Remesh();
        }


        if (blockInZonePos.y == 0) {
            zone = this->GetZone(IntVector2(zonePos.x, zonePos.y - 1));
            if (zone) zone->chunk.Remesh();
        }
        else if (blockInZonePos.y == cube::BLOCKS_PER_ZONE - 1) {
            zone = this->GetZone(IntVector2(zonePos.x, zonePos.y + 1));
            if (zone) zone->chunk.Remesh();
        }
    }


    
}
cube::Block* cube::World::GetBlock(LongVector3 block_pos) {
    IntVector2 zonePos = cube::Zone::ZoneCoordsFromBlocks(block_pos.x, block_pos.y);
    cube::Zone* zone = this->GetZone(zonePos);
    if (!zone) return nullptr;
    IntVector3 zoneBlockPos(pymod(block_pos.x, cube::BLOCKS_PER_ZONE), pymod(block_pos.y, cube::BLOCKS_PER_ZONE), block_pos.z);

    return zone->GetBlock(zoneBlockPos);
}

cube::Block cube::World::GetBlockInterpolated(LongVector3 block_pos) {
    IntVector2 zonePos = cube::Zone::ZoneCoordsFromBlocks(block_pos.x, block_pos.y);
    cube::Zone* zone = this->GetZone(zonePos);

    if (!zone) {
        cube::Block block;
        block.red = 255;
        block.green = 255;
        block.blue = 255;
        block.field_3 = 0;
        block.type = cube::Block::Air;
        block.breakable = 0;
        return block;
    }
    IntVector3 zoneBlockPos(pymod(block_pos.x, cube::BLOCKS_PER_ZONE), pymod(block_pos.y, cube::BLOCKS_PER_ZONE), block_pos.z);

    return zone->GetBlockInterpolated(zoneBlockPos);
}

cube::Block* cube::World::GetBlock(uint64_t block_x, uint64_t block_y, uint64_t block_z) {
    LongVector3 position(block_x, block_y, block_z);
    return this->GetBlock(position);
}

cube::Block cube::World::GetBlockInterpolated(uint64_t block_x, uint64_t block_y, uint64_t block_z) {
    LongVector3 position(block_x, block_y, block_z);
    return this->GetBlockInterpolated(position);
}

void cube::World::LockZones() {
    EnterCriticalSection(&this->zones_critical_section);
}
void cube::World::UnlockZones() {
    LeaveCriticalSection(&this->zones_critical_section);
}

void cube::World::SetTime(float ms) {
    this->state.time = ms;
}
void cube::World::SetTime(int ms) {
    this->state.time = (float)ms;
}
void cube::World::SetTime(int hour, int minute) {
    this->state.time = (float)((hour * 60 * 60 * 1000) + (minute * 60 * 1000));
}
float cube::World::GetTime() {
    return this->state.time;
}

void cube::World::CW_2E0B50()
{
    ((void(*)(cube::World*))CWOffset(0x2E0B50))(this);
}

// Generates a creature appearance based on race field
void cube::World::GenerateCreatureAppearance(cube::Creature* creature, int value)
{
    ((void (*)(cube::World*, int, cube::Creature*))CWOffset(0x2B67B0))(&cube::GetGame()->host.world, 0, creature);
}

cube::Creature* cube::World::GetCreatureByID(__int64 id)
{
    return ((cube::Creature* (*)(cube::World*, __int64))CWOffset(0xE720))(this, id);
}

void* cube::World::AddCreature(cube::Creature* creature)
{
    return ((void* (*)(cube::World*, cube::Creature*))CWOffset(0x29D0D0))(this, creature);
}

bool cube::World::IsValidBuildingType(unsigned int buildingType)
{
    return ((bool (*)(unsigned int))CWOffset(0x25EB30))(buildingType);
}

void cube::World::DropLoot(cube::Creature* target)
{
    ((void (*)(cube::World*, cube::Creature*))CWOffset(0x2A6860))(this, target);
}

void cube::World::DropItem(cube::Item* item, LongVector3* position)
{
    ((void (*)(cube::World*, cube::Item*, LongVector3*))CWOffset(0x2A5B70))(this, item, position);
}
