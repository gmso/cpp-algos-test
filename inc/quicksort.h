#pragma once

#include "utils.h"

namespace quicksort
{
	utils::types::Test_Results run();

	template<typename Algo_function, typename Container>
	utils::types::Algo_result_for_print test_algorithm(
		Algo_function fun,
		std::string algo_name,
		std::string data_structure,
		utils::types::Int_number max_iterations,
		Container& container/*,
		utils::types::Int_number num_to_find*/)
	{
		utils::types::Algo_result_for_print algo_for_print;
		algo_for_print.algo_name = algo_name;
		algo_for_print.data_structure = data_structure;
		algo_for_print.data_is_ordered = false;
		algo_for_print.size_data_structure = container.size();
		algo_for_print.max_iterations = max_iterations;

		algo_for_print.results_with_time =
			utils::test::time_algorithm_sort(fun, container.begin(), container.end());

		return algo_for_print;
	}

	utils::types::Arr_nums::iterator partition(
		utils::types::Arr_nums::iterator& begin,
		utils::types::Arr_nums::iterator& end
	);

	utils::types::Int_number custom_quicksort(
		utils::types::Arr_nums::iterator& begin,
		utils::types::Arr_nums::iterator& end,
		utils::types::Int_number accumulator = 0
	);
}