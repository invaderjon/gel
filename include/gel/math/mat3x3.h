// mat3x3.h
#ifndef GEL_MAT3X3_H
#define GEL_MAT3X3_H

#include <assert.h>
#include <gel/gellib.h>
#include <gel/math/vec3.h>
#include <gel/math/mat_math.h>
#include <iostream>

/**
 * This protects against template issues where U could also be one of the undesired types thereby
 * hiding another function.
 */
#define VALIDATE( T, U, R ) \
typename std::enable_if<!std::is_same<typename TMat3x3<T>::Column, U>::value && \
                        !std::is_same<typename TMat3x3<T>::Row,    U>::value, R>::type

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
class TVec3;

template <typename T>
class TVec4;

template <typename T>
class TMat2x2;

template <typename T>
class TMat3x3;

template <typename T>
class TMat4x4;

template <typename T>
class TMat3x3
{
  public:
    // TYPES
    typedef T Value;
    typedef TVec3<T> Column;
    typedef TVec3<T> Row;

  private:
    /**
     * The columns.
     */
    Column _value[3];

  public:
    // CONSTANTS
    static const int COLUMNS = 3;
    static const int ROWS = 3;

    static const TMat3x3<T> IDENTITY;
    static const TMat3x3<T> ZERO;

    // CONSTRUCTORS
    /**
     * Constructs a new identity matrix.
     */
    TMat3x3();

    /**
     * Constructs a copy of the given matrix.
     *
     * @param m The matrix to copy.
     */
    TMat3x3( const TMat3x3<T>& m );

    // CONVERSION CONSTRUCTORS
    /**
     * Constructs a new diagonal matrix.
     *
     * @param s The diagonal value.
     */
    template <typename U>
    explicit TMat3x3( const U& s );

    /**
     * Constructs a new matrix.
     *
     * @param x1 The C1R1 value
     * @param x2 The C2R1 value.
     * @param x3 The C3R1 value.
     * @param y1 The C1R2 value.
     * @param y2 The C2R2 value.
     * @param y3 The C3R2 value.
     * @param z1 The C1R3 value.
     * @param z2 The C2R3 value.
     * @param z3 The C3R3 value.
     */
    template <typename X1, typename X2, typename X3,
              typename Y1, typename Y2, typename Y3,
              typename Z1, typename Z2, typename Z3>
    explicit TMat3x3( const X1& x1, const X2& x2, const X3& x3,
                      const Y1& y1, const Y2& y2, const Y3& y3,
                      const Z1& z1, const Z2& z2, const Z3& z3 );

    /**
     * Constructs a new matrix.
     *
     * @param c1 The first column.
     * @param c2 The second column.
     * @param c3 The third column.
     */
    template <typename I, typename J, typename K>
    explicit TMat3x3( const TVec3<I>& c1, const TVec3<J>& c2, const TVec3<K>& c3 );

    /**
     * Constructs a 4x4 copy of the give matrix.
     *
     * @param m The matrix to copy.
     */
    template <typename U>
    explicit TMat3x3( const TMat2x2<U>& m );

    /**
     * Constructs a 4x4 copy of the give matrix.
     *
     * @param m The matrix to copy.
     */
    template <typename U>
    explicit TMat3x3( const TMat3x3<U>& m );

    /**
     * Constructs a 4x4 copy of the give matrix.
     *
     * @param m The matrix to copy.
     */
    template <typename U>
    explicit TMat3x3( const TMat4x4<U>& m );

    /**
     * Destructs a matrix.
     */
    ~TMat3x3();

    // ACCESSOR FUNCTIONS
    /**
     * Gets the ith column in the matrix.
     *
     * @param i The index.
     * @return The column.
     */
    const Column& operator[]( Size i ) const;

    /**
     * Gets the ith column in the matrix.
     *
     * @param i The index.
     * @return The column.
     */
    Column& operator[]( Size i );

    // ASSIGNMENT OPERATORS
    /**
     * Makes this a copy of the other matrix.
     *
     * @param m The matrix to copy.
     * @return The copy.
     */
    template <typename U>
    TMat3x3<T>& operator=( const TMat3x3<U>& m );

    // ARITHMETIC UNARY OPERATORS
    /**
     * Adds a scalar value to the components.
     *
     * @param s The scalar to add.
     */
    template <typename U>
    TMat3x3<T>& operator+=( const U& s );

    /**
     * Adds another matrix to this.
     *
     * @param The matrix to add.
     * @return The resulting matrix.
     */
    template <typename U>
    TMat3x3<T>& operator+=( const TMat3x3<U>& m );

