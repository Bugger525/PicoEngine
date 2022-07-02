#include "../Math.h"

namespace PE
{
	bool Vector2i::operator==(const Vector2i& vec)
	{
		return (X == vec.X) && (Y == vec.Y);
	}
	bool Vector2i::operator<(const Vector2i& vec)
	{
		return (X < vec.X) && (Y < vec.Y);
	}
	bool Vector2i::operator>(const Vector2i& vec)
	{
		return (X > vec.X) && (Y > vec.Y);
	}
	bool Vector2i::operator<=(const Vector2i& vec)
	{
		return (X <= vec.X) && (Y <= vec.Y);
	}
	bool Vector2i::operator>=(const Vector2i& vec)
	{
		return (X >= vec.X) && (Y >= vec.Y);
	}
	Vector2i& Vector2i::operator+(Vector2i& vec)
	{
		auto v = Vector2i{ X + vec.X, Y + vec.Y };
		return v;
	}
}