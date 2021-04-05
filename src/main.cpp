#include <exception>
#include <iostream>
#include <string>
#include <vector>

void printWelcome(const std::vector<std::string>& algos)
{
	std::cout << "Choose which algorithm to test\n";
	std::cout << "Use a number from 0 to " << algos.size() - 1 << "\n\n";

	for (size_t i = 0; i < algos.size(); i++)
	{
		std::cout << i << " : " << algos.at(i) << "\n";
	}
}

int processInput()
{
	std::string input;
	std::cin >> input;

	for (size_t i = 0; i < input.size(); i++)
	{
		if (!(std::isdigit(input[i])))
			return -1;
	}

	return (std::stoi(input));
}

void executeAlgo(const std::vector<std::string>& algos, int input)
{
	std::cout << "\nExecuing algorithm " << algos.at(input) << "...\n";

	switch (input)
	{
	case 0:
		std::cout << "Binary search";
		break;
	case 1:
		std::cout << "Other";
		break;

	default:
		break;
	}

	std::cin.get();
}

int run(int argc, char* argv[])
{
	std::vector<std::string> algos{
		"Binary search", "Stuff"
	};

	while (true)
	{
		printWelcome(algos);

		auto input = processInput();
		if (input < 0)
			continue;

		executeAlgo(algos, input);
	}
}

int main(int argc, char* argv[])
{
	try
	{
		run(argc, argv);
		return 0;
	}
	catch (const std::exception& e)
	{
		std::cerr << "exception: " << e.what() << std::endl;
		return -1;
	}
}