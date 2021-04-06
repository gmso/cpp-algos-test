#include <functional>
#include <exception>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "binary_search.h"

namespace app
{
	struct Algo
	{
		Algo() {};
		Algo(
			std::string name,
			std::function<std::vector<std::string>()> callback) :
			m_name(name),
			m_callbackFn(callback)
		{};

		std::string m_name;
		std::function<std::vector<std::string>()> m_callbackFn;
	};

	typedef std::map<std::string, Algo> Algo_Map;

	void printHelp(Algo_Map& algos)
	{
		std::cout <<
			"\n\nUse the following arguments to test each algorithm:\n";
		std::cout <<
			"\n\tKey\tAlgorithm\n\t----------------------";

		for (auto& algo : algos)
		{
			std::cout <<
				"\n\t" << algo.first << "\t" << algo.second.m_name;
		}

		std::cout << "\n\n";
	}

	Algo_Map initAlgos()
	{
		Algo_Map algos;

		/*auto testFn = []() {
			std::vector<std::string> ret{ "test" };
			return ret;
		};*/

		algos.insert({
			"0",
			Algo("Binary search",binary_search::return_result) });

		return algos;
	}

	int run(int argc, char* argv[])
	{
		auto algos = initAlgos();

		if (argc != 2)
		{
			std::cout <<
				"\n\nInvalid argument count. Use argument \"help\" for clarification\n";
			return 1;
		}

		auto argument = std::string(argv[1]);
		if (argument == "help")
		{
			printHelp(algos);
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

			auto results = algos[argument].m_callbackFn();

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
}

int main(int argc, char* argv[])
{
	try
	{
		app::run(argc, argv);
		return 0;
	}
	catch (const std::exception& e)
	{
		std::cerr << "exception: " << e.what() << std::endl;
		return -1;
	}
}