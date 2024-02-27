
#ifndef OPENGL_VERTEX_H
#define OPENGL_VERTEX_H

#include "../Engine/Core/Math/Math.h" // Would prefer to forward declare. Issue with glm::vec typedef. TODO: Investigate

namespace ABFramework
{
	class Vertex
	{
	public:
		// ----- Constructor / Destructor ----- //

		Vertex();
		Vertex(const Point& _point);
		Vertex(const Point& _point, const TextureCoord& _texCoord);
		~Vertex();

		// ----- Operators ----- //

		// ------ Utility ----- //

		// ----- Setters ----- //

		void Set(const Point& _point);
		void Set(const Point& _point, const TextureCoord& _texCoord);

		// ----- Getters ----- //

		inline const Point* GetPoint() const { return &m_Point; }
		inline const TextureCoord* GetTextureCoord() const { return &m_TexCoord; }

	private:
		Point m_Point;
		TextureCoord m_TexCoord;
		// color;
		// TexCoord

	};
}

#endif // !OPENGL_VERTEX_H


