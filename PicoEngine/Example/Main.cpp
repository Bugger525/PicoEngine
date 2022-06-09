#include "../PicoEngine/GameWindow.h"
#include "../PicoEngine/Graphics.h"
#include "../PicoEngine/Debug.h"
#include "../PicoEngine/Input.h"
#include <Windows.h>
#include <conio.h>
#include <string>

class Example : public PE::GameWindow
{
private:
protected:
	void Initialize() override
	{
		InitTitle("Example game");
		InitDebugMode(true);

		base::Initialize();

		//Exit();
	}
	void Update(float deltaTime) override
	{
		PE::Debug::Log("lol");
		if (PE::Input::GetKeyDownAsync(PE::Keys::Escape))
		{
			PE::Debug::WriteLine(PE::Style("!", PE::Colors::LightRed, PE::Colors::Black, PE::TextStyles::Underline));
			Exit();
		}
	}
	void Render(float deltaTime) override
	{

	}
	void Cleanup() override
	{
		Sleep(1000);
		_getch();
		PE::Debug::Log(std::to_string(PE::Input::GetKeyDown(PE::Keys::Any)));
		Sleep(5000);
	}
};
int main()
{
	Example().Run();
}