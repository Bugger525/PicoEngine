#include "../Game.h"
#include "../GameWindow.h"
#include <Windows.h>

namespace PE
{
	Object::Object(int x, int y, int width, int height)
	{
		position_ = { x, y };
		size_ = { width, height };
	}
	Object::Object(const Vector2i& position, const Vector2i& size)
	{
		position_ = position;
		size_ = size;
	}
	const Vector2i& Object::GetPosition() const
	{
		return position_;
	}
	void Object::SetPosition(int x, int y)
	{
		position_ = { x, y };
	}
	void Object::SetPosition(const Vector2i& position)
	{
		position_ = position;
	}
	const Vector2i& Object::GetSize() const
	{
		return size_;
	}
	void Object::SetSize(int x, int y)
	{
		size_ = { x, y };
	}
	void Object::SetSize(const Vector2i& size)
	{
		size_ = size;
	}
	const Texture& Object::GetTexture() const
	{
		return texture_;
	}
	void Object::SetTexture(const Texture& texture)
	{
		texture_ = texture;
	}
	void Object::SetTexture(const std::vector<StyledString>& styledStrVector)
	{
		for (auto i = 0; i < styledStrVector.size(); i++)
		{
			texture_[i] = styledStrVector[i];
		}
	}
	void Object::SetTexture(const std::vector<std::string>& strVector)
	{
		texture_.Set(strVector);
	}
	RigidBody::RigidBody(int x, int y, int width, int height)
		: Object(x, y, width, height)
	{
	}
	RigidBody::RigidBody(const Vector2i& position, const Vector2i& size)
		: Object(position, size)
	{
	}
	const Vector2i& RigidBody::GetVelocity() const
	{
		return velocity_;
	}
	void RigidBody::SetVelocity(int x, int y)
	{
		velocity_ = { x, y };
	}
	void RigidBody::SetVelocity(const Vector2i& velocity)
	{
		velocity_ = velocity;
	}
	void RigidBody::AddForce(int x, int y)
	{
		velocity_.X += x;
		velocity_.Y += y;
	}
	void RigidBody::AddForce(const Vector2i& force)
	{
		velocity_.X += force.X;
		velocity_.Y += force.Y;
	}
	Camera::Camera(int x, int y, int width, int height)
	{
		position_ = { x, y };
		size_ = { width, height };
	}
	Camera::Camera(const Vector2i& position, const Vector2i& size)
	{
		position_ = position;
		size_ = size;
	}
	const Vector2i& Camera::GetPosition() const
	{
		return position_;
	}
	void Camera::SetPosition(int x, int y)
	{
		position_ = { x, y };
	}
	void Camera::SetPosition(const Vector2i& position)
	{
		position_ = position;
	}
	const Vector2i& Camera::GetSize() const
	{
		return size_;
	}
	void Camera::SetSize(int x, int y)
	{
		size_ = { x, y };
	}
	void Camera::SetSize(const Vector2i& size)
	{
		size_ = size;
	}
	void Sleep(int seconds)
	{
		::Sleep(seconds);
	}
}