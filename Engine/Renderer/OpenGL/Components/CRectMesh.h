
#ifndef OPENGL_CRECTMESH_H
#define OPENGL_CRECTMESH_H

namespace OGL
{
	class CRectMesh
	{
	public:
		CRectMesh();
		~CRectMesh();

		struct Vertex* GetVertices() const;
		struct TriangleIndex* GetIndices() const;
		size_t GetVertexCount() const;
		size_t GetIndexCount() const;
		size_t GetVertexSize() const;
		size_t GetIndexSize() const;

	private:
		struct Vertex* pVertices;
		struct TriangleIndex* pIndices;
		size_t m_vertexCount;
		size_t m_indexCount;
	};

}

#endif // !OPENGL_CRECTMESH_H



