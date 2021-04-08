#include <numeric>

#include "binary_search.h"
#include <windows.h>
utils::types::Test_Results binary_search::run()
{
	auto init_ordered_array = [](auto size) {
		std::vector<int> arr;
		std::iota(arr.begin(), arr.end(), size);
		return arr;
	};

	const int arr_size_1 = 100;
	const std::vector<int> data_array_1 = init_ordered_array(arr_size_1);

	utils::types::Test_Results ret;

	auto algo_time =
		utils::test::time_algorithm(simple_binary_search, data_array_1, 3);
	ret.push_back(utils::test::format_algo_result(
		"Custom algorithm", "array", arr_size_1, true,
		algo_time));

	return ret;
}

void binary_search::simple_binary_search(
	const std::vector<int>& arr, int num_to_find)
{
	/*auto low = arr[0];
	auto high = arr[arr.size() - 1];
	auto mid = low;
	while (low <= high)
	{
		mid = (high - low);
		mid = (mid % 2 == 0) ? mid : (mid + 1);
		if (arr[mid] == num_to_find)
		{
		}
	}*/
	Sleep(1000);
}