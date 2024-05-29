#include <maths/vec2i.h>
#include <maths/vec2f.h>
#include <gtest/gtest.h>
#include <SFML/System/Vector2.hpp>

struct Vec2iOperationFixture :
	public ::testing::TestWithParam<std::pair<core::Vec2i, core::Vec2i>>
{

};

TEST_P(Vec2iOperationFixture, Add)
{
	auto [v1, v2] = GetParam();
	const auto result = v1 + v2;
	EXPECT_EQ(result.x, v1.x + v2.x);
	EXPECT_EQ(result.y, v1.y + v2.y);
}

TEST_P(Vec2iOperationFixture, Sub)
{
	auto [v1, v2] = GetParam();
	const auto result = v1 - v2;
	EXPECT_EQ(result.x, v1.x - v2.x);
	EXPECT_EQ(result.y, v1.y - v2.y);

	const auto neg1 = -v1;
	const auto neg2 = -v2;
	EXPECT_EQ(neg1.x, -v1.x);
	EXPECT_EQ(neg1.y, -v1.y);
	EXPECT_EQ(neg2.x, -v2.x);
	EXPECT_EQ(neg2.y, -v2.y);
}

TEST_P(Vec2iOperationFixture, Dot)
{
	auto [v1, v2] = GetParam();
	const auto result = core::Vec2i::Dot(v1, v2);
	EXPECT_EQ(result, v1.x * v2.x + v1.y * v2.y);
}

TEST_P(Vec2iOperationFixture, Div)
{
	auto [v1, v2] = GetParam();
	if (v2.x != 0 || v2.y != 0)
	{
		const auto result = core::Vec2i::Div(v1, v2);
		EXPECT_FLOAT_EQ(result, v1.x / v2.x + v1.y / v2.y);
	}
	else
	{
		std::cout << "Impossible" << std::endl;
	}
}

TEST_P(Vec2iOperationFixture, Perpendicular)
{
	auto [v1, v2] = GetParam();
	const auto p1 = v1.Perpendicular();
	const auto p2 = v2.Perpendicular();
	EXPECT_EQ(core::Vec2i::Dot(v1, p1), 0);
	EXPECT_EQ(core::Vec2i::Dot(v2, p2), 0);

	const auto r1 = v1.Perpendicular2();
	const auto r2 = v2.Perpendicular2();
	EXPECT_EQ(core::Vec2i::Dot(v1, r1), 0);
	EXPECT_EQ(core::Vec2i::Dot(v2, r2), 0);
}

TEST_P(Vec2iOperationFixture, Lerp)
{
	auto [v1, t] = GetParam();
	const auto result = core::Vec2i::Lerp(v1, t.x);
	EXPECT_FLOAT_EQ(result, v1.x * (1 - t.x) + v1.y * t.x);
}

TEST_P(Vec2iOperationFixture, Magnitude)
{
	auto [v1, v2] = GetParam();
	if (v1.x != NULL || v1.y != NULL || v2.x != NULL || v2.y != NULL)
	{
		const auto result = core::Vec2i::Magnitude(v1, v2);
		EXPECT_FLOAT_EQ(result, std::sqrt(v1.x * v2.x + v1.y * v2.y));
	}
	else
	{
		std::cout << "Rien" << std::endl;
	}
}

INSTANTIATE_TEST_SUITE_P(AllNumbers,
	Vec2iOperationFixture,
	testing::Values(
		std::pair{ core::Vec2i{1,3}, core::Vec2i{2,-4} },
		std::pair{ core::Vec2i{-10, 15}, core::Vec2i{-25, -35} },
		std::pair{ core::Vec2i{0, 0}, core::Vec2i{0, 0} },
		std::pair{ core::Vec2i{}, core::Vec2i{} },
		std::pair{ core::Vec2i{1, 2}, core::Vec2i{} },
		std::pair{ core::Vec2i{}, core::Vec2i{1, 2} }
	)
);


