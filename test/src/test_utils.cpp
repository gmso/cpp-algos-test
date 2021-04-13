#include "doctest.h"

#include "utils.h"

TEST_SUITE("utils")
{
	/*TEST_CASE("testing the factorial function")
	{
		CHECK(factorial(1) == 1);
		CHECK(factorial(2) == 2);
		CHECK(factorial(3) == 6);
		CHECK(factorial(10) == 3628800);
	}*/

	SCENARIO("algo results structs are available")
	{
		GIVEN("An algo result for print is created")
		{
			utils::types::Algo_result_for_print algo;

			REQUIRE(algo.algo_name == "");
			REQUIRE(algo.data_structure == "");
			REQUIRE(algo.data_is_ordered == false);
			REQUIRE(algo.size_data_structure == 0);
			REQUIRE(algo.max_iterations == 0);
			REQUIRE(algo.results_with_time.time_run == "0");
			REQUIRE(algo.results_with_time.result.iterations == 0);
			REQUIRE(algo.results_with_time.result.is_search_algo == false);
			REQUIRE(algo.results_with_time.result.item_to_be_found == 0);
			REQUIRE(algo.results_with_time.result.item_found == false);

			WHEN("algo name, max iterations and type change")
			{
				algo.algo_name = "new name";
				algo.max_iterations = 100;
				algo.results_with_time.result.is_search_algo = true;

				THEN("the corresponding data changes")
				{
					REQUIRE(algo.algo_name == "new name");
					REQUIRE(algo.max_iterations == 100);
					REQUIRE(algo.results_with_time.result.is_search_algo == true);
				}
			}
			/*WHEN( "the size is reduced" ) {
				v.resize( 0 );

				THEN( "the size changes but not capacity" ) {
					REQUIRE( v.size() == 0 );
					REQUIRE( v.capacity() >= 5 );
				}*/
		}
	}
}