    /**
     * Subtracts a scalar value from the components.
     *
     * @param s The scalar to subtract.
     * @return The resulting matrix.
     */
    template <typename U>
    TMat3x3<T>& operator-=( const U& s );

    /**
     * Subtracts another matrix from this.
     *
     * @param m The matrix to subtract.
     * @return The resulting matrix.
     */
    template <typename U>
    TMat3x3<T>& operator-=( const TMat3x3<U>& m );

    /**
     * Multiplies the components by a scalar value.
     *
     * @param s The scalar to multiply by.
     * @return The resulting matrix.
     */
    template <typename U>
    TMat3x3<T>& operator*=( const U& s );

    /**
     * Multiplies this with another matrix.
     *
     * @param m The matrix to multiply by.
     * @return The resulting matrix.
     */
    template <typename U>
    TMat3x3<T>& operator*=( const TMat3x3<U>& m );

    /**
     * Divides the components by a scalar value.
     *
     * @param s The scalar to divide by.
     * @return The resulting matrix.
     */
    template <typename U>
    TMat3x3<T>& operator/=( const U& s );

    /**
     * Divides this by another matrix.
     *
     * @param m The matrix to divide by.
     * @return The resulting matrix.
     */
    template <typename U>
    TMat3x3<T>& operator/=( const TMat3x3<U>& m );

    /**
     * Gets the modulus of the components with a scalar value.
     *
     * @param s The scalar to modulo with.
     * @return The resulting matrix.
     */
    template <typename U>
    TMat3x3<T>& operator%=( const U& s );

    /**
     * Performs modulo with the components of the other matrix.
     *
     * @param m The matrix.
     * @return The resulting matrix.
     */
    template <typename U>
    TMat3x3<T>& operator%=( const TMat3x3<U>& m );

    /**
     * Pre-increments the components..
     *
     * @return The resulting matrix.
     */
    TMat3x3<T>& operator++();

    /**
     * Pre-decrements the components.
     *
     * @return The resulting matrix.
     */
    TMat3x3<T>& operator--();

    /**
     * Post-increments the components.
     *
     * @return The resulting matrix.
     */
    TMat3x3<T>& operator++( int );

    /**
     * Post-increments the components.
     *
     * @return The resulting matrix.
     */
    TMat3x3<T>& operator--( int );

    /**
     * Gets the negative matrix.
     *
     * @return The negative matrix.
     */
    TMat3x3<T> operator-() const;

    // BITWISE UNARY OPERATORS
    /**
     * Performs bitwise AND with the components and a scalar.
     *
     * @param s The scalar.
     * @return The resulting matrix.
     */
    template <typename U>
    TMat3x3<T>& operator&=( const U& s );

    /**
     * Performs a component-wise AND operation.
     *
     * @param m The other matrix.
     * @return The resulting matrix.
     */
    template <typename U>
    TMat3x3<T>& operator&=( const TMat3x3<U>& m );

    /**
     * Performs bitwise OR with the components and a scalar.
     *
     * @param s The scalar.
     * @return The resulting matrix.
     */
    template <typename U>
    TMat3x3<T>& operator|=( const U& s );

    /**
     * Performs a component-wise OR operation.
     *
     * @param m The other matrix.
     * @return The resulting matrix.
     */
    template <typename U>
    TMat3x3<T>& operator|=( const TMat3x3<U>& s );

    /**
     * Performs bitwise XOR with the components and a scalar.
     *
     * @param s The scalar.
     * @return The resulting matrix.
     */
    template <typename U>
    TMat3x3<T>& operator^=( const U& s );

    /**
     * Performs a component-wise XOR operation.
     *
     * @param m The other matrix.
     * @return The resulting matrix.
     */
    template <typename U>
    TMat3x3<T>& operator^=( const TMat3x3<U>& s );

    /**
     * Shifts left each component by the specified number of bits.
     *
     * @param shift The number of bits to shift.
     * @return The resulting matrix.
     */
    TMat3x3<T>& operator<<=( uint32 shift );

    /**
     * Shifts right each component by the specified number of bits.
     *
     * @param shift The number of bits to shift.
     * @return The resulting matrix.
     */
    TMat3x3<T>& operator>>=( uint32 shift );

    /**
     * Gets the bitwise inverse of the components.
     *
     * @return The resulting matrix.
     */
    TMat3x3<T> operator~() const;
};

