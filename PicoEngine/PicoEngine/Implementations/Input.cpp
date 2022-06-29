#include "../Input.h"
#include "../Debug.h"
#include <string>
#include <conio.h>
#include <Windows.h>

#define ClearKeyboardInputBuffer() while (_kbhit()) _getch();

namespace PE
{
	bool Input::GetKeyDown(Keys key)
	{
		ClearKeyboardInputBuffer();

		if (key == Keys::Any)
			return _getch();
		return (static_cast<int>(key) == _getch());
	}
	bool Input::GetKeyDownAsync(Keys key)
	{
		if (key == Keys::Any)
			return _kbhit();
		return (GetAsyncKeyState(static_cast<int>(key)) & 0x8000);
	}
	bool Input::GetKeyUp(Keys key)
	{
		ClearKeyboardInputBuffer();

		if (key == Keys::Any)
			return !_getch();
		return (static_cast<int>(key) != _getch());
	}
	bool Input::GetKeyUpAsync(Keys key)
	{
		if (key == Keys::Any)
			return !_kbhit();
		return !(GetAsyncKeyState(static_cast<int>(key)) & 0x8000);
	}
}