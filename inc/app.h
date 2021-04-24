#pragma once

#include "utils.h"

namespace app
{
	void printHelp(utils::types::Algo_Map& algos);

	utils::types::Algo_Map initAlgos();

	int run(int argc, char* argv[]);
}