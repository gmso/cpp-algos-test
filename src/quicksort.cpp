#include "quicksort.h"
#include "..\inc\quicksort.h"

utils::types::Test_Results quicksort::run()
{
	const utils::types::Arr_nums arrays_sizes = {
		utils::config::array_size_minimum / 10,
		utils::config::array_size_minimum * 10,
		utils::config::array_size_minimum * 100
	};

	const utils::types::Arr_nums nums_to_find = {
		utils::generate::random(arrays_sizes.at(0) - 1),
		utils::generate::random(arrays_sizes.at(1) - 1),
		utils::generate::random(arrays_sizes.at(2) - 1)
	};

	const std::vector<std::string> algo_names = {
		"[ Quicksort ] Custom algo,"
		//"[ Selection sort ] Custom algo, swapping elements in container,",
	};

	std::vector<
		utils::types::Int_number(*)(
			utils::types::Arr_nums::iterator&,
			utils::types::Arr_nums::iterator&,
			utils::types::Int_number)
	>
		algo_functions = {
		custom_quicksort
	};

	utils::types::Test_Results ret;

	for (size_t i = 0; i < arrays_sizes.size(); i++)
	{
		for (size_t a = 0; a < algo_names.size(); a++)
		{
			auto cont = utils::generate::unordered_array(arrays_sizes.at(i));

			const auto algo_result = test_algorithm(
				algo_functions.at(a),
				algo_names.at(a),
				"array",
				(cont.size() * cont.size()),
				cont
			);
			ret.push_back(utils::test::format_algo_result(algo_result));
		}
		ret.push_back("\n");
	}

	return ret;
}

utils::types::Arr_nums::iterator quicksort::partition(
	utils::types::Arr_nums::iterator& begin,
	utils::types::Arr_nums::iterator& end)
{
	typedef utils::types::Arr_nums::iterator Itr;

	Itr first = begin;
	Itr last = end - 1;
	Itr ret_it = last;

	while (first != last)
	{
		if (*first < *last)
		{
			if (ret_it == first)
			{
				last--;
			}
			else
			{
				first++;
			}
		}
		else
		{
			std::iter_swap(first, last);
			if (ret_it == last)
			{
				ret_it = first;
				last--;
			}
			else
			{
				ret_it = last;
				first++;
			}
		}
	}

	return ret_it;
}

utils::types::Int_number quicksort::custom_quicksort(
	utils::types::Arr_nums::iterator& begin,
	utils::types::Arr_nums::iterator& end,
	utils::types::Int_number accumulator)
{
	if (begin == end)
		return accumulator;

	auto pivot = quicksort::partition(begin, end);
	accumulator++;

	return (
		custom_quicksort(begin, pivot, accumulator) +
		custom_quicksort(pivot + 1, end, accumulator)
		);
}

/*utils::types::Algo_result quicksort::custom_quicksort(
	std::vector<utils::types::Int_number>& cont)
{
	utils::types::Algo_result result;
	result.iterations = 0;

	return result;
}*/