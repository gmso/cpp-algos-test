#include <algorithm>
#include <math.h>
#include <numeric>

#include "selection_sort.h"

utils::types::Test_Results selection_sort::run()
{
	utils::types::Test_Results ret;

	const std::vector<utils::types::Int_number> arrays_sizes = {
		utils::config::array_size_minimum,
		utils::config::array_size_minimum * 10,
		utils::config::array_size_minimum * 100
	};

	const std::vector<utils::types::Int_number> nums_to_find = {
		utils::generate::random(utils::config::array_size_minimum - 1),
		utils::generate::random(utils::config::array_size_minimum * 10 - 1),
		utils::generate::random(utils::config::array_size_minimum * 100 - 1)
	};

	for (size_t i = 0; i < arrays_sizes.size(); i++)
	{
		auto u_set =
			utils::generate::unordered_array(arrays_sizes.at(i));

		const auto algo_result_0 = test_algorithm(
			custom_selection_sort,
			"[ Selection sort ] Custom algorithm,",
			(u_set.size() * u_set.size()),
			u_set
		);
		ret.push_back(utils::test::format_algo_result(algo_result_0));

		/*const auto algo_result_1 = test_algorithm(
			std_find,
			"[ Sequential ] std::find,",
			(data_array.size()),
			data_array,
			nums_to_find.at(i)
		);
		ret.push_back(utils::test::format_algo_result(algo_result_1));*/

		ret.push_back("\n");
	}

	return ret;
}

utils::types::Algo_result selection_sort::custom_selection_sort(
	std::vector<utils::types::Int_number>& unsorted_arr)
{
	utils::types::Algo_result result;
	result.iterations = 0;

	typedef std::vector<utils::types::Int_number> U_Arr;
	U_Arr new_arr;

	while (!(unsorted_arr.empty()))
	{
		auto min_num_it = unsorted_arr.begin();

		const auto end = unsorted_arr.end();

		for (U_Arr::iterator it = unsorted_arr.begin(); it != end; it++)
		{
			if (*it < *min_num_it)
			{
				min_num_it = it;
			}
			result.iterations++;
		}

		new_arr.push_back(*min_num_it);
		unsorted_arr.erase(min_num_it);
	}

	return result;
}
/*
utils::types::Algo_result binary_search::std_find(
	const std::vector<utils::types::Int_number>& arr,
	utils::types::Int_number num_to_find)
{
	utils::types::Algo_result result;
	result.is_search_algo = true;
	result.item_to_be_found = num_to_find;

	auto it = std::find(arr.begin(), arr.end(), num_to_find);

	if (it != arr.end())
	{
		result.item_found = true;
	}
	result.iterations = std::distance(arr.begin(), it) + 1;

	return result;
}
*/