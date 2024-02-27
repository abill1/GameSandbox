
#ifndef OPENGL_VERTEX_ARRAY_H
#define OPENGL_VERTEX_ARRAY_H

namespace ABFramework
{
	class VertexArray
	{
	public:
		// ----- Constructor / Destructor ----- //

		VertexArray();
		~VertexArray();

		// ----- Operators ----- //

		// ------ Utility ----- //

		void Bind() const;
		void Unbind() const;
		void BindLayout() const;

		// ----- Setters ----- //

		// ----- Getters ----- //

	private:
		unsigned int m_ID;
		const unsigned int m_positionAttribute = 0;
		const unsigned int m_textureAttribute = 1;

	};
}

#endif // !OPENGL_VERTEX_ARRAY_H

