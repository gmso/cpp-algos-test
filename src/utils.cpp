#include "utils.h"

void utils::time::Timer::start()
{
	end = Clock::now();
	begin = Clock::now();
}

void utils::time::Timer::stop()
{
	end = Clock::now();
}

std::string utils::time::Timer::getTime()
{
	std::chrono::duration<double, std::milli> time_diff_ms = end - begin;
	return (std::to_string(time_diff_ms.count()));
}

/*template<typename Algorithm, typename... Inputs>
std::string utils::test::time_algorithm(
	Algorithm algo_function,
	Inputs... algo_inputs)
{
	time::Timer timer;

	timer.start();
	algo_function(algo_inputs...);
	timer.stop();

	return (timer.getTime());
}*/

std::string utils::test::format_algo_result(
	std::string algo_name,
	std::string data_structure,
	int size_data_structure,
	bool data_is_ordered,
	utils::types::Algo_result_with_time results_with_time
)
{
	const std::vector<std::string> search_algo_info = [&]() {
		std::vector<std::string> ret{ "","" };
		if (results_with_time.result.is_search_algo)
		{
			ret.at(0) =
				std::string{ "\n\t\t-----> Item searched: \t" +
				std::to_string(results_with_time.result.item_to_be_found) };
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
		std::to_string(size_data_structure) + " elements " +
		"\n\t\t-----> Runtime : \t" + results_with_time.time_run + " ms" +
		"\n\t\t-----> Iterations : \t" + std::to_string(results_with_time.result.iterations) +
		search_algo_info.at(0) +
		search_algo_info.at(1)
		//iterations
		);
}