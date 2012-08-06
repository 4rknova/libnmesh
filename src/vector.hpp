/*

	This file is part of libnmesh.

	vector.h
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

#ifndef LIBNMESH_VECTOR_HPP_INCLUDED
#define LIBNMESH_VECTOR_HPP_INCLUDED

#include "declspec.h"
#include "precision.h"

namespace NMesh {

struct vec2_t { scalar_t x, y; };
struct vec3_t { scalar_t x, y, z; };

typedef struct vec2_t vec2_t;
typedef struct vec3_t vec3_t;

class DECLSPEC Vector3f
{
    public:
        /* Constructors */
        explicit Vector3f(scalar_t aX = 0.0f, scalar_t aY = 0.0f, scalar_t aZ = 0.0f);
        Vector3f(const Vector3f &v);

        /* Assignment operator */
        inline const Vector3f &operator =(const Vector3f &v);

        /* Unary operator */
        friend inline const Vector3f operator -(const Vector3f &v);

        /* Arithmetic operators */
        /* - Binary */
        friend inline const Vector3f operator +(const Vector3f &v1, const Vector3f &v2);
        friend inline const Vector3f operator -(const Vector3f &v1, const Vector3f &v2);
        friend inline const Vector3f operator *(const Vector3f &v1, const Vector3f &v2);
        friend inline const Vector3f operator /(const Vector3f &v1, const Vector3f &v2);
        /* - Scalar */
        friend inline const Vector3f operator +(scalar_t r, const Vector3f &v);
        friend inline const Vector3f operator +(const Vector3f &v, scalar_t r);
        friend inline const Vector3f operator -(const Vector3f &v, scalar_t r);
        friend inline const Vector3f operator *(scalar_t r, const Vector3f &v);
        friend inline const Vector3f operator *(const Vector3f &v, scalar_t r);
        friend inline const Vector3f operator /(const Vector3f &v, scalar_t r);

        /* Compound assignment operators */
        /* - Binary */
        friend inline Vector3f &operator +=(Vector3f &v1, const Vector3f &v2);
        friend inline Vector3f &operator -=(Vector3f &v1, const Vector3f &v2);
        friend inline Vector3f &operator *=(Vector3f &v1, const Vector3f &v2);
        friend inline Vector3f &operator /=(Vector3f &v1, const Vector3f &v2);
        /* - Scalar */
        friend inline Vector3f &operator +=(Vector3f &vec, scalar_t scalar);
        friend inline Vector3f &operator -=(Vector3f &vec, scalar_t scalar);
        friend inline Vector3f &operator *=(Vector3f &vec, scalar_t scalar);
        friend inline Vector3f &operator /=(Vector3f &vec, scalar_t scalar);

        /* Comparison operations */
        friend inline bool operator ==(const Vector3f &v1, const Vector3f &v2);
        friend inline bool operator !=(const Vector3f &v1, const Vector3f &v2);

        /* Vector member functions */
        /* - Length */
        inline scalar_t length() const;
        inline scalar_t length_squared() const;
        /* - Normalization */
        inline void normalize();
        inline Vector3f normalized() const;

        scalar_t x, y, z;
};

inline scalar_t dot(const Vector3f &v1, const Vector3f &v2);
inline Vector3f cross(const Vector3f &v1, const Vector3f &v2);

} /* namespace NMesh */

#include "vector.inl"

#endif /* LIBNMESH_VECTOR_HPP_INCLUDED */
