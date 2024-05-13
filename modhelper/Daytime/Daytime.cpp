#include "Daytime.h"

void modhelper::Daytime::DaytimeManager::SetDayTime(Daytimes dtm)
{
	dtm_current = dtm;
	switch (dtm_current)
	{
	case modhelper::Daytime::EarlyMorning:
		dtm_Game->host.world.SetTime(3, 00);
		break;
	case modhelper::Daytime::Morning:
		dtm_Game->host.world.SetTime(6, 00);
		break;
	case modhelper::Daytime::LateMorning:
		dtm_Game->host.world.SetTime(9, 00);
		break;
	case modhelper::Daytime::Noon:
		dtm_Game->host.world.SetTime(12, 00);
		break;
	case modhelper::Daytime::Afternoon:
		dtm_Game->host.world.SetTime(15, 00);
		break;
	case modhelper::Daytime::Night:
		dtm_Game->host.world.SetTime(18, 00);
		break;
	case modhelper::Daytime::Midnight:
		dtm_Game->host.world.SetTime(00, 00);
		break;
	default:
		dtm_Game->PrintMessage(L"This hour has not been set");
		break;
	}
	
}

modhelper::Daytime::Daytimes modhelper::Daytime::DaytimeManager::GetLastDayTime()
{
	return Daytimes();
}

modhelper::Daytime::Daytimes modhelper::Daytime::DaytimeManager::GetHourToDayTime()
{
	int hour = dtm_Game->host.world.GetTime() / 60 / 60 / 1000;
	int minute = dtm_Game->host.world.GetTime() / 60 / 1000;

	std::wstring houer;
	houer.append(L"Hour: ").append(std::to_wstring(hour));
	houer.append(L"|");
	houer.append(L"Minute: ").append(std::to_wstring(minute));

	dtm_Game->PrintMessage(houer.c_str());

	return Daytimes();
}

std::string modhelper::Daytime::DaytimeManager::GetLastDayTimeString()
{
	return std::string();
}

void modhelper::Daytime::DaytimeManager::SetGame(cube::Game* gm)
{
	dtm_Game = gm;
}
