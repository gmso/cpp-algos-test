#include "doctest.h"

#include "quicksort.cpp"

TEST_SUITE("quicksort")
{
	SCENARIO("running tests returns results")
	{
		GIVEN("no preconditions")
		{
			WHEN("algoritm tests are run")
			{
				const auto test_results = quicksort::run();

				THEN("the returned results are valid")
				{
					CHECK(test_results.size() > 0);
					CHECK(test_results.at(0) != "");
				}
			}
		}
	}

	SCENARIO("algorithm (sorting same array) performs expected function")
	{
		GIVEN("an unordered array of size 100")
		{
			auto u_arr = utils::generate::unordered_array(10);

			const auto is_not_sorted = std::is_sorted(u_arr.begin(), u_arr.end());
			CHECK(is_not_sorted == false);

			WHEN("custom sequential search, swapping values, is executed")
			{
				const auto iterations =
					quicksort::custom_quicksort(u_arr.begin(), u_arr.end());

				THEN("the algo results are valid")
				{
					//iterations <= n^2 (worst case is O(n^2)). Average is O(n * log(n)
					CHECK(iterations <= (u_arr.size() * u_arr.size()));

					//input container should now be sorted, as values were swapped in-place
					const auto is_sorted =
						std::is_sorted(u_arr.begin(), u_arr.end());
					CHECK(is_sorted == true);
				}
			}
		}
	}
}