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

std::string utils::test::format_algo_result(const utils::types::Algo_result_for_print& res_for_print)
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

	auto s_data_structure_size = int_to_string(
		res_for_print.size_data_structure);
	auto s_item_searched = int_to_string(
		res_for_print.results_with_time.result.item_to_be_found);
	auto s_iterations = int_to_string(
		res_for_print.results_with_time.result.iterations);
	auto s_max_iterations = int_to_string(
		res_for_print.max_iterations);

	const std::vector<std::string> search_algo_info = [&]() {
		std::vector<std::string> ret{ "","" };
		if (res_for_print.results_with_time.result.is_search_algo)
		{
			ret.at(0) =
				std::string{ "\n\t\t-----> Item searched: \t" + s_item_searched };
			ret.at(1) = (std::string{ "\n\t\t-----> Item found?: \t" });
			if (res_for_print.results_with_time.result.item_found)
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
		res_for_print.algo_name + " performed on " +
		(res_for_print.data_is_ordered ? "ordered " : "unordered ") +
		res_for_print.data_structure + " of " +
		s_data_structure_size + " elements " +
		"\n\t\t-----> Runtime :\t" + res_for_print.results_with_time.time_run + " ms" +
		"\n\t\t-----> Iterations(max):\t" + s_iterations + "(" + s_max_iterations + ")" +
		search_algo_info.at(0) +
		search_algo_info.at(1)
		//iterations
		);
}