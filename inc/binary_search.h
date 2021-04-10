#pragma once

#include "utils.h"

namespace binary_search
{
	utils::types::Test_Results run();

	template<typename Algo_function>
	utils::types::Algo_result_for_print test_algorithm(
		Algo_function fun,
		std::string algo_name,
		const std::vector<utils::types::Int_number>& data_array,
		utils::types::Int_number num_to_find)
	{
		utils::types::Algo_result_for_print algo_for_print;
		algo_for_print.algo_name = algo_name;
		algo_for_print.data_structure = "array";
		algo_for_print.data_is_ordered = true;
		algo_for_print.size_data_structure = data_array.size();
		algo_for_print.max_iterations = log2(data_array.size()) + 1;

		//const auto data_array =
		//	utils::generate::ordered_array(size_data_structure);

		algo_for_print.results_with_time = utils::test::time_algorithm_search(
			fun, data_array, num_to_find);

		return algo_for_print;
	}

	/*utils::types::Algo_result_for_print test_simple_binary_search(
		const utils::types::Int_number& size_data_structure,
		utils::types::Int_number num_to_find);*/

	utils::types::Algo_result simple_binary_search(
		const std::vector<utils::types::Int_number>& arr,
		utils::types::Int_number num_to_find);

	/*utils::types::Algo_result_for_print test_std_binary_search(
		const utils::types::Int_number& size_data_structure,
		utils::types::Int_number num_to_find);*/

	utils::types::Algo_result std_binary_search(
		const std::vector<utils::types::Int_number>& arr,
		utils::types::Int_number num_to_find);
}