#include "../Graphics.h"

#include <sstream>

using std::string;

namespace PE
{
	const string Style(const string& text, Colors foreground, Colors background, TextStyles textStyle)
	{
		std::stringstream ss;

		if (textStyle == TextStyles::Default)
			ss << "\x1b[" << static_cast<int>(foreground) << ";" << static_cast<int>(background) + 10 << "m" << text << "\x1b[0m";
		else
			ss << "\x1b[" << static_cast<int>(foreground) << ";" << static_cast<int>(background) + 10 << ";" << static_cast<int>(textStyle) << "m" << text << "\x1b[0m";
		return ss.str();
	}
	Texture2D::Texture2D(const std::vector<string>& texture)
	{
		texture_.assign(texture.begin(), texture.end());
	}
	string& Texture2D::operator[](int index)
	{
		return texture_[index];
	}
}