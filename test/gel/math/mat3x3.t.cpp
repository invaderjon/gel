// mat3x3.t.cpp
#include <gel/gelint.h>
#include <gel/math/mat.h>
#include <gtest/gtest.h>

TEST( TMat3x3, Construction )
{
    using namespace gel::math;

    unsigned int i, j;
    Mat3 m;

    for ( i = 0; i < 3; ++i )
    {
        for ( j = 0; j < 3; ++j )
        {
            if ( i != j )
            {
                ASSERT_EQ( 0, Mat3::IDENTITY[i][j] );
            }
            else
            {
                ASSERT_EQ( 1, Mat3::IDENTITY[i][j] );
            }
        }
    }

    ASSERT_EQ( Mat3::IDENTITY, m );
    ASSERT_EQ( Mat3::IDENTITY, m = Mat3( 1 ) );
    ASSERT_EQ( Mat3::ZERO, m = Mat3( 0 ) );
    ASSERT_EQ( Mat3::IDENTITY, Mat3( Mat2::IDENTITY ) );
    ASSERT_EQ( Mat3::IDENTITY, Mat3( Mat4::IDENTITY ) );

    m = Mat3( 0, 1, 2, 3, 4, 5, 6, 7, 8 );

    for ( i = 0; i < 9; ++i )
    {
        ASSERT_EQ( i, m[i % 3][i / 3] );
    }

    m = Mat3( Mat3::Column( 0, 3, 6 ), Mat3::Column( 1, 4, 7 ), Mat3::Column( 2, 5, 8 ) );

    for ( i = 0; i < 9; ++i )
    {
        ASSERT_EQ( i, m[i % 3][i / 3] );
    }
}

TEST( TMat3x3, AccessOperators )
{
    using namespace gel::math;
    Mat3 m;

    EXPECT_EQ( Vec3( 1, 0, 0 ), m[0] );

    m[0] = Vec3( 2, 0, 0 );

    EXPECT_EQ( Vec3( 2, 0, 0 ), m[0] );

    EXPECT_DEATH( m[3], "Assertion .* failed" );
}

TEST( TMat3x3, ArithmeticUnaryOperators )
{
    using namespace gel::math;

    Mat3 m;

    ASSERT_EQ( 3, ( m += 2 )[0][0] );
    ASSERT_EQ( 3, m[1][1] );
    ASSERT_EQ( 3, m[2][2] );


    ASSERT_EQ( 1, ( m -= 2 )[0][0] );
    ASSERT_EQ( 1, m[1][1] );
    ASSERT_EQ( 1, m[2][2] );

    ASSERT_EQ( 2, ( m *= 2 )[0][0] );
    ASSERT_EQ( 2, m[1][1] );
    ASSERT_EQ( 2, m[2][2] );

    ASSERT_EQ( 1, ( m /= 2 )[0][0] );
    ASSERT_EQ( 1, m[1][1] );
    ASSERT_EQ( 1, m[2][2] );

    ASSERT_EQ( 2, ( m++ )[0][0] );
    ASSERT_EQ( 2, m[1][1] );
    ASSERT_EQ( 2, m[2][2] );


    ASSERT_EQ( 1, ( m-- )[0][0] );
    ASSERT_EQ( 1, m[1][1] );
    ASSERT_EQ( 1, m[2][2] );

    ASSERT_EQ( 2, ( ++m )[0][0] );
    ASSERT_EQ( 2, m[1][1] );
    ASSERT_EQ( 2, m[2][2] );


    ASSERT_EQ( 1, ( --m )[0][0] );
    ASSERT_EQ( 1, m[1][1] );
    ASSERT_EQ( 1, m[2][2] );

    m = -m;
    ASSERT_EQ( -1, m[0][0] );
    ASSERT_EQ( -1, m[1][1] );
    ASSERT_EQ( -1, m[2][2] );

    TMat3x3<int> i;
    i *= 5;
    ASSERT_EQ( 1, ( i %= 4 )[0][0] );
    ASSERT_EQ( 1, i[1][1] );
    ASSERT_EQ( 1, i[2][2] );
}

