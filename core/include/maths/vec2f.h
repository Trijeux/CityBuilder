#ifndef CORE_MATHS_VEC2F_H_
#define CORE_MATHS_VEC2F_H_

namespace core
{
	/**
	 * \brief Vec2f is a mathematical object represented
	 */

	 //Add constructor template

	struct Vec2f
	{
		float x = 0, y = 0;

		constexpr Vec2f operator+(Vec2f other) const
		{
			return { x + other.x, y + other.y };
		}

		constexpr Vec2f operator-(Vec2f other) const
		{
			return { x - other.x, y - other.y };
		}

		constexpr Vec2f operator-() const
		{
			return { -x, -y };
		}
		static constexpr float Dot(Vec2f v1, Vec2f v2)
		{
			return v1.x * v2.x + v1.y * v2.y;
		}

		//static constexpr float DotSca(Vec2f v1, Vec2f v2)
		//{
		//	//demander au prof
		//}

		static constexpr float Div(Vec2f v1, Vec2f v2)
		{
				return v1.x / v2.x + v1.y / v2.y;
		}

		//static constexpr float DivSca(Vec2f v1, Vec2f v2)
		//{
		//	//demander au prof
		//}

		constexpr Vec2f Perpendicular() const
		{
			return { -y, x };
		}
		constexpr Vec2f Perpendicular2() const
		{
			return { y, -x };
		}
		static constexpr float Lerp(Vec2f v1, float t)
		{
			return v1.x * (1 - t) + v1.y * t;
		}
		static float Magnitude(Vec2f v1, Vec2f v2) 
		{
			float result = std::sqrt(v1.x * v2.x + v1.y * v2.y);
			return result;
		}

		//static constexpr float normalise()
		//{
		//	//Demander au prof
		//}

	}; // struct Vec2i

} // namespace core





#endif  //CORE_MATHS_VEC2F.H_