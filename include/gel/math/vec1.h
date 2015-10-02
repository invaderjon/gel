// vec1.h
#ifndef GEL_VEC1_H
#define GEL_VEC1_H
#include <assert.h>
#include "gel/gellib.h"

namespace gel
{

namespace math
{

template <typename T>
class TRef1;

template <typename T>
class TRef2;

template <typename T>
class TRef3;

template <typename T>
class TRef4;

template <typename T>
class TVec2;

template <typename T>
class TVec3;

template <typename T>
class TVec4;

template <typename T>
class TVec1
{
  public:
    typedef T ValueType;

    union
    {
        struct { ValueType x; };
        struct { ValueType r; };
        struct { ValueType s; };
        struct { ValueType i; };
        struct { ValueType hue; };
    };

    // IMPLICIT CONSTRUCTORS
    /**
     * Constructs a new vector.
     */
    TVec1();

    /**
     * Constructs a new vector that is a copy of another.
     *
     * @param v The vector to copy.
     */
    TVec1( const TVec1<T>& v );

    /**
     * Destructs the vector.
     */
    ~TVec1();

    // EXPLICIT CONSTRUCTORS
    /**
     * Constructs a new vector and initializes its components to v.
     * @param v The component value.
     * @tparam U The component value type.
     */
    template <typename U>
    explicit TVec1( const U& s );

    /**
     * Constructs a copy of the vector with the given first component value.
     *
     * @param s The first component value.
     * @param v The vector to copy.
     * @tparam U The first component type.
     * @tparam V The vector type.
     */
    template <typename U>
    explicit TVec1( const TVec1<U>& v );

    /**
     * Constructs a copy of the vector with the given first component value.
     *
     * @param s The first component value.
     * @param v The vector to copy.
     * @tparam U The first component type.
     * @tparam V The vector type.
     */
    template <typename U>
    explicit TVec1( const TVec2<U>& v );

    /**
     * Constructs a copy of the vector.
     *
     * @param v The vector to copy.
     * @tparam U The component type.
     */
    template <typename U>
    explicit TVec1( const TVec3<U>& v );

    /**
     * Constructs a copy of the vector.
     *
     * @param v The vector to copy.
     * @tparam U The component type.
     */
    template <typename U>
    explicit TVec1( const TVec4<U>& v );

    // SWIZZLE CONSTRUCTOR
    /**
     * Constructs a new vector that is a copy of a reference vector.
     */
    TVec1( const TRef1<T>& r );

    // UNARY OPERATORS
    /**
     * Makes this a copy of the other vector.
     *
     * @param v The vector to copy.
     */
    TVec1<T>& operator=( const TVec1<T>& v );

    /**
     * Makes this a copy of the other vector.
     *
     * @param v The vector to copy.
     * @tparam U The component value type..
     */
    template <typename U>
    TVec1<T>& operator=( const TVec1<U>& v );

    /**
     * Adds a scalar value to the components.
     *
     * @param s The scalar value to add.
     * @tparam U The scalar value type.
     */
    template <typename U>
    TVec1<T>& operator+=( const U& s );

    /**
     * Adds another vector to this.
     *
     * @param v The vector to add.
     * @tparam U The component value type.
     */
    template <typename U>
    TVec1<T>& operator+=( const TVec1<U>& v );

    /**
     * Subtracts a scale from the components.
     *
     * @param s The scalar to subtract.
     * @tparam U The scalar value type.
     */
    template <typename U>
    TVec1<T>& operator-=( const U& s );

    /**
     * Subtracts another vector from this.
     *
     * @param v The vector to subtract.
     * @tparam U The component value type.
     */
    template <typename U>
    TVec1<T>& operator-=( const TVec1<U>& v );

    /**
     * Multiplies the this by a scalar.
     *
     * @param s The scalar to multiply by.
     * @tparam U The scalar value type.
     */
    template <typename U>
    TVec1<T>& operator*=( const U& s );

    /**
     * Multiplies this vector by another.
     *
     * @param v The vector to multiply by.
     * @tparam The component value type.
     */
    template <typename U>
    TVec1<T>& operator*=( const TVec1<U>& v );

    /**
     * Divides this vector by a scalar.
     *
     * @param v The scalar to divide by.
     * @tparam U The scalar value type.
     */
    template <typename U>
    TVec1<T>& operator/=( const U& s );

    /**
     * Divides this vector by another.
     *
     * @param v THe vector to divide by.
     * @tparam U The component value type.
     */
    template <typename U>
    TVec1<T>& operator/=( const TVec1<U>& v );

    /**
     * Adds one to the vector's component values.
     */
    TVec1<T>& operator++();

    /**
     * Subtracts one from the vector's component values.
     */
    TVec1<T>& operator--();

    TVec1<T>& operator++( int );

    TVec1<T>& operator--( int );


    // UNARY BIT OPERATORS
    /**
     * Performs modulo on each of the components.
     *
     * @param s The scalar to perform modulo with.
     * @tparam The scalar value type.
     */
    template <typename U>
    TVec1<T>& operator%=( const U& s );

