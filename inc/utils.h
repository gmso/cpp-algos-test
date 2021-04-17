#pragma once

#include <chrono>
#include <climits>
#include <iostream>
#include <fstream>
#include <functional>
#include <filesystem>
#include <map>
#include <numeric>
#include <random>
#include <string>
#include <unordered_set>
#include <vector>

namespace utils
{
	namespace types
	{
		typedef long long Int_number;

		struct Algo_result
		{
			int iterations = 0;
			bool is_search_algo = false;
			int item_to_be_found = 0;
			bool item_found = false;
		};

		struct Algo_result_with_time
		{
			Algo_result result;
			std::string time_run = "0";
		};

		struct Algo_result_for_print
		{
			std::string algo_name = "";
			std::string data_structure = "";
			bool data_is_ordered = false;
			types::Int_number size_data_structure = 0;
			types::Int_number max_iterations = 0;
			utils::types::Algo_result_with_time results_with_time;
		};

		typedef std::vector<std::string> Test_Results;

		struct Algo
		{
			Algo() {};
			Algo(
				std::string name,
				std::function<Test_Results()> callback) :
				m_name(name),
				m_callbackFn(callback)
			{};

			std::string m_name;
			std::function<Test_Results()> m_callbackFn;
		};

		typedef std::map<std::string, Algo> Algo_Map;

		typedef std::vector<utils::types::Int_number> Arr_nums;
		typedef std::list<utils::types::Int_number> Linked_list_nums;
	}

	namespace config
	{
		const std::string config_file_name{ "config.txt" };

		const types::Int_number array_size_minimum_default = 100;
		const types::Int_number array_size_middle_default = 1000000;
		const types::Int_number array_size_maximum_default = 100000000;

		const int config_file_line_num_array_minimum = 1;
		const int config_file_line_num_array_middle = 2;
		const int config_file_line_num_array_maximum = 3;

		auto init_config_file = []() {
			if (!(std::filesystem::exists(config_file_name)))
			{
				std::ofstream file{ config_file_name };
				file << array_size_minimum_default << "\n";
				file << array_size_middle_default << "\n";
				file << array_size_maximum_default << "\n";
				file.close();
			}
		};

		auto read_line_from_config_file = [](int line_number_starting_at_1) {
			init_config_file();
			if (!(std::filesystem::exists(config_file_name)))
			{
				//Config file not found, using small values instead
				return (std::to_string(std::pow(10, line_number_starting_at_1)));
			}
			else
			{
				std::ifstream file{ config_file_name };
				std::string line;
				for (size_t i = 0; i < line_number_starting_at_1; i++)
				{
					std::getline(file, line);
				}
				return (line);
			}
		};

		const types::Int_number array_size_minimum =
			std::stoll(read_line_from_config_file(config_file_line_num_array_minimum));
		const types::Int_number array_size_middle =
			std::stoll(read_line_from_config_file(config_file_line_num_array_middle));
		const types::Int_number array_size_maximum =
			std::stoll(read_line_from_config_file(config_file_line_num_array_maximum));

		auto read_whole_config_file = [&]() {
			std::vector<std::string> lines;
			if (std::filesystem::exists(config_file_name))
			{
				std::ifstream file{ config_file_name };
				std::string line;
				while (std::getline(file, line))
				{
					lines.push_back(line);
				}
			}
			return (lines);
		};

		auto delete_content_config_file = []() {
			std::ofstream outfile;
			outfile.open(config_file_name, std::ofstream::out | std::ofstream::trunc);
			outfile.close();
		};

		auto reduce_array_size_maximum_in_config_file = []() {
			auto original = read_whole_config_file();

			delete_content_config_file();

			std::ofstream file{ config_file_name };
			for (size_t i = 0; i < original.size(); i++)
			{
				const auto line_to_write = [&]() {
					if ((i + 1) == config_file_line_num_array_maximum)
					{
						return (std::to_string(std::stoll(original.at(i)) / 10));
					}
					else
					{
						return (original.at(i));
					}
				}();

				file << line_to_write << "\n";
			}
			file.close();
		};
	}

	namespace generate
	{
		auto random = [](types::Int_number max, types::Int_number min = 0) {
			// Seed with a real random value, if available
			std::random_device r;

			// Choose a random mean between 0 and max
			std::default_random_engine e1(r());
			std::uniform_int_distribution<types::Int_number> uniform_dist(min, max);
			auto mean = uniform_dist(e1);
			return mean;
		};

		auto ordered_array = [](auto size) {
			std::vector<types::Int_number> arr(size);
			std::iota(arr.begin(), arr.end(), 0);
			return arr;
		};

		auto unordered_array = [](auto size) {
			std::vector<types::Int_number> u_arr(size);

			for (auto& num : u_arr)
			{
				num = utils::generate::random(size * 10);
			}
			return u_arr;
		};

		auto unordered_set = [](auto size) {
			std::unordered_set<types::Int_number> u_set(size);

			for (size_t i = 0; i < size; i++)
			{
				u_set.insert(utils::generate::random(size * 10));
			}
			return u_set;
		};

		auto unordered_linked_list = [](auto size) {
			std::list<types::Int_number> u_linked_list(size);

			for (auto& num : u_linked_list)
			{
				num = utils::generate::random(size * 10);
			}
			return u_linked_list;
		};
	}

	namespace time
	{
		struct Timer
		{
			typedef std::chrono::high_resolution_clock Clock;
			typedef std::chrono::time_point<Clock> Time_point;

			Time_point begin;
			Time_point end;

			void start();

			void stop();

			std::string get_time_ms();
		};
	}

	namespace test
	{
		template<typename Algorithm, typename Input>
		utils::types::Algo_result_with_time time_algorithm(
			Algorithm& algo_function, Input& algo_input)
		{
			time::Timer timer;
			types::Algo_result_with_time result_with_time;

			timer.start();
			result_with_time.result = algo_function(algo_input);
			timer.stop();

			result_with_time.time_run = timer.get_time_ms();

			return (result_with_time);
		}

		template<typename Algorithm, typename Input_1, typename Input_2>
		utils::types::Algo_result_with_time time_algorithm_search(
			Algorithm& algo_function, Input_1& algo_input_1, Input_2& algo_input_2)
		{
			time::Timer timer;
			types::Algo_result_with_time result_with_time;

			timer.start();
			result_with_time.result = algo_function(algo_input_1, algo_input_2);
			timer.stop();

			result_with_time.time_run = timer.get_time_ms();

			return (result_with_time);
		}

		std::string format_algo_result(
			const utils::types::Algo_result_for_print& res_for_print);
	}
}