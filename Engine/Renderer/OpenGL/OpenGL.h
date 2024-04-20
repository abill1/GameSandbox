
#ifndef ENGINE_RENDERER_OPENGL_H
#define ENGINE_RENDERER_OPENGL_H

//======================================================================
// Includes
//======================================================================

#include "DataStructures/OGLDataStructures.h"
#include "../Framework/Framework.h"

//======================================================================
// OpenGL Definitions
//======================================================================

namespace OGL
{

	struct OpenGLAttributes
	{
		unsigned char  m_MajorVersion;
		unsigned char  m_MinorVersion;
		unsigned char  m_Profile;
		unsigned char  m_DoubleBuffer;
		unsigned char  m_DepthBufferSize;
		unsigned char  m_AntiAliasing;
		OpenGLAttributes()
			:m_MajorVersion(4), m_MinorVersion(4), m_Profile(1), m_DoubleBuffer(1), m_DepthBufferSize(24), m_AntiAliasing(4)
		{

		}
	};

	enum class UniformTypes : unsigned char
	{
		VEC2,
		VEC3,
		VEC4, 
		MAT4,
		INT
	};

	class OpenGL
	{
	public:
		static Shader LoadShader(const Framework::String& _vertexShader, const Framework::String& _fragmentShader)
		{
			Shader programID = glCreateProgram();
			
			unsigned int vs = privLoadCompileAttachShader(programID, GL_VERTEX_SHADER, _vertexShader);
			unsigned int fs = privLoadCompileAttachShader(programID, GL_FRAGMENT_SHADER, _fragmentShader);
			//glAttachShader(programID, vs);
			//glAttachShader(programID, fs);
			privLinkAndValidate(programID);
			privCleanUp(vs, fs);

			return programID;
		}

		static void DestroyShader(Shader _shader)
		{
			glDeleteProgram(_shader);
		}
		
		static void BindShader(Shader _shader)
		{
			glUseProgram(_shader);
		}

		static void LinkVertexArray(VertexArray& _vertArray)
		{
			glGenVertexArrays(1, &_vertArray.m_ID);
		}

		static void LinkVertexBuffer(VertexBuffer& _vertBuffer)
		{
			glGenBuffers(1, &_vertBuffer);
		}

		static void LinkIndexBuffer(IndexBuffer& _indexBuffer)
		{
			glGenBuffers(1, &_indexBuffer);
		}

		static void BindVertexArray(const VertexArray& _vertArray)
		{
			glBindVertexArray(_vertArray.m_ID);
		}

		static void BindVertexBuffer(const VertexBuffer& _vertBuffer)
		{
			glBindBuffer(GL_ARRAY_BUFFER, _vertBuffer);
		}

		static void BindIndexBuffer(const IndexBuffer& _indexBuffer)
		{
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _indexBuffer);
		}

		static void UnlinkVertexArray(VertexArray& _vertArray)
		{
			glDeleteVertexArrays(1, &_vertArray.m_ID);
		}

		static void UnlinkVertexBuffer(VertexBuffer& _vertBuffer)
		{
			glDeleteBuffers(1, &_vertBuffer);
		}

		static void UnlinkIndexBuffer(IndexBuffer& _indexBuffer)
		{
			glDeleteBuffers(1, &_indexBuffer);
		}

		static void SetVertexBufferData(signed long long int _vertSize, Vertex* _pVerts)
		{
			glBufferData(GL_ARRAY_BUFFER, _vertSize, _pVerts, GL_STATIC_DRAW);
		}

		static void SetIndexBufferData(signed long long int _indexSize, IndexBuffer* _pIndices)
		{
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, _indexSize, _pIndices, GL_STATIC_DRAW);
		}

		static void BindVertexArrayLayout(const VertexArray& _vertArray)
		{
			glEnableVertexAttribArray(_vertArray.m_Point.m_Index);
			glEnableVertexAttribArray(_vertArray.m_Color.m_Index);
			glEnableVertexAttribArray(_vertArray.m_TextureCoordinate.m_Index);
			privSetAttribPointer(_vertArray.m_Point);
			privSetAttribPointer(_vertArray.m_Color);
			privSetAttribPointer(_vertArray.m_TextureCoordinate);

		}

	private:

		static void privSetAttribPointer(const VertexAttribute& _attrib)
		{
			glVertexAttribPointer(_attrib.m_Index, _attrib.m_ElementCount, _attrib.m_ElementType, _attrib.m_IsNormalized, _attrib.m_Stride, _attrib.m_OffsetInStride);

		}

		static unsigned int privLoadCompileAttachShader(Shader _shader, unsigned int _type, const Framework::String& _file)
		{
			Framework::Buffer buffer;
			CHECK_SUCCESS(Framework::File::Load(buffer, _file));
			unsigned int prog = privCompile(_type, buffer);
			glAttachShader(_shader, prog);
			return prog;
		}

		static unsigned int privCompile(unsigned int _type, const Framework::Buffer& _buffer)
		{
			unsigned int hShader = glCreateShader(_type);

			const char* src = _buffer.GetData();
			CHECK_NULL(src);
			glShaderSource(hShader, 1, &src, nullptr);
			glCompileShader(hShader);
			privCheckForErrorMessage(hShader);

			return hShader;
		}

		static void privCheckForErrorMessage(unsigned int& _hShader)
		{
			int result;
			glGetShaderiv(_hShader, GL_COMPILE_STATUS, &result);
			if (result == GL_FALSE)
			{
				int length;
				glGetShaderiv(_hShader, GL_INFO_LOG_LENGTH, &length);
				char* message = new char[length];
				memset(&message, 0, length);
				glGetShaderInfoLog(_hShader, length, &length, message);

				printf("ERROR: Failed to compile shader.\n");
				printf("LOG: %s\n", message);
				delete[] message;

				glDeleteShader(_hShader);
				_hShader = 0;
			}
		}

		static void privLinkAndValidate(Shader _shader)
		{
			glLinkProgram(_shader);
			glValidateProgram(_shader);
		}
		
		static void privCleanUp(unsigned int _vs, unsigned int _fs)
		{
			glDeleteShader(_vs);
			glDeleteShader(_fs);
		}

	};


	


}



#endif // !ENGINE_RENDERER_OPENGL_H

