/*

	This file is part of libnmesh.

	precision.h
	Precision

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

#ifndef NMESH_PRECISION_H_INCLUDED
#define NMESH_PRECISION_H_INCLUDED

namespace NMesh {

#ifdef __cplusplus
	extern "C" {
#endif /* __cplusplus */

typedef double scalar_t;

#ifndef EPSILON
	#define EPSILON         1E-8
	#define FLOAT_EPSILON   EPSILON
	#define DOUBLE_EPSILON  1E-15
#endif /* EPSILON */

#ifdef __cplusplus
	} /* extern */
#endif /* __cplusplus */

} /* namespace NMesh */

#endif /* NMESH_PRECISION_H_INCLUDED */
