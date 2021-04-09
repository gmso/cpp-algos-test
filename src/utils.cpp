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
	utils::types::Algo_Result result
)
{
	const std::string iterations = [&]() {
		if (result.iterations > 0)
		{
			std::string ret{ "\n\t\t-----> Iterations : \t" };
			ret.append(std::to_string(result.iterations));
			return ret;
		}
		return (std::string{ "" });
	}();

	return(
		algo_name + " performed on " +
		(data_is_ordered ? "ordered " : "unordered ") +
		data_structure + " of " +
		std::to_string(size_data_structure) + " elements" +
		"\n\t\t-----> Runtime : \t" + result.time_run + " ms" +
		iterations
		);
}