#pragma once

namespace PE
{
	// �밡�� ���� �Ⱦ�
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