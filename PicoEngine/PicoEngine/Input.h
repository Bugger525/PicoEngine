#pragma once

namespace PE
{
	enum class Keys
	{
		Any = -1,
		Escape = 0x1B
	};
	class Input
	{
	public:
		static bool GetKeyDown(Keys key);
		static bool GetKeyDownAsync(Keys key);

		static bool GetKeyReleased(Keys key);
		static bool GetKeyReleasedAsync(Keys key);
	};
}