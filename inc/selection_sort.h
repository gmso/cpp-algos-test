#pragma once

#include "utils.h"

namespace selection_sort
{
	utils::types::Test_Results run();

	template<typename Algo_function, typename Container>
	utils::types::Algo_result_for_print test_algorithm(
		Algo_function fun,
		std::string algo_name,
		utils::types::Int_number max_iterations,
		Container& container/*,
		utils::types::Int_number num_to_find*/)
	{
		utils::types::Algo_result_for_print algo_for_print;
		algo_for_print.algo_name = algo_name;
		algo_for_print.data_structure = "array";
		algo_for_print.data_is_ordered = false;
		algo_for_print.size_data_structure = container.size();
		algo_for_print.max_iterations = max_iterations;

		algo_for_print.results_with_time =
			utils::test::time_algorithm(fun, container);

		return algo_for_print;
	}

	utils::types::Algo_result custom_sort_creating_new_container(
		std::vector<utils::types::Int_number>& unsorted_arr);

	utils::types::Algo_result custom_sort_creating_swapping_values(
		std::vector<utils::types::Int_number>& cont);
}