TEST( TMat3x3, ArithmeticMatrixUnaryOperators )
{
    using namespace gel::math;

    Mat3 m( 1, 2, 3, 2, 3, 1, 3, 1, 2 );
    Mat3 n( 3, 1, 2, 2, 3, 1, 1, 2, 3 );
    Mat3 r( 1, 2, 3, 2, 3, 1, 3, 1, 2 );
    Mat3 e;

    e = Mat3( 10, 13, 13, 13, 13, 10, 13, 10, 13 );
    EXPECT_EQ( e, m *= n );
    m = r;

    e = Mat3( 4, 3, 5, 4, 6, 2, 4, 3, 5 );
    EXPECT_EQ( e, m += n );
    m = r;

    e = Mat3( -2, 1, 1, 0, 0, 0, 2, -1, -1 );
    EXPECT_EQ( e, m -= n );
    m = r;

    e = Mat3(  7.0/18.0f,  1.0/18.0f, -5.0/18.0f,
               -5.0/18.0f,  7.0/18.0f,  1.0/18.0f,
                1.0/18.0f, -5.0/18.0f,  7.0/18.0f );
    EXPECT_TRUE( e == Mat::invert( n ) );

    // division is not checked because of rounding errors

    IMat3  x( 5, 5, 5, 7, 7, 7, 11, 11, 11 );
    IMat3  y( 3, 4, 5, 3, 5, 7,  7,  9, 11 );
    IMat3 ie( 2, 1, 0, 1, 2, 0,  4,  2,  0 );
    EXPECT_EQ( ie, x %= y );
}

TEST( TMat3x3, BitwiseUnaryOperators )
{
    using namespace gel::math;
    using namespace gel;

    TMat3x3<int64> m( 1, 1, 1, 0, 0, 0, 1, 0, 1 );
    TMat3x3<int64> n( 1, 1, 1, 0, 0, 0, 0, 1, 1 );
    TMat3x3<int64> r( 1, 1, 1, 0, 0, 0, 1, 0, 1 );
    TMat3x3<int64> e;

    e = TMat3x3<int64>( 0 );
    ASSERT_EQ( e, m &= 0 );
    m = r;

    e = TMat3x3<int64>( 1, 1, 1, 0, 0, 0, 0, 0, 1 );
    ASSERT_EQ( e, m &= n );
    m = r;

    e = TMat3x3<int64>( 1, 1, 1, 1, 1, 1, 1, 1, 1 );
    ASSERT_EQ( e, m |= 1 );
    m = r;

    e = TMat3x3<int64>( 1, 1, 1, 0, 0, 0, 1, 1, 1 );
    ASSERT_EQ( e, m |= n );
    m = r;

    e = TMat3x3<int64>( 0, 0, 0, 1, 1, 1, 0, 1, 0 );
    ASSERT_EQ( e, m ^= 1 );
    m = r;

    e = TMat3x3<int64>( 0, 0, 0, 0, 0, 0, 1, 1, 0 );
    ASSERT_EQ( e, m ^= n );
    m = r;

    e = TMat3x3<int64>( 2, 2, 2, 0, 0, 0, 2, 0, 2 );
    EXPECT_EQ( e, m <<= 1 );
    EXPECT_EQ( r, m >>= 1 );

    e = TMat3x3<int64>( ~1, ~1, ~1, ~0, ~0, ~0, ~1, ~0, ~1 );
    EXPECT_EQ( e, ~m );
}

