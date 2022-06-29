#pragma once

#include <string>
#include "Math.h"

namespace PE
{
	class Object
	{
	public:
		Object(const std::string& name);
	private:
		std::string name_;
		Vector2i position_;
		Vector2i size_;
	};
	class Scene
	{

	};
	class World
	{

	};
	class Camera
	{

	};
	void Sleep(int seconds);
}