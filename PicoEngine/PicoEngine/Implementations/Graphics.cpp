#include "../Graphics.h"

#include <sstream>

using std::string;

namespace PE
{
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
	Texture2D::Texture2D(const std::vector<string>& texture)
	{
		for (const auto& line : texture)
		{
			texture_.push_back(StyledString{ line });
		}
	}
	StyledString& Texture2D::operator[](int index)
	{
		return texture_[index];
	}
	const Vector2i Texture2D::GetSize() const
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
}