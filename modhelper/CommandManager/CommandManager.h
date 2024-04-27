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
		};

		class CommandsManager
		{
		private:

			//Defines the name of the mod and the suffix for the calls in the chat like: /{modname} help
			std::string ModName;

			//The container for all the commands
			std::vector<fnc> command_vector;

		public:
			//Sets a default Manager and sets the mod name to 'Undefined', you can leave as it is while you develop your mod
			CommandsManager() : ModName("Undefined") {};

			#pragma region Setters

				//Adds the function into the array
				void add(fnc command)
				{
					fnc c = command;
					command_vector.push_back(c);
				}
				void set_mod_name(std::string name);

			#pragma endregion

			#pragma region Getters

				void call(std::string name); //Calls the function according its name.
				void call(int index); //Call the function according its index in the array.

				std::string get_mod_name();

			#pragma endregion

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