#include <math.h>
#include <numeric>

#include "binary_search.h"

utils::types::Test_Results binary_search::run()
{
	utils::types::Test_Results ret;

	const std::vector<utils::types::Int_number> arrays_sizes = {
		utils::constants::array_size_minimum,
		utils::constants::array_size_middle,
		utils::constants::array_size_maximum
	};

	const std::vector<utils::types::Int_number> nums_to_find = {
		utils::generate::random(utils::constants::array_size_minimum - 1),
		utils::generate::random(utils::constants::array_size_middle - 1),
		utils::generate::random(utils::constants::array_size_maximum - 1)
	};

	for (size_t i = 0; i < arrays_sizes.size(); i++)
	{
		const auto data_array =
			utils::generate::ordered_array(arrays_sizes.at(i));

		const auto algo_result_0 = test_algorithm(
			custom_sequential_search,
			"[ Sequential ] Custom algorithm,",
			(data_array.size()),
			data_array,
			nums_to_find.at(i)
		);
		ret.push_back(utils::test::format_algo_result(algo_result_0));

		const auto algo_result_2 = test_algorithm(
			custom_binary_search,
			"[ Binary ] Custom algorithm,",
			(log2(data_array.size()) + 1),
			data_array,
			nums_to_find.at(i)
		);
		ret.push_back(utils::test::format_algo_result(algo_result_2));

		const auto algo_result_3 = test_algorithm(
			std_binary_search,
			"[ Binary ] std::binary_search,",
			(log2(data_array.size()) + 1),
			data_array,
			nums_to_find.at(i)
		);
		ret.push_back(utils::test::format_algo_result(algo_result_3));
		ret.push_back("\n");
	}

	return ret;
}

utils::types::Algo_result binary_search::custom_sequential_search(
	const std::vector<utils::types::Int_number>& arr,
	utils::types::Int_number num_to_find)
{
	utils::types::Algo_result result;
	result.is_search_algo = true;
	result.item_to_be_found = num_to_find;
	result.iterations = 1;

	for (auto& num : arr)
	{
		if (num == num_to_find)
		{
			result.item_found = true;
			return result;
		}
		result.iterations++;
	}
	return result;
}

utils::types::Algo_result binary_search::custom_binary_search(
	const std::vector<utils::types::Int_number>& arr,
	utils::types::Int_number num_to_find)
{
	auto low = arr[0];
	auto high = arr[arr.size() - 1];
	auto mid = low;

	utils::types::Algo_result result;
	result.is_search_algo = true;
	result.item_to_be_found = num_to_find;
	result.iterations = 1;

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

utils::types::Algo_result binary_search::std_binary_search(
	const std::vector<utils::types::Int_number>& arr,
	utils::types::Int_number num_to_find)
{
	utils::types::Algo_result result;
	result.is_search_algo = true;
	result.item_to_be_found = num_to_find;

	result.item_found = std::binary_search(arr.begin(), arr.end(), num_to_find);

	return result;
}