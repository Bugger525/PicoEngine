#pragma once

namespace PE
{
	using uint = unsigned int;

	struct Vector2i
	{
		int X = 0;
		int Y = 0;

		bool operator==(const Vector2i& vec);
		bool operator>(const Vector2i& vec);
		bool operator<(const Vector2i& vec);
		bool operator>=(const Vector2i& vec);
		bool operator<=(const Vector2i& vec);

		Vector2i& operator+(Vector2i& vec);
	};
}