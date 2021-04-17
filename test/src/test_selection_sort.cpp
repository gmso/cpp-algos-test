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

	SCENARIO("algorithm (new array) performs expected function")
	{
		GIVEN("an unordered array of size 100")
		{
			auto u_arr = utils::generate::unordered_array(100);

			WHEN("custom sequential search, creating new container, is executed")
			{
				const auto algo_result =
					selection_sort::custom_sort_creating_new_container(u_arr);

				THEN("the algo results are valid")
				{
					CHECK(algo_result.is_search_algo == false);

					//iterations <= iterations^2, due to O(n^2) complexity
					CHECK(algo_result.iterations <=
						(algo_result.iterations * algo_result.iterations));

					//input container should be empty, as values were transferred
					//to a new container
					CHECK(u_arr.size() == 0);
				}
			}
		}
	}

	SCENARIO("algorithm (sorting same array) performs expected function")
	{
		GIVEN("an unordered array of size 100")
		{
			auto u_arr = utils::generate::unordered_array(100);

			WHEN("custom sequential search, swapping values, is executed")
			{
				const auto algo_result =
					selection_sort::custom_sort_creating_swapping_values(u_arr);

				THEN("the algo results are valid")
				{
					CHECK(algo_result.is_search_algo == false);

					//iterations <= iterations^2, due to O(n^2) complexity
					CHECK(algo_result.iterations <=
						(algo_result.iterations * algo_result.iterations));

					//input container should now be sorted, as values were swapped in-place
					const auto arr_is_sorted = std::is_sorted(u_arr.begin(), u_arr.end());
					CHECK(arr_is_sorted == true);
				}
			}
		}
	}

	SCENARIO("algorithm (new linked list) performs expected function")
	{
		GIVEN("an unordered linked list of size 100")
		{
			auto linked_list = utils::generate::unordered_linked_list(100);

			WHEN("custom sequential search, creating new container, is executed")
			{
				const auto algo_result =
					selection_sort::custom_sort_creating_new_container(linked_list);

				THEN("the algo results are valid")
				{
					CHECK(algo_result.is_search_algo == false);

					//iterations <= iterations^2, due to O(n^2) complexity
					CHECK(algo_result.iterations <=
						(algo_result.iterations * algo_result.iterations));

					//input container should be empty, as values were transferred
					//to a new container
					CHECK(linked_list.size() == 0);
				}
			}
		}
	}

	SCENARIO("algorithm (sorting same linked list) performs expected function")
	{
		GIVEN("an unordered array of size 100")
		{
			auto linked_list = utils::generate::unordered_linked_list(100);

			WHEN("custom sequential search, swapping values, is executed")
			{
				const auto algo_result =
					selection_sort::custom_sort_creating_swapping_values(linked_list);

				THEN("the algo results are valid")
				{
					CHECK(algo_result.is_search_algo == false);

					//iterations <= iterations^2, due to O(n^2) complexity
					CHECK(algo_result.iterations <=
						(algo_result.iterations * algo_result.iterations));

					//input container should now be sorted, as values were swapped in-place
					const auto ll_is_sorted = std::is_sorted(linked_list.begin(), linked_list.end());
					CHECK(ll_is_sorted == true);
				}
			}
		}
	}
}