// ARITHMETIC BINARY OPERATOR DECLARATIONS
/**
 * Adds a scalar to the components of a matrix.
 *
 * @param m The matrix.
 * @param s The scalar.
 * @return The resulting matrix.
 */
template <typename T, typename U>
TMat3x3<T> operator+( const TMat3x3<T>& m, const U& s );

/**
 * Adds two matrices together.
 *
 * @param m1 The first matrix.
 * @param m2 The second matrix.
 * @return The resulting matrix.
 */
template <typename T>
TMat3x3<T> operator+( const TMat3x3<T>& m1, const TMat3x3<T>& m2 );

/**
 * Subtracts a scalar from the components of a matrix.
 *
 * @param m The matrix.
 * @param s The scalar.
 * @return The resulting matrix.
 */
template <typename T, typename U>
TMat3x3<T> operator-( const TMat3x3<T>& m, const U& s );

/**
 * Subtracts a matrix from another.
 *
 * @param m1 The first matrix.
 * @param m2 The second matrix.
 * @return The resulting matrix.
 */
template <typename T>
TMat3x3<T> operator-( const TMat3x3<T>& m1, const TMat3x3<T>& m2 );

/**
 * Multiplies the components of a matrix by a scalar.
 *
 * @param m The matrix.
 * @param s The scalar.
 * @return The resulting matrix.
 */
template <typename T, typename U>
VALIDATE( T, U, TMat3x3<T> ) operator*( const TMat3x3<T>& m, const U& s );

/**
 * Multiplies the components of a matrix by a scalar.
 *
 * @param s The scalar.
 * @param m The matrix.
 * @return The resulting matrix.
 */
template <typename T, typename U>
VALIDATE( U, T, TMat3x3<U> ) operator*( const T& s, const TMat3x3<U>& m );

/**
 * Multiplies the matrix by a vector.
 *
 * @param m The matrix.
 * @param v The vector.
 * @return The resulting vector.
 */
template <typename T>
typename TMat3x3<T>::Column operator*( const TMat3x3<T>& m, const typename TMat3x3<T>::Row& v );

/**
 * Multiplies the vector by a matrix.
 *
 * @param v The vector.
 * @param m The matrix.
 * @return The resulting vector.
 */
template <typename T>
typename TMat3x3<T>::Row operator*( const typename TMat3x3<T>::Column& v, const TMat3x3<T>& m );

/**
 * Multiplies two matrices together.
 *
 * @param a The first matrix.
 * @param b The second matrix.
 * @return The resulting matrix.
 */
template <typename T>
TMat3x3<T> operator*( const TMat3x3<T>& a, const TMat3x3<T>& b );

/**
 * Divides the components of a matrix by a scalar.
 *
 * @param m The matrix.
 * @param s The scalar.
 * @return The resulting matrix.
 */
template <typename T, typename U>
VALIDATE( T, U, TMat3x3<T> ) operator/( const TMat3x3<T>& m, const U& s );

/**
 * Divides the components of a matrix by a scalar.
 *
 * @param s The scalar.
 * @param m The matrix.
 * @return The resulting matrix.
 */
template <typename T, typename U>
VALIDATE( U, T, TMat3x3<U> ) operator/( const T& s, const TMat3x3<U>& m );

/**
 * Multiplies the row vector by a matrix.
 *
 * @param m The matrix.
 * @param r The row vector.
 * @return The resulting column vector.
 */
template <typename T>
typename TMat3x3<T>::Column operator/( const TMat3x3<T>& m, const typename TMat3x3<T>::Row& v );

/**
 * Divides the matrix by a column vector.
 *
 * @param c The column vector.
 * @param m The matrix.
 * @return The resulting row vector.
 */
template <typename T>
typename TMat3x3<T>::Row operator/( const typename TMat3x3<T>::Column& v, const TMat3x3<T>& m );

/**
 * Divides the first matrix by the second.
 *
 * @param m1 The first matrix.
 * @param m2 The second matrix.
 * @return The resulting matrix.
 */
template <typename T>
TMat3x3<T> operator/( const TMat3x3<T>& m1, const TMat3x3<T>& m2 );

/**
 * Gets the modulus of the components with a scalar value.
 *
 * @param m The matrix.
 * @param s The scalar to modulo with.
 * @return The resulting matrix.
 */
template <typename T, typename U>
TMat3x3<T> operator%( const TMat3x3<T> m, const U& s );

/**
 * Gets the modulus of the components with a scalar value.
 *
 * @param m The matrix.
 * @param s The scalar to modulo with.
 * @return The resulting matrix.
 */