    /**
     * Performs a component-wise modulus.
     *
     * @param v The vector to perform modulo with.
     * @tparam U The component value type.
     */
    template <typename U>
    TVec1<T>& operator%=( const TVec1<U>& v );

    /**
     * Performs the bitwise-and operation with each of the components.
     *
     * @param s The scalar to perform and with.
     * @tparam U The scalar value type.
     */
    template <typename U>
    TVec1<T>& operator&=( const U& s );

    /**
     * Performs a component-wise bitwise-and operation.
     *
     * @param v The vector to perform and with.
     * @tparam U The component value type.
     */
    template <typename U>
    TVec1<T>& operator&=( const TVec1<U>& v );

    /**
     * Performs the bitwise-or operation with each of the components.
     *
     * @param s The scalar to perform or with.
     * @tparam U The scalar value type.
     */
    template <typename U>
    TVec1<T>& operator|=( const U& s );

    /**
     * Performs a component-wise bitwise-or operation.
     *
     * @param s The vector to perform or with.
     * @tparam U The scalar value type.
     */
    template <typename U>
    TVec1<T>& operator|=( const TVec1<U>& v );

    /**
     * Performs the bitwise-xor operation with each of the components.
     *
     * @param s The scalar to perform xor with.
     * @tparam U The component value type.
     */
    template <typename U>
    TVec1<T>& operator^=( const U& s );

    /**
     * Performs a component-wise bitwise-xor operation.
     *
     * @param v The vector to perform xor with.
     * @tparam U The component value type.
     */
    template <typename U>
    TVec1<T>& operator^=( const TVec1<U>& v );

    /**
     * Performs the shift-left operation with each of the components.
     *
     * @param s The scalar to perform shift left with.
     * @tparam U The scalar value type.
     */
    template <typename U>
    TVec1<T>& operator<<=( const U& s );

    /**
     * Performs a component-wise bitwise-shift left operation.
     *
     * @param The vector to perform shift left with.
     * @tparam U The component value type.
     */
    template <typename U>
    TVec1<T>& operator<<=( const TVec1<U>& v );

    /**
     * Performs the shift-right operation with each of the components.
     *
     * @param s The scalar to perform shift right with.
     * @tparam U The scalar value type.
     */
    template <typename U>
    TVec1<T>& operator>>=( const U& s );

    /**
     * Performs a component-wise bitwise-shift right operation.
     *
     * @param The vector to perform shift right with.
     * @tparam U The component value type.
     */
    template <typename U>
    TVec1<T>& operator>>=( const TVec1<U>& v );

    // ACCESSOR OPERATORS
    /**
     * Gets the vector component value at the given index.
     */
    const ValueType& operator[]( Size index ) const;

    /**
     * Sets the vector component value at the given index.
     */
    ValueType& operator[]( Size index );
};

template <typename T>
class TRef1
{
  public:
    T& x;

    // CONSTRUCTORS
    /**
     * Constructs reference vector for the reference components.
     * @param s1 The first reference component.
     * @param s2 The second reference component.
     */
    TRef1( T& s1 );

    /**
     * Constructs a new reference vector for an existing reference vector.
     * @param r The reference vector.
     */
    TRef1( const TRef1<T>& r );

    /**
     * Constructs a new reference vector for the given vector.
     * @param v The vector to reference.
     */
    TRef1( const TVec1<T>& v );

