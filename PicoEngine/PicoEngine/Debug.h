#pragma once

#include <string>

namespace PE
{
	class Debug
	{
	public:
		static void Log(const std::string& text);
		static void Write(const std::string& text);
		static void WriteLine(const std::string& text);
	};
}