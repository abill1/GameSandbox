
#ifndef OPENGL_CMESH_H
#define OPENGL_CMESH_H

namespace OGL 
{
	class CMesh
	{
	public:
		CMesh() = default;
		CMesh(struct Vertex* _pVerts, struct TriangleIndex* _pIndices, size_t _vertCount, size_t _indexCount)
			:pVertices(_pVerts), pIndices(_pIndices), m_vertexCount(_vertCount), m_indexCount(_indexCount)
		{

		}
		~CMesh()
		{
			delete[] pVertices;
			delete[] pIndices;
		}

		void Set( struct Vertex* const _pVerts, struct TriangleIndex* const _pIndices, const size_t _vertCount, const size_t _indexCount)
		{
			pVertices = _pVerts;
			pIndices = _pIndices;
			m_vertexCount = _vertCount;
			m_indexCount = _indexCount;
		}

	public:
		struct Vertex* pVertices;
		struct TriangleIndex* pIndices;
		size_t m_vertexCount;
		size_t m_indexCount;
	};

}

#endif // !OPENGL_CMESH_H


