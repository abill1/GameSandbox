
#ifndef ENGINE_RENDERER_OPENGL_DATASTRUCTURES_H
#define ENGINE_RENDERER_OPENGL_DATASTRUCTURES_H

//======================================================================
// Includes
//======================================================================

#include "../Vendor/glad/glad.h"
#include "../Vendor/glm/glm.hpp"
#include "../Vendor/glm/ext.hpp"

namespace OGL
{
	//======================================================================
	// Typedefs
	//======================================================================

	typedef int Shader;
	typedef unsigned int IndexBuffer;
	typedef unsigned int VertexBuffer;
	typedef unsigned int SSBO;

	//======================================================================
	// Data Structures
	//======================================================================

	struct Uniform
	{
		static constexpr int NAME_LENGTH = 12;
		char m_Name[NAME_LENGTH];
		int m_Location;
	};

	struct VertexAttribute
	{
		unsigned int m_Index;
		int m_ElementCount;
		unsigned int m_ElementType;
		int m_IsNormalized;
		int m_Stride;
		const void* m_OffsetInStride;
	};

	struct Vertex
	{
		glm::vec4 m_Point;
		glm::vec4 m_Color;
		glm::vec2 m_TextureCoordinate;
		Vertex() = default;
		~Vertex() {};
	};

	struct TriangleIndex
	{
		unsigned int m_Index1;
		unsigned int m_Index2;
		unsigned int m_Index3;
		TriangleIndex() = default;
		~TriangleIndex(){};
	};

	struct VertexArray
	{
		unsigned int m_ID;
		VertexAttribute m_Point;
		VertexAttribute m_Color;// = { 1U, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const void*)sizeof(glm::vec4) };
		VertexAttribute m_TextureCoordinate;// = { 2U, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const void*)sizeof(glm::vec4) };
		VertexArray()
			:m_ID(0U), 
			m_Point({             0U, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const void*)offsetof(OGL::Vertex, m_Point) }),
			m_Color({             1U, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const void*)offsetof(OGL::Vertex, m_Color) }),
			m_TextureCoordinate({ 2U, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const void*)offsetof(OGL::Vertex, m_TextureCoordinate) })
		{

		}
	};

}

#endif // !ENGINE_RENDERER_OPENGL_DATASTRUCTURES_H