template <typename T, typename U>
TMat3x3<U> operator%( const T& s, const TMat3x3<U> m );

/**
 * Performs modulo between the components of two matrices.
 *
 * @param m1 The first matrix.
 * @param m2 The second matrix..
 * @return The resulting matrix.
 */
template <typename T>
TMat3x3<T> operator%( const TMat3x3<T>& m1, const TMat3x3<T>& m2 );

// BITWISE BINARY OPERATOR DECLARATIONS
/**
 * Performs bitwise AND with the components and a scalar.
 *
 * @param m The matrix.
 * @param s The scalar.
 * @return The resulting matrix.
 */
template <typename T, typename U>
TMat3x3<T> operator&( const TMat3x3<T>& m, const U& s );

/**
 * Performs a component-wise AND operation.
 *
 * @param m1 The first matrix.
 * @param m2 The second matrix.
 * @return The resulting matrix.
 */
template <typename T>
TMat3x3<T> operator&( const TMat3x3<T>& m1, const TMat3x3<T> m2 );

/**
 * Performs bitwise OR the components and a scalar.
 *
 * @param m The matrix.
 * @param s The scalar.
 * @return The resulting matrix.
 */
template <typename T, typename U>
TMat3x3<T> operator|( const TMat3x3<T>& m, const U& s );

/**
 * Performs a component-wise OR operation.
 *
 * @param m1 The first matrix.
 * @param m2 The second matrix.
 * @return The resulting matrix.
 */
template <typename T>
TMat3x3<T> operator|( const TMat3x3<T>& m1, const TMat3x3<T> m2 );

/**
 * Performs bitwise XOR with the components and a scalar.
 *
 * @param m The matrix.
 * @param s The scalar.
 * @return The resulting matrix.
 */
template <typename T, typename U>
TMat3x3<T> operator^( const TMat3x3<T>& m, const U& s );

/**
 * Performs a component-wise XOR operation.
 *
 * @param m1 The first matrix.
 * @param m2 The second matrix.
 * @return The resulting matrix.
 */
template <typename T>
TMat3x3<T> operator^( const TMat3x3<T>& m1, const TMat3x3<T> m2 );

/**
 * Shifts the components of the matrix left x bits.
 *
 * @param shift The number of bits to shift.
 * @return The resulting matrix.
 */
template <typename T>
TMat3x3<T> operator<<( const TMat3x3<T>& m, uint32 shift );

/**
 * Shifts the components of the matrix right x bits.
 *
 * @param shift The number of bits to shift.
 * @return The resulting matrix.
 */
template <typename T>
TMat3x3<T> operator>>( const TMat3x3<T>& m, uint32 shift );

// COMPARISON BINARY OPERATOR DECLARATIONS
/**
 * Checks if two matrices are equal.
 *
 * @param m1 The first matrix.
 * @param m2 The second matrix.
 * @return If they are equal.
 */
template <typename T, typename U>
bool operator==( const TMat3x3<T>& m1, const TMat3x3<T>& m2 );

/**
 * Checks if two matrices are not equal.
 *
 * @param m1 The first matrix.
 * @param m2 The second matrix.
 * @return If they are equal.
 */
template <typename T, typename U>
bool operator!=( const TMat3x3<T>& m1, const TMat3x3<T>& m2 );

// DEFINITIONS

// CONSTANTS
template <typename T>
const TMat3x3<T> TMat3x3<T>::IDENTITY = TMat3x3<T>( 1 );

template <typename T>
const TMat3x3<T> TMat3x3<T>::ZERO = TMat3x3<T>( 0 );

// CONSTRUCTORS
template <typename T>
inline
TMat3x3<T>::TMat3x3() : _value( { Column( 1, 0, 0 ),
                                  Column( 0, 1, 0 ),
                                  Column( 0, 0, 1 ) } )
{
}

template <typename T>
inline
TMat3x3<T>::TMat3x3( const TMat3x3<T>& m ) : _value( { m[0], m[1], m[2] } )
{
}

template <typename T>
template <typename U>
inline
TMat3x3<T>::TMat3x3( const U& s ) : _value( { Column( s, 0, 0 ),
                                              Column( 0, s, 0 ),
                                              Column( 0, 0, s ) } )
{
}

template <typename T>
template <typename X1, typename X2, typename X3,
          typename Y1, typename Y2, typename Y3,
          typename Z1, typename Z2, typename Z3>
