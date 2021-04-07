#include <numeric>

#include "binary_search.h"

utils::types::Test_Results binary_search::run()
{
	auto init_ordered_array = [](auto size) {
		std::vector<int> arr;
		std::iota(arr.begin(), arr.end(), size);
		return arr;
	};

	const size_t arr_size_1 = 100;
	const std::vector<int> data_array_1 = init_ordered_array(arr_size_1);

	utils::types::Test_Results ret;

	auto algo_time = utils::test::test_algo(simple_binary_search, arr_size_1);

	return ret;
}

void binary_search::simple_binary_search(size_t arr)
{
}