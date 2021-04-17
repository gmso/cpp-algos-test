#include <thread>

#include "doctest.h"

#include "binary_search.cpp"

TEST_SUITE("binary_search")
{
	SCENARIO("running tests returns results")
	{
		GIVEN("no preconditions")
		{
			WHEN("algoritm tests are run")
			{
				const auto test_results = binary_search::run();

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
		GIVEN("an ordered array of size 100, a random searched element between 0 and 99")
		{
			const auto data_array = utils::generate::ordered_array(100);
			const auto num_searched = utils::generate::random(99);

			WHEN("custom sequential search is executed")
			{
				const auto algo_result =
					binary_search::custom_sequential_search(data_array, num_searched);

				THEN("the algo results are valid")
				{
					CHECK(algo_result.is_search_algo == true);
					CHECK(algo_result.item_found == true);
					CHECK(algo_result.item_to_be_found == num_searched);
					//iterations == num_searched because searched started at 0
					CHECK(algo_result.iterations == num_searched + 1);
				}
			}

			WHEN("std::find sequential search is executed")
			{
				const auto algo_result =
					binary_search::std_find(data_array, num_searched);

				THEN("the algo results are valid")
				{
					CHECK(algo_result.is_search_algo == true);
					CHECK(algo_result.item_found == true);
					CHECK(algo_result.item_to_be_found == num_searched);
					//iterations == num_searched because searched started at 0
					CHECK(algo_result.iterations == num_searched + 1);
				}
			}

			WHEN("custom binary search is executed")
			{
				const auto algo_result =
					binary_search::custom_binary_search(data_array, num_searched);

				THEN("the algo results are valid")
				{
					CHECK(algo_result.is_search_algo == true);
					CHECK(algo_result.item_found == true);
					CHECK(algo_result.item_to_be_found == num_searched);
					//iterations <= log2(n) + 1, binary search's maximum
					CHECK(algo_result.iterations <= (log2(data_array.size()) + 1));
				}
			}

			WHEN("std::binary_search is executed")
			{
				const auto algo_result =
					binary_search::std_binary_search(data_array, num_searched);

				THEN("the algo results are valid")
				{
					CHECK(algo_result.is_search_algo == true);
					CHECK(algo_result.item_found == true);
					CHECK(algo_result.item_to_be_found == num_searched);
					//iterations <= log2(n) + 1, binary search's maximum
					CHECK(algo_result.iterations <= (log2(data_array.size()) + 1));
				}
			}
		}
	}
}