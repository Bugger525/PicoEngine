#include "../PicoEngine/GameWindow.h"
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

		auto tex = PE::Texture2D({
			" | | ",
			"<-U->"
			});
		tex[0].Set(PE::TextStyles::Underline, PE::Colors::LightBlue);

		PE::Renderer::Draw(tex);
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