#pragma once
#include <vector>
#include <string>
#include <functional>



namespace modhelper
{
	namespace Commands
	{
		using Function = std::function<void()>;

		class fnc
		{
		private:
			std::string function_name;
			Function function;

		public:

			fnc(std::string name, Function fn);
			fnc(std::string name);


			template <typename ... args>
			void Assign(Function fn, args... as)
			{
				function = Function(std::bind(fn, std::forward<args>(as)...));
			}

			auto Call()
			{
				return function();
			}
			std::string GetName()
			{
				return function_name;
			}
		};

		class CommandsManager
		{
		private:
			//The container for all the commands
			std::vector<fnc> command_vector;

		public:
			//Sets a default/empty Manager.
			CommandsManager() {};


			//Adds the function into the array
			void add(fnc command);

			void call(std::string name); //Calls the function according its name.
			void call(int index); //Call the function according its index in the array.


			//Do not use, multiple commands will be used at once, this was for prototyping purposes.
			void GroupCall()
			{
				for (int i = 0; i < command_vector.size(); i++)
				{
					command_vector[i].Call();
				}
			}
		};
	}
}