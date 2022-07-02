#include "../GameWindow.h"
#include "../Graphics.h"
#include <cmath>
#include <sstream>
#include <Windows.h>
#include <cstdlib>

using std::string;

namespace PE
{
	GameWindow::GameWindow()
	{
		title_ = "PicoEngine";
		size_ = { 80, 25 };
		isOpen_ = false;
		debugMode_ = false;
		frameRate_ = 30;

		endOfInit_ = false;
	}
	void GameWindow::Run()
	{
		Initialize();

		float deltaTime = static_cast<float>(std::floor((1.0 / frameRate_) * 100) / 100);
		while (isOpen_)
		{
			Update(deltaTime);
			Render(deltaTime);
			Sleep(frameRate_);
		}
		Cleanup();
		exit(0);
	}
	const string GameWindow::GetTitle() const
	{
		return title_;
	}
	void GameWindow::InitTitle(const string& title)
	{
		if (!endOfInit_)
			title_ = title;
	}
	void GameWindow::SetTitle(const string& title)
	{
		title_ = title;
		SetConsoleTitleA(title_.c_str());
	}
	const Vector2i& GameWindow::GetSize() const
	{
		return size_;
	}
	void GameWindow::InitSize(uint width, uint height)
	{
		if (!endOfInit_)
			size_ = { static_cast<int>(width), static_cast<int>(height) };
	}
	void GameWindow::SetSize(uint width, uint height)
	{
		size_ = { static_cast<int>(width), static_cast<int>(height) };

		std::stringstream ss;
		ss << "mode con lines=" << size_.Y << " cols=" << size_.X;

		system(ss.str().c_str());

		DeleteMenu(GetSystemMenu(GetConsoleWindow(), false), SC_MINIMIZE, MF_BYCOMMAND);
		DeleteMenu(GetSystemMenu(GetConsoleWindow(), false), SC_MAXIMIZE, MF_BYCOMMAND);
		DeleteMenu(GetSystemMenu(GetConsoleWindow(), false), SC_SIZE, MF_BYCOMMAND);
	}
	void GameWindow::SetSize(const Vector2i& size)
	{
		size_ = size;

		std::stringstream ss;
		ss << "mode con lines=" << size_.Y << " cols=" << size_.X;

		system(ss.str().c_str());

		DeleteMenu(GetSystemMenu(GetConsoleWindow(), false), SC_MINIMIZE, MF_BYCOMMAND);
		DeleteMenu(GetSystemMenu(GetConsoleWindow(), false), SC_MAXIMIZE, MF_BYCOMMAND);
		DeleteMenu(GetSystemMenu(GetConsoleWindow(), false), SC_SIZE, MF_BYCOMMAND);
	}
	void GameWindow::InitDebugMode(bool debugMode)
	{
		if (!endOfInit_)
			debugMode_ = debugMode;
	}
	void GameWindow::InitFrameRate(uint frameRate)
	{
		if (!endOfInit_)
			frameRate_ = frameRate;
	}
	void GameWindow::Exit()
	{
		isOpen_ = false;
	}
	void GameWindow::Initialize()
	{
		isOpen_ = true;

		SetConsoleTitleA(title_.c_str());

		std::stringstream ss;
		ss << "mode con lines=" << size_.Y << " cols=" << size_.X;

		system(ss.str().c_str());

		DeleteMenu(GetSystemMenu(GetConsoleWindow(), false), SC_MINIMIZE, MF_BYCOMMAND);
		DeleteMenu(GetSystemMenu(GetConsoleWindow(), false), SC_MAXIMIZE, MF_BYCOMMAND);
		DeleteMenu(GetSystemMenu(GetConsoleWindow(), false), SC_SIZE, MF_BYCOMMAND);

		DWORD dwMode = 0;
		HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

		GetConsoleMode(hOut, &dwMode);
		dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
		SetConsoleMode(hOut, dwMode);

		endOfInit_ = true;
	}
	void GameWindow::Update(float deltaTime)
	{
		// erase things
	}
}