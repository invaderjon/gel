// math.h
#ifndef GEL_GELMATH_H
#define GEL_GELMATH_H
#include <gel/gelint.h>
#include <gel/gelfloat.h>
#include <cmath>

namespace gel
{

namespace math
{

struct Math
{
    // INTEGRAL MATH
    /**
     * Gets the absolute value of an integer.
     *
     * @param The value.
     * @return The absolute value.
     */
    static int8 abs( int8 x );

    /**
     * Gets the absolute value of an integer.
     *
     * @param The value.
     * @return The absolute value.
     */
    static int16 abs( int16 x );

    /**
     * Gets the absolute value of an integer.
     *
     * @param The value.
     * @return The absolute value.
     */
    static int32 abs( int32 x );

    /**
     * Gets the absolute value of an integer.
     *
     * @param The value.
     * @return The absolute value.
     */
    static int64 abs( int64 x );

    // FLOATING POINT MATH
    /**
     * Gets the absolute value of a floating point value.
     *
     * @param The value.
     * @return The absolute value.
     */
    static float abs( float x );

    /**
     * Gets the absolute value of a floating point value.
     *
     * @param The value.
     * @return The absolute value.
     */
    static double abs( double x );

    /**
     * Gets the pth power of x.
     *
     * @param x The value.
     * @param p The power.
     * @return The pth power.
     */
    static float pow( float x, float p );

    /**
     * Gets the pth power of x.
     *
     * @param x The value.
     * @param p The power.
     * @return The pth power.
     */
    static double pow( double x, double p );

    /**
     * Gets the square root of a value.
     *
     * @param x The value.
     * @return The square root.
     */
    static float sqrt( float x );

    /**
     * Gets the square root of a value.
     *
     * @param x The value.
     * @return The square root.
     */
    static double sqrt( double x );

    /**
     * Ges the inverse root of a value (x^-1/2).
     *
     * @param x The value.
     * @return The inverse root.
     */
    static float invsqrt( float x );

    /**
     * Ges the inverse root of a value (x^-1/2).
     *
     * @param x The value.
     * @return The inverse root.
     */
    static double invsqrt( double x );

    /**
     * Gets the minimum value.
     *
     * @param x The first value.
     * @param y The second value.
     * @return The min value.
     */
    static float min( float x, float y );

    /**
     * Gets the minimum value.
     *
     * @param x The first value.
     * @param y The second value.
     * @return The min value.
     */
    static double min( double x, double y );

    /**
     * Gets the maximum value.
     *
     * @param x The first value.
     * @param y The second value.
     * @return The max value.
     */
    static float max( float x, float y );

    /**
     * Gets the maximum value.
     *
     * @param x The first value.
     * @param y The second value.
     * @return The max value.
     */
    static double max( double x, double y );

    // FLOATING POINT COMPARISON
    /**
    * Magic number used in computing the inverse root.
    */
    static const int32 INVSQRT_FLT_MAGIC = 0x5f375a86;

    /**
     * Magic number used in computing the inverse root.
     */
    static const int64 INVSQRT_DBL_MAGIC = 0x5fe6eb50c7b537a9LL;

    /**
     * Checks two floating point values for approximate equality.
     *
     * @param x The first value.
     * @param y The second value.
     * @return If they are approximately equal.
     */
    static bool eq( float x, float y );

    /**
     * Checks two floating point values for approximate equality.
     *
     * @param x The first value.
     * @param y The second value.
     * @return If they are approximately equal.
     */
    static bool eq( double x, double y );

    /**
     * Checks two floating point values for approximate inequality.
     *
     * @param x The first value.
     * @param y The second value.
     * @return If they are approximately not equal.
     */
    static bool neq( float x, float y );

    /**
     * Checks two floating point values for approximate inequality.
     *
     * @param x The first value.
     * @param y The second value.
     * @return If they are approximately not equal.
     */
    static bool neq( double x, double y );

    /**
     * Checks if one floating point value is approximately greater than another.
     *
     * @param x The first value.
     * @param y The second value.
     * @return If x is approximately greater than y.
     */
    static bool gt( float x, float y );

    /**
     * Checks if one floating point value is approximately greater than another.
     *
     * @param x The first value.
     * @param y The second value.
     * @return If x is approximately greater than y.
     */
    static bool gt( double x, double y );

    /**
     * Checks if one floating point value is approximately greater than or equal to another.
     *
     * @param x The first value.
     * @param y The second value.
     * @return If x is approximately greater than or equal to y.
     */
    static bool gte( float x, float y );

    /**
     * Checks if one floating point value is approximately greater than or equal to another.
     *
     * @param x The first value.
     * @param y The second value.
     * @return If x is approximately greater than or equal to y.
     */
    static bool gte( double x, double y );

