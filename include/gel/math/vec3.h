// vector.h
#ifndef GEL_VECT3_H
#define GEL_VECT3_H
#include <assert.h>
#include "gel/gellib.h"

namespace gel
{

namespace math
{
template <typename T>
class TRef2;

template <typename T>
class TRef3;

template <typename T>
class TRef4;

template <typename T>
class TVec2;

template <typename T>
class TVec4;

template <typename T>
class TVec3
{
  public:
    typedef T ValueType;

    union
    {
        struct { ValueType x, y, z; };
        struct { ValueType r, g, b; };
        struct { ValueType s, t, p; };
        struct { ValueType i, j, k; };
        struct { ValueType hue, sat, lum; };
    };

    // IMPLICIT CONSTRUCTORS
    /**
     * Constructs a new vector.
     */
    TVec3( );

    /**
     * Constructs this vector as a copy of the other.
     * @param v The vector to copy.
     */
    TVec3( const TVec3<T>& v );

    /**
     * Destructs the vector.
     */
    ~TVec3();

    // EXPLICIT CONSTRUCTORS
    /**
     * Constructs a new vector and initializes its components to v.
     * @param v The component value.
     * @tparam U The component value type.
     */
    template <typename U>
    explicit TVec3( const U& s );

    /**
     * Constructs a new vector.
     * @param s1 The first component value.
     * @param s2 The second component value
     * @param s3 The third component value.
     * @tparam U The first component value type.
     * @tparam V The second component value type.
     * @tparam W The third component value type.
     */
    template <typename U, typename V, typename W>
    explicit TVec3( const U& s1, const V& s2, const W& s3 );

    /**
     * Constructs a copy of the vector with the given last component value.
     * @param v The vector to copy.
     * @parma s The last component value.
     * @tparam U The vector type.
     * @tparam V The last component type.
     */
    template <typename U, typename V>
    explicit TVec3( const TVec2<U>& v, const V& s );

    /**
     * Constructs a copy of the vector with the given first component value.
     * @param s The first component value.
     * @param v The vector to copy.
     * @tparam U The first component type.
     * @tparam V The vector type.
     */
    template <typename U, typename V>
    explicit TVec3( const U& s, const TVec2<V>& v );

    /**
     * Constructs a copy of the vector.
     * @param v The vector to copy.
     * @tparam U The component type.
     */
    template <typename U>
    explicit TVec3( const TVec3<U>& v );

    /**
     * Constructs a copy of the vector.
     * @param v The vector to copy.
     * @tparam U The component type.
     */
    template <typename U>
    explicit TVec3( const TVec4<U>& v );

    // SWIZZLE CONSTRUCTORS
    TVec3( const TRef3<T>& r );

    // UNARY OPERATORS
    /**
     * Makes this a copy of the other vector.
     *
     * @param v The vector to copy.
     */
    TVec3<T>& operator=( const TVec3<T>& v );

    /**
     * Makes this a copy of the other vector.
     *
     * @param v The vector to copy.
     * @tparam U The component value type..
     */
    template <typename U>
    TVec3<T>& operator=( const TVec3<U>& v );

    /**
     * Adds a scalar value to the components.
     *
     * @param s The scalar value to add.
     * @tparam U The scalar value type.
     */
    template <typename U>
    TVec3<T>& operator+=( const U& s );

    /**
     * Adds another vector to this.
     *
     * @param v The vector to add.
     * @tparam U The component value type.
     */
    template <typename U>
    TVec3<T>& operator+=( const TVec3<U>& v );

    /**
     * Subtracts a scale from the components.
     *
     * @param s The scalar to subtract.
     * @tparam U The scalar value type.
     */
    template <typename U>
    TVec3<T>& operator-=( const U& s );

    /**
     * Subtracts another vector from this.
     *
     * @param v The vector to subtract.
     * @tparam U The component value type.
     */
    template <typename U>
    TVec3<T>& operator-=( const TVec3<U>& v );

    /**
     * Multiplies the this by a scalar.
     *
     * @param s The scalar to multiply by.
     * @tparam U The scalar value type.
     */
    template <typename U>
    TVec3<T>& operator*=( const U& s );

    /**
     * Multiplies this vector by another.
     *
     * @param v The vector to multiply by.
     * @tparam The component value type.
     */
    template <typename U>
    TVec3<T>& operator*=( const TVec3<U>& v );

    /**
     * Divides this vector by a scalar.
     *
     * @param v The scalar to divide by.
     * @tparam U The scalar value type.
     */
    template <typename U>
    TVec3<T>& operator/=( const U& s );

