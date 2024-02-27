
#ifndef OPENGL_MESH_H
#define OPENGL_MESH_H

namespace ABFramework
{
	class Mesh
	{
	public:

		// ----- Constructor / Destructor ----- //

		Mesh();
		virtual ~Mesh();

		// ----- Operators ----- //

		// ------ Utility ----- //

		// ----- Setters ----- //

		// ----- Getters ----- //

		inline class Vertex* GetVertices() const { return pVertices; }
		inline unsigned int* GetIndices() const { return pIndices; }
		inline size_t GetVertexCount() const { return m_VertexCount; }
		inline unsigned int GetIndexCount() const { return m_IndexCount; }
		size_t GetVertexSize() const;
		size_t GetIndexSize() const;

	protected:
		class Vertex* pVertices;
		unsigned int* pIndices;
		size_t m_VertexCount;
		unsigned int m_IndexCount;

	};
}

#endif // !OPENGL_MESH_H