    /**
     * Checks if one floating point value is approximately less than another.
     *
     * @param x The first value.
     * @param y The second value.
     * @return If x is approximately less than y.
     */
    static bool lt( float x, float y );

    /**
     * Checks if one floating point value is approximately less than another.
     *
     * @param x The first value.
     * @param y The second value.
     * @return If x is approximately less than y.
     */
    static bool lt( double x, double y );

    /**
     * Checks if one floating point value is approximately less than or equal to another.
     *
     * @param x The first value.
     * @param y The second value.
     * @return If x is approximately less than or equal to y.
     */
    static bool lte( float x, float y );

    /**
     * Checks if one floating point value is approximately less than or equal to another.
     *
     * @param x The first value.
     * @param y The second value.
     * @return If x is approximately less than or equal to y.
     */
    static bool lte( double x, double y );
};

// INTEGER MATH
inline
int8 Math::abs( int8 x )
{
    return x & static_cast<int8>( 0x7F );
}

inline
int16 Math::abs( int16 x )
{
    return x & static_cast<int16>( 0x7FFF );
}

inline
int32 Math::abs( int32 x )
{
    return x & 0x7FFFFFFF;
}

inline
int64 Math::abs( int64 x )
{
    return x & 0x7FFFFFFFFFFFFFFFLL;
}

// FLOATING POINT MATH
inline
float Math::abs( float x )
{
    return std::abs( x );
}

inline
double Math::abs( double x )
{
    return std::abs( x );
}

inline
float Math::pow( float x, float p )
{
    return std::pow( x, p );
}

inline
double Math::pow( double x, double p )
{
    return std::pow( x, p );
}

inline
float Math::sqrt( float x )
{
    return std::sqrt( x );
}

inline
double Math::sqrt( double x )
{
    return std::sqrt( x );
}

inline
float Math::invsqrt( float x )
{
    int32 i;
    float x2;
    const float threehalfs = 1.5f;

    // more information:
    // https://en.wikipedia.org/wiki/Fast_inverse_square_root
    x2 = x * 0.5f;
    i = reinterpret_cast<int32&>( x );
    i = INVSQRT_FLT_MAGIC - ( i >> 1 );
    x = reinterpret_cast<float&>( i );

    // newton iterations
    x *= ( threehalfs - ( x2 * x * x ) );
    x *= ( threehalfs - ( x2 * x * x ) );

    return x;
}

inline
double Math::invsqrt( double x )
{
    int64 i;
    double x2;
    const double threehalfs = 1.5;

    // more information:
    // https://en.wikipedia.org/wiki/Fast_inverse_square_root
    x2 = x * 0.5;
    i = reinterpret_cast<int64&>( x );
    i = INVSQRT_FLT_MAGIC - ( i >> 1 );
    x = reinterpret_cast<double&>( i );

    // newton iterations
    x *= ( threehalfs - ( x2 * x * x ) );
    x *= ( threehalfs - ( x2 * x * x ) );

    return x;
}

inline
float Math::min( float x, float y )
{
    return x < y ? x : y;
}

inline
double Math::min( double x, double y )
{
    return x < y ? x : y;
}

inline
float Math::max( float x, float y )
{
    return x > y ? x : y;
}

inline
double Math::max( double x, double y )
{
    return x > y ? x : y;
}

// FLOATING POINT COMPARISON FUNCTIONS
inline
bool Math::eq( float x, float y )
{
    return abs( x - y ) <= Float::GEL_FLT_EPSILON * max( abs( x ), abs ( y ) );
}

inline
bool Math::eq( double x, double y )
{
    return abs( x - y ) <= Float::GEL_DBL_EPSILON * max( abs( x ), abs ( y ) );
}

inline
bool Math::neq( float x, float y )
{
    return abs( x - y ) > Float::GEL_FLT_EPSILON * max( abs( x ), abs ( y ) );
}

inline
bool Math::neq( double x, double y )
{
    return abs( x - y ) > Float::GEL_DBL_EPSILON * max( abs( x ), abs ( y ) );
}

inline
bool Math::gt( float x, float y )
{
    return x > y && neq( x, y );
}

inline
bool Math::gt( double x, double y )
{
    return x > y && neq( x, y );
}

inline
bool Math::gte( float x, float y )
{
    return x > y || eq( x, y );
}

inline
bool Math::gte( double x, double y )
{
    return x > y || eq( x, y );
}

inline
bool Math::lt( float x, float y )
{
    return x < y && neq( x, y );
}

inline
bool Math::lt( double x, double y )
{
    return x < y && neq( x, y );
}

inline
bool Math::lte( float x, float y )
{
    return x < y || eq( x, y );
}

inline
bool Math::lte( double x, double y )
{
    return x < y || eq( x, y );
}

} // End nspc math

} // End nspc gel

#endif //GEL_MATH_H
