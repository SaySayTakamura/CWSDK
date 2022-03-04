#include "Equipment.h"
#include "../cwsdk.h"

cube::Equipment* cube::Equipment::Copy(cube::Equipment* other)
{
	return ((cube::Equipment* (*)(cube::Equipment*, cube::Equipment*))CWOffset(0x3B6B0))(this, other);
}

void cube::Equipment::Clear()
{
	cube::Item empty(0, 0);
	this->unk_item = empty;
	this->neck = empty;
	this->chest = empty;
	this->feet = empty;
	this->hands = empty;
	this->shoulder = empty;
	this->weapon_left = empty;
	this->weapon_right = empty;
	this->ring_left = empty;
	this->ring_right = empty;
	this->pet = empty;
}