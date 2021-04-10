#pragma once

#include "utils.h"

namespace binary_search
{
	utils::types::Test_Results run();

	utils::types::Algo_result_for_print test_simple_binary_search(
		const utils::types::Int_number& size_data_structure,
		utils::types::Int_number num_to_find);

	utils::types::Algo_result simple_binary_search(
		const std::vector<utils::types::Int_number>& arr,
		utils::types::Int_number num_to_find);
}