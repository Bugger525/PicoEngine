#pragma once

#include <string>
#include <vector>
#include "Math.h"

namespace PE
{
	enum class TextStyles { Default = -1, Bold = 1, Underline = 4, Reversed = 7, Reset = 0 };
	enum class Colors
	{
		Black = 30, Red, Green, Yellow, Blue, Magenta, Cyan, White,
		Gray = 90, LightRed, LightGreen, LightYellow, LightBlue, LightMagenta, LightCyan, LightWhite
	};
	const std::string Style(const std::string& text, Colors foreground, Colors background, TextStyles textStyle);

	class Texture2D
	{
	public:
		Texture2D(const std::vector<std::string>& texture);

		std::string& operator[](int index);

		const Vector2i GetSize() const;
	private:
		std::vector<std::string> texture_;
	};
	class Renderer
	{

	};
}