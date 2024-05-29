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

		constexpr Vec2f operator*(float t)
		{
			return { x * t,y * t };
		}
		constexpr Vec2f operator/(float t)
		{
			return { x / t,y / t };
		}

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
		float Magnitude() const
		{
			const float result = std::sqrt(x * x + y * y);
			return result;
		}

		float MagnitudeSqu() const
		{
			const float result = x * x + y * y;
			return result;
		}

		Vec2f Normalise()
		{
			const float man = Magnitude();
			if (man == 0)
			{
				std::cout << "Imposible" << std::endl;
				return Vec2f(0, 0);
			}
			return *this / man;
		}

	}; // struct Vec2i

	/*constexpr Vec2f operator/(Vec2f v1, float t)
	{
		return { t / v1.x,t / v1.y };
	}*/

} // namespace core





#endif  //CORE_MATHS_VEC2F.H_