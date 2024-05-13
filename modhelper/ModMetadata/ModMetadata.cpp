#include "ModMetadata.h"

modhelper::ModMetadata::ModMetadata()
{
	mmd_ModName = "UNDEFINED";
	mmd_ModDescription = "UNDEFINED";
}
modhelper::ModMetadata::ModMetadata(std::string Name)
{
	mmd_ModName = Name; mmd_ModDescription = "UNDEFINED";
}
modhelper::ModMetadata::ModMetadata(std::string Name, std::string Description)
{ 
	mmd_ModName = Name; 
	mmd_ModDescription = Description; 
}
const char* modhelper::ModMetadata::GetName()
{
	return mmd_ModName.c_str();
}
const char* modhelper::ModMetadata::GetDescription()
{
	return mmd_ModDescription.c_str();
}
std::wstring modhelper::ModMetadata::GetNameLitheral()
{
	return std::wstring((wchar_t*)mmd_ModName.c_str());
}
std::wstring modhelper::ModMetadata::GetDescriptionLitheral()
{
	return std::wstring((wchar_t*)mmd_ModDescription.c_str());
}

void modhelper::ModMetadata::SetName(std::string Name)
{
	mmd_ModName = Name;
}
void modhelper::ModMetadata::SetDescription(std::string Description)
{
	mmd_ModDescription = Description;
}