    /**
     * Destructs the reference vector.
     */
    ~TRef1();
};

// 1D VECTOR

// IMPLICIT CONSTRUCTORS
template <typename T>
inline
TVec1<T>::TVec1( ) : x( 0 )
{
}

template <typename T>
inline
TVec1<T>::TVec1( const TVec1<T>& v ) : x( v.x )
{
}

template <typename T>
inline
TVec1<T>::~TVec1()
{
}

// EXPLICIT CONSTRUCTORS
template <typename T>
template <typename U>
inline
TVec1<T>::TVec1( const U& s ) : x( static_cast<T>( s ) )
{
}

template <typename T>
template <typename U>
inline
TVec1<T>::TVec1( const TVec2<U>& v ) : x( static_cast<T>( v.x ) )
{
}

template <typename T>
template <typename U>
inline
TVec1<T>::TVec1( const TVec3<U>& v ) : x( static_cast<T>( v.x ) )
{
}

template <typename T>
template <typename U>
inline
TVec1<T>::TVec1( const TVec4<U>& v ) : x( static_cast<T>( v.x ) )
{
}

// SWIZZLE CONSTRUCTORS
template <typename T>
inline
TVec1<T>::TVec1( const TRef1<T>& r ) : x( r.x )
{
}

// UNARY OPERATORS
template <typename T>
inline
TVec1<T>& TVec1<T>::operator=( const TVec1<T>& v )
{
    x = v.x;
    return *this;
}

template <typename T>
template <typename U>
inline
TVec1<T>& TVec1<T>::operator=( const TVec1<U>& v )
{
    x = static_cast<T>( v.x );
    return *this;
}

template <typename T>
template <typename U>
inline
TVec1<T>& TVec1<T>::operator+=( const U& s )
{
    x += static_cast<T>( s );
    return *this;
}

template <typename T>
template <typename U>
inline
TVec1<T>& TVec1<T>::operator+=( const TVec1<U>& v )
{
    x += static_cast<T>( v.x );
    return *this;
}

template <typename T>
template <typename U>
inline
TVec1<T>& TVec1<T>::operator-=( const U& s )
{
    x -= static_cast<T>( s );
    return *this;
}

template <typename T>
template <typename U>
inline
TVec1<T>& TVec1<T>::operator-=( const TVec1<U>& v )
{
    x -= static_cast<T>( v.x );
    return *this;
}

template <typename T>
template <typename U>
inline
TVec1<T>& TVec1<T>::operator*=( const U& s )
{
    x *= static_cast<T>( s );
    return *this;
}

template <typename T>
template <typename U>
inline
TVec1<T>& TVec1<T>::operator*=( const TVec1<U>& v )
{
    x *= static_cast<T>( v.x );
    return *this;
}

template <typename T>
template <typename U>
inline
TVec1<T>& TVec1<T>::operator/=( const U& s )
{
    assert( s != 0 );
    x /= static_cast<T>( s );
    return *this;
}

template <typename T>
template <typename U>
inline
TVec1<T>& TVec1<T>::operator/=( const TVec1<U>& v )
{
    assert( v.x != 0 );
    x /= static_cast<T>( v.x );
    return *this;
}

template <typename T>
inline
TVec1<T>& TVec1<T>::operator++()
{
    ++x;
    return *this;
}

template <typename T>
inline
TVec1<T>& TVec1<T>::operator--()
{
    --x;
    return *this;
}

template <typename T>
inline
TVec1<T>& TVec1<T>::operator++( int )
{
    ++x;
    return *this;
}

template <typename T>
inline
TVec1<T>& TVec1<T>::operator--( int )
{
    --x;
    return *this;
}

// UNARY BIT OPERATORS
template <typename T>
template <typename U>
inline
TVec1<T>& TVec1<T>::operator%=( const U& s )
{
    assert( s != 0 );
    x %= static_cast<T>( s );
    return *this;
}

template <typename T>
template <typename U>
inline
TVec1<T>& TVec1<T>::operator%=( const TVec1<U>& v )
{
    assert( v.x != 0 );
    x %= static_cast<T>( v.x );
    return *this;
}

template <typename T>
template <typename U>
inline
TVec1<T>& TVec1<T>::operator&=( const U& s )
{
    x &= static_cast<T>( s );
    return *this;
}

template <typename T>
template <typename U>
inline
TVec1<T>& TVec1<T>::operator&=( const TVec1<U>& v )
{
    x &= static_cast<T>( v.x );
    return *this;
}

template <typename T>
template <typename U>
inline
TVec1<T>& TVec1<T>::operator|=( const U& s )
{
    x |= static_cast<T>( s );
    return *this;
}

template <typename T>
template <typename U>
inline
TVec1<T>& TVec1<T>::operator|=( const TVec1<U>& v )
{
    x |= static_cast<T>( v.x );
    return *this;
}

template <typename T>
template <typename U>
inline
TVec1<T>& TVec1<T>::operator^=( const U& s )
{
    x ^= static_cast<T>( s );
    return *this;
}

template <typename T>
template <typename U>
inline
TVec1<T>& TVec1<T>::operator^=( const TVec1<U>& v )
{
    x ^= static_cast<T>( v.x );
    return *this;
}

template <typename T>
template <typename U>
inline
TVec1<T>& TVec1<T>::operator<<=( const U& s )
{
    x <<= static_cast<T>( s );
    return *this;
}

template <typename T>
template <typename U>
inline
TVec1<T>& TVec1<T>::operator<<=( const TVec1<U>& v )
{
    x <<= static_cast<T>( v.x );
    return *this;
}

template <typename T>
template <typename U>
inline
TVec1<T>& TVec1<T>::operator>>=( const U& s )
{
    x >>= static_cast<T>( s );
    return *this;
}

template <typename T>
template <typename U>
inline
TVec1<T>& TVec1<T>::operator>>=( const TVec1<U>& v )
{
    x >>= static_cast<T>( v.x );
    return *this;
}

// ACCESSOR OPERATORS
template <typename T>
inline
const T& TVec1<T>::operator[]( Size index ) const
{
    assert( index >= 0 && index < 1 );
    return ( &x )[index];
}

template <typename T>
inline
T& TVec1<T>::operator[]( Size index )
{
    assert( index >= 0 && index < 1 );
    return ( &x )[index];
}

// 1D REFERENCE VECTOR

// CONSTRUCTORS
template <typename T>
inline
TRef1<T>::TRef1( T& s1 ) : x( s1 )
{
}

template <typename T>
inline
TRef1<T>::TRef1( const math::TRef1<T>& r ) : x( r.x )
{
}

template <typename T>
inline
TRef1<T>::TRef1( const TVec1<T>& v ) : x( v.x )
{
}

template <typename T>
inline
TRef1<T>::~TRef1()
{
}

} // End nspc math

} // End nspc gel

#endif //GEL_VEC2_H
