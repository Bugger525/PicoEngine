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
			return _kbhit();
		return (GetAsyncKeyState(static_cast<int>(key)) & 0x8000);
	}
	bool Input::GetKeyUp(Keys key)
	{
		if (key == Keys::Any)
			return !_kbhit();
		return !(GetAsyncKeyState(static_cast<int>(key)) & 0x8000);
	}
}