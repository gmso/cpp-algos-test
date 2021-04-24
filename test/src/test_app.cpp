#include <thread>

#include "doctest.h"

//namespace app_main
//{
//#include "main.cpp"
//}

TEST_SUITE("app")
{
	SCENARIO("program execution returns help, when requested")
	{
		GIVEN("the command argument \"help\"")
		{
			auto command_argument = "help";

			WHEN("application is executed with command")
			{
				//app_main::main
				THEN("the corresponding data changes")
				{
					//CHECK(algo.algo_name == "new name");
					//CHECK(algo.max_iterations == 100);
					//CHECK(algo.results_with_time.result.is_search_algo == true);
				}
			}
		}
	}
}