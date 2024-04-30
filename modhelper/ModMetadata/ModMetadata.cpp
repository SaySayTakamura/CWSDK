#include "ModMetadata.h"

modhelper::ModMD::ModMetadata::ModMetadata()
{
	mmd_ModName = "UNDEFINED";
	mmd_ModDescription = "UNDEFINED";
}
modhelper::ModMD::ModMetadata::ModMetadata(std::string Name)
{
	mmd_ModName = Name; mmd_ModDescription = "UNDEFINED";
}
modhelper::ModMD::ModMetadata::ModMetadata(std::string Name, std::string Description)
{ 
	mmd_ModName = Name; 
	mmd_ModDescription = Description; 
}
const char* modhelper::ModMD::ModMetadata::GetName()
{
	return mmd_ModName.c_str();
}
const char* modhelper::ModMD::ModMetadata::GetDescription()
{
	return mmd_ModDescription.c_str();
}
std::wstring modhelper::ModMD::ModMetadata::GetNameLitheral()
{
	return std::wstring((wchar_t*)mmd_ModName.c_str());
}
std::wstring modhelper::ModMD::ModMetadata::GetDescriptionLitheral()
{
	return std::wstring((wchar_t*)mmd_ModDescription.c_str());
}

void modhelper::ModMD::ModMetadata::SetName(std::string Name)
{
	mmd_ModName = Name;
}
void modhelper::ModMD::ModMetadata::SetDescription(std::string Description)
{
	mmd_ModDescription = Description;
}
