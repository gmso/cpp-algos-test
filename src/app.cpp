#include <iostream>
#include <string>
#include <vector>

#include "app.h"

#include "utils.h"
#include "binary_search.h"
#include "selection_sort.h"
#include "quicksort.h"

void app::printHelp(utils::types::Algo_Map& algos)
{
	std::cout <<
		"\n\nUse the following arguments to test each algorithm set:\n";
	std::cout <<
		"\n\tKey\tAlgorithm\n\t---------------------------------------------------------";

	for (auto& algo : algos)
	{
		std::cout <<
			"\n\t" << algo.first << "\t" << algo.second.m_name;
	}

	std::cout << "\n\n";
}

utils::types::Algo_Map app::initAlgos()
{
	utils::types::Algo_Map algos;

	algos.insert({
		"0",
		utils::types::Algo("Sequential (O(n)) vs. Binary search (O(log n))",binary_search::run) });

	algos.insert({
		"1",
		utils::types::Algo("Selection sort (O(n^2))",selection_sort::run) });

	algos.insert({
		"2",
		utils::types::Algo("Quicksort (Average: O(n*log(n), Worse: O(n^2)))",quicksort::run) });

	return algos;
}

int app::run(int argc, char* argv[])
{
	auto algos = app::initAlgos();

	if (argc != 2)
	{
		std::cout <<
			"\n\nInvalid argument count. Use argument \"help\" for clarification\n";
		return 1;
	}

	const auto argument = std::string(argv[1]);
	if (argument == "help")
	{
		app::printHelp(algos);
		return 0;
	}

	if (algos.count(argument) == 0)
	{
		std::cout << "\n\nInvalid argument. Use argument \"help\" for clarification\n\n";
		return 1;
	}
	else
	{
		std::cout <<
			"\n\n-------- Executing tests for algorithm " <<
			algos[argument].m_name << " ---------\n";

		const auto results = algos[argument].m_callbackFn();

		for (auto& result : results)
		{
			std::cout << "\n\t" << result;
		}

		std::cout <<
			"\n\n-------- Finished tests for algorithm " <<
			algos[argument].m_name << " ---------\n";
	}

	return 0;
}