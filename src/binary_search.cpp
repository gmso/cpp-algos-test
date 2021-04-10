#include <math.h>
#include <numeric>

#include "binary_search.h"

utils::types::Test_Results binary_search::run()
{
	utils::types::Test_Results ret;

	std::vector<utils::types::Int_number> arrays_to_test = {
		utils::constants::array_size_minimum,
		utils::constants::array_size_middle,
		utils::constants::array_size_maximum
	};

	std::vector<utils::types::Int_number> nums_to_find = {
		utils::generate::random(utils::constants::array_size_minimum - 1),
		utils::generate::random(utils::constants::array_size_middle - 1),
		utils::generate::random(utils::constants::array_size_maximum - 1)
	};

	for (size_t i = 0; i < arrays_to_test.size(); i++)
	{
		auto algo_result_for_print = test_simple_binary_search(
			arrays_to_test.at(i),
			nums_to_find.at(i)
		);
		ret.push_back(utils::test::format_algo_result(algo_result_for_print));
	}

	return ret;
}

utils::types::Algo_result_for_print binary_search::test_simple_binary_search(
	const utils::types::Int_number& size_data_structure,
	utils::types::Int_number num_to_find)
{
	utils::types::Algo_result_for_print algo_for_print;
	algo_for_print.algo_name = "Custom algorithm";
	algo_for_print.data_structure = "array";
	algo_for_print.data_is_ordered = true;
	algo_for_print.size_data_structure = size_data_structure;
	algo_for_print.max_iterations = log2(size_data_structure) + 1;

	const auto data_array =
		utils::generate::ordered_array(size_data_structure);

	algo_for_print.results_with_time = utils::test::time_algorithm_search(
		simple_binary_search, data_array, num_to_find);

	return algo_for_print;
}

utils::types::Algo_result binary_search::simple_binary_search(
	const std::vector<utils::types::Int_number>& arr,
	utils::types::Int_number num_to_find)
{
	auto low = arr[0];
	auto high = arr[arr.size() - 1];
	auto mid = low;

	utils::types::Algo_result result;
	result.is_search_algo = true;
	result.item_to_be_found = num_to_find;

	while (low <= high)
	{
		mid = (high + low) / 2;
		if (arr[mid] == num_to_find)
		{
			result.item_found = true;
			return result;
		}
		result.iterations++;
		if (arr[mid] > num_to_find)
		{
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}
	return result;
}