// vec2.h
#ifndef GEL_VEC2_H
#define GEL_VEC2_H
#include <assert.h>
#include "gel/gellib.h"

namespace gel
{

namespace math
{

template <typename T>
class TRef2;

template <typename T>
class TRef2;

template <typename T>
class TRef4;

template <typename T>
class TVec2;

template <typename T>
class TVec2;

template <typename T>
class TVec4;

template <typename T>
class TVec2
{
  public:
    typedef T ValueType;

    union
    {
        struct { ValueType x, y; };
        struct { ValueType r, g; };
        struct { ValueType s, t; };
        struct { ValueType i, j; };
        struct { ValueType hue, lum; };
    };

    // IMPLICIT CONSTRUCTORS
    /**
     * Constructs a new vector.
     */
    TVec2();

    /**
     * Constructs this vector as a copy of the other.
     *
     * @param v The vector to copy.
     */
    TVec2( const TVec2<T>& v );

    /**
     * Destructs the vector.
     */
    ~TVec2();

    // EXPLICIT CONSTRUCTORS
    /**
     * Constructs a new vector and initializes its components to v.
     *
     * @param v The component value.
     * @tparam U The component value type.
     */
    template <typename U>
    explicit TVec2( const U& s );

    /**
     * Constructs a new vector.
     *
     * @param s1 The first component value.
     * @param s2 The second component value
     * @tparam U The first component value type.
     * @tparam V The second component value type.
     */
    template <typename U, typename V>
    explicit TVec2( const U& s1, const V& s2 );

    /**
     * Constructs a copy of the vector.
     *
     * @param v The vector to copy.
     * @tparam U The component type.
     */
    template <typename U>
    explicit TVec2( const TVec2<U>& v );

    // SWIZZLE CONSTRUCTORS
    /**
     * Construct from a reference vector.
     *
     * @param r The reference vector.
     */
    TVec2( const TRef2<T>& r );

    // UNARY OPERATORS
    /**
     * Makes this a copy of the other vector.
     *
     * @param v The vector to copy.
     */
    TVec2<T>& operator=( const TVec2<T>& v );

    /**
     * Makes this a copy of the other vector.
     *
     * @param v The vector to copy.
     * @tparam U The component value type..
     */
    template <typename U>
    TVec2<T>& operator=( const TVec2<U>& v );

    /**
     * Adds a scalar value to the components.
     *
     * @param s The scalar value to add.
     * @tparam U The scalar value type.
     */
    template <typename U>
    TVec2<T>& operator+=( const U& s );

    /**
     * Adds another vector to this.
     *
     * @param v The vector to add.
     * @tparam U The component value type.
     */
    template <typename U>
    TVec2<T>& operator+=( const TVec2<U>& v );

    /**
     * Subtracts a scale from the components.
     *
     * @param s The scalar to subtract.
     * @tparam U The scalar value type.
     */
    template <typename U>
    TVec2<T>& operator-=( const U& s );

    /**
     * Subtracts another vector from this.
     *
     * @param v The vector to subtract.
     * @tparam U The component value type.
     */
    template <typename U>
    TVec2<T>& operator-=( const TVec2<U>& v );

    /**
     * Multiplies the this by a scalar.
     *
     * @param s The scalar to multiply by.
     * @tparam U The scalar value type.
     */
    template <typename U>
    TVec2<T>& operator*=( const U& s );

    /**
     * Multiplies this vector by another.
     *
     * @param v The vector to multiply by.
     * @tparam The component value type.
     */
    template <typename U>
    TVec2<T>& operator*=( const TVec2<U>& v );

    /**
     * Divides this vector by a scalar.
     *
     * @param v The scalar to divide by.
     * @tparam U The scalar value type.
     */
    template <typename U>
    TVec2<T>& operator/=( const U& s );

    /**
     * Divides this vector by another.
     *
     * @param v THe vector to divide by.
     * @tparam U The component value type.
     */
    template <typename U>
    TVec2<T>& operator/=( const TVec2<U>& v );