TEST( TMat3x3, ArithmatixBinaryOperators )
{
    using namespace gel::math;

    Mat3 m;

    ASSERT_EQ( 3, ( m = m + 2 )[0][0] );
    ASSERT_EQ( 3, m[1][1] );
    ASSERT_EQ( 3, m[2][2] );


    ASSERT_EQ( 1, ( m = m - 2 )[0][0] );
    ASSERT_EQ( 1, m[1][1] );
    ASSERT_EQ( 1, m[2][2] );

    ASSERT_EQ( 2, ( m = m * 2 )[0][0] );
    ASSERT_EQ( 2, m[1][1] );
    ASSERT_EQ( 2, m[2][2] );

    ASSERT_EQ( 1, ( m = m / 2 )[0][0] );
    ASSERT_EQ( 1, m[1][1] );
    ASSERT_EQ( 1, m[2][2] );

    TMat3x3<int> i;
    i *= 5;
    ASSERT_EQ( 1, ( i = i % 4 )[0][0] );
    ASSERT_EQ( 1, i[1][1] );
    ASSERT_EQ( 1, i[2][2] );
}

TEST( TMat3x3, ArithmeticMatrixBinaryOperators )
{
    using namespace gel::math;

    DMat3 m( 1, 2, 3, 3, 1, 2, 2, 3, 1 );
    DMat3 n( 3, 1, 2, 2, 3, 1, 1, 2, 3 );
    DMat3 r( 1, 2, 3, 3, 1, 2, 2, 3, 1 );
    DMat3 e;
    DMat3::Row row;
    DMat3::Column col;

    e = DMat3( 10, 13, 13, 13, 10, 13, 13, 13, 10 );
    EXPECT_TRUE( e == m * n );

    e = DMat3( 4, 3, 5, 5, 4, 3, 3, 5, 4 );
    EXPECT_TRUE( e == m + n );

    e = DMat3( -2, 1, 1, 1, -2, 1, 1, 1, -2 );
    EXPECT_TRUE( e == m - n );

    EXPECT_TRUE( m / n == m * Mat::invert( n ) );

    row = DMat3::Row( 1, 2, 3 );
    col = DMat3::Column( 14, 11, 11 );
    EXPECT_TRUE( col == m * row );

    col = DMat3::Column( 1, 2, 3 );
    row = DMat3::Row( 13, 13, 10 );
    EXPECT_TRUE( row == col * m );

    // division is not checked because of rounding errors

    IMat3  x( 5, 5, 5, 7, 7, 7, 11, 11, 11 );
    IMat3  y( 3, 4, 5, 3, 5, 7,  7,  9, 11 );
    IMat3 ie( 2, 1, 0, 1, 2, 0,  4,  2,  0 );
    EXPECT_EQ( ie, x % y );
}

TEST( TMat3x3, BitwiseBinaryOperators )
{
    using namespace gel::math;
    using namespace gel;

    TMat3x3<int64> m( 1, 1, 1, 0, 0, 0, 1, 0, 1 );
    TMat3x3<int64> n( 1, 1, 1, 0, 0, 0, 0, 1, 1 );
    TMat3x3<int64> r( 1, 1, 1, 0, 0, 0, 1, 0, 1 );
    TMat3x3<int64> e;

    e = TMat3x3<int64>( 0 );
    ASSERT_EQ( e, m & 0 );

    e = TMat3x3<int64>( 1, 1, 1, 0, 0, 0, 0, 0, 1 );
    ASSERT_EQ( e, m & n );

    e = TMat3x3<int64>( 1, 1, 1, 1, 1, 1, 1, 1, 1 );
    ASSERT_EQ( e, m | 1 );

    e = TMat3x3<int64>( 1, 1, 1, 0, 0, 0, 1, 1, 1 );
    ASSERT_EQ( e, m | n );

    e = TMat3x3<int64>( 0, 0, 0, 1, 1, 1, 0, 1, 0 );
    ASSERT_EQ( e, m ^ 1 );

    e = TMat3x3<int64>( 0, 0, 0, 0, 0, 0, 1, 1, 0 );
    ASSERT_EQ( e, m ^ n );

    e = TMat3x3<int64>( 2, 2, 2, 0, 0, 0, 2, 0, 2 );
    EXPECT_EQ( e, m << 1 );
    EXPECT_EQ( r, ( m << 1 ) >> 1 );
}
