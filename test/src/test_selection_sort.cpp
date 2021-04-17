#include "doctest.h"

#include "selection_sort.cpp"

TEST_SUITE("selection sort")
{
	SCENARIO("running tests returns results")
	{
		GIVEN("no preconditions")
		{
			WHEN("algoritm tests are run")
			{
				const auto test_results = selection_sort::run();

				THEN("the returned results are valid")
				{
					CHECK(test_results.size() > 0);
					CHECK(test_results.at(0) != "");
				}
			}
		}
	}

	SCENARIO("algorithms perform expected function")
	{
		GIVEN("an unordered array of size 100")
		{
			auto u_arr = utils::generate::unordered_array(100);

			WHEN("custom sequential search is executed")
			{
				const auto algo_result = selection_sort::custom_selection_sort(u_arr);

				THEN("the algo results are valid")
				{
					CHECK(algo_result.is_search_algo == false);
					//iterations <= iterations^2, due to O(n^2) complexity
					CHECK(algo_result.iterations <=
						(algo_result.iterations * algo_result.iterations));
				}
			}
		}
	}
}