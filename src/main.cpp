#include <exception>
#include <iostream>
#include <string>
#include <vector>

#include "utils.h"
#include "binary_search.h"
#include "selection_sort.h"
#include "quicksort.h"
#include "app.h"

int main(int argc, char* argv[])
{
	try
	{
		app::run(argc, argv);
		return 0;
	}
	catch (const std::exception& e)
	{
		auto string_contains = [](std::string original, std::string substring) {
			int pos = 0;
			int index;
			while ((index = original.find(substring, pos)) != std::string::npos)
			{
				return true;
			}
			return false;
		};

		if (string_contains(std::string{ e.what() }, "bad allocation"))
		{
			utils::config::reduce_array_size_maximum_in_config_file();

			std::cerr << "\nCould not allocate large memory for test.";
			std::cerr << "\nConfiguration changed, please rerun program again\n";
			return -1;
		}
		std::cerr << "exception: " << e.what() << std::endl;
		return -1;
	}
}