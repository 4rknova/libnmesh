/*

	This file is part of libnmesh.

	buffer.hpp
	General purpose buffer

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

#ifndef NMESH_BUFFER_HPP_INCLUDED
#define NMESH_BUFFER_HPP_INCLUDED

namespace NMesh {

template <class T>
class Buffer
{
	public:
		Buffer();
		Buffer(const Buffer &rhs);
		Buffer &operator =(const Buffer &rhs);
		virtual ~Buffer();

		int init(const unsigned int count);
		void clear();

		unsigned int count() const;

		T& operator[] (const unsigned int idx);
		const T& operator[] (const unsigned int idx) const;

	private:
		void release();

		unsigned int m_count;
		// The following is a default value that will be used if
		// an index based access request is made on an uninitialized 
		// buffer.
		T m_single_object;
		T *m_data;
};

} /* namespace NMesh */

#include "buffer.tml"

#endif /* NMESH_BUFFER_HPP_INCLUDED */
