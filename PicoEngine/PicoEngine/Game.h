#pragma once

#include <string>
#include <vector>
#include <memory>
#include "Math.h"
#include "Graphics.h"

namespace PE
{
	class GameWindow;

	class Object
	{
	public:
		Object(int x = 0, int y = 0, int width = 1, int height = 1);
		Object(const Vector2i& position, const Vector2i& size);

		const Vector2i& GetPosition() const;
		void SetPosition(int x, int y);
		void SetPosition(const Vector2i& position);

		const Vector2i& GetSize() const;
		void SetSize(int x, int y);
		void SetSize(const Vector2i& size);

		const Texture& GetTexture() const;
		void SetTexture(const Texture& texture);
		void SetTexture(const std::vector<StyledString>& styledStrVector);
		void SetTexture(const std::vector<std::string>& strVector);
	protected:
		Vector2i position_;
		Vector2i size_;
		Texture texture_;
	};
	class RigidBody : public Object
	{
	public:
		RigidBody(int x = 0, int y = 0, int width = 1, int height = 1);
		RigidBody(const Vector2i& position, const Vector2i& size);

		const Vector2i& GetVelocity() const;
		void SetVelocity(int x, int y);
		void SetVelocity(const Vector2i& velocity);

		void AddForce(int x, int y);
		void AddForce(const Vector2i& force);
	private:
		Vector2i velocity_;
	};
	class Camera
	{
	public:
		Camera(int x, int y, int width, int height);
		Camera(const Vector2i& position, const Vector2i& size);

		const Vector2i& GetPosition() const;
		void SetPosition(int x, int y);
		void SetPosition(const Vector2i& position);

		const Vector2i& GetSize() const;
		void SetSize(int x, int y);
		void SetSize(const Vector2i& size);
	private:
		Vector2i position_;
		Vector2i size_;
	};
	void Sleep(int seconds);
}