// vec4.t.cpp
#include <gel/math/vec.h>
#include <gtest/gtest.h>

TEST( TVec4, Construction )
{
    using namespace gel::math;

    Vec4 v;
    EXPECT_TRUE( ( v.x == v.y ) && ( v.y == v.z ) && ( v.z == v.w ) && ( v.w == 0 ) );

    v = Vec4( v );
    EXPECT_TRUE( ( v.x == v.y ) && ( v.y == v.z ) && ( v.z == v.w ) && ( v.w == 0 ) );

    v = Vec4( 1 );
    EXPECT_TRUE( ( v.x == v.y ) && ( v.y == v.z ) && ( v.z == v.w ) && ( v.w == 1 ) );

    v = Vec4( 1, 2, 3, 4 );
    EXPECT_TRUE( v.x == 1 && v.y == 2 && v.z == 3 && v.w == 4 );

    // todo: vec2 and vec3 upgrades

    v = Vec4( TVec4<int>( 1 ) );
    EXPECT_TRUE( ( v.x == v.y ) && ( v.y == v.z ) && ( v.z == v.w ) && ( v.w == 1 ) );
}

TEST( TVec4, ArithmeticUrnaryOperators )
{
    using namespace gel::math;

    Vec4 u( 1, 2, 3, 4 );
    Vec4 v( 1, 2, 3, 4 );

    v += 5;
    ASSERT_TRUE( v.x == 6 && v.y == 7 && v.z == 8 && v.w == 9 );

    v += u;
    ASSERT_TRUE( v.x == 7 && v.y == 9 && v.z == 11 && v.w == 13 );

    v -= 5;
    ASSERT_TRUE( v.x == 2 && v.y == 4 && v.z == 6 && v.w == 8 );

    v -= u;
    ASSERT_TRUE( v.x == 1 && v.y == 2 && v.z == 3 && v.w == 4 );

    v *= 5;
    ASSERT_TRUE( v.x == 5 && v.y == 10 && v.z == 15 && v.w == 20 );

    v /= 5;
    ASSERT_TRUE( v.x == 1 && v.y == 2 && v.z == 3 && v.w == 4 );

    v *= u;
    ASSERT_TRUE( v.x == 1 && v.y == 4 && v.z == 9 && v.w == 16 );

    v /= u;
    ASSERT_TRUE( v.x == 1 && v.y == 2 && v.z == 3 && v.w == 4 );

    v++;
    ASSERT_TRUE( v.x == 2 && v.y == 3 && v.z == 4 && v.w == 5 );

    ++v;
    ASSERT_TRUE( v.x == 3 && v.y == 4 && v.z == 5 && v.w == 6 );

    v--;
    ASSERT_TRUE( v.x == 2 && v.y == 3 && v.z == 4 && v.w == 5 );

    --v;
    ASSERT_TRUE( v.x == 1 && v.y == 2 && v.z == 3 && v.w == 4 );

    v = -v;
    ASSERT_TRUE( v.x == -1 && v.y == -2 && v.z == -3 && v.w == -4 );

    v = -v;
    ASSERT_TRUE( v.x == 1 && v.y == 2 && v.z == 3 && v.w == 4 );
}

TEST( TVec4, BitwiseUrnaryOperators )
{
    using namespace gel::math;

    TVec4<int> u( 1, 0, 1, 0 );
    TVec4<int> v( 0, 1, 1, 0 );
    TVec4<int> r( 1, 0, 1, 0 );

    ASSERT_EQ( TVec4<int>( 0, 0, 0, 0 ), u &= 0 );
    u = r;

    ASSERT_EQ( TVec4<int>( 0, 0, 1, 0 ), u &= v );
    u = r;

    ASSERT_EQ( TVec4<int>( 1, 1, 1, 1 ), u |= 1 );
    u = r;

    ASSERT_EQ( TVec4<int>( 1, 1, 1, 0 ), u |= v );
    u = r;

    ASSERT_EQ( TVec4<int>( 0, 1, 0, 1 ), u ^= 1 );
    u = r;

    ASSERT_EQ( TVec4<int>( 1, 1, 0, 0 ), u ^= v );
    u = r;

    ASSERT_EQ( TVec4<int>( 2, 0, 2, 0 ), u <<= 1 );
    ASSERT_EQ( TVec4<int>( 1, 0, 1, 0 ), u >>= 1 );
    u = r;

    ASSERT_EQ( TVec4<int>( ~1, ~0, ~1, ~0 ), ~u );
}

