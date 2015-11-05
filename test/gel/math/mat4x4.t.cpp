// mat4x4.t.cpp
#include <gel/gelint.h>
#include <gel/math/mat.h>
#include <gtest/gtest.h>

TEST( TMat4x4, Construction )
{
    using namespace gel::math;

    unsigned int i, j;
    Mat4 m;

    for ( i = 0; i < 4; ++i )
    {
        for ( j = 0; j < 4; ++j )
        {
            if ( i != j )
            {
                ASSERT_EQ( 0, Mat4::IDENTITY[i][j] );
            }
            else
            {
                ASSERT_EQ( 1, Mat4::IDENTITY[i][j] );
            }
        }
    }

    ASSERT_EQ( Mat4::IDENTITY, m );
    ASSERT_EQ( Mat4::IDENTITY, m = Mat4( 1 ) );
    ASSERT_EQ( Mat4::ZERO, m = Mat4( 0 ) );
    ASSERT_EQ( Mat4::IDENTITY, Mat4( Mat2::IDENTITY ) );
    ASSERT_EQ( Mat4::IDENTITY, Mat4( Mat3::IDENTITY ) );

    m = Mat4( 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 );

    for ( i = 0; i < 16; ++i )
    {
        ASSERT_EQ( i, m[i % 4][i / 4] );
    }

    m = Mat4( Mat4::Column( 0, 4, 8, 12 ), Mat4::Column( 1, 5, 9, 13 ),
              Mat4::Column( 2, 6, 10, 14 ), Mat4::Column( 3, 7, 11, 15 ) );

    for ( i = 0; i < 16; ++i )
    {
        ASSERT_EQ( i, m[i % 4][i / 4] );
    }
}

TEST( TMat4x4, AccessOperators )
{
    using namespace gel::math;
    Mat4 m;

    EXPECT_EQ( Vec4( 1, 0, 0, 0 ), m[0] );

    m[0] = Vec4( 2, 0, 0, 0 );

    EXPECT_EQ( Vec4( 2, 0, 0, 0), m[0] );

    EXPECT_DEATH( m[4], "Assertion .* failed" );
}

TEST( TMat4x4, ArithmeticUnaryOperators )
{
    using namespace gel::math;

    Mat4 m;

    ASSERT_EQ( 3, ( m += 2 )[0][0] );
    ASSERT_EQ( 3, m[1][1] );
    ASSERT_EQ( 3, m[2][2] );
    ASSERT_EQ( 3, m[3][3] );


    ASSERT_EQ( 1, ( m -= 2 )[0][0] );
    ASSERT_EQ( 1, m[1][1] );
    ASSERT_EQ( 1, m[2][2] );
    ASSERT_EQ( 1, m[3][3] );

    ASSERT_EQ( 2, ( m *= 2 )[0][0] );
    ASSERT_EQ( 2, m[1][1] );
    ASSERT_EQ( 2, m[2][2] );
    ASSERT_EQ( 2, m[3][3] );

    ASSERT_EQ( 1, ( m /= 2 )[0][0] );
    ASSERT_EQ( 1, m[1][1] );
    ASSERT_EQ( 1, m[2][2] );
    ASSERT_EQ( 1, m[3][3] );

    ASSERT_EQ( 2, ( m++ )[0][0] );
    ASSERT_EQ( 2, m[1][1] );
    ASSERT_EQ( 2, m[2][2] );
    ASSERT_EQ( 2, m[3][3] );


    ASSERT_EQ( 1, ( m-- )[0][0] );
    ASSERT_EQ( 1, m[1][1] );
    ASSERT_EQ( 1, m[2][2] );
    ASSERT_EQ( 1, m[3][3] );

    ASSERT_EQ( 2, ( ++m )[0][0] );
    ASSERT_EQ( 2, m[1][1] );
    ASSERT_EQ( 2, m[2][2] );
    ASSERT_EQ( 2, m[3][3] );


    ASSERT_EQ( 1, ( --m )[0][0] );
    ASSERT_EQ( 1, m[1][1] );
    ASSERT_EQ( 1, m[2][2] );
    ASSERT_EQ( 1, m[3][3] );

    m = -m;
    ASSERT_EQ( -1, m[0][0] );
    ASSERT_EQ( -1, m[1][1] );
    ASSERT_EQ( -1, m[2][2] );
    ASSERT_EQ( -1, m[3][3] );

    TMat4x4<int> i;
    i *= 5;
    ASSERT_EQ( 1, ( i %= 4 )[0][0] );
    ASSERT_EQ( 1, i[1][1] );
    ASSERT_EQ( 1, i[2][2] );
    ASSERT_EQ( 1, i[3][3] );
}

