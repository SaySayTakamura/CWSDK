#pragma once

#include <cwsdk.h>

namespace modhelper
{
	namespace Daytime
	{
		//Confirmed that Cube World indeed uses the 24-Hour-Format
		typedef enum Daytimes
		{
			EarlyMorning = 0, // 03::00 AM
			Morning, // 06::00 AM
			LateMorning, // 09::00 AM
			Noon, // 12::00 PM
			Afternoon, // 15::00 PM
			Night, // 18::00 PM
			Midnight, // 00::00 AM
		};

		class DaytimeManager
		{
			
			//Variables//

		private:
			//Game Instance used to call the functions that modify the daytime
			cube::Game* dtm_Game;

			//The current daytime to set;
			Daytimes dtm_current; 


			//Methods//
		public:
			//This function works wraps mostly of the base SetTime() functions of Cube::World
			void SetDayTime(Daytimes dtm);

			//Get the last Daytime in enum value
			Daytimes GetLastDayTime();

			//This converts hours into Daytimes enum;
			Daytimes GetHourToDayTime();

			//Gets the last Daytime and translate it into a string.
			std::string GetLastDayTimeString();

			void SetGame(cube::Game* gm);


		};
	}
}