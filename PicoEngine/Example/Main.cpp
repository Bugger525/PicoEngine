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

		auto obj = PE::Object(10, 15);
		obj.GetTexture().Set({
			" | | ",
			"<-U->",
			});
		obj.GetTexture()[0].Set(PE::TextStyles::Default, PE::Colors::LightRed, PE::Colors::Black);
		obj.SetSize(obj.GetTexture().GetSize());

		PE::Renderer::Draw(obj);
		Exit();
	}
	void Update(float deltaTime) override
	{
		base::Update(deltaTime);
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