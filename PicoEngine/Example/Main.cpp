#include "../PicoEngine/Game.h"
#include "../PicoEngine/Graphics.h"
#include <conio.h>
#include <iostream>

class Example : public PE::Game
{
protected:
	void Initialize() override
	{
		InitTitle("Example game");
		InitDebugMode(true);

		base::Initialize();

		std::cout << PE::Style("Hello World!", PE::Color::LightYellow, PE::Color::Black, PE::TextStyle::Underline) << std::endl;
		_getch();
		Exit();
	}
	void Update(float deltaTime) override
	{

	}
	void Render(float deltaTime) override
	{

	}
	void Cleanup() override
	{

	}
};
int main()
{
	Example().Run();
}