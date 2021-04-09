#pragma once

#include "utils.h"

namespace binary_search
{
	utils::types::Test_Results run();

	utils::types::Iterations simple_binary_search(
		const std::vector<int>& arr, int num_to_find);
}