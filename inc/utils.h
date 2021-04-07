#pragma once

#include <functional>
#include <map>
#include <string>
#include <vector>

namespace utils
{
	namespace types
	{
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
	}
}