    /**
     * Divides this vector by another.
     *
     * @param v THe vector to divide by.
     * @tparam U The component value type.
     */
    template <typename U>
    TVec3<T>& operator/=( const TVec3<U>& v );

    /**
     * Adds one to the vector's component values.
     */
    TVec3<T>& operator++( );

    /**
     * Subtracts one from the vector's component values.
     */
    TVec3<T>& operator--( );

    /**
     * Adds one to the vector's component values.
     */
    TVec3<T>& operator++( int );

    /**
     * Subtracts one from the vector's component values.
     */
    TVec3<T>& operator--( int );

    // UNARY BIT OPERATORS
    /**
     * Performs modulo on each of the components.
     *
     * @param s The scalar to perform modulo with.
     * @tparam The scalar value type.
     */
    template <typename U>
    TVec3<T>& operator%=( const U& s );

    /**
     * Performs a component-wise modulus.
     *
     * @param v The vector to perform modulo with.
     * @tparam U The component value type.
     */
    template <typename U>
    TVec3<T>& operator%=( const TVec3<U>& v );

    /**
     * Performs the bitwise-and operation with each of the components.
     *
     * @param s The scalar to perform and with.
     * @tparam U The scalar value type.
     */
    template <typename U>
    TVec3<T>& operator&=( const U& s );

    /**
     * Performs a component-wise bitwise-and operation.
     *
     * @param v The vector to perform and with.
     * @tparam U The component value type.
     */
    template <typename U>
    TVec3<T>& operator&=( const TVec3<U>& v );

    /**
     * Performs the bitwise-or operation with each of the components.
     *
     * @param s The scalar to perform or with.
     * @tparam U The scalar value type.
     */
    template <typename U>
    TVec3<T>& operator|=( const U& s );

    /**
     * Performs a component-wise bitwise-or operation.
     *
     * @param s The vector to perform or with.
     * @tparam U The scalar value type.
     */
    template <typename U>
    TVec3<T>& operator|=( const TVec3<U>& v );

    /**
     * Performs the bitwise-xor operation with each of the components.
     *
     * @param s The scalar to perform xor with.
     * @tparam U The component value type.
     */
    template <typename U>
    TVec3<T>& operator^=( const U& s );

    /**
     * Performs a component-wise bitwise-xor operation.
     *
     * @param v The vector to perform xor with.
     * @tparam U The component value type.
     */
    template <typename U>
    TVec3<T>& operator^=( const TVec3<U>& v );

    /**
     * Performs the shift-left operation with each of the components.
     *
     * @param s The scalar to perform shift left with.
     * @tparam U The scalar value type.
     */
    template <typename U>
    TVec3<T>& operator<<=( const U& s );

    /**
     * Performs a component-wise bitwise-shift left operation.
     *
     * @param The vector to perform shift left with.
     * @tparam U The component value type.
     */
    template <typename U>
    TVec3<T>& operator<<=( const TVec3<U>& v );

    /**
     * Performs the shift-right operation with each of the components.
     *
     * @param s The scalar to perform shift right with.
     * @tparam U The scalar value type.
     */
    template <typename U>
    TVec3<T>& operator>>=( const U& s );

    /**
     * Performs a component-wise bitwise-shift right operation.
     *
     * @param The vector to perform shift right with.
     * @tparam U The component value type.
     */
    template <typename U>
    TVec3<T>& operator>>=( const TVec3<U>& v );

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
class TRef3
{
  public:
    T& x;
    T& y;
    T& z;

    // CONSTRUCTORS
    /**
     * Constructs reference vector for the reference components.
     * @param s1 The first reference component.
     * @param s2 The second reference component.
     * @param s3 The third reference component.
     */
    TRef3( T& s1, T& s2, T& s3 );

    /**
     * Constructs a new reference vector for an existing reference vector.
     * @param r The reference vector.
     */
    TRef3( const TRef3<T>& r );

    /**
     * Constructs a new reference vector for the given vector.
     * @param v The vector to reference.
     */
    TRef3( const TVec3<T>& v );

