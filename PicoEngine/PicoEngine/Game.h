#pragma once

#include <string>
#include "Math.h"

namespace PE
{
	class Game
	{
	public:
		Game();

		void Run();
	protected:
		const std::string GetTitle() const;
		void InitTitle(const std::string& title);
		void SetTitle(const std::string& title);

		const Vector2i& GetSize() const;
		void InitSize(uint width, uint height);
		void SetSize(uint width, uint height);
		void SetSize(const Vector2i& size);

		void InitDebugMode(bool debugMode);

		void InitFrameRate(uint frameRate);

		void Exit();

		virtual void Initialize();
		virtual void Update(float deltaTime) = 0;
		virtual void Render(float deltaTime) = 0;
		virtual void Cleanup() = 0;
	private:
		std::string title_;
		Vector2i size_;
		bool isOpen_;
		bool debugMode_;
		uint frameRate_;
	};
}

using base = PE::Game;