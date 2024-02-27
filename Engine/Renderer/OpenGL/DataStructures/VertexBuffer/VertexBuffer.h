
#ifndef OPENGL_VERTEX_BUFFER_H
#define OPENGL_VERTEX_BUFFER_H

namespace ABFramework
{
	class VertexBuffer
	{
	public:

		// ----- Constructor / Destructor ----- //

		VertexBuffer();
		~VertexBuffer();

		// ----- Operators ----- //

		// ------ Utility ----- //

		void Bind() const;
		void Unbind() const;

		// ----- Setters ----- //

		void SetData(const class Mesh& _mesh);
		void SetData(const class Mesh* _pMesh);

		// ----- Getters ----- //

		inline unsigned int GetID() const { return m_ID; }

	private:
		unsigned int m_ID;

	};
}

#endif // !OPENGL_VERTEX_BUFFER_H