    /**
     * Destructs the reference vector.
     */
    ~TRef3();
};

// 3D VECTOR

// IMPLICIT CONSTRUCTORS
template <typename T>
inline
TVec3<T>::TVec3( ) : x( 0 ), y( 0 ), z( 0 )
{
}

template <typename T>
inline
TVec3<T>::TVec3( const TVec3<T>& v ) : x( v.x ), y( v.y ), z( v.z )
{
}

template <typename T>
TVec3<T>::~TVec3()
{
}

// EXPLICIT CONSTRUCTORS
template <typename T>
template <typename U>
inline
TVec3<T>::TVec3( const U& s ) : x( static_cast<T>( s ) ),
                                y( static_cast<T>( s ) ),
                                z( static_cast<T>( s ) )
{
}

template <typename T>
template <typename U, typename V, typename W>
inline
TVec3<T>::TVec3( const U& s1, const V& s2, const W& s3 )
    : x( static_cast<T>( s1 ) ), y( static_cast<T>( s2 ) ),
      z( static_cast<T>( s3 ) )
{
}

template <typename T>
template <typename U, typename V>
TVec3<T>::TVec3( const TVec2<U>& v, const V& s )
    : x( static_cast<T>( v.x ) ), y( static_cast<T>( v.y ) ),
      z( static_cast<T>( s ) )
{
}

template <typename T>
template <typename U, typename V>
TVec3<T>::TVec3( const U& s, const TVec2<V>& v )
    : x( static_cast<T>( s ) ), y( static_cast<T>( v.x ) ),
      z( static_cast<T>( v.y ) )
{
}

template <typename T>
template <typename U>
inline
TVec3<T>::TVec3( const TVec3<U>& v )
    : x( static_cast<T>( v.x ) ), y( static_cast<T>( v.y ) ),
      z( static_cast<T>( v.z ) )
{
}

template <typename T>
template <typename U>
inline
TVec3<T>::TVec3( const TVec4<U>& v )
    : x( static_cast<T>( v.x ) ), y( static_cast<T>( v.y ) ),
      z( static_cast<T>( v.z ) )
{
}

// SWIZZLE CONSTRUCTORS
template <typename T>
inline
TVec3<T>::TVec3( const TRef3<T>& r ) : x( r.x ), y( r.y ), y( r.z )
{
}

// UNARY OPERATORS
template <typename T>
inline
TVec3<T>& TVec3<T>::operator=( const TVec3<T>& v )
{
    x = v.x;
    y = v.y;
    z = v.z;
    return *this;
}

template <typename T>
template <typename U>
inline
TVec3<T>& TVec3<T>::operator=( const TVec3<U>& v )
{
    x = static_cast<T>( v.x );
    y = static_cast<T>( v.y );
    z = static_cast<T>( v.z );
    return *this;
}

template <typename T>
template <typename U>
inline
TVec3<T>& TVec3<T>::operator+=( const U& s )
{
    x += static_cast<T>( s );
    y += static_cast<T>( s );
    z += static_cast<T>( s );
    return *this;
}

template <typename T>
template <typename U>
inline
TVec3<T>& TVec3<T>::operator+=( const TVec3<U>& v )
{
    x += static_cast<T>( v.x );
    y += static_cast<T>( v.y );
    z += static_cast<T>( v.z );
    return *this;
}

template <typename T>
template <typename U>
inline
TVec3<T>& TVec3<T>::operator-=( const U& s )
{
    x -= static_cast<T>( s );
    y -= static_cast<T>( s );
    z -= static_cast<T>( s );
    return *this;
}

template <typename T>
template <typename U>
inline
TVec3<T>& TVec3<T>::operator-=( const TVec3<U>& v )
{
    x -= static_cast<T>( v.x );
    y -= static_cast<T>( v.y );
    z -= static_cast<T>( v.z );
    return *this;
}

template <typename T>
template <typename U>
inline
TVec3<T>& TVec3<T>::operator*=( const U& s )
{
    x *= static_cast<T>( s );
    y *= static_cast<T>( s );
    z *= static_cast<T>( s );
    return *this;
}

template <typename T>
template <typename U>
inline
TVec3<T>& TVec3<T>::operator*=( const TVec3<U>& v )
{
    x *= static_cast<T>( v.x );
    y *= static_cast<T>( v.y );
    z *= static_cast<T>( v.z );
    return *this;
}

template <typename T>
template <typename U>
inline
TVec3<T>& TVec3<T>::operator/=( const U& s )
{
    assert( s != 0 );
    x /= static_cast<T>( s );
    y /= static_cast<T>( s );
    z /= static_cast<T>( s );
    return *this;
}

template <typename T>
template <typename U>
inline
TVec3<T>& TVec3<T>::operator/=( const TVec3<U>& v )
{
    assert( v.x != 0 && v.y != 0 && v.z != 0 );
    x /= static_cast<T>( v.x );
    y /= static_cast<T>( v.y );
    z /= static_cast<T>( v.z );
    return *this;
}

template <typename T>
inline
TVec3<T>& TVec3<T>::operator++()
{
    ++x;
    ++y;
    ++z;
    return *this;
}

template <typename T>
inline
TVec3<T>& TVec3<T>::operator--()
{
    --x;
    --y;
    --z;
    return *this;
}

template <typename T>
inline
TVec3<T>& TVec3<T>::operator++( int )
{
    ++x;
    ++y;
    ++z;
    return *this;
}

template <typename T>
inline
TVec3<T>& TVec3<T>::operator--( int )
{
    --x;
    --y;
    --z;
    return *this;
}

// UNARY BIT OPERATORS
template <typename T>
template <typename U>
inline
TVec3<T>& TVec3<T>::operator%=( const U& s )
{
    assert( s != 0 );
    x %= static_cast<T>( s );
    y %= static_cast<T>( s );
    z %= static_cast<T>( s );
    return *this;
}

template <typename T>
template <typename U>
inline
TVec3<T>& TVec3<T>::operator%=( const TVec3<U>& v )
{
    assert( v.x != 0 && v.y != 0 && v.z != 0 );
    x %= static_cast<T>( v.x );
    y %= static_cast<T>( v.y );
    z %= static_cast<T>( v.z );
    return *this;
}

template <typename T>
template <typename U>
inline
TVec3<T>& TVec3<T>::operator&=( const U& s )
{
    x &= static_cast<T>( s );
    y &= static_cast<T>( s );
    z &= static_cast<T>( s );
    return *this;
}

template <typename T>
template <typename U>
inline
TVec3<T>& TVec3<T>::operator&=( const TVec3<U>& v )
{
    x &= static_cast<T>( v.x );
    y &= static_cast<T>( v.y );
    z &= static_cast<T>( v.z );
    return *this;
}

template <typename T>
template <typename U>
inline
TVec3<T>& TVec3<T>::operator|=( const U& s )
{
    x |= static_cast<T>( s );
    y |= static_cast<T>( s );
    z |= static_cast<T>( s );
    return *this;
}

template <typename T>
template <typename U>
inline
TVec3<T>& TVec3<T>::operator|=( const TVec3<U>& v )
{
    x |= static_cast<T>( v.x );
    y |= static_cast<T>( v.y );
    z |= static_cast<T>( v.z );
    return *this;
}

template <typename T>
template <typename U>
inline
TVec3<T>& TVec3<T>::operator^=( const U& s )
{
    x ^= static_cast<T>( s );
    y ^= static_cast<T>( s );
    z ^= static_cast<T>( s );
    return *this;
}

template <typename T>
template <typename U>
inline
TVec3<T>& TVec3<T>::operator^=( const TVec3<U>& v )
{
    x ^= static_cast<T>( v.x );
    y ^= static_cast<T>( v.y );
    z ^= static_cast<T>( v.z );
    return *this;
}

template <typename T>
template <typename U>
inline
TVec3<T>& TVec3<T>::operator<<=( const U& s )
{
    x <<= static_cast<T>( s );
    y <<= static_cast<T>( s );
    z <<= static_cast<T>( s );
    return *this;
}

template <typename T>
template <typename U>
inline
TVec3<T>& TVec3<T>::operator<<=( const TVec3<U>& v )
{
    x <<= static_cast<T>( v.x );
    y <<= static_cast<T>( v.y );
    z <<= static_cast<T>( v.z );
    return *this;
}

template <typename T>
template <typename U>
inline
TVec3<T>& TVec3<T>::operator>>=( const U& s )
{
    x >>= static_cast<T>( s );
    y >>= static_cast<T>( s );
    z >>= static_cast<T>( s );
    return *this;
}

template <typename T>
template <typename U>
inline
TVec3<T>& TVec3<T>::operator>>=( const TVec3<U>& v )
{
    x >>= static_cast<T>( v.x );
    y >>= static_cast<T>( v.y );
    z >>= static_cast<T>( v.z );
    return *this;
}

// ACCESSOR OPERATORS
template <typename T>
inline
const T& TVec3<T>::operator[]( Size index ) const
{
    assert( index >= 0 && index < 3 );
    return ( &x )[index];
}

template <typename T>
inline
T& TVec3<T>::operator[]( Size index )
{
    assert( index >= 0 && index < 3 );
    return ( &x )[index];
}

// 3D REFERENCE VECTOR

// CONSTRUCTORS
template <typename T>
inline
TRef3<T>::TRef3( T& s1, T& s2, T& s3 ) : x( s1 ), y( s2 ), z( s3 )
{
}

template <typename T>
inline
TRef3<T>::TRef3( const TRef3<T>& r ) : x( r.x ), y( r.y ), z( r.z )
{
}

template <typename T>
inline
TRef3<T>::TRef3( const TVec3<T>& v ) : x( v.x ), y( v.y ), z( v.z )
{
}

template <typename T>
inline
TRef3<T>::~TRef3()
{
}

} // End nspc math

} // End nspc gel

#endif //GEL_VECTOR_H
