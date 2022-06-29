#pragma once

#include <string>
#include <vector>
#include <memory>
#include "Math.h"
#include "Graphics.h"

namespace PE
{
	class Object
	{
	public:
		Object(const std::string& name);

		const std::string GetName() const;
		void SetName(const std::string& name);

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
		std::string name_;
		Vector2i position_;
		Vector2i size_;
		Texture texture_;
	};
	class RigidBody : public Object
	{
	public:
		RigidBody(const std::string& name);

		const Vector2i& GetVelocity() const;
		void SetVelocity(int x, int y);
		void SetVelocity(const Vector2i& velocity);

		void AddForce(int x, int y);
		void AddForce(const Vector2i& force);
	private:
		Vector2i velocity_;
	};
	class Scene
	{
	public:

	private:
		std::vector<Object> objects_;
	};
	class Camera
	{

	};
	void Sleep(int seconds);
}