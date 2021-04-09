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

		std::string format_algo_result(
			std::string algo_name,
			std::string data_structure,
			int size_data_structure,
			bool data_is_ordered,
			utils::types::Algo_result_with_time result
		);
	}
}