    /**
     * Adds one to the vector's component values.
     *
     * @return The resultant vector.
     */
    TVec2<T>& operator++( );

    /**
     * Subtracts one from the vector's component values.
     *
     * @return The resultant vector.
     */
    TVec2<T>& operator--( );

    /**
     * Adds one to the vector's component values.
     *
     * @return The resultant vector.
     */
    TVec2<T>& operator++( int );

    /**
     * Subtracts one from the vector's component values.
     *
     * @return The resultant vector.
     */
    TVec2<T>& operator--( int );

    /**
     * Multiplies the vector by negative one.
     *
     * @return The negative vector.
     */
    TVec2<T> operator-() const;

    // UNARY BIT OPERATORS
    /**
     * Performs modulo on each of the components.
     *
     * @param s The scalar to perform modulo with.
     * @tparam The scalar value type.
     */
    template <typename U>
    TVec2<T>& operator%=( const U& s );

    /**
     * Performs a component-wise modulus.
     *
     * @param v The vector to perform modulo with.
     * @tparam U The component value type.
     */
    template <typename U>
    TVec2<T>& operator%=( const TVec2<U>& v );

    /**
     * Performs the bitwise-and operation with each of the components.
     *
     * @param s The scalar to perform and with.
     * @tparam U The scalar value type.
     */
    template <typename U>
    TVec2<T>& operator&=( const U& s );

    /**
     * Performs a component-wise bitwise-and operation.
     *
     * @param v The vector to perform and with.
     * @tparam U The component value type.
     */
    template <typename U>
    TVec2<T>& operator&=( const TVec2<U>& v );

    /**
     * Performs the bitwise-or operation with each of the components.
     *
     * @param s The scalar to perform or with.
     * @tparam U The scalar value type.
     */
    template <typename U>
    TVec2<T>& operator|=( const U& s );

    /**
     * Performs a component-wise bitwise-or operation.
     *
     * @param s The vector to perform or with.
     * @tparam U The scalar value type.
     */
    template <typename U>
    TVec2<T>& operator|=( const TVec2<U>& v );

    /**
     * Performs the bitwise-xor operation with each of the components.
     *
     * @param s The scalar to perform xor with.
     * @tparam U The component value type.
     */
    template <typename U>
    TVec2<T>& operator^=( const U& s );

    /**
     * Performs a component-wise bitwise-xor operation.
     *
     * @param v The vector to perform xor with.
     * @tparam U The component value type.
     */
    template <typename U>
    TVec2<T>& operator^=( const TVec2<U>& v );

    /**
     * Performs the shift-left operation with each of the components.
     *
     * @param s The scalar to perform shift left with.
     * @tparam U The scalar value type.
     */
    template <typename U>
    TVec2<T>& operator<<=( const U& s );

    /**
     * Performs a component-wise bitwise-shift left operation.
     *
     * @param The vector to perform shift left with.
     * @tparam U The component value type.
     */
    template <typename U>
    TVec2<T>& operator<<=( const TVec2<U>& v );

    /**
     * Performs the shift-right operation with each of the components.
     *
     * @param s The scalar to perform shift right with.
     * @tparam U The scalar value type.
     */
    template <typename U>
    TVec2<T>& operator>>=( const U& s );

    /**
     * Performs a component-wise bitwise-shift right operation.
     *
     * @param The vector to perform shift right with.
     * @tparam U The component value type.
     */
    template <typename U>
    TVec2<T>& operator>>=( const TVec2<U>& v );

    /**
     * Gets the bitwise inverse vector.
     *
     * @return The bitwise inverse vector.
     */
    TVec2<T> operator~() const;

    // ACCESSOR OPERATORS
    /**
     * Sets the vector component value at the given index.
     */
    ValueType& operator[]( Size index );

    /**
     * Gets the vector component value at the given index.
     */
    const ValueType& operator[]( Size index ) const;
};

template <typename T>
class TRef2
{
  public:
    T& x;
    T& y;
    // CONSTRUCTORS
    /**
     * Constructs reference vector for the reference components.
     * @param s1 The first reference component.
     * @param s2 The second reference component.
     */
    TRef2( T& s1, T& s2 );

