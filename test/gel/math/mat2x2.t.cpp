// mat2x2.t.cpp
#include <gel/gelint.h>
#include <gel/math/mat.h>
#include <gtest/gtest.h>

TEST( TMat2x2, Construction )
{
    using namespace gel::math;

    unsigned int i, j;
    Mat2 m;

    for ( i = 0; i < 2; ++i )
    {
        for ( j = 0; j < 2; ++j )
        {
            if ( i != j )
            {
                ASSERT_EQ( 0, Mat2::IDENTITY[i][j] );
            }
            else
            {
                ASSERT_EQ( 1, Mat2::IDENTITY[i][j] );
            }
        }
    }

    ASSERT_EQ( Mat2::IDENTITY, m );
    ASSERT_EQ( Mat2::IDENTITY, m = Mat2( 1 ) );
    ASSERT_EQ( Mat2::ZERO, m = Mat2( 0 ) );
    ASSERT_EQ( Mat2::IDENTITY, Mat2( Mat3::IDENTITY ) );
    ASSERT_EQ( Mat2::IDENTITY, Mat2( Mat4::IDENTITY ) );

    m = Mat2( 0, 1, 2, 3 );

    for ( i = 0; i < 4; ++i )
    {
        ASSERT_EQ( i, m[i % 2][i / 2] );
    }

    m = Mat2( Mat2::Column( 0, 2 ), Mat2::Column( 1, 3 ) );

    for ( i = 0; i < 4; ++i )
    {
        ASSERT_EQ( i, m[i % 2][i / 2] );
    }
}

TEST( TMat2x2, AccessOperators )
{
    using namespace gel::math;
    Mat2 m;

    EXPECT_EQ( Vec2( 1, 0 ), m[0] );

    m[0] = Vec2( 2, 0 );

    EXPECT_EQ( Vec2( 2, 0 ), m[0] );

    EXPECT_DEATH( m[2], "Assertion .* failed" );
}

TEST( TMat2x2, ArithmeticUnaryOperators )
{
    using namespace gel::math;

    Mat2 m;

    ASSERT_EQ( 3, ( m += 2 )[0][0] );
    ASSERT_EQ( 3, m[1][1] );


    ASSERT_EQ( 1, ( m -= 2 )[0][0] );
    ASSERT_EQ( 1, m[1][1] );

    ASSERT_EQ( 2, ( m *= 2 )[0][0] );
    ASSERT_EQ( 2, m[1][1] );

    ASSERT_EQ( 1, ( m /= 2 )[0][0] );
    ASSERT_EQ( 1, m[1][1] );

    ASSERT_EQ( 2, ( m++ )[0][0] );
    ASSERT_EQ( 2, m[1][1] );


    ASSERT_EQ( 1, ( m-- )[0][0] );
    ASSERT_EQ( 1, m[1][1] );

    ASSERT_EQ( 2, ( ++m )[0][0] );
    ASSERT_EQ( 2, m[1][1] );


    ASSERT_EQ( 1, ( --m )[0][0] );
    ASSERT_EQ( 1, m[1][1] );

    m = -m;
    ASSERT_EQ( -1, m[0][0] );
    ASSERT_EQ( -1, m[1][1] );

    TMat2x2<int> i;
    i *= 5;
    ASSERT_EQ( 1, ( i %= 4 )[0][0] );
    ASSERT_EQ( 1, i[1][1] );
}

TEST( TMat2x2, ArithmeticMatrixUnaryOperators )
{
    using namespace gel::math;

    Mat2 m( 1, 2, 3, 4 );
    Mat2 n( 3, 5, 7, 9 );
    Mat2 r( 1, 2, 3, 4 );
    Mat2 e;

    e = Mat2( 17, 23, 37, 51 );
    EXPECT_EQ( e, m *= n );
    m = r;

    e = Mat2( 4, 7, 10, 13 );
    EXPECT_EQ( e, m += n );
    m = r;
    std::cout << m[0][0] << std::endl;

    e = Mat2( -2, -3, -4, -5 );
    EXPECT_EQ( e, m -= n );
    m = r;

    e = Mat2( -9/8.0f,  5/8.0f,
               7/8.0f, -3/8.0f );
    EXPECT_TRUE( e == Mat::invert( n ) );

    // division is not checked because of rounding errors

    IMat2  x( 1, 3, 5, 7 );
    IMat2  y( 4, 4, 4, 4  );
    IMat2 ie( 1, 3, 1, 3 );
    EXPECT_EQ( ie, x %= y );
}