TEST( TMat4x4, ArithmeticMatrixUnaryOperators )
{
    using namespace gel::math;

    Mat4 m( 1, 2, 3, 4, 4, 1, 2, 3, 3, 4, 1, 2, 2, 3, 4, 1 );
    Mat4 n( 2, 3, 4, 1, 3, 4, 1, 2, 4, 1, 2, 3, 1, 2, 3, 4 );
    Mat4 r( 1, 2, 3, 4, 4, 1, 2, 3, 3, 4, 1, 2, 2, 3, 4, 1 );
    Mat4 e;

    e = Mat4( 24, 22, 24, 30, 22, 24, 30, 24, 24, 30, 24, 22, 30, 24, 22, 24 );
    EXPECT_EQ( e, m *= n );
    m = r;

    e = Mat4( 3, 5, 7, 5, 7, 5, 3, 5, 7, 5, 3, 5, 3, 5, 7, 5 );
    EXPECT_EQ( e, m += n );
    m = r;

    e = Mat4( -1, -1, -1, 3, 1, -3, 1, 1, -1, 3, -1, -1, 1, 1, 1, -3 );
    EXPECT_EQ( e, m -= n );
    m = r;

    e = Mat4(  1/40.0f,  1/40.0f, 11/40.0f, -9/40.0f,
               1/40.0f, 11/40.0f, -9/40.0f,  1/40.0f,
              11/40.0f, -9/40.0f,  1/40.0f,  1/40.0f,
              -9/40.0f,  1/40.0f,  1/40.0f, 11/40.0f );
    EXPECT_EQ( e, Mat::invert( n ) );

    // division is not checked because of rounding errors

    IMat4  x( 5, 5, 5, 5, 7, 7, 7, 7, 11, 11, 11, 11, 13, 13, 13, 13 );
    IMat4  y( 3, 4, 5, 6, 3, 5, 7, 9,  7,  9, 11, 13,  9, 11, 13, 15 );
    IMat4 ie( 2, 1, 0, 5, 1, 2, 0, 7,  4,  2,  0, 11,  4,  2,  0, 13 );
    EXPECT_EQ( ie, x % y );
}

TEST( TMat4x4, BitwiseUnaryOperators )
{
    using namespace gel::math;

    TMat4x4<long long> m( 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1 );
    TMat4x4<long long> n( 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1 );
    TMat4x4<long long> r( 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1 );
    TMat4x4<long long> e;

    e = TMat4x4<long long>( 0 );
    ASSERT_EQ( e, m &= 0 );
    m = r;

    e = TMat4x4<long long>( 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1 );
    ASSERT_EQ( e, m &= n );
    m = r;

    e = TMat4x4<long long>( 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 );
    ASSERT_EQ( e, m |= 1 );
    m = r;

    e = TMat4x4<long long>( 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1 );
    ASSERT_EQ( e, m |= n );
    m = r;

    e = TMat4x4<long long>( 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0 );
    ASSERT_EQ( e, m ^= 1 );
    m = r;

    e = TMat4x4<long long>( 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 0 );
    ASSERT_EQ( e, m ^= n );
    m = r;

    e = TMat4x4<long long>( 2, 2, 2, 2, 0, 0, 0, 0, 2, 0, 2, 0, 0, 2, 0, 2 );
    EXPECT_EQ( e, m <<= 1 );
    EXPECT_EQ( r, m >>= 1 );

    e = TMat4x4<long long>( ~1, ~1, ~1, ~1, ~0, ~0, ~0, ~0, ~1, ~0, ~1, ~0, ~0, ~1, ~0, ~1 );
    EXPECT_EQ( e, ~m );
}