inline
TMat3x3<T>::TMat3x3( const X1& x1, const X2& x2, const X3& x3,
                     const Y1& y1, const Y2& y2, const Y3& y3,
                     const Z1& z1, const Z2& z2, const Z3& z3 )
    : _value( { Column( T( x1 ), T( y1 ), T( z1 ) ),
                Column( T( x2 ), T( y2 ), T( z2 ) ),
                Column( T( x3 ), T( y3 ), T( z3 ) ) } )
{
}

template <typename T>
template <typename I, typename J, typename K>
inline
TMat3x3<T>::TMat3x3( const TVec3<I>& c1, const TVec3<J>& c2, const TVec3<K>& c3 )
    : _value( { c1, c2, c3 } )
{
}

template <typename T>
template <typename U>
inline
TMat3x3<T>::TMat3x3( const TMat2x2<U>& m )
    : _value( { Column( TVec2<T>( m[0] ), 0 ),
                Column( TVec2<T>( m[1] ), 0 ),
                Column( 0, 0, 1 ) } )
{
}

template <typename T>
template <typename U>
inline
TMat3x3<T>::TMat3x3( const TMat3x3<U>& m )
    : _value( { Column( m[0] ),
                Column( m[1] ),
                Column( m[2] ) } )
{
}

template <typename T>
template <typename U>
inline
TMat3x3<T>::TMat3x3( const TMat4x4<U>& m )
    : _value( { Column( m[0] ),
                Column( m[1] ),
                Column( m[2] ) } )
{
}

template <typename T>
inline
TMat3x3<T>::~TMat3x3()
{
}

// ACCESSOR FUNCTIONS
template <typename T>
inline
const typename TMat3x3<T>::Column& TMat3x3<T>::operator[]( Size i ) const
{
    assert( i < TMat3x3<T>::COLUMNS );
    return _value[i];
}

template <typename T>
inline
typename TMat3x3<T>::Column& TMat3x3<T>::operator[]( Size i )
{
    assert( i < TMat3x3<T>::COLUMNS );
    return _value[i];
}

// ASSIGNMENT OPERATORS
template <typename T>
template <typename U>
TMat3x3<T>& TMat3x3<T>::operator=( const TMat3x3<U>& m )
{
    _value[0] = Column( m[0] );
    _value[1] = Column( m[1] );
    _value[2] = Column( m[2] );
    return *this;
}

// ARITHMETIC OPERATORS
template <typename T>
template <typename U>
inline
TMat3x3<T>& TMat3x3<T>::operator+=( const U& s )
{
    _value[0] += s;
    _value[1] += s;
    _value[2] += s;
    return *this;
}

template <typename T>
template <typename U>
inline
TMat3x3<T>& TMat3x3<T>::operator+=( const TMat3x3<U>& m )
{
    _value[0] += m[0];
    _value[1] += m[1];
    _value[2] += m[2];
    return *this;
}

template <typename T>
template <typename U>
inline
TMat3x3<T>& TMat3x3<T>::operator-=( const U& s )
{
    _value[0] -= s;
    _value[1] -= s;
    _value[2] -= s;
    return *this;
}

template <typename T>
template <typename U>
inline
TMat3x3<T>& TMat3x3<T>::operator-=( const TMat3x3<U>& m )
{
    _value[0] -= m[0];
    _value[1] -= m[1];
    _value[2] -= m[2];
    return *this;
}

template <typename T>
template <typename U>
inline
TMat3x3<T>& TMat3x3<T>::operator*=( const U& s )
{
    _value[0] *= s;
    _value[1] *= s;
    _value[2] *= s;
    return *this;
}

template <typename T>
template <typename U>
inline
TMat3x3<T>& TMat3x3<T>::operator*=( const TMat3x3<U>& m )
{
    // todo: do here if necessary
    return ( *this = *this * m );
}

template <typename T>
template <typename U>
inline
TMat3x3<T>& TMat3x3<T>::operator/=( const U& s )
{
    _value[0] /= s;
    _value[1] /= s;
    _value[2] /= s;
    return *this;
}

template <typename T>
template <typename U>
inline
TMat3x3<T>& TMat3x3<T>::operator/=( const TMat3x3<U>& m )
{
    return ( *this = *this / m );
}

template <typename T>
template <typename U>
inline
TMat3x3<T>& TMat3x3<T>::operator%=( const U& s )
{
    _value[0] %= s;
    _value[1] %= s;
    _value[2] %= s;
    return *this;
}

