#pragma once

namespace PE
{
	// 노가다 존나 싫어
	enum class Keys
	{
		Any = -1,
		Escape = 27,
		Space = 32,
	};
	class Input
	{
	public:
		static bool GetKeyDown(Keys key);
		static bool GetKeyDownAsync(Keys key);

		static bool GetKeyUp(Keys key);
		static bool GetKeyUpAsync(Keys key);
	};
}