struct Vec2fOperationFixture :
	public ::testing::TestWithParam<std::pair<core::Vec2f, core::Vec2f>>
{

};

TEST_P(Vec2fOperationFixture, Add)
{
	auto [v1, v2] = GetParam();
	const auto result = v1 + v2;
	EXPECT_FLOAT_EQ(result.x, v1.x + v2.x);
	EXPECT_FLOAT_EQ(result.y, v1.y + v2.y);
}

TEST_P(Vec2fOperationFixture, Sub)
{
	auto [v1, v2] = GetParam();
	const auto result = v1 - v2;
	EXPECT_FLOAT_EQ(result.x, v1.x - v2.x);
	EXPECT_FLOAT_EQ(result.y, v1.y - v2.y);

	const auto neg1 = -v1;
	const auto neg2 = -v2;
	EXPECT_FLOAT_EQ(neg1.x, -v1.x);
	EXPECT_FLOAT_EQ(neg1.y, -v1.y);
	EXPECT_FLOAT_EQ(neg2.x, -v2.x);
	EXPECT_FLOAT_EQ(neg2.y, -v2.y);
}

TEST_P(Vec2fOperationFixture, Dot)
{
	auto [v1, v2] = GetParam();
	const auto result = core::Vec2f::Dot(v1, v2);
	EXPECT_FLOAT_EQ(result, v1.x * v2.x + v1.y * v2.y);
}

TEST_P(Vec2fOperationFixture, Div)
{
	auto [v1, v2] = GetParam();
	if (v2.x != 0 || v2.y != 0)
	{
		const auto result = core::Vec2f::Div(v1, v2);
		EXPECT_FLOAT_EQ(result, v1.x / v2.x + v1.y / v2.y);
	}
	else
	{
		std::cout << "Impossible" << std::endl;
	}
}

TEST_P(Vec2fOperationFixture, Perpendicular)
{
	auto [v1, v2] = GetParam();
	const auto p1 = v1.Perpendicular();
	const auto p2 = v2.Perpendicular();
	EXPECT_FLOAT_EQ(core::Vec2f::Dot(v1, p1), 0);
	EXPECT_FLOAT_EQ(core::Vec2f::Dot(v2, p2), 0);

	const auto r1 = v1.Perpendicular2();
	const auto r2 = v2.Perpendicular2();
	EXPECT_FLOAT_EQ(core::Vec2f::Dot(v1, r1), 0);
	EXPECT_FLOAT_EQ(core::Vec2f::Dot(v2, r2), 0);
}

TEST_P(Vec2fOperationFixture, Lerp)
{
	auto [v1, t] = GetParam();
	const auto result = core::Vec2f::Lerp(v1, t.x);
	EXPECT_FLOAT_EQ(result, v1.x * (1 - t.x) + v1.y * t.x);
}

TEST_P(Vec2fOperationFixture, Magnitude)
{
	auto [v1, v2] = GetParam();
	if (v1.x != NULL || v1.y != NULL || v2.x != NULL || v2.y != NULL)
	{
		const auto result = core::Vec2f::Magnitude(v1, v2);
		EXPECT_FLOAT_EQ(result, std::sqrt(v1.x * v2.x + v1.y * v2.y));
	}
	else
	{
		std::cout << "Rein" << std::endl;
	}
}

INSTANTIATE_TEST_SUITE_P(AllNumbers,
	Vec2fOperationFixture,
	testing::Values(
		std::pair{ core::Vec2f{1.5f,3.2f}, core::Vec2f{2.3f,-4.1f} },
		std::pair{ core::Vec2f{-10.2f, 15.2f}, core::Vec2f{-25.2f, -35.3f} },
		std::pair{ core::Vec2f{0.0f, 0.0f}, core::Vec2f{0.0f, 0.0f} },
		std::pair{ core::Vec2f{}, core::Vec2f{} },
		std::pair{ core::Vec2f{1.2f, 2.1f}, core::Vec2f{} },
		std::pair{ core::Vec2f{}, core::Vec2f{1.2f, 2.1f} }
	)
);