template <typename T>
template <typename U>
inline
TMat3x3<T>& TMat3x3<T>::operator%=( const TMat3x3<U>& m )
{
    _value[0] %= m[0];
    _value[1] %= m[1];
    _value[2] %= m[2];
    return *this;
}

template <typename T>
inline
TMat3x3<T>& TMat3x3<T>::operator++()
{
    ++_value[0];
    ++_value[1];
    ++_value[2];
    return *this;
}

template <typename T>
inline
TMat3x3<T>& TMat3x3<T>::operator--()
{
    --_value[0];
    --_value[1];
    --_value[2];
    return *this;
}

template <typename T>
inline
TMat3x3<T>& TMat3x3<T>::operator++( int )
{
    ++_value[0];
    ++_value[1];
    ++_value[2];
    return *this;
}

template <typename T>
inline
TMat3x3<T>& TMat3x3<T>::operator--( int )
{
    --_value[0];
    --_value[1];
    --_value[2];
    return *this;
}

template <typename T>
inline
TMat3x3<T> TMat3x3<T>::operator-() const
{
    return TMat3x3<T>( -_value[0], -_value[1], -_value[2] );
}

// BITWISE UNARY OPERATORS
template <typename T>
template <typename U>
inline
TMat3x3<T>& TMat3x3<T>::operator&=( const U& s )
{
    _value[0] &= s;
    _value[1] &= s;
    _value[2] &= s;
    return *this;
}

template <typename T>
template <typename U>
inline
TMat3x3<T>& TMat3x3<T>::operator&=( const TMat3x3<U>& m )
{
    _value[0] &= m[0];
    _value[1] &= m[1];
    _value[2] &= m[2];
    return *this;
}

template <typename T>
template <typename U>
inline
TMat3x3<T>& TMat3x3<T>::operator|=( const U& s )
{
    _value[0] |= s;
    _value[1] |= s;
    _value[2] |= s;
    return *this;
}

template <typename T>
template <typename U>
inline
TMat3x3<T>& TMat3x3<T>::operator|=( const TMat3x3<U>& m )
{
    _value[0] |= m[0];
    _value[1] |= m[1];
    _value[2] |= m[2];
    return *this;
}

template <typename T>
template <typename U>
inline
TMat3x3<T>& TMat3x3<T>::operator^=( const U& s )
{
    _value[0] ^= s;
    _value[1] ^= s;
    _value[2] ^= s;
    return *this;
}

template <typename T>
template <typename U>
inline
TMat3x3<T>& TMat3x3<T>::operator^=( const TMat3x3<U>& m )
{
    _value[0] ^= m[0];
    _value[1] ^= m[1];
    _value[2] ^= m[2];
    return *this;
}

template <typename T>
inline
TMat3x3<T>& TMat3x3<T>::operator<<=( uint32 shift )
{
    _value[0] <<= shift;
    _value[1] <<= shift;
    _value[2] <<= shift;
    return *this;
}

template <typename T>
inline
TMat3x3<T>& TMat3x3<T>::operator>>=( uint32 shift )
{
    _value[0] >>= shift;
    _value[1] >>= shift;
    _value[2] >>= shift;
    return *this;
}

template <typename T>
inline
TMat3x3<T> TMat3x3<T>::operator~() const
{
    return TMat3x3<T>( ~_value[0], ~_value[1], ~_value[2] );
}

// ARITHMETIC BINARY OPERATORS
template <typename T>
inline
TMat3x3<T> operator+( const TMat3x3<T>& m, const T& s )
{
    return TMat3x3<T>( m[0] + s, m[1] + s, m[2] + s );
}

template <typename T, typename U>
inline
TMat3x3<T> operator+( const TMat3x3<T>& m, const U& s )
{
    return ( m + static_cast<T>( s ) );
}

template <typename T>
inline
TMat3x3<T> operator+( const TMat3x3<T>& m1, const TMat3x3<T>& m2 )
{
    return TMat3x3<T>( m1[0] + m2[0],
                       m1[1] + m2[1],
                       m1[2] + m2[2] );
}

template <typename T>
inline
TMat3x3<T> operator-( const TMat3x3<T>& m, const T& s )
{
    return TMat3x3<T>( m[0] - s,
                       m[1] - s,
                       m[2] - s );
}

template <typename T, typename U>
inline
TMat3x3<T> operator-( const TMat3x3<T>& m, const U& s )
{
    return ( m - static_cast<T>( s ) );
}

