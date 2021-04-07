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

			void start()
			{
				end = Clock::now();
				begin = Clock::now();
			}

			void stop()
			{
				end = Clock::now();
			}

			std::string getTime()
			{
				std::chrono::duration<double> time_diff = end - begin;
				return (std::to_string(time_diff.count()));
			}
		};
	}

	namespace test
	{
		template<typename Algo_input>
		std::string test_algo(
			std::function<void(Algo_input input)> algo_function,
			Algo_input input)
		{
			time::Timer timer;

			timer.start();
			algo_function(input);
			timer.stop();

			return (timer.getTime());
		}

		std::string format_algo_result(
			std::string algo_name,
			std::string data_structure,
			size_t size_data_structure,
			bool data_is_ordered,
			std::string time_of_test
		)
		{
			return(
				algo_name + "\t performed on \t" +
				(data_is_ordered ? "ordered \t" : "unordered \t") +
				data_structure + "\t of \t" +
				std::to_string(size_data_structure) + " elements" +
				"\t Runtime -----> \t" + time_of_test + "\t nanosec."
				);
		}
	}
}