    /**
     * Constructs a new reference vector for an existing reference vector.
     * @param r The reference vector.
     */
    TRef2( TRef2<T>& r );

    /**
     * Constructs a new reference vector for the given vector.
     * @param v The vector to reference.
     */
    TRef2( TVec2<T>& v );

    /**
     * Destructs the reference vector.
     */
    ~TRef2();
};

// ARITHMETIC BINARY OPERATOR DECLARATIONS
/**
 * Adds a scalar value to the components of a vector.
 *
 * @param v The vector.
 * @param s The scalar.
 * @return The resultant vector.
 */
template <typename T>
TVec2<T> operator+( const TVec2<T>& v, const T& s );

/**
 * Adds the components of two vectors.
 *
 * @param u The first vector.
 * @param v The second vector.
 * @return The resultant vector.
 */
template <typename T>
TVec2<T> operator+( const TVec2<T>& u, const TVec2<T>& v );

/**
 * Subtracts a scalar value from the components of a vector.
 *
 * @param v The vector.
 * @param s The scalar.
 * @return The resultant vector.
 */
template <typename T>
TVec2<T> operator-( const TVec2<T>& v, const T& s );

/**
 * Subtracts the components of two vectors.
 *
 * @param u The first vector.
 * @param v The second vector.
 * @return The resultant vector.
 */
template <typename T>
TVec2<T> operator-( const TVec2<T>& u, const TVec2<T>& v );

/**
 * Multiplies the components of a vector by a scalar value.
 *
 * @param v The vector.
 * @param s The scalar.
 * @return The resultant vector.
 */
template <typename T>
TVec2<T> operator*( const TVec2<T>& v, const T& s );

/**
 * Multiplies the components of a vector by a scalar value.
 *
 * @param v The vector.
 * @param s The scalar.
 * @return The resultant vector.
 */
template <typename T>
TVec2<T> operator*( const T& s, const TVec2<T>& v );

/**
 * Multiplies the components of two vectors.
 *
 * @param u The first vector.
 * @param v The second vector.
 * @return The resultant vector.
 */
template <typename T>
TVec2<T> operator*( const TVec2<T>& u, const TVec2<T>& v );

/**
 * Multiplies the components of a vector by a scalar value.
 *
 * @param v The vector.
 * @param s The scalar.
 * @return The resultant vector.
 */
template <typename T>
TVec2<T> operator/( const TVec2<T>& v, const T& s );

/**
 * Multiplies the components of a vector by a scalar value.
 *
 * @param v The vector.
 * @param s The scalar.
 * @return The resultant vector.
 */
template <typename T>
TVec2<T> operator/( const T& s, const TVec2<T>& v );

/**
 * Divides the components of two vectors.
 *
 * @param u The first vector.
 * @param v The second vector.
 * @return The resultant vector.
 */
template <typename T>
TVec2<T> operator/( const TVec2<T>& u, const TVec2<T>& v );

/**
 * Performs modulus on a vector and a scalar.
 *
 * @param v The vector.
 * @param s The scalar.
 * @return The resultant vector.
 */
template <typename T>
TVec2<T> operator%( const TVec2<T>& v, const T& s );

/**
 * Performs modulus on a vector and a scalar.
 *
 * @param s The scalar.
 * @param v The vector.
 * @return The resultant vector.
 */
template <typename T>
TVec2<T> operator%( const T& s, const TVec2<T>& v );

/**
 * Performs modulus on the components of two vectors.
 *
 * @param u The first vector.
 * @param v The second vector.
 * @return The resultant vector.
 */
template <typename T>
TVec2<T> operator%( const TVec2<T>& u, const TVec2<T>& v );

// BINARY BITWISE OPERATOR DECLARATIONS
/**
 * Performs bitwise AND on the components with the scalar.
 *
 * @param v The vector.
 * @param s The scalar.
 * @return The resultant vector.
 */
template <typename T>
TVec2<T> operator&( const TVec2<T>& v, const T& s );

/**
 * Performs bitwise AND on the components from the two vectors.
 *
 * @param u The first vector.
 * @param v The second vector.
 * @return The resultant vector.
 */
template <typename T>
TVec2<T> operator&( const TVec2<T>& u, const TVec2<T>& v );

/**
 * Performs bitwise OR on the components with the scalar.
 *
 * @param v The vector.
 * @param s The scalar.
 * @return The resultant vector.
 */
template <typename T>
TVec2<T> operator|( const TVec2<T>& v, const T& s );

/**
 * Performs bitwise OR on the components from the two vectors.
 *
 * @param u The first vector.
 * @param v The second vector.
 * @return The resultant vector.
 */
template <typename T>
TVec2<T> operator|( const TVec2<T>& u, const TVec2<T>& v );


/**
 * Performs bitwise XOR on the components with the scalar.
 *
 * @param v The vector.
 * @param s The scalar.
 * @return The resultant vector.
 */
template <typename T>
TVec2<T> operator^( const TVec2<T>& v, const T& s );

/**
 * Performs bitwise XOR on the components from the two vectors.
 *
 * @param u The first vector.
 * @param v The second vector.
 * @return The resultant vector.
 */
template <typename T>
TVec2<T> operator^( const TVec2<T>& u, const TVec2<T>& v );

/**
 * Shifts the bits of the components left.
 *
 * @param v The vector.
 * @param shift How many bits to shift.
 * @return The resultant vector.
 */
template <typename T>
TVec2<T> operator<<( const TVec2<T>& v, unsigned int shift );

/**
 * Shifts the bits of the components right.
 *
 * @param v The vector.
 * @param shift How many bits to shift.
 * @return The resultant vector.
 */
template <typename T>
TVec2<T> operator>>( const TVec2<T>& u, unsigned int shift );

// COMPARISON OPERATOR DECLARATIONS
/**
 * Checks if the components of two vectors are equal.
 *
 * @param u The first vector.
 * @param v The second vector.
 * @return If they are equal.
 */
template <typename T>
bool operator==( const TVec2<T>& u, const TVec2<T>& v );

/**
 * Checks if the components of two vectors are not equal.
 *
 * @param u The first vector.
 * @param v The second vector.
 * @return If they are not equal.
 */
template <typename T>
bool operator!=( const TVec2<T>& u, const TVec2<T>& v );

// IMPLEMENTATION

// IMPLICIT CONSTRUCTORS
template <typename T>
inline
TVec2<T>::TVec2( ) : x( 0 ), y( 0 )
{
}

template <typename T>
inline
TVec2<T>::TVec2( const TVec2<T>& v ) : x( v.x ), y( v.y )
{
}

template <typename T>
inline
TVec2<T>::~TVec2()
{
}

// EXPLICIT CONSTRUCTORS
template <typename T>
template <typename U>
inline
TVec2<T>::TVec2( const U& s ) : x( static_cast<T>( s ) ),
                                y( static_cast<T>( s ) )
{
}

template <typename T>
template <typename U, typename V>
inline
TVec2<T>::TVec2( const U& s1, const V& s2 )
    : x( static_cast<T>( s1 ) ), y( static_cast<T>( s2 ) )
{
}

template <typename T>
template <typename U>
inline
TVec2<T>::TVec2( const TVec2<U>& v )
    : x( static_cast<T>( v.x ) ), y( static_cast<T>( v.y ) )
{
}

// SWIZZLE CONSTRUCTORS
template <typename T>
inline
TVec2<T>::TVec2( const TRef2<T>& r ) : x( r.x ), y( r.y )
{
}

// UNARY OPERATORS
template <typename T>
inline
TVec2<T>& TVec2<T>::operator=( const TVec2<T>& v )
{
    x = v.x;
    y = v.y;
    return *this;
}

template <typename T>
template <typename U>
inline
TVec2<T>& TVec2<T>::operator=( const TVec2<U>& v )
{
    x = static_cast<T>( v.x );
    y = static_cast<T>( v.y );
    return *this;
}

template <typename T>
template <typename U>
inline
TVec2<T>& TVec2<T>::operator+=( const U& s )
{
    x += static_cast<T>( s );
    y += static_cast<T>( s );
    return *this;
}

template <typename T>
template <typename U>
inline
TVec2<T>& TVec2<T>::operator+=( const TVec2<U>& v )
{
    x += static_cast<T>( v.x );
    y += static_cast<T>( v.y );
    return *this;
}

template <typename T>
template <typename U>
inline
TVec2<T>& TVec2<T>::operator-=( const U& s )
{
    x -= static_cast<T>( s );
    y -= static_cast<T>( s );
    return *this;
}

template <typename T>
template <typename U>
inline
TVec2<T>& TVec2<T>::operator-=( const TVec2<U>& v )
{
    x -= static_cast<T>( v.x );
    y -= static_cast<T>( v.y );
    return *this;
}

template <typename T>
template <typename U>
inline
TVec2<T>& TVec2<T>::operator*=( const U& s )
{
    x *= static_cast<T>( s );
    y *= static_cast<T>( s );
    return *this;
}

template <typename T>
template <typename U>
inline
TVec2<T>& TVec2<T>::operator*=( const TVec2<U>& v )
{
    x *= static_cast<T>( v.x );
    y *= static_cast<T>( v.y );
    return *this;
}

template <typename T>
template <typename U>
inline
TVec2<T>& TVec2<T>::operator/=( const U& s )
{
    assert( s != 0 );
    x /= static_cast<T>( s );
    y /= static_cast<T>( s );
    return *this;
}

template <typename T>
template <typename U>
inline
TVec2<T>& TVec2<T>::operator/=( const TVec2<U>& v )
{
    assert( v.x != 0 && v.y != 0 );
    x /= static_cast<T>( v.x );
    y /= static_cast<T>( v.y );
    return *this;
}

template <typename T>
inline
TVec2<T>& TVec2<T>::operator++()
{
    ++x;
    ++y;
    return *this;
}

template <typename T>
inline
TVec2<T>& TVec2<T>::operator--()
{
    --x;
    --y;
    return *this;
}

template <typename T>
inline
TVec2<T>& TVec2<T>::operator++( int )
{
    ++x;
    ++y;
    return *this;
}

template <typename T>
inline
TVec2<T>& TVec2<T>::operator--( int )
{
    --x;
    --y;
    return *this;
}

template <typename T>
inline
TVec2<T> TVec2<T>::operator-() const
{
    return TVec2<T>( -x, -y );
}

template <typename T>
template <typename U>
inline
TVec2<T>& TVec2<T>::operator%=( const U& s )
{
    assert( s != 0 );
    x %= static_cast<T>( s );
    y %= static_cast<T>( s );
    return *this;
}

template <typename T>
template <typename U>
inline
TVec2<T>& TVec2<T>::operator%=( const TVec2<U>& v )
{
    assert( v.x != 0 && v.y != 0 );
    x %= static_cast<T>( v.x );
    y %= static_cast<T>( v.y );
    return *this;
}

// UNARY BITWISE OPERATORS
template <typename T>
template <typename U>
inline
TVec2<T>& TVec2<T>::operator&=( const U& s )
{
    x &= static_cast<T>( s );
    y &= static_cast<T>( s );
    return *this;
}

template <typename T>
template <typename U>
inline
TVec2<T>& TVec2<T>::operator&=( const TVec2<U>& v )
{
    x &= static_cast<T>( v.x );
    y &= static_cast<T>( v.y );
    return *this;
}

template <typename T>
template <typename U>
inline
TVec2<T>& TVec2<T>::operator|=( const U& s )
{
    x |= static_cast<T>( s );
    y |= static_cast<T>( s );
    return *this;
}

template <typename T>
template <typename U>
inline
TVec2<T>& TVec2<T>::operator|=( const TVec2<U>& v )
{
    x |= static_cast<T>( v.x );
    y |= static_cast<T>( v.y );
    return *this;
}

template <typename T>
template <typename U>
inline
TVec2<T>& TVec2<T>::operator^=( const U& s )
{
    x ^= static_cast<T>( s );
    y ^= static_cast<T>( s );
    return *this;
}

template <typename T>
template <typename U>
inline
TVec2<T>& TVec2<T>::operator^=( const TVec2<U>& v )
{
    x ^= static_cast<T>( v.x );
    y ^= static_cast<T>( v.y );
    return *this;
}

template <typename T>
template <typename U>
inline
TVec2<T>& TVec2<T>::operator<<=( const U& s )
{
    x <<= static_cast<T>( s );
    y <<= static_cast<T>( s );
    return *this;
}

template <typename T>
template <typename U>
inline
TVec2<T>& TVec2<T>::operator<<=( const TVec2<U>& v )
{
    x <<= static_cast<T>( v.x );
    y <<= static_cast<T>( v.y );
    return *this;
}

template <typename T>
template <typename U>
inline
TVec2<T>& TVec2<T>::operator>>=( const U& s )
{
    x >>= static_cast<T>( s );
    y >>= static_cast<T>( s );
    return *this;
}

template <typename T>
template <typename U>
inline
TVec2<T>& TVec2<T>::operator>>=( const TVec2<U>& v )
{
    x >>= static_cast<T>( v.x );
    y >>= static_cast<T>( v.y );
    return *this;
}

template <typename T>
inline
TVec2<T> TVec2<T>::operator~() const
{
    return TVec2<T>( ~x, ~y );
}

// ACCESSOR OPERATORS
template <typename T>
inline
const T& TVec2<T>::operator[]( Size index ) const
{
    assert( index >= 0 && index < 2 );
    return ( &x )[index];
}

template <typename T>
inline
T& TVec2<T>::operator[]( Size index )
{
    assert( index >= 0 && index < 2 );
    return ( &x )[index];
}

// BINARY ARITHMETIC OPERATORS
template <typename T>
inline
TVec2<T> operator+( const TVec2<T>& v, const T& s )
{
    return TVec2<T>( v.x + s, v.y + s );
}

template <typename T>
inline
TVec2<T> operator+( const TVec2<T>& u, const TVec2<T>& v )
{
    return TVec2<T>( u.x + v.x, u.y + v.y );
}

template <typename T>
inline
TVec2<T> operator-( const TVec2<T>& v, const T& s )
{
    return TVec2<T>( v.x - s, v.y - s );
}

template <typename T>
inline
TVec2<T> operator-( const TVec2<T>& u, const TVec2<T>& v )
{
    return TVec2<T>( u.x - v.x, u.y - v.y );
}

template <typename T>
inline
TVec2<T> operator*( const TVec2<T>& v, const T& s )
{
    return TVec2<T>( v.x * s, v.y * s );
}

template <typename T>
inline
TVec2<T> operator*( const T& s, const TVec2<T>& v )
{
    return TVec2<T>( s * v.x, s * v.y );
}

template <typename T>
inline
TVec2<T> operator*( const TVec2<T>& u, const TVec2<T>& v )
{
    return TVec2<T>( u.x * v.x, u.y * v.y );
}

template <typename T>
inline
TVec2<T> operator/( const TVec2<T>& v, const T& s )
{
    assert( s != T( 0 ) );
    return TVec2<T>( v.x / s, v.y / s );
}

template <typename T>
inline
TVec2<T> operator/( const T& s, const TVec2<T>& v )
{
    assert( v.x != 0 && v.y != 0 );
    return TVec2<T>( s / v.x, s / v.y );
}

template <typename T>
inline
TVec2<T> operator/( const TVec2<T>& u, const TVec2<T>& v )
{
    assert ( v.x != 0 && v.y != 0  );
    return TVec2<T>( u.x / v.x, u.y / v.y );
}

template <typename T>
inline
TVec2<T> operator%( const TVec2<T>& v, const T& s )
{
    assert( s != 0 );
    return TVec2<T>( v.x % s, v.y % s );
}

template <typename T>
inline
TVec2<T> operator%( const T& s, const TVec2<T>& v )
{
    assert( v.x != 0 && v.y != 0  );
    return TVec2<T>( s % v.x, s % v.y );
}

template <typename T>
inline
TVec2<T> operator%( const TVec2<T>& u, const TVec2<T>& v )
{
    assert ( v.x != 0 && v.y != 0  );
    return TVec2<T>( u.x % v.x, u.y % v.y );
}

// BINARY BITWISE OPERATORS
template <typename T>
inline
TVec2<T> operator&( const TVec2<T>& v, const T& s )
{
    return TVec2<T>( v.x & s, v.y & s );
}

template <typename T>
inline
TVec2<T> operator&( const TVec2<T>& u, const TVec2<T>& v )
{
    return TVec2<T>( u.x & v.x, u.y & v.y );
}

template <typename T>
inline
TVec2<T> operator|( const TVec2<T>& v, const T& s )
{
    return TVec2<T>( v.x | s, v.y | s );
}

template <typename T>
inline
TVec2<T> operator|( const TVec2<T>& u, const TVec2<T>& v )
{
    return TVec2<T>( u.x | v.x, u.y | v.y );
}

template <typename T>
inline
TVec2<T> operator^( const TVec2<T>& v, const T& s )
{
    return TVec2<T>( v.x ^ s, v.y ^ s );
}

template <typename T>
inline
TVec2<T> operator^( const TVec2<T>& u, const TVec2<T>& v )
{
    return TVec2<T>( u.x ^ v.x, u.y ^ v.y );
}

template <typename T>
inline
TVec2<T> operator<<( const TVec2<T>& v, unsigned int shift )
{
    return TVec2<T>( v.x << shift, v.y << shift );
}

template <typename T>
inline
TVec2<T> operator>>( const TVec2<T>& u, unsigned int shift )
{
    return TVec2<T>( u.x >> shift, u.y >> shift );
}

template <typename T>
inline
bool operator==( const TVec2<T>& u, const TVec2<T>& v )
{
    return u.x == v.x && u.y == v.y;
}

template <typename T>
inline
bool operator==( const TVec2<T>& u, const TRef2<T>& v )
{
    return u.x == v.x || u.y == v.y;
}

template <typename T>
inline
bool operator==( const TRef2<T>& u, const TVec2<T>& v )
{
    return u.x == v.x || u.y == v.y;
}

template <typename T>
inline
bool operator==( const TRef2<T>& u, const TRef2<T>& v )
{
    return u.x == v.x || u.y == v.y;
}

template <typename T>
inline
bool operator!=( const TVec2<T>& u, const TVec2<T>& v )
{
    return u.x != v.x || u.y != v.y;
}

template <typename T>
inline
bool operator!=( const TVec2<T>& u, const TRef2<T>& v )
{
    return u.x != v.x || u.y != v.y;
}

template <typename T>
inline
bool operator!=( const TRef2<T>& u, const TVec2<T>& v )
{
    return u.x != v.x || u.y != v.y;
}

template <typename T>
inline
bool operator!=( const TRef2<T>& u, const TRef2<T>& v )
{
    return u.x != v.x || u.y != v.y;
}

// 4D REFERENCE VECTOR

// CONSTRUCTORS
template <typename T>
inline
TRef2<T>::TRef2( T& s1, T& s2 ) : x( s1 ), y( s2 )
{
}

template <typename T>
inline
TRef2<T>::TRef2( TRef2<T>& r ) : x( r.x ), y( r.y )
{
}

template <typename T>
inline
TRef2<T>::TRef2( TVec2<T>& v ) : x( v.x ), y( v.y )
{
}

template <typename T>
inline
TRef2<T>::~TRef2()
{
}

} // End nspc math

} // End nspc gel

#endif //GEL_VEC2_H
