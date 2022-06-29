#include "../Debug.h"
#include "../Graphics.h"
#include <ctime>
#include <sstream>

#include <iostream>

namespace PE
{
	const std::string GetCurrentTime()
	{
		std::time_t t = std::time(0);
		std::tm* now = std::localtime(&t);
		std::stringstream ss;
		ss << now->tm_hour << ':' << now->tm_min << ':' << now->tm_sec;

		return ss.str();
	}
	void Debug::Log(const std::string& text)
	{
		std::cout << StyledString{ '[' + GetCurrentTime() + ']', TextStyles::Underline, Colors::Yellow, Colors::Black }.ToString() << ' ' << text << std::endl;
	}
	void Debug::Log(int text)
	{
		std::cout << StyledString{ '[' + GetCurrentTime() + ']', TextStyles::Underline, Colors::Yellow, Colors::Black }.ToString() << ' ' << text << std::endl;
	}
	void Debug::Log(float text)
	{
		std::cout << StyledString{ '[' + GetCurrentTime() + ']', TextStyles::Underline, Colors::Yellow, Colors::Black }.ToString() << ' ' << text << std::endl;
	}
	void Debug::Write(const std::string& text)
	{
		std::cout << text;
		std::cout.flush();
	}
	void Debug::Write(int text)
	{
		std::cout << text;
		std::cout.flush();
	}
	void Debug::Write(float text)
	{
		std::cout << text;
		std::cout.flush();
	}
	void Debug::WriteLine(const std::string& text)
	{
		std::cout << text << std::endl;
	}
	void Debug::WriteLine(int text)
	{
		std::cout << text << std::endl;
	}
	void Debug::WriteLine(float text)
	{
		std::cout << text << std::endl;
	}
}