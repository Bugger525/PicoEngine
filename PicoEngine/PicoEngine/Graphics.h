#pragma once

#include <string>
#include <vector>
#include "Math.h"

#include <iostream>
namespace PE
{
	enum class TextStyles { Default = -1, Bold = 1, Underline = 4, Reversed = 7, Reset = 0 };
	enum class Colors
	{
		Black = 30, Red, Green, Yellow, Blue, Magenta, Cyan, White,
		Gray = 90, LightRed, LightGreen, LightYellow, LightBlue, LightMagenta, LightCyan, LightWhite
	};
	struct StyledString
	{
		std::string Text = "";

		TextStyles TextStyle = TextStyles::Default;
		Colors ForegroundColor = Colors::White;
		Colors BackgroundColor = Colors::Black;

		const std::string ToString() const;
		void Set(TextStyles textStyle = TextStyles::Default, Colors foregroundColor = Colors::White, Colors backgroundColor = Colors::Black);
	};
	class Texture
	{
	public:
		Texture();
		Texture(const std::vector<std::string>& texture);

		StyledString& operator[](int index);

		const Vector2i& GetSize() const;
		void Set(const std::vector<std::string>& texture);
	private:
		std::vector<StyledString> texture_;
	};
	class Renderer
	{
	public:
		static void Draw(Texture& texture)
		{
			for (int i = 0; i < texture.GetSize().Y; i++)
			{
				std::cout << texture[i].ToString() << "\n";
			}
			std::cout.flush();
		}
	};
}