#pragma once

#include <functional>
#include <chrono>
#include <map>
#include <string>
#include <vector>

namespace utils
{
	namespace types
	{
		struct Algo_result
		{
			int iterations = 1;
			bool is_search_algo = false;
			int item_to_be_found = 0;
			bool item_found = false;
		};

		struct Algo_result_with_time
		{
			Algo_result result;
			std::string time_run = "0";
		};

		typedef std::vector<std::string> Test_Results;

		struct Algo
		{
			Algo() {};
			Algo(
				std::string name,
				std::function<Test_Results()> callback) :
				m_name(name),
				m_callbackFn(callback)
			{};

			std::string m_name;
			std::function<Test_Results()> m_callbackFn;
		};

		typedef std::map<std::string, Algo> Algo_Map;
	}

	namespace time
	{
		struct Timer
		{
			typedef std::chrono::high_resolution_clock Clock;
			typedef std::chrono::time_point<Clock> Time_point;

			Time_point begin;
			Time_point end;

			void start();

			void stop();

			std::string getTime();
		};
	}

	namespace test
	{
		template<typename Algorithm, typename Input>
		utils::types::Algo_result_with_time time_algorithm(
			Algorithm algo_function,
			Input algo_input)
		{
			time::Timer timer;
			types::Algo_result_with_time result_with_time;

			timer.start();
			result_with_time.result = algo_function(algo_input);
			timer.stop();

			result_with_time.time_run = timer.getTime();

			return (result_with_time);
		}

		template<typename Algorithm, typename Input_1, typename Input_2>
		utils::types::Algo_result_with_time time_algorithm_search(
			Algorithm algo_function, Input_1 algo_input_1, Input_2 algo_input_2)
		{
			time::Timer timer;
			types::Algo_result_with_time result_with_time;

			timer.start();
			result_with_time.result = algo_function(algo_input_1, algo_input_2);
			timer.stop();

			result_with_time.time_run = timer.getTime();

			return (result_with_time);
		}

		template<typename Integer_size>
		std::string format_algo_result(
			std::string algo_name,
			std::string data_structure,
			Integer_size size_data_structure,
			bool data_is_ordered,
			utils::types::Algo_result_with_time results_with_time
		)
		{
			auto int_to_string = [](auto integer) {
				std::string ans = "";

				auto num = std::to_string(integer);

				int count = 0;

				// Traverse the string in reverse
				for (int i = num.size() - 1; i >= 0; i--) {
					count++;
					ans.push_back(num[i]);

					// If three characters are traversed
					if (count == 3) {
						ans.push_back('\'');
						count = 0;
					}
				}

				// Reverse the string to get the desired output
				reverse(ans.begin(), ans.end());

				// If the given string is less than 1000
				if (ans.size() % 4 == 0) {
					ans.erase(ans.begin());
				}

				return ans;
			};

			auto s_data_structure_size = int_to_string(size_data_structure);
			auto s_item_searched = int_to_string(results_with_time.result.item_to_be_found);
			auto s_iterations = int_to_string(results_with_time.result.iterations);

			const std::vector<std::string> search_algo_info = [&]() {
				std::vector<std::string> ret{ "","" };
				if (results_with_time.result.is_search_algo)
				{
					ret.at(0) =
						std::string{ "\n\t\t-----> Item searched: \t" + s_item_searched };
					ret.at(1) = (std::string{ "\n\t\t-----> Item found?: \t" });
					if (results_with_time.result.item_found)
					{
						ret.at(1).append("Yes");
					}
					else
					{
						ret.at(1).append("No");
					}
				}
				return (ret);
			}();

			return(
				algo_name + " performed on " +
				(data_is_ordered ? "ordered " : "unordered ") +
				data_structure + " of " +
				s_data_structure_size + " elements " +
				"\n\t\t-----> Runtime : \t" + results_with_time.time_run + " ms" +
				"\n\t\t-----> Iterations : \t" + s_iterations +
				search_algo_info.at(0) +
				search_algo_info.at(1)
				//iterations
				);
		}
	}
}