template <typename T>
inline
TMat3x3<T> operator-( const TMat3x3<T>& m1, const TMat3x3<T>& m2 )
{
    return TMat3x3<T>( m1[0] - m2[0],
                       m1[1] - m2[1],
                       m1[2] - m2[2] );
}

template <typename T>
inline
VALIDATE( T, T, TMat3x3<T> ) operator*( const TMat3x3<T>& m, const T& s )
{
    return TMat3x3<T>( m[0] * s,
                       m[1] * s,
                       m[2] * s );
}

template <typename T, typename U>
inline
VALIDATE( T, U, TMat3x3<T> ) operator*( const TMat3x3<T>& m, const U& s )
{
    return ( m * static_cast<T>( s ) );
}

template <typename T>
inline
VALIDATE( T, T, TMat3x3<T> ) operator*( const T& s, const TMat3x3<T>& m )
{
    return TMat3x3<T>( m[0] * s,
                       m[1] * s,
                       m[2] * s );
}

template <typename T, typename U>
inline
VALIDATE( U, T, TMat3x3<U> ) operator*( const T& s, const TMat3x3<U>& m )
{
    return ( static_cast<U>( s ) * m );
}

template <typename T>
inline
typename TMat3x3<T>::Column operator*( const TMat3x3<T>& m, const typename TMat3x3<T>::Row& v )
{
    return typename TMat3x3<T>::Column(
        m[0][0] * v[0] + m[1][0] * v[1] + m[2][0] * v[2],
        m[0][1] * v[0] + m[1][1] * v[1] + m[2][1] * v[2],
        m[0][2] * v[0] + m[1][2] * v[1] + m[2][2] * v[2] );
}

template <typename T>
inline
typename TMat3x3<T>::Row operator*( const typename TMat3x3<T>::Column& v, const TMat3x3<T>& m )
{
    return typename TMat3x3<T>::Row(
        v[0] * m[0][0] + v[1] * m[0][1] + v[2] * m[0][2],
        v[0] * m[1][0] + v[1] * m[1][1] + v[2] * m[1][2],
        v[0] * m[2][0] + v[1] * m[2][1] + v[2] * m[2][2] );
}

template <typename T>
inline
TMat3x3<T> operator*( const TMat3x3<T>& a, const TMat3x3<T>& b )
{
    return TMat3x3<T>(
        a[0][0] * b[0][0] + a[1][0] * b[0][1] + a[2][0] * b[0][2],
        a[0][0] * b[1][0] + a[1][0] * b[1][1] + a[2][0] * b[1][2],
        a[0][0] * b[2][0] + a[1][0] * b[2][1] + a[2][0] * b[2][2],

        a[0][1] * b[0][0] + a[1][1] * b[0][1] + a[2][1] * b[0][2],
        a[0][1] * b[1][0] + a[1][1] * b[1][1] + a[2][1] * b[1][2],
        a[0][1] * b[2][0] + a[1][1] * b[2][1] + a[2][1] * b[2][2],

        a[0][2] * b[0][0] + a[1][2] * b[0][1] + a[2][2] * b[0][2],
        a[0][2] * b[1][0] + a[1][2] * b[1][1] + a[2][2] * b[1][2],
        a[0][2] * b[2][0] + a[1][2] * b[2][1] + a[2][2] * b[2][2] );
}

template <typename T>
inline
VALIDATE( T, T, TMat3x3<T> ) operator/( const TMat3x3<T>& m, const T& s )
{
    assert( s != 0 );
    return TMat3x3<T>(
        m[0] / s,
        m[1] / s,
        m[2] / s );
}

template <typename T, typename U>
inline
VALIDATE( T, U, TMat3x3<T> ) operator/( const TMat3x3<T>& m, const U& s )
{
    return ( m / static_cast<T>( s ) );
}

template <typename T>
inline
VALIDATE( T, T, TMat3x3<T> ) operator/( const T& s, const TMat3x3<T>& m )
{
    return TMat3x3<T>(
        s / m[0],
        s / m[1],
        s / m[2] );
}

template <typename T, typename U>
inline
VALIDATE( U, T, TMat3x3<U> ) operator/( const T& s, const TMat3x3<U>& m )
{
    return ( static_cast<U>( s ) / m );
}

template <typename T>
inline
typename TMat3x3<T>::Column operator/( const TMat3x3<T>& m, const typename TMat3x3<T>::Row& v )
{
    return Mat::inv( m ) * v;
}