TEST( TMat2x2, BitwiseUnaryOperators )
{
    using namespace gel::math;
    using namespace gel;

    TMat2x2<int64> m( 1, 0, 1, 0 );
    TMat2x2<int64> n( 1, 1, 0, 0 );
    TMat2x2<int64> r( 1, 0, 1, 0 );
    TMat2x2<int64> e;

    e = TMat2x2<int64>( 0 );
    ASSERT_EQ( e, m &= 0 );
    m = r;

    e = TMat2x2<int64>( 1, 0, 0, 0 );
    ASSERT_EQ( e, m &= n );
    m = r;

    e = TMat2x2<int64>( 1, 1, 1, 1 );
    ASSERT_EQ( e, m |= 1 );
    m = r;

    e = TMat2x2<int64>( 1, 1, 1, 0 );
    ASSERT_EQ( e, m |= n );
    m = r;

    e = TMat2x2<int64>( 0, 1, 0, 1 );
    ASSERT_EQ( e, m ^= 1 );
    m = r;

    e = TMat2x2<int64>( 0, 1, 1, 0 );
    ASSERT_EQ( e, m ^= n );
    m = r;

    e = TMat2x2<int64>( 2, 0, 2, 0 );
    EXPECT_EQ( e, m <<= 1 );
    EXPECT_EQ( r, m >>= 1 );

    e = TMat2x2<int64>( ~1, ~0, ~1, ~0 );
    EXPECT_EQ( e, ~m );
}

TEST( TMat2x2, ArithmatixBinaryOperators )
{
    using namespace gel::math;

    Mat2 m;

    ASSERT_EQ( 3, ( m = m + 2 )[0][0] );
    ASSERT_EQ( 3, m[1][1] );


    ASSERT_EQ( 1, ( m = m - 2 )[0][0] );
    ASSERT_EQ( 1, m[1][1] );

    ASSERT_EQ( 2, ( m = m * 2 )[0][0] );
    ASSERT_EQ( 2, m[1][1] );

    ASSERT_EQ( 1, ( m = m / 2 )[0][0] );
    ASSERT_EQ( 1, m[1][1] );

    TMat2x2<int> i;
    i *= 5;
    ASSERT_EQ( 1, ( i = i % 4 )[0][0] );
    ASSERT_EQ( 1, i[1][1] );
}

TEST( TMat2x2, ArithmeticMatrixBinaryOperators )
{
    using namespace gel::math;

    DMat2 m( 1, 2, 3, 4 );
    DMat2 n( 3, 5, 7, 9 );
    DMat2 r( 1, 2, 3, 4 );
    DMat2 e;
    DMat2::Row row;
    DMat2::Column col;

    e = Mat2( 17, 23, 37, 51 );
    EXPECT_TRUE( e == m * n );

    e = Mat2( 4, 7, 10, 13 );
    EXPECT_TRUE( e == m + n );

    e = Mat2( -2, -3, -4, -5 );
    EXPECT_TRUE( e == m - n );

    EXPECT_TRUE( m / n == m * Mat::invert( n ) );

    row = DMat2::Row( 1, 2 );
    col = DMat2::Column( 5, 11 );
    EXPECT_TRUE( col == m * row );

    col = DMat2::Column( 1, 2 );
    row = DMat2::Row( 7, 10 );
    EXPECT_TRUE( row == col * m );

    // division is not checked because of rounding errors

    IMat2  x( 1, 3, 5, 7 );
    IMat2  y( 4, 4, 4, 4  );
    IMat2 ie( 1, 3, 1, 3 );
    EXPECT_EQ( ie, x % y );
}

TEST( TMat2x2, BitwiseBinaryOperators )
{
    using namespace gel::math;
    using namespace gel;

    TMat2x2<int64> m( 1, 0, 1, 0 );
    TMat2x2<int64> n( 1, 1, 0, 0 );
    TMat2x2<int64> r( 1, 0, 1, 0 );
    TMat2x2<int64> e;

    e = TMat2x2<int64>( 0 );
    ASSERT_EQ( e, m & 0 );

    e = TMat2x2<int64>( 1, 0, 0, 0 );
    ASSERT_EQ( e, m & n );

    e = TMat2x2<int64>( 1, 1, 1, 1 );
    ASSERT_EQ( e, m | 1 );

    e = TMat2x2<int64>( 1, 1, 1, 0 );
    ASSERT_EQ( e, m | n );

    e = TMat2x2<int64>( 0, 1, 0, 1 );
    ASSERT_EQ( e, m ^ 1 );

    e = TMat2x2<int64>( 0, 1, 1, 0 );
    ASSERT_EQ( e, m ^ n );

    e = TMat2x2<int64>( 2, 0, 2, 0 );
    EXPECT_EQ( e, m << 1 );
    EXPECT_EQ( r, ( m << 1 ) >> 1 );
}
