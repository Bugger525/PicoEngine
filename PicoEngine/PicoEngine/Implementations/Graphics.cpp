#include "../Graphics.h"
#include "../Game.h"
#include "../Debug.h"

#include <sstream>
#include <iostream>
#include <Windows.h>

using std::string;

namespace PE
{
	void SetCursorPosition(int x, int y)
	{
		COORD pos = { x, y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	}
	void SetCursorPosition(const Vector2i& position)
	{
		COORD pos = { position.X, position.Y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	}
	const string StyledString::ToString() const
	{
		std::stringstream ss;
		if (TextStyle == TextStyles::Default)
			ss << "\x1b[" << static_cast<int>(ForegroundColor) << ";" << static_cast<int>(BackgroundColor) + 10 << "m" << Text << "\x1b[0m";
		else
			ss << "\x1b[" << static_cast<int>(ForegroundColor) << ";" << static_cast<int>(BackgroundColor) + 10 << ";" << static_cast<int>(TextStyle) << "m" << Text << "\x1b[0m";
		return ss.str();
	}
	void StyledString::Set(TextStyles textStyle, Colors foregroundColor, Colors backgroundColor)
	{
		TextStyle = textStyle;
		ForegroundColor = foregroundColor;
		BackgroundColor = backgroundColor;
	}
	Texture::Texture() { }
	Texture::Texture(const std::vector<string>& texture)
	{
		for (const auto& line : texture)
		{
			texture_.push_back(StyledString{ line });
		}
	}
	StyledString& Texture::operator[](int index)
	{
		return texture_[index];
	}
	const Vector2i& Texture::GetSize() const
	{
		int x = 0;
		for (const auto& line : texture_)
		{
			if (x < line.Text.length())
				x = line.Text.length();
		}
		int y = texture_.size();

		return Vector2i{ x, y };
	}
	void Texture::Set(const std::vector<std::string>& texture)
	{
		for (const auto& line : texture)
		{
			texture_.push_back(StyledString{ line });
		}
	}
	void Renderer::Draw(Object& object)
	{
		CONSOLE_SCREEN_BUFFER_INFO csbi;

		GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
		Vector2i size = { csbi.srWindow.Right - csbi.srWindow.Left + 1, csbi.srWindow.Bottom - csbi.srWindow.Top + 1 };

		if (size < object.GetPosition())
			return;
		for (auto y = 0; y < object.GetTexture().GetSize().Y; y++)
		{
			SetCursorPosition(object.GetPosition().X, object.GetPosition().Y + y);
			std::cout << object.GetTexture()[y].ToString();
		}
	}
}