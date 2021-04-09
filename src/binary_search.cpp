#include <numeric>

#include "binary_search.h"
//#include <windows.h>
utils::types::Test_Results binary_search::run()
{
	auto init_ordered_array = [](auto size) {
		std::vector<int> arr(size);
		std::iota(arr.begin(), arr.end(), 0);
		return arr;
	};

	const int arr_size_1 = 1000000;
	const std::vector<int> data_array_1 = init_ordered_array(arr_size_1);

	utils::types::Test_Results ret;

	auto algo_result =
		utils::test::time_algorithm_search(simple_binary_search, data_array_1, 3);
	ret.push_back(utils::test::format_algo_result(
		"Custom algorithm", "array", arr_size_1, true,
		algo_result));

	return ret;
}

utils::types::Algo_result binary_search::simple_binary_search(
	const std::vector<int>& arr, int num_to_find)
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
		//mid = (mid % 2 == 0) ? mid : (mid + 1);
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

	//Sleep(1000);
	//return 100;
}