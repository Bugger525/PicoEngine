#include "../Graphics.h"

#include <sstream>

namespace PE
{
	const std::string Style(const std::string& text, Color foreground, Color background, TextStyle textStyle)
	{
		std::stringstream ss;

		if (textStyle == TextStyle::Default)
			ss << "\x1b[" << static_cast<int>(foreground) << ";" << static_cast<int>(background) + 10 << "m" << text << "\x1b[0m";
		else
			ss << "\x1b[" << static_cast<int>(foreground) << ";" << static_cast<int>(background) + 10 << ";" << static_cast<int>(textStyle) << "m" << text << "\x1b[0m";
		return ss.str();
	}
}