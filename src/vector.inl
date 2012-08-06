/*

	This file is part of libnmesh.

	vector.inl
	Vector

	Copyright (C) 2008, 2010 - 2012
	Papadopoulos Nikolaos

	This program is free software; you can redistribute it and/or
	modify it under the terms of the GNU Lesser General Public
	License as published by the Free Software Foundation; either
	version 3 of the License, or (at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU	Lesser General Public License for more details.

	You should have received a copy of the GNU Lesser General
	Public License along with this program; if not, write to the
	Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
	Boston, MA 02110-1301 USA

*/

#ifndef LIBNMESH_VECTOR_INL_INCLUDED
#define LIBNMESH_VECTOR_INL_INCLUDED

#ifndef LIBNMESH_VECTOR_HPP_INCLUDED
    #error "vector.hpp must be included before vector.inl"
#endif /* LIBNMESH_VECTOR_HPP_INCLUDED */

#include <cmath>
#include "precision.h"

namespace NMesh {

inline const Vector3f& Vector3f::operator =(const Vector3f& v)
{
    x = v.x;
    y = v.y;
    z = v.z;
    return v;
}

inline const Vector3f operator -(const Vector3f& v)
{
	return Vector3f(-v.x, -v.y, -v.z);
}

inline const Vector3f operator +(const Vector3f& v1, const Vector3f& v2)
{
	return Vector3f(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}

inline const Vector3f operator -(const Vector3f& v1, const Vector3f& v2)
{
	return Vector3f(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}

inline const Vector3f operator *(const Vector3f& v1, const Vector3f& v2)
{
	return Vector3f(v1.x * v2.x, v1.y * v2.y, v1.z * v2.z);
}

inline const Vector3f operator /(const Vector3f& v1, const Vector3f& v2)
{
	return Vector3f(v1.x / v2.x, v1.y / v2.y, v1.z / v2.z);
}

inline const Vector3f operator +(const Vector3f& v, scalar_t r)
{
	return Vector3f(v.x + r, v.y + r, v.z + r);
}

inline const Vector3f operator +(scalar_t r, const Vector3f& v)
{
	return Vector3f(v.x + r, v.y + r, v.z + r);
}

inline const Vector3f operator -(const Vector3f& v, scalar_t r)
{
	return Vector3f(v.x - r, v.y - r, v.z - r);
}

inline const Vector3f operator *(const Vector3f& v, scalar_t r)
{
	return Vector3f(v.x * r, v.y * r, v.z * r);
}

inline const Vector3f operator *(scalar_t r, const Vector3f& v)
{
	return Vector3f(v.x * r, v.y * r, v.z * r);
}

inline const Vector3f operator /(const Vector3f& v, scalar_t r)
{
	return Vector3f(v.x / r, v.y / r, v.z / r);
}

inline Vector3f& operator +=(Vector3f& v1, const Vector3f& v2)
{
	v1.x += v2.x;
	v1.y += v2.y;
	v1.z += v2.z;
	return v1;
}

inline Vector3f& operator -=(Vector3f& v1, const Vector3f& v2)
{
	v1.x -= v2.x;
	v1.y -= v2.y;
	v1.z -= v2.z;
	return v1;
}

inline Vector3f& operator *=(Vector3f& v1, const Vector3f& v2)
{
	v1.x *= v2.x;
	v1.y *= v2.y;
	v1.z *= v2.z;
	return v1;
}

inline Vector3f& operator /=(Vector3f& v1, const Vector3f& v2)
{
	v1.x /= v2.x;
	v1.y /= v2.y;
	v1.z /= v2.z;
	return v1;
}

inline Vector3f& operator +=(Vector3f& v, scalar_t r)
{
	v.x += r;
	v.y += r;
	v.z += r;
	return v;
}

inline Vector3f& operator -=(Vector3f& v, scalar_t r)
{
	v.x -= r;
	v.y -= r;
	v.z -= r;
	return v;
}

inline Vector3f& operator *=(Vector3f& v, scalar_t r)
{
	v.x *= r;
	v.y *= r;
	v.z *= r;
	return v;
}

inline Vector3f& operator /=(Vector3f& v, scalar_t r)
{
	v.x /= r;
	v.y /= r;
	v.z /= r;
	return v;
}

inline bool operator ==(const Vector3f& v1, const Vector3f& v2)
{
	return (fabs(v1.x - v2.x) < EPSILON) && (fabs(v1.y - v2.y) < EPSILON) && (fabs(v1.z - v2.z) < EPSILON);
}

inline bool operator !=(const Vector3f& v1, const Vector3f& v2)
{
	return (fabs(v1.x - v2.x) >= EPSILON) && (fabs(v1.y - v2.y) >= EPSILON) && (fabs(v1.z - v2.z) >= EPSILON);
}

inline bool operator < (const Vector3f &v1, const Vector3f &v2)
{
	return v1.x < v2.x && v1.y < v2.y && v1.z < v2.z;
}

inline bool operator > (const Vector3f &v1, const Vector3f &v2)
{
	return v1.x > v2.x && v1.y > v2.y && v1.z > v2.z;
}

inline scalar_t Vector3f::length() const
{
	return sqrt(x*x + y*y + z*z);
}

inline scalar_t Vector3f::length_squared() const
{
	return x*x + y*y + z*z;
}

inline void Vector3f::normalize()
{
	scalar_t len = length();

	if(!len)
		return;

	x /= len;
	y /= len;
	z /= len;
}

inline Vector3f Vector3f::normalized() const
{
	scalar_t len = length();
	return (len != 0) ? Vector3f(x / len, y / len, z / len) : *this;
}

inline scalar_t dot(const Vector3f& v1, const Vector3f& v2)
{
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

inline Vector3f cross(const Vector3f& v1, const Vector3f& v2)
{
	return Vector3f(v1.y * v2.z - v1.z * v2.y,  v1.z * v2.x - v1.x * v2.z,  v1.x * v2.y - v1.y * v2.x);
}

} /* namespace NMesh */

#endif /* LIBNMESH_VECTOR_INL_INCLUDED */
