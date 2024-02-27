
#ifndef OPENGL_INDEX_BUFFER_H
#define OPENGL_INDEX_BUFFER_H

namespace ABFramework
{
	class IndexBuffer
	{
	public:
		// ----- Constructor / Destructor ----- //

		IndexBuffer();
		~IndexBuffer();

		// ----- Operators ----- //

		// ------ Utility ----- //

		void Bind() const;
		void Unbind() const;

		// ----- Setters ----- //

		void SetData(const class Mesh& _mesh);
		void SetData(const class Mesh* _pMesh);

		// ----- Getters ----- //

		inline unsigned int GetCount() const { return m_IndexCount; }

	private:
		unsigned int m_ID;
		unsigned int m_IndexCount;

	};
}

#endif // !OPENGL_INDEX_BUFFER_H


