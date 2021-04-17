#include <algorithm>
#include <math.h>
#include <numeric>

#include "selection_sort.h"

utils::types::Test_Results selection_sort::run()
{
	utils::types::Test_Results ret;

	typedef utils::types::Arr_nums Array_nums;

	const Array_nums arrays_sizes = {
		utils::config::array_size_minimum,
		utils::config::array_size_minimum * 5,
		utils::config::array_size_minimum * 25
	};

	const Array_nums nums_to_find = {
		utils::generate::random(utils::config::array_size_minimum - 1),
		utils::generate::random(utils::config::array_size_minimum * 5 - 1),
		utils::generate::random(utils::config::array_size_minimum * 25 - 1)
	};

	const std::vector<std::string> algo_names = {
		"[ Selection sort ] Custom algo, creating new container,",
		"[ Selection sort ] Custom algo, swapping elements in container,"
	};

	std::vector<utils::types::Algo_result(*)(Array_nums&)> algo_functions = {
		custom_sort_creating_new_container,
		custom_sort_creating_swapping_values
	};

	for (size_t i = 0; i < arrays_sizes.size(); i++)
	{
		for (size_t a = 0; a < algo_names.size(); a++)
		{
			auto u_arr = utils::generate::unordered_array(arrays_sizes.at(i));

			const auto algo_result = test_algorithm(
				algo_functions.at(a),
				algo_names.at(a),
				(u_arr.size() * u_arr.size()),
				u_arr
			);
			ret.push_back(utils::test::format_algo_result(algo_result));
		}

		ret.push_back("\n");
	}

	return ret;
}

utils::types::Algo_result selection_sort::custom_sort_creating_new_container(
	std::vector<utils::types::Int_number>& unsorted_arr)
{
	utils::types::Algo_result result;
	result.iterations = 0;

	utils::types::Arr_nums new_arr;

	while (!(unsorted_arr.empty()))
	{
		auto min_num_it = unsorted_arr.begin();

		const auto end = unsorted_arr.end();

		for (utils::types::Arr_nums::iterator it = unsorted_arr.begin(); it != end; it++)
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

utils::types::Algo_result selection_sort::custom_sort_creating_swapping_values(
	std::vector<utils::types::Int_number>& cont)
{
	utils::types::Algo_result result;
	result.iterations = 0;

	typedef std::vector<utils::types::Int_number>::iterator Itr;
	auto itr = cont.begin();
	while (itr != cont.end())
	{
		auto itr_min = itr;
		for (Itr i = itr + 1; i != cont.end(); i++)
		{
			if (*i < *itr_min)
			{
				itr_min = i;
			}
			result.iterations++;
		}
		std::iter_swap(itr, itr_min);
		itr++;
	}

	return result;
}