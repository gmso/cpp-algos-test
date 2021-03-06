#include <thread>

#include "doctest.h"

#include "utils.cpp"

TEST_SUITE("utils")
{
	SCENARIO("algo results structs are available")
	{
		GIVEN("An algo result for print is created with default values")
		{
			utils::types::Algo_result_for_print algo;

			CHECK(algo.algo_name == "");
			CHECK(algo.data_structure == "");
			CHECK(algo.data_is_ordered == false);
			CHECK(algo.size_data_structure == 0);
			CHECK(algo.max_iterations == 0);
			CHECK(algo.results_with_time.time_run == "0");
			CHECK(algo.results_with_time.result.iterations == 0);
			CHECK(algo.results_with_time.result.is_search_algo == false);
			CHECK(algo.results_with_time.result.item_to_be_found == 0);
			CHECK(algo.results_with_time.result.item_found == false);

			WHEN("algo name, max iterations and type change")
			{
				algo.algo_name = "new name";
				algo.max_iterations = 100;
				algo.results_with_time.result.is_search_algo = true;

				THEN("the corresponding data changes")
				{
					CHECK(algo.algo_name == "new name");
					CHECK(algo.max_iterations == 100);
					CHECK(algo.results_with_time.result.is_search_algo == true);
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

	SCENARIO("config file is created and valid")
	{
		namespace fs = std::filesystem;

		GIVEN("config file does not exist")
		{
			fs::remove(utils::config::config_file_name);

			REQUIRE(fs::exists(utils::config::config_file_name) == false);

			WHEN("config file is created")
			{
				utils::config::init_config_file();

				THEN("config file exists")
				{
					REQUIRE(fs::exists(utils::config::config_file_name) == true);
				}

				THEN("config file content is valid")
				{
					const auto line_1 =
						std::stoll(utils::config::read_line_from_config_file(1));
					const auto line_2 =
						std::stoll(utils::config::read_line_from_config_file(2));
					const auto line_3 =
						std::stoll(utils::config::read_line_from_config_file(3));

					CHECK(line_1 < line_2);
					CHECK(line_2 < line_3);
				}
			}
		}
	}

	SCENARIO("change config file if largest size is too large")
	{
		namespace fs = std::filesystem;

		GIVEN("a config with a largest size too large")
		{
			fs::remove(utils::config::config_file_name);
			REQUIRE(fs::exists(utils::config::config_file_name) == false);

			utils::config::init_config_file();
			REQUIRE(fs::exists(utils::config::config_file_name) == true);

			const auto old_size =
				std::stoll(utils::config::read_line_from_config_file(3));

			WHEN("largest size is reduced")
			{
				utils::config::reduce_array_size_maximum_in_config_file();

				THEN("largest size has been reduced (divided by 10)")
				{
					const auto new_size =
						std::stoll(utils::config::read_line_from_config_file(3));

					REQUIRE(old_size == new_size * 10);

					//delete created config file, as it has been changed from the default
					fs::remove(utils::config::config_file_name);
					REQUIRE(fs::exists(utils::config::config_file_name) == false);
				}
			}
		}
	}

	SCENARIO("data structures generation")
	{
		GIVEN("no preconditions")
		{
			WHEN("ordered sequential array starting at 0, with random size (max 100), is generated")
			{
				const auto random_num = utils::generate::random(100);
				const auto arr = utils::generate::ordered_array(random_num);
				CHECK(arr.size() == random_num);

				THEN("all elements must be ordered from smaller to larger")
				{
					const auto arr_is_sorted =
						std::is_sorted(arr.begin(), arr.end());
					CHECK(arr_is_sorted == true);
				}
			}

			WHEN("unordered array, with random size (50-100), is generated")
			{
				const auto random_num = utils::generate::random(100, 50);
				const auto arr = utils::generate::unordered_array(random_num);
				CHECK(arr.size() == random_num);

				THEN("array is not sorted")
				{
					const auto arr_is_sorted =
						std::is_sorted(arr.begin(), arr.end());
					CHECK(arr_is_sorted == false);
				}
			}

			WHEN("unordered set, with random size (50-100), is generated")
			{
				const auto random_num = utils::generate::random(100, 50);
				const auto u_set = utils::generate::unordered_set(random_num);
				//set size can be smaller than random number, if repeated
				//numbers were attempted to be added
				CHECK(u_set.size() <= random_num);

				THEN("unordered set is not sorted")
				{
					const auto u_set_is_sorted =
						std::is_sorted(u_set.begin(), u_set.end());
					CHECK(u_set_is_sorted == false);
				}
			}

			WHEN("unordered linked list, with random size (50-100), is generated")
			{
				const auto random_num = utils::generate::random(100, 50);
				const auto u_linked_list = utils::generate::unordered_linked_list(random_num);
				//set size can be smaller than random number, if repeated
				//numbers were attempted to be added
				CHECK(u_linked_list.size() <= random_num);

				THEN("unordered linked list is not sorted")
				{
					const auto u_linked_list_is_sorted =
						std::is_sorted(u_linked_list.begin(), u_linked_list.end());
					CHECK(u_linked_list_is_sorted == false);
				}
			}
		}
	}

	SCENARIO("timer functionality")
	{
		using namespace std::chrono_literals;
		GIVEN("a newly created Timer object")
		{
			utils::time::Timer new_timer;

			WHEN("timer is started")
			{
				new_timer.start();

				THEN("after 200 ms, timer is stopped and duration is available")
				{
					std::this_thread::sleep_for(200ms);
					new_timer.stop();

					const auto duration = std::stof(new_timer.get_time_ms());

					//since std::this_thread stops execution for at least
					//the specified time, we have to check that the duration
					//is at least the desired one
					CHECK(duration >= 200);
				}
			}
		}
	}

	SCENARIO("test string contains helper function")
	{
		GIVEN("a set of phrases and loose words")
		{
			std::string phrase_1{ "ain't no sunshine when she's gone" };
			std::string phrase_2{ "en un lugar de la mancha, de cuyo nombre no quiero acordarme" };

			std::string word_1{ "sun" };
			std::string word_2{ "gone" };
			std::string word_3{ "mancha" };
			std::string word_4{ "no" };
			std::string word_5{ "sancho" };

			WHEN("words are present in phrases")
			{
				THEN("substrings are contained in string")
				{
					CHECK(utils::helpers::string_contains(phrase_1, word_1) == true);
					CHECK(utils::helpers::string_contains(phrase_1, word_2) == true);
					CHECK(utils::helpers::string_contains(phrase_2, word_3) == true);
					CHECK(utils::helpers::string_contains(phrase_1, word_4) == true);
					CHECK(utils::helpers::string_contains(phrase_2, word_4) == true);
				}
			}

			WHEN("words are NOT present in phrases")
			{
				THEN("substrings are NOT contained in string")
				{
					CHECK(utils::helpers::string_contains(phrase_2, word_1) == false);
					CHECK(utils::helpers::string_contains(phrase_2, word_2) == false);
					CHECK(utils::helpers::string_contains(phrase_1, word_3) == false);
					CHECK(utils::helpers::string_contains(phrase_1, word_5) == false);
					CHECK(utils::helpers::string_contains(phrase_2, word_5) == false);
				}
			}
		}
	}
}