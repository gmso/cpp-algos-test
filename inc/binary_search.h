#pragma once

#include "utils.h"

namespace binary_search
{
	typedef long long Int_number;

	utils::types::Test_Results run();

	utils::types::Algo_result simple_binary_search(
		const std::vector<Int_number>& arr, Int_number num_to_find);
}