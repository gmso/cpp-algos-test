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
		typedef int Iterations;
		struct Algo_Result
		{
			Iterations iterations = 0;
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
		types::Algo_Result time_algorithm(Algorithm algo_function,
			Input algo_input)
		{
			time::Timer timer;
			types::Algo_Result result;

			timer.start();
			result.iterations = algo_function(algo_input);
			timer.stop();

			result.time_run = timer.getTime();

			return (result);
		}

		template<typename Algorithm, typename Input_1, typename Input_2>
		types::Algo_Result time_algorithm(Algorithm algo_function,
			Input_1 algo_input_1, Input_2 algo_input_2)
		{
			time::Timer timer;
			types::Algo_Result result;

			timer.start();
			result.iterations = algo_function(algo_input_1, algo_input_2);
			timer.stop();

			result.time_run = timer.getTime();

			return (result);
		}

		std::string format_algo_result(
			std::string algo_name,
			std::string data_structure,
			int size_data_structure,
			bool data_is_ordered,
			utils::types::Algo_Result result
		);
	}
}