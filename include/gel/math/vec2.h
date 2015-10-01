// vec2.h
#ifndef GEL_VEC2_H
#define GEL_VEC2_H
#include "gel/gellib.h"

namespace gel
{

namespace math
{

template <typename T>
class TVec3;

template <typename T>
class TVec4;

template <typename T>
class TVec2
{
  private:
  public:
    typedef T ValueType;

    union
    {
        struct { ValueType x, y; };
        struct { ValueType r, g; };
        struct { ValueType s, t; };
        struct { ValueType u, v; };
        struct { ValueType i, j; };
        struct { ValueType hue, lum; };
    };

    // IMPLICIT CONSTRUCTORS

    // EXPLICIT CONSTRUCTORS
    /**
 * Constructs a new vector and initializes its components to v.
 * @param v The component value.
 * @tparam U The component value type.
 */
    template <typename U>
    explicit TVec2(const U& s);

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
    explicit TVec2(const U& s1, const V& s2);

    /**
     * Constructs a copy of the vector with the given first component value.
     * @param s The first component value.
     * @param v The vector to copy.
     * @tparam U The first component type.
     * @tparam V The vector type.
     */
    template <typename U>
    explicit TVec2(const TVec2<U>& v);

    /**
     * Constructs a copy of the vector.
     * @param v The vector to copy.
     * @tparam U The component type.
     */
    template <typename U>
    explicit TVec2(const TVec3<U>& v);

    /**
     * Constructs a copy of the vector.
     * @param v The vector to copy.
     * @tparam U The component type.
     */
    template <typename U>
    explicit TVec2(const TVec4<U>& v);

    // UNARY OPERATORS
    /**
     * Makes this a copy of the other vector.
     *
     * @param v The vector to copy.
     */
    TVec2<T> operator=(TVec2<T> v);

    /**
     * Makes this a copy of the other vector.
     *
     * @param v The vector to copy.
     * @tparam U The component value type..
     */
    template<typename U>
    TVec2<T>& operator=(TVec2<U> v);

    /**
     * Adds a scalar value to the components.
     *
     * @param s The scalar value to add.
     * @tparam U The scalar value type.
     */
    template <typename U>
    TVec2<T>& operator+=(const U& s);

    /**
     * Adds another vector to this.
     *
     * @param v The vector to add.
     * @tparam U The component value type.
     */
    template <typename U>
    TVec2<T>& operator+=(const TVec2<U>& v);

    /**
     * Subtracts a scale from the components.
     *
     * @param s The scalar to subtract.
     * @tparam U The scalar value type.
     */
    template <typename U>
    TVec2<T>& operator-=(const U& s);

    /**
     * Subtracts another vector from this.
     *
     * @param v The vector to subtract.
     * @tparam U The component value type.
     */
    template <typename U>
    TVec2<T>& operator-=(const TVec2<U>& v);

    /**
     * Multiplies the this by a scalar.
     *
     * @param s The scalar to multiply by.
     * @tparam U The scalar value type.
     */
    template <typename U>
    TVec2<T>& operator*=(const U& s);

    /**
     * Multiplies this vector by another.
     *
     * @param v The vector to multiply by.
     * @tparam The component value type.
     */
    template <typename U>
    TVec2<T>& operator*=(const TVec2<U>& v);

    /**
     * Divides this vector by a scalar.
     *
     * @param v The scalar to divide by.
     * @tparam U The scalar value type.
     */
    template <typename U>
    TVec2<T>& operator/=(const U& s);

    /**
     * Divides this vector by another.
     *
     * @param v THe vector to divide by.
     * @tparam U The component value type.
     */
    template <typename U>
    TVec2<T>& operator/=(const TVec2<U>& v);

    /**
     * Adds one to the vector's component values.
     */
    TVec2<T>& operator++();

    /**
     * Subtracts one from the vector's component values.
     */
    TVec2<T>& operator--();

    // UNARY BIT OPERATORS
    /**
     * Performs modulo on each of the components.
     *
     * @param s The scalar to perform modulo with.
     * @tparam The scalar value type.
     */
    template <typename U>
    TVec2<T>& operator%=(const U& s);

    /**
     * Performs a component-wise modulus.
     *
     * @param v The vector to perform modulo with.
     * @tparam U The component value type.
     */
    template <typename U>
    TVec2<T>& operator%=(const TVec2<U>& v);

    /**
     * Performs the bitwise-and operation with each of the components.
     *
     * @param s The scalar to perform and with.
     * @tparam U The scalar value type.
     */
    template <typename U>
    TVec2<T>& operator&=(const U& s);

    /**
     * Performs a component-wise bitwise-and operation.
     *
     * @param v The vector to perform and with.
     * @tparam U The component value type.
     */
    template <typename U>
    TVec2<T>& operator&=(const TVec2<U>& v);

    /**
     * Performs the bitwise-or operation with each of the components.
     *
     * @param s The scalar to perform or with.
     * @tparam U The scalar value type.
     */
    template <typename U>
    TVec2<T>& operator|=(const U& s);

    /**
     * Performs a component-wise bitwise-or operation.
     *
     * @param s The vector to perform or with.
     * @tparam U The scalar value type.
     */
    template <typename U>
    TVec2<T>& operator|=(const TVec2<U>& v);

    /**
     * Performs the bitwise-xor operation with each of the components.
     *
     * @param s The scalar to perform xor with.
     * @tparam U The component value type.
     */
    template <typename U>
    TVec2<T>& operator^=(const U& s);

    /**
     * Performs a component-wise bitwise-xor operation.
     *
     * @param v The vector to perform xor with.
     * @tparam U The component value type.
     */
    template <typename U>
    TVec2<T>& operator^=(const TVec2<U>& v);

    /**
     * Performs the shift-left operation with each of the components.
     *
     * @param s The scalar to perform shift left with.
     * @tparam U The scalar value type.
     */
    template <typename U>
    TVec2<T>& operator<<=(const U& s);

    /**
     * Performs a component-wise bitwise-shift left operation.
     *
     * @param The vector to perform shift left with.
     * @tparam U The component value type.
     */
    template <typename U>
    TVec2<T>& operator<<=(const TVec2<U>& v);

    /**
     * Performs the shift-right operation with each of the components.
     *
     * @param s The scalar to perform shift right with.
     * @tparam U The scalar value type.
     */
    template <typename U>
    TVec2<T>& operator>>=(const U& s);

    /**
     * Performs a component-wise bitwise-shift right operation.
     *
     * @param The vector to perform shift right with.
     * @tparam U The component value type.
     */
    template <typename U>
    TVec2<T>& operator>>=(const TVec2<U>& v);

    // ACCESSOR OPERATORS
    /**
     * Sets the vector component value at the given index.
     */
    ValueType &operator[]( Size index );

    /**
     * Gets the vector component value at the given index.
     */
    const ValueType& operator[]( Size index ) const;
};

} // End nspc math

} // End nspc gel

#endif //GEL_VEC2_H
