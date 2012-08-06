/*

	This file is part of libnmesh.

	mesh.hpp
	Mesh

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

#ifndef NMESH_MESH_HPP_INCLUDED
#define NMESH_MESH_HPP_INCLUDED

#include "declspec.h"
#include "vertex.h"
#include "buffer.hpp"

namespace NMesh {

class DECLSPEC Mesh
{
	public:
		Mesh();
		Mesh(const Mesh &m);
		Mesh &operator =(const Mesh &m);
		virtual ~Mesh();

		// RETURN CODES:
		//	0. Everything went well.
		//  1. Failed to initialize vertices.
		//  2. Failed to initialize indices.
		//  3. Failed to initialize both.
		int init(const unsigned int vcount, const unsigned int icount);
		
		const Buffer<vertex_t> &vertices_ro() const;
		const Buffer<index_t> &indices_ro() const;

		Buffer<vertex_t> &vertices();
		Buffer<index_t> &indices();

	private:
		Buffer<vertex_t> m_vertices;
		Buffer<index_t> m_indices;
};

} /* namespace NMesh */

#endif /* NMESH_MESH_HPP_INCLUDED */
