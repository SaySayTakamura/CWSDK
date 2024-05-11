#pragma once
#include <string>

namespace modhelper
{
	class ModMetadata
	{
	private:
		std::string mmd_ModName;
		std::string mmd_ModDescription;
	public:

		ModMetadata();
		ModMetadata(std::string Name);
		ModMetadata(std::string Name, std::string Description);

		const char* GetName();
		const char* GetDescription();

		std::wstring GetNameLitheral();
		std::wstring GetDescriptionLitheral();

		void SetName(std::string Name);
		void SetDescription(std::string Description);
	};
};