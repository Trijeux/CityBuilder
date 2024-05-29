#ifndef CORE_MATHS_VEC2I_H_
#define CORE_MATHS_VEC2I_H_
#include <complex>
#include <gtest/gtest.h>
#include <SFML/System/Vector2.hpp>

namespace core 
{
	/**
	 * \brief Vec2i is a mathematical object represented
	 */

     //Add constructor template

	struct Vec2i
    {
        int x = 0, y = 0;

        constexpr Vec2i operator+(Vec2i other) const
        {
            return { x + other.x, y + other.y };
        }

        constexpr Vec2i operator-(Vec2i other) const
        {
            return { x - other.x, y - other.y };
        }

        constexpr Vec2i operator-() const
        {
            return { -x, -y };
        }
        static constexpr int Dot(Vec2i v1, Vec2i v2)
        {
            return v1.x * v2.x + v1.y * v2.y;
        }

        //static constexpr int DotSca(Vec2i v1, Vec2i v2)
        //{
        //    //demander au prof
        //}

        static constexpr int Div(Vec2i v1, Vec2i v2)
        {
                return v1.x / v2.x + v1.y / v2.y;
        }

        //static constexpr int DivSca(Vec2i v1, Vec2i v2)
        //{
        //    //demander au prof
        //}

        constexpr Vec2i Perpendicular() const
        {
            return { -y, x };
        }
        constexpr Vec2i Perpendicular2() const
        {
            return { y, -x };
        }
        static int Lerp(Vec2i v1, int t)
        {
            return v1.x * (1 - t) + v1.y * t;
        }
		static int Magnitude(Vec2i v1, Vec2i v2)
        {
            int result = std::sqrt(v1.x * v2.x + v1.y * v2.y);
            return result;
        }

        //static constexpr float normalise()
        //{
        //    //Demander au prof
        //}

    }; // struct Vec2i
    
} // namespace core





#endif  //CORE_MATHS_VEC2I.H_