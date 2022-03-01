#include "Item.h"
#include "../cwsdk.h"

cube::Item::Item(){
	ctor();
}
cube::Item::Item(char category, int id) {
	ctor();
    this->category = category;
    this->id = id;
}

cube::Item* cube::Item::ctor()
{
	this->category = 0;
	this->id = 0;
	this->rarity = 0;
	this->modifier = 0;
	this->region = IntVector2(0, 0);
	this->material = 0;
	this->formula_category = 0;
	this->num_spirits = 0;

	for (int i = 0; i < 32; i++)
	{
		this->spirits[i] = { 0, 0, 0, 0 };
	}
	return this;
}

void cube::Item::Copy(cube::Item* src)
{
	((void(*)(cube::Item*, cube::Item*))CWOffset(0x9CD0))(this, src);
}

float cube::Item::GetArmor(cube::Creature* creature)
{
	return ((float (*)(cube::Item*, cube::Creature*))CWOffset(0x108D50))(this, creature);
}

float cube::Item::GetHP(cube::Creature * creature)
{
	return ((float (*)(cube::Item*, cube::Creature*))CWOffset(0x1097B0))(this, creature);
}

float cube::Item::GetRegeneration(cube::Creature* creature)
{
	return ((float (*)(cube::Item*, cube::Creature*))CWOffset(0x109F30))(this, creature);
}

float cube::Item::GetResistance(cube::Creature* creature)
{
	return ((float (*)(cube::Item*, cube::Creature*))CWOffset(0x10A1E0))(this, creature);
}

float cube::Item::GetHaste(cube::Creature* creature)
{
	return ((float (*)(cube::Item*, cube::Creature*))CWOffset(0x10A490))(this, creature);
}

float cube::Item::GetPower(cube::Creature* creature)
{
	return ((float (*)(cube::Item*, cube::Creature*))CWOffset(0x10AD90))(this, creature);
}

float cube::Item::GetCritical(cube::Creature* creature)
{
	return ((float (*)(cube::Item*, cube::Creature*))CWOffset(0x1090F0))(this, creature);
}

int cube::Item::GetArtifactType()
{
	return ((int (*)(cube::Item*))CWOffset(0x108EF0))(this);
}

int cube::Item::GetEffectiveRarity(IntVector2* region)
{
	return ((int (*)(cube::Item*, IntVector2*))CWOffset(0x109720))(this, region);
}

int cube::Item::GetBuyingPrice()
{
	return ((int (*)(cube::Item*))CWOffset(0x109D30))(this);
}

int cube::Item::GetSellingPrice()
{
	return ((int (*)(cube::Item*))CWOffset(0x10A390))(this);
}

bool cube::Item::ClassCanWearItem(int classType)
{
	return ((bool(*)(cube::Item*, int))CWOffset(0x1094D0))(this, classType);
}

float cube::Item::GetGearRarityModifier(cube::Creature* creature, signed int spirits)
{
	return ((float (*)(cube::Item*, cube::Creature*, signed int))CWOffset(0x109C50))(this, creature, spirits);
}

float cube::Item::GetPowerOfSpirits(cube::Creature* creature)
{
	//C++ implementation of 0x10AD50
	return this->GetPower(creature) - this->GetPowerWithoutSpirits(creature);
}

float cube::Item::GetPowerWithoutSpirits(cube::Creature* creature)
{
	return ((float (*)(cube::Item*, cube::Creature*))CWOffset(0x108F20))(this, creature);
}

bool cube::Item::IsValidEquipmentForCreature(cube::Creature* creature, int itemCategory)
{
	if (this->category != itemCategory)
	{
		return false;
	}

	if (creature->entity_data.hostility_type != 0 || this->ClassCanWearItem(creature->entity_data.classType))
	{
		return true;
	}

	return false;
}

bool cube::Item::IsPlusItem()
{
	if (this->rarity < 0)
	{
		return false;
	}

	return this->modifier % ((this->rarity + 1) * 10) == 0;
}

void cube::Item::ConvertToPlusItem()
{
	while (!this->IsPlusItem())
	{
		this->modifier++;
	}
}

void cube::Item::ConvertToNormalWeapon()
{
	if (this->IsPlusItem())
	{
		this->modifier--;
	}
}

void cube::Item::UpgradeItem()
{
	if (this->IsPlusItem())
	{
		this->rarity++;
		this->num_spirits = 0;
		this->ConvertToNormalWeapon();
	}
	else
	{
		this->num_spirits = 0;
		this->ConvertToPlusItem();
	}
}
