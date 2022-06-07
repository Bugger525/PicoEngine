#pragma once

#include <string>
#include <vector>

namespace PE
{
	enum class TextStyle { Default = -1, Bold = 1, Underline = 4, Reversed = 7, Reset = 0 };
	enum class Color
	{
		Black = 30, Red, Green, Yellow, Blue, Magenta, Cyan, White,
		Gray = 90, LightRed, LightGreen, LightYellow, LightBlue, LightMagenta, LightCyan, LightWhite
	};
	const std::string Style(const std::string& text, Color foreground, Color background, TextStyle textStyle);

	class Texture2D
	{
	public:
		Texture2D(const std::vector<std::string>& texture);

		std::string& operator[](int index);
	private:
		std::vector<std::string> texture_;
	};
}