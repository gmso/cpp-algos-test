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