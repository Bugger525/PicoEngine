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

		auto tex = PE::Texture2D(
			{
				PE::Style("  ^", PE::Colors::LightYellow, PE::Colors::Black, PE::TextStyles::Default),
				PE::Style("  |", PE::Colors::Gray, PE::Colors::Black, PE::TextStyles::Default),
				PE::Style("<-v->", PE::Colors::Gray, PE::Colors::Black, PE::TextStyles::Default),
			});
		// Oh shit X is including ansi characters lmao
		PE::Debug::Write(tex.GetSize().X);
		PE::Debug::Write(tex.GetSize().Y);

		bool flag = false;
		do
		{
			flag = PE::Input::GetKeyDown(PE::Keys::Any);
		} while (flag == false);

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