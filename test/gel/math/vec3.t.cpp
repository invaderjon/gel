// vec3.t.cpp
#include <gel/math/vec.h>
#include <gtest/gtest.h>

TEST( TVec3, Construction )
{
    using namespace gel::math;

    Vec3 v;
    EXPECT_TRUE( ( v.x == v.y ) && ( v.y == v.z ) && ( v.z == 0 ) );

    v = Vec3( v );
    EXPECT_TRUE( ( v.x == v.y ) && ( v.y == v.z ) && ( v.z == 0 ) );

    v = Vec3( 1 );
    EXPECT_TRUE( ( v.x == v.y ) && ( v.y == v.z ) && ( v.z == 1 ) );

    v = Vec3( 1, 2, 3 );
    EXPECT_TRUE( v.x == 1 && v.y == 2 && v.z == 3 );

    // todo: vec2 and vec3 upgrades

    v = Vec3( TVec3<int>( 1 ) );
    EXPECT_TRUE( ( v.x == v.y ) && ( v.y == v.z ) && ( v.z == 1 ) );
}

TEST( TVec3, ArithmeticUrnaryOperators )
{
    using namespace gel::math;

    Vec3 u( 1, 2, 3 );
    Vec3 v( 1, 2, 3 );

    v += 5;
    ASSERT_TRUE( v.x == 6 && v.y == 7 && v.z == 8 );

    v += u;
    ASSERT_TRUE( v.x == 7 && v.y == 9 && v.z == 11 );

    v -= 5;
    ASSERT_TRUE( v.x == 2 && v.y == 4 && v.z == 6 );

    v -= u;
    ASSERT_TRUE( v.x == 1 && v.y == 2 && v.z == 3 );

    v *= 5;
    ASSERT_TRUE( v.x == 5 && v.y == 10 && v.z == 15 );

    v /= 5;
    ASSERT_TRUE( v.x == 1 && v.y == 2 && v.z == 3 );

    v *= u;
    ASSERT_TRUE( v.x == 1 && v.y == 4 && v.z == 9 );

    v /= u;
    ASSERT_TRUE( v.x == 1 && v.y == 2 && v.z == 3 );

    v++;
    ASSERT_TRUE( v.x == 2 && v.y == 3 && v.z == 4 );

    ++v;
    ASSERT_TRUE( v.x == 3 && v.y == 4 && v.z == 5 );

    v--;
    ASSERT_TRUE( v.x == 2 && v.y == 3 && v.z == 4 );

    --v;
    ASSERT_TRUE( v.x == 1 && v.y == 2 && v.z == 3 );

    v = -v;
    ASSERT_TRUE( v.x == -1 && v.y == -2 && v.z == -3 );

    v = -v;
    ASSERT_TRUE( v.x == 1 && v.y == 2 && v.z == 3 );
}

TEST( TVec3, BitwiseUrnaryOperators )
{
    using namespace gel::math;

    TVec3<int> u( 1, 0, 1 );
    TVec3<int> v( 0, 1, 1 );
    TVec3<int> r( 1, 0, 1 );

    ASSERT_EQ( TVec3<int>( 0, 0, 0 ), u &= 0 );
    u = r;

    ASSERT_EQ( TVec3<int>( 0, 0, 1 ), u &= v );
    u = r;

    ASSERT_EQ( TVec3<int>( 1, 1, 1 ), u |= 1 );
    u = r;

    ASSERT_EQ( TVec3<int>( 1, 1, 1 ), u |= v );
    u = r;

    ASSERT_EQ( TVec3<int>( 0, 1, 0 ), u ^= 1 );
    u = r;

    ASSERT_EQ( TVec3<int>( 1, 1, 0 ), u ^= v );
    u = r;

    ASSERT_EQ( TVec3<int>( 2, 0, 2 ), u <<= 1 );
    ASSERT_EQ( TVec3<int>( 1, 0, 1 ), u >>= 1 );
    u = r;

    ASSERT_EQ( TVec3<int>( ~1, ~0, ~1 ), ~u );
}

TEST( TVec3, AccessOperators )
{
    using namespace gel::math;

    Vec3 v( 1, 2, 3 );
    ASSERT_TRUE( v[0] == 1 && v[1] == 2 && v[2] == 3 );

    v[0] = 5;
    ASSERT_EQ( 5, v[0] );
}

TEST( TVec3, ArithmeticBinaryOperators )
{
    using namespace gel::math;

    Vec3 u( 1, 2, 3 );
    Vec3 v( 1, 2, 3 );

    v =  v + 5;
    ASSERT_TRUE( v.x == 6 && v.y == 7 && v.z == 8 );

    v = v + u;
    ASSERT_TRUE( v.x == 7 && v.y == 9 && v.z == 11 );

    v = v - 5;
    ASSERT_TRUE( v.x == 2 && v.y == 4 && v.z == 6 );

    v = v - u;
    ASSERT_TRUE( v.x == 1 && v.y == 2 && v.z == 3 );

    v = v * 5;
    ASSERT_TRUE( v.x == 5 && v.y == 10 && v.z == 15 );

    v = 5 * v;
    ASSERT_TRUE( v.x == 25 && v.y == 50 && v.z == 75 );

    v = v / 5;
    ASSERT_TRUE( v.x == 5 && v.y == 10 && v.z == 15 );

    v = v / 5;
    ASSERT_TRUE( v.x == 1 && v.y == 2 && v.z == 3 );

    v = 5 / v;
    ASSERT_TRUE( v.x == 5.0f && v.y == 5.0f/2.0f && v.z == 5.0f/3.0f );

    v = 5 / v;
    ASSERT_TRUE( v.x == 1 && v.y == 2 && v.z == 3 );

    v = v * u;
    ASSERT_TRUE( v.x == 1 && v.y == 4 && v.z == 9 );

    v = v / u;
    ASSERT_TRUE( v.x == 1 && v.y == 2 && v.z == 3 );
}

TEST( TVec3, BitwiseBinaryOperators )
{
    using namespace gel::math;

    TVec3<long long> u( 1, 0, 1 );
    TVec3<long long> v( 0, 1, 1 );

    ASSERT_EQ( TVec3<int>( 0, 0, 0 ), u & 0 );
    ASSERT_EQ( TVec3<int>( 0, 0, 1 ), u & v );
    ASSERT_EQ( TVec3<int>( 1, 1, 1 ), u | 1 );
    ASSERT_EQ( TVec3<int>( 1, 1, 1 ), u | v );
    ASSERT_EQ( TVec3<int>( 0, 1, 0 ), u ^ 1 );
    ASSERT_EQ( TVec3<int>( 1, 1, 0 ), u ^ v );
    ASSERT_EQ( TVec3<int>( 2, 0, 2 ), u << 1 );
    ASSERT_EQ( TVec3<int>( 1, 0, 1 ), TVec3<int>( 2, 0, 2 ) >> 1 );
}

TEST( TVec3, ComparisonOperators )
{
    using namespace gel::math;

    Vec3 u( 1, 0, 1 );
    TVec3<int> v( 0, 1, 1 );

    ASSERT_TRUE( u == u );
    ASSERT_FALSE( u == v );

    ASSERT_TRUE( u != v );
    ASSERT_FALSE( u != u );
}

TEST( TRef3, Construction )
{
    using namespace gel::math;

    TVec3<float> u( 0, 1, 2 );
    TVec3<float> v( 1, 2, 3 );

    TRef3<float> i( u );
    TRef3<float> j( v );
    TRef3<float> k( i );
}

TEST( TRef3, Comparison )
{
    using namespace gel::math;

    TVec3<float> u( 0, 1, 2 );
    TVec3<int> v( 1, 2, 3 );

    TRef3<float> i( u );
    TRef3<int> j( v );

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