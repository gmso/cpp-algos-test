#include <thread>

#include "doctest.h"

#include "app.cpp"

TEST_SUITE("app")
{
	std::string ssystem(const char* command) {
		char tmpname[L_tmpnam];
		std::tmpnam(tmpname);
		//std::string scommand = command;
		//std::string cmd = scommand + " >> " + tmpname;
		//std::system(cmd.c_str());
		std::ifstream file(tmpname, std::ios::in | std::ios::binary);
		std::string result;
		if (file) {
			while (!file.eof()) result.push_back(file.get())
				;
			file.close();
		}
		remove(tmpname);
		return result;
	}

	SCENARIO("app execution returns help, when requested")
	{
		std::cout << "\n################### TEST START ###################";

		GIVEN("the command argument \"help\"")
		{
			const auto arg_count = 2;
			char* command_argument = "help";
			char* arg_values[] =
			{ "algo_test",command_argument };

			WHEN("application is executed with command")
			{
				auto returned_value =
					app::run(arg_count, arg_values);

				THEN("the returned value is valid")
				{
					CHECK(returned_value == 0);
					std::cout << "################### TEST END ###################\n";
				}
			}
		}
	}

	SCENARIO("app execution executes algorithm, when requested")
	{
		std::cout << "\n################### TEST START ###################";

		GIVEN("the command argument \"0\"")
		{
			const auto arg_count = 2;
			char* command_argument = "0";
			char* arg_values[] =
			{ "algo_test",command_argument };

			WHEN("application is executed with command")
			{
				auto returned_value =
					app::run(arg_count, arg_values);

				THEN("the returned value is valid")
				{
					CHECK(returned_value == 0);
					std::cout << "################### TEST END ###################\n";
				}
			}
		}
	}

	SCENARIO("app interrupted due to invalid arguments")
	{
		std::cout << "\n################### TEST START ###################";

		GIVEN("the command argument \"99\"")
		{
			const auto arg_count = 2;
			char* command_argument = "99";
			char* arg_values[] =
			{ "algo_test",command_argument };

			WHEN("application is executed with command")
			{
				auto returned_value =
					app::run(arg_count, arg_values);

				THEN("the returned value is invalid")
				{
					CHECK(returned_value == 1);
					std::cout << "################### TEST END ###################\n";
				}
			}
		}
	}

	SCENARIO("app interrupted due to invalid argument count")
	{
		std::cout << "\n################### TEST START ###################";

		GIVEN("the command arguments \"0 1\"")
		{
			const auto arg_count = 3;
			char* command_argument_1 = "0";
			char* command_argument_2 = "1";
			char* arg_values[] =
			{ "algo_test",command_argument_1, command_argument_2 };

			WHEN("application is executed with command")
			{
				auto returned_value =
					app::run(arg_count, arg_values);

				THEN("the returned value is invalid")
				{
					CHECK(returned_value == 1);
					std::cout << "################### TEST END ###################\n";
				}
			}
		}
	}
}