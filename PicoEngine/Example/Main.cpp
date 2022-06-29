#include "../PicoEngine/GameWindow.h"
#include "../PicoEngine/Game.h"
#include "../PicoEngine/Graphics.h"
#include "../PicoEngine/Debug.h"
#include "../PicoEngine/Input.h"

class Example : public PE::GameWindow
{
private:
protected:
	void Initialize() override
	{
		InitTitle("Example game");
		InitDebugMode(true);

		base::Initialize();

		auto object = PE::Object("o1_test");
		auto rigidBody = PE::RigidBody("r1_test");

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
		PE::Debug::WriteLine("Press any key to end program.");
		PE::Input::GetKeyDown(PE::Keys::Any);
	}
};
int main()
{
	Example().Run();
}