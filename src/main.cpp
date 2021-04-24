#include <exception>
#include <iostream>
#include <string>
#include <vector>

#include "utils.h"
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
		if (utils::helpers::string_contains(std::string{ e.what() }, "bad allocation"))
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