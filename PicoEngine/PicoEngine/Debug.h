#pragma once

#include <string>

namespace PE
{
	class Debug
	{
	public:
		static void Log(const std::string& text);
		static void Log(int text);
		static void Log(float text);

		static void Write(const std::string& text);
		static void Write(int text);
		static void Write(float text);

		static void WriteLine(const std::string& text);
		static void WriteLine(int text);
		static void WriteLine(float text);
	};
}