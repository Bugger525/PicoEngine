#include "../Input.h"
#include "../Debug.h"
#include <string>
#include <conio.h>
#include <Windows.h>

namespace PE
{
	bool Input::GetKeyDown(Keys key)
	{
		if (key == Keys::Any)
			return (_getch() >= 0);
		return (_getch() == static_cast<char>(key));
	}
	bool Input::GetKeyDownAsync(Keys key)
	{
		if (key == Keys::Any)
			return _kbhit();
		return (GetAsyncKeyState(static_cast<int>(key)) & 0x8000);
	}
}