TEST( TMat4x4, ArithmatixBinaryOperators )
{
    using namespace gel::math;

    Mat4 m;

    ASSERT_EQ( 3, ( m = m + 2 )[0][0] );
    ASSERT_EQ( 3, m[1][1] );
    ASSERT_EQ( 3, m[2][2] );
    ASSERT_EQ( 3, m[3][3] );


    ASSERT_EQ( 1, ( m = m - 2 )[0][0] );
    ASSERT_EQ( 1, m[1][1] );
    ASSERT_EQ( 1, m[2][2] );
    ASSERT_EQ( 1, m[3][3] );

    ASSERT_EQ( 2, ( m = m * 2 )[0][0] );
    ASSERT_EQ( 2, m[1][1] );
    ASSERT_EQ( 2, m[2][2] );
    ASSERT_EQ( 2, m[3][3] );

    ASSERT_EQ( 1, ( m = m / 2 )[0][0] );
    ASSERT_EQ( 1, m[1][1] );
    ASSERT_EQ( 1, m[2][2] );
    ASSERT_EQ( 1, m[3][3] );

    TMat4x4<int> i;
    i *= 5;
    ASSERT_EQ( 1, ( i = i % 4 )[0][0] );
    ASSERT_EQ( 1, i[1][1] );
    ASSERT_EQ( 1, i[2][2] );
    ASSERT_EQ( 1, i[3][3] );
}

TEST( TMat4x4, ArithmeticMatrixBinaryOperators )
{
    using namespace gel::math;

    DMat4 m( 1, 2, 3, 4, 4, 1, 2, 3, 3, 4, 1, 2, 2, 3, 4, 1 );
    DMat4 n( 2, 3, 4, 1, 3, 4, 1, 2, 4, 1, 2, 3, 1, 2, 3, 4 );
    DMat4 r( 1, 2, 3, 4, 4, 1, 2, 3, 3, 4, 1, 2, 2, 3, 4, 1 );
    DMat4 e;
    DMat4::Row row;
    DMat4::Column col;

    e = DMat4( 24, 22, 24, 30, 22, 24, 30, 24, 24, 30, 24, 22, 30, 24, 22, 24 );
    EXPECT_EQ( e, m = m * n );
    m = r;

    e = DMat4( 3, 5, 7, 5, 7, 5, 3, 5, 7, 5, 3, 5, 3, 5, 7, 5 );
    EXPECT_EQ( e, m = m + n );
    m = r;

    e = DMat4( -1, -1, -1, 3, 1, -3, 1, 1, -1, 3, -1, -1, 1, 1, 1, -3 );
    EXPECT_EQ( e, m = m - n );
    m = r;

    EXPECT_TRUE( m / n == m * Mat::invert( n ) );

    row = DMat4::Row( 1, 2, 3, 4 );
    col = DMat4::Column( 30, 24, 22, 24 );
    EXPECT_EQ( col, m * row );

    col = DMat4::Column( 1, 2, 3, 4 );
    row = DMat4::Row( 26, 28, 26, 20 );
    EXPECT_EQ( row, col * m );

    // division is not check because although it works it leads to rounding errors
    e = DMat4( 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0 );

    IMat4  x( 5, 5, 5, 5, 7, 7, 7, 7, 11, 11, 11, 11, 13, 13, 13, 13 );
    IMat4  y( 3, 4, 5, 6, 3, 5, 7, 9,  7,  9, 11, 13,  9, 11, 13, 15 );
    IMat4 ie( 2, 1, 0, 5, 1, 2, 0, 7,  4,  2,  0, 11,  4,  2,  0, 13 );
    EXPECT_EQ( ie, x %= y );
}

TEST( TMat4x4, BitwiseBinaryOperators )
{
    using namespace gel::math;

    TMat4x4<long long> m( 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1 );
    TMat4x4<long long> n( 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1 );
    TMat4x4<long long> r( 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1 );
    TMat4x4<long long> e;

    e = TMat4x4<long long>( 0 );
    ASSERT_EQ( e, m & 0 );

    e = TMat4x4<long long>( 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1 );
    ASSERT_EQ( e, m & n );

    e = TMat4x4<long long>( 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 );
    ASSERT_EQ( e, m | 1 );

    e = TMat4x4<long long>( 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1 );
    ASSERT_EQ( e, m | n );

    e = TMat4x4<long long>( 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0 );
    ASSERT_EQ( e, m ^ 1 );

    e = TMat4x4<long long>( 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 0 );
    ASSERT_EQ( e, m ^ n );

    e = TMat4x4<long long>( 2, 2, 2, 2, 0, 0, 0, 0, 2, 0, 2, 0, 0, 2, 0, 2 );
    EXPECT_EQ( e, m << 1 );
    EXPECT_EQ( r, ( m << 1 ) >> 1 );
}