template <typename T>
inline
typename TMat3x3<T>::Row operator/( const typename TMat3x3<T>::Column& v, const TMat3x3<T>& m )
{
    return v * Mat::inv( m );
}

template <typename T>
inline
TMat3x3<T> operator/( const TMat3x3<T>& m1, const TMat3x3<T>& m2 )
{
    return ( m1 * Mat::inv( m2 ) );
}

template <typename T>
inline
TMat3x3<T> operator%( const TMat3x3<T> m, const T& s )
{
    return TMat3x3<T>( m[0] % s,
                       m[1] % s,
                       m[2] % s );
}

template <typename T, typename U>
inline
TMat3x3<T> operator%( const TMat3x3<T>& m, const U& s )
{
    return ( m % static_cast<T>( s ) );
}

template <typename T>
inline
TMat3x3<T> operator%( const T& s, const TMat3x3<T> m )
{
    return TMat3x3<T>( s % m[0],
                       s % m[1],
                       s % m[2] );
}

template <typename T, typename U>
inline
TMat3x3<U> operator%( const T& s, const TMat3x3<U>& m )
{
    return ( static_cast<U>( s ) % m );
}

template <typename T>
inline
TMat3x3<T> operator%( const TMat3x3<T>& m1, const TMat3x3<T>& m2 )
{
    return TMat3x3<T>( m1[0] % m2[0],
                       m1[1] % m2[1],
                       m1[2] % m2[2] );
}

// BITWISE BINARY OPERATORS
template <typename T>
inline
TMat3x3<T> operator&( const TMat3x3<T>& m, const T& s )
{
    return TMat3x3<T>( m[0] & s,
                       m[1] & s,
                       m[2] & s );
}

template <typename T, typename U>
inline
TMat3x3<T> operator&( const TMat3x3<T>& m, const U& s )
{
    return ( m & static_cast<T>( s ) );
}

template <typename T>
inline
TMat3x3<T> operator&( const TMat3x3<T>& m1, const TMat3x3<T> m2 )
{
    return TMat3x3<T>( m1[0] & m2[0],
                       m1[1] & m2[1],
                       m1[2] & m2[2] );
}

template <typename T>
inline
TMat3x3<T> operator|( const TMat3x3<T>& m, const T& s )
{
    return TMat3x3<T>( m[0] | s,
                       m[1] | s,
                       m[2] | s );
}

template <typename T, typename U>
inline
TMat3x3<T> operator|( const TMat3x3<T>& m, const U& s )
{
    return ( m | static_cast<T>( s ) );
}

template <typename T>
inline
TMat3x3<T> operator|( const TMat3x3<T>& m1, const TMat3x3<T> m2 )
{
    return TMat3x3<T>( m1[0] | m2[0],
                       m1[1] | m2[1],
                       m1[2] | m2[2] );
}

template <typename T>
inline
TMat3x3<T> operator^( const TMat3x3<T>& m, const T& s )
{
    return TMat3x3<T>( m[0] ^ s,
                       m[1] ^ s,
                       m[2] ^ s );
}

template <typename T, typename U>
inline
TMat3x3<T> operator^( const TMat3x3<T>& m, const U& s )
{
    return ( m ^ static_cast<T>( s ) );
}

template <typename T>
inline
TMat3x3<T> operator^( const TMat3x3<T>& m1, const TMat3x3<T> m2 )
{
    return TMat3x3<T>( m1[0] ^ m2[0],
                       m1[1] ^ m2[1],
                       m1[2] ^ m2[2] );
}

template <typename T>
inline
TMat3x3<T> operator<<( const TMat3x3<T>& m, uint32 shift )
{
    return TMat3x3<T>( m[0] << shift, m[1] << shift, m[2] << shift );
}

template <typename T>
inline
TMat3x3<T> operator>>( const TMat3x3<T>& m, uint32 shift )
{
    return TMat3x3<T>( m[0] >> shift, m[1] >> shift, m[2] >> shift );
}

// COMPARISON BINARY OPERATORS
template <typename T, typename U>
inline
bool operator==( const TMat3x3<T>& m1, const TMat3x3<U>& m2 )
{
    return m1[0] == m2[0] && m1[1] == m2[1] && m1[2] == m2[2];
}

template <typename T, typename U>
inline
bool operator!=( const TMat3x3<T>& m1, const TMat3x3<U>& m2 )
{
    return m1[0] != m2[0] || m1[1] != m2[1] || m1[2] != m2[2];
}

} // End nspc math

} // End nspc gel

#undef VALIDATE

#endif //GEL_MAT3X3_H