// vec2.t.cpp
#include <gel/math/vec.h>
#include <gtest/gtest.h>

TEST( TVec2, Construction )
{
    using namespace gel::math;

    Vec2 v;
    EXPECT_TRUE( ( v.x == v.y ) && ( v.y == 0) );

    v = Vec2( v );
    EXPECT_TRUE( ( v.x == v.y ) && ( v.y == 0 ) );

    v = Vec2( 1 );
    EXPECT_TRUE( ( v.x == v.y ) && ( v.y == 1 ) );

    v = Vec2( 1, 2 );
    EXPECT_TRUE( v.x == 1 && v.y == 2 );

    // todo: vec2 and vec3 upgrades

    v = Vec2( TVec2<int>( 1 ) );
    EXPECT_TRUE( ( v.x == v.y ) && ( v.y == 1 ) );
}

TEST( TVec2, ArithmeticUrnaryOperators )
{
    using namespace gel::math;

    Vec2 u( 1, 2 );
    Vec2 v( 1, 2 );

    v += 5;
    ASSERT_TRUE( v.x == 6 && v.y == 7 );

    v += u;
    ASSERT_TRUE( v.x == 7 && v.y == 9 );

    v -= 5;
    ASSERT_TRUE( v.x == 2 && v.y == 4 );

    v -= u;
    ASSERT_TRUE( v.x == 1 && v.y == 2 );

    v *= 5;
    ASSERT_TRUE( v.x == 5 && v.y == 10 );

    v /= 5;
    ASSERT_TRUE( v.x == 1 && v.y == 2 );

    v *= u;
    ASSERT_TRUE( v.x == 1 && v.y == 4 );

    v /= u;
    ASSERT_TRUE( v.x == 1 && v.y == 2 );

    v++;
    ASSERT_TRUE( v.x == 2 && v.y == 3 );

    ++v;
    ASSERT_TRUE( v.x == 3 && v.y == 4 );

    v--;
    ASSERT_TRUE( v.x == 2 && v.y == 3 );

    --v;
    ASSERT_TRUE( v.x == 1 && v.y == 2 );

    v = -v;
    ASSERT_TRUE( v.x == -1 && v.y == -2 );

    v = -v;
    ASSERT_TRUE( v.x == 1 && v.y == 2 );
}

TEST( TVec2, BitwiseUrnaryOperators )
{
    using namespace gel::math;

    TVec2<int> u( 1, 0 );
    TVec2<int> v( 0, 1 );
    TVec2<int> r( 1, 0 );

    ASSERT_EQ( TVec2<int>( 0, 0 ), u &= 0 );
    u = r;

    ASSERT_EQ( TVec2<int>( 0, 0 ), u &= v );
    u = r;

    ASSERT_EQ( TVec2<int>( 1, 1 ), u |= 1 );
    u = r;

    ASSERT_EQ( TVec2<int>( 1, 1 ), u |= v );
    u = r;

    ASSERT_EQ( TVec2<int>( 0, 1 ), u ^= 1 );
    u = r;

    ASSERT_EQ( TVec2<int>( 1, 1 ), u ^= v );
    u = r;

    ASSERT_EQ( TVec2<int>( 2, 0 ), u <<= 1 );
    ASSERT_EQ( TVec2<int>( 1, 0 ), u >>= 1 );
    u = r;

    ASSERT_EQ( TVec2<int>( ~1, ~0 ), ~u );
}

TEST( TVec2, AccessOperators )
{
    using namespace gel::math;

    Vec2 v( 1, 2 );
    ASSERT_TRUE( v[0] == 1 && v[1] == 2 );

    v[0] = 5;
    ASSERT_EQ( 5, v[0] );

    EXPECT_DEATH( v[2], "Assertion .* failed" );
}

TEST( TVec2, ArithmeticBinaryOperators )
{
    using namespace gel::math;

    Vec2 u( 1, 2 );
    Vec2 v( 1, 2 );

    v =  v + 5;
    ASSERT_TRUE( v.x == 6 && v.y == 7 );

    v = v + u;
    ASSERT_TRUE( v.x == 7 && v.y == 9 );

    v = v - 5;
    ASSERT_TRUE( v.x == 2 && v.y == 4 );

    v = v - u;
    ASSERT_TRUE( v.x == 1 && v.y == 2 );

    v = v * 5;
    ASSERT_TRUE( v.x == 5 && v.y == 10 );

    v = 5 * v;
    ASSERT_TRUE( v.x == 25 && v.y == 50 );

    v = v / 5;
    ASSERT_TRUE( v.x == 5 && v.y == 10 );

    v = v / 5;
    ASSERT_TRUE( v.x == 1 && v.y == 2 );

    v = 5 / v;
    ASSERT_TRUE( v.x == 5.0f && v.y == 5.0f/2.0f );

    v = 5 / v;
    ASSERT_TRUE( v.x == 1 && v.y == 2 );

    v = v * u;
    ASSERT_TRUE( v.x == 1 && v.y == 4 );

    v = v / u;
    ASSERT_TRUE( v.x == 1 && v.y == 2 );
}

TEST( TVec2, BitwiseBinaryOperators )
{
    using namespace gel::math;

    TVec2<long long> u( 1, 0 );
    TVec2<long long> v( 0, 1 );

    ASSERT_EQ( TVec2<int>( 0, 0 ), u & 0 );
    ASSERT_EQ( TVec2<int>( 0, 0 ), u & v );
    ASSERT_EQ( TVec2<int>( 1, 1 ), u | 1 );
    ASSERT_EQ( TVec2<int>( 1, 1 ), u | v );
    ASSERT_EQ( TVec2<int>( 0, 1 ), u ^ 1 );
    ASSERT_EQ( TVec2<int>( 1, 1 ), u ^ v );
    ASSERT_EQ( TVec2<int>( 2, 0 ), u << 1 );
    ASSERT_EQ( TVec2<int>( 1, 0 ), TVec2<int>( 2, 0 ) >> 1 );
}

TEST( TVec2, ComparisonOperators )
{
    using namespace gel::math;

    Vec2 u( 1, 0 );
    Vec2 v( 0, 1 );

    ASSERT_TRUE( u == u );
    ASSERT_FALSE( u == v );

    ASSERT_TRUE( u != v );
    ASSERT_FALSE( u != u );
}

TEST( TRef2, Construction )
{
    using namespace gel::math;

    TVec2<float> u( 0, 1 );
    TVec2<float> v( 1, 2 );

    TRef2<float> i( u );
    TRef2<float> j( v );
    TRef2<float> k( i );
}

TEST( TRef2, Comparison )
{
    using namespace gel::math;

    TVec2<float> u( 0, 1 );
    TVec2<int> v( 1, 2 );

    TRef2<float> i( u );
    TRef2<int> j( v );

    ASSERT_TRUE( u == i );
    ASSERT_FALSE( u == j );

    ASSERT_TRUE( i == u );
    ASSERT_FALSE( j == u );

    ASSERT_TRUE( i == i );
    ASSERT_FALSE( i == j );

    ASSERT_FALSE( u != i );
    ASSERT_TRUE( u != j );

    ASSERT_FALSE( i != u );
    ASSERT_TRUE( j != u );

    ASSERT_FALSE( i != i );
    ASSERT_TRUE( i != j );
}