TEST( TVec4, AccessOperators )
{
    using namespace gel::math;

    Vec4 v( 1, 2, 3, 4 );
    ASSERT_TRUE( v[0] == 1 && v[1] == 2 && v[2] == 3 && v[3] == 4 );

    v[0] = 5;
    ASSERT_EQ( 5, v[0] );
}

TEST( TVec4, ArithmeticBinaryOperators )
{
    using namespace gel::math;

    Vec4 u( 1, 2, 3, 4 );
    Vec4 v( 1, 2, 3, 4 );

    v =  v + 5.0f;
    ASSERT_TRUE( v.x == 6 && v.y == 7 && v.z == 8 && v.w == 9 );

    v = v + u;
    ASSERT_TRUE( v.x == 7 && v.y == 9 && v.z == 11 && v.w == 13 );

    v = v - 5.0f;
    ASSERT_TRUE( v.x == 2 && v.y == 4 && v.z == 6 && v.w == 8 );

    v = v - u;
    ASSERT_TRUE( v.x == 1 && v.y == 2 && v.z == 3 && v.w == 4 );

    v = v * 5.0f;
    ASSERT_TRUE( v.x == 5 && v.y == 10 && v.z == 15 && v.w == 20 );

    v = 5.0f * v;
    ASSERT_TRUE( v.x == 25 && v.y == 50 && v.z == 75 && v.w == 100 );

    v = v / 5.0f;
    ASSERT_TRUE( v.x == 5 && v.y == 10 && v.z == 15 && v.w == 20 );

    v = v / 5.0f;
    ASSERT_TRUE( v.x == 1 && v.y == 2 && v.z == 3 && v.w == 4 );

    v = 5.0f / v;
    ASSERT_TRUE( v.x == 5.0f && v.y == 5.0f/2.0f && v.z == 5.0f/3.0f && v.w == 5.0f/4.0f );

    v = 5.0f / v;
    ASSERT_TRUE( v.x == 1 && v.y == 2 && v.z == 3 && v.w == 4 );

    v = v * u;
    ASSERT_TRUE( v.x == 1 && v.y == 4 && v.z == 9 && v.w == 16 );

    v = v / u;
    ASSERT_TRUE( v.x == 1 && v.y == 2 && v.z == 3 && v.w == 4 );
}

TEST( TVec4, BitwiseBinaryOperators )
{
    using namespace gel::math;

    TVec4<int> u( 1, 0, 1, 0 );
    TVec4<int> v( 0, 1, 1, 0 );

    ASSERT_EQ( TVec4<int>( 0, 0, 0, 0 ), u & 0 );
    ASSERT_EQ( TVec4<int>( 0, 0, 1, 0 ), u & v );
    ASSERT_EQ( TVec4<int>( 1, 1, 1, 1 ), u | 1 );
    ASSERT_EQ( TVec4<int>( 1, 1, 1, 0 ), u | v );
    ASSERT_EQ( TVec4<int>( 0, 1, 0, 1 ), u ^ 1 );
    ASSERT_EQ( TVec4<int>( 1, 1, 0, 0 ), u ^ v );
    ASSERT_EQ( TVec4<int>( 2, 0, 2, 0 ), u << 1 );
    ASSERT_EQ( TVec4<int>( 1, 0, 1, 0 ), TVec4<int>( 2, 0, 2, 0 ) >> 1 );
}

TEST( TVec4, ComparisonOperators )
{
    using namespace gel::math;

    Vec4 u( 1, 0, 1, 0 );
    Vec4 v( 0, 1, 1, 0 );

    ASSERT_TRUE( u == u );
    ASSERT_FALSE( u == v );

    ASSERT_TRUE( u != v );
    ASSERT_FALSE( u != u );
}

TEST( TRef4, Construction )
{
    using namespace gel::math;

    TVec4<float> u( 0, 1, 2, 3 );
    TVec4<float> v( 1, 2, 3, 4 );

    TRef4<float> i( u );
    TRef4<float> j( v );
    TRef4<float> k( i );
}

TEST( TRef4, Comparison )
{
    using namespace gel::math;

    TVec4<float> u( 0, 1, 2, 3 );
    TVec4<float> v( 1, 2, 3, 4 );

    TRef4<float> i( u );
    TRef4<float> j( v );

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