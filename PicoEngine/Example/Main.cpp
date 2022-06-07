#include "../PicoEngine/Game.h"
#include "../PicoEngine/Graphics.h"
#include "../PicoEngine/Debug.h"
#include <conio.h>

class Example : public PE::Game
{
protected:
	void Initialize() override
	{
		InitTitle("Example game");
		InitDebugMode(true);

		base::Initialize();

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