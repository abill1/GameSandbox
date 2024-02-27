
#include "ShaderObject.h"

#include "glad/glad.h"
#include "../ABFramework/Codes/ABCode.h"
#include "../ABFramework/ABString/ABString.h"
#include "../ABFramework/Buffer/Buffer.h"
#include "../ABFramework/File/ABFile.h"
#include "../ABFramework/Debugging/Assert/Assert.h"

//********************************************************************************//
//                        Constructors / Destructor                                //
//********************************************************************************//

ABFramework::ShaderObject::ShaderObject()
	:m_programID(0U)
{

}

ABFramework::ShaderObject::~ShaderObject()
{
	glDeleteProgram(m_programID);
}

//********************************************************************************//
//                               Operators                                        //
//********************************************************************************//




//********************************************************************************//
//                                Utility                                         //
//********************************************************************************//

ABFramework::Code ABFramework::ShaderObject::Load(const ABFramework::String& _vertexShader, const ABFramework::String& _fragmentShader)
{
	Code code = Code::FAILURE;

	// ----- Load shader files
	Buffer vertex_Buffer;
	Buffer frag_Buffer;

	code = File::Load(vertex_Buffer, _vertexShader);
	CHECK_EQUAL(code, Code::SUCCESS);
	code = File::Load(frag_Buffer, _fragmentShader);
	CHECK_EQUAL(code, Code::SUCCESS);
	if (code == Code::SUCCESS)
	{
		m_programID = glCreateProgram();
		unsigned int vs = privCompile(GL_VERTEX_SHADER, vertex_Buffer);
		unsigned int fs = privCompile(GL_FRAGMENT_SHADER, frag_Buffer);
		glAttachShader(m_programID, vs);
		glAttachShader(m_programID, fs);
		glLinkProgram(m_programID);
		glValidateProgram(m_programID);
		glDeleteShader(vs);
		glDeleteShader(fs);
		code = Code::SUCCESS;
	}

	return code;
}

int ABFramework::ShaderObject::FindUniformLocation(const ABFramework::String& _uniformName) const
{
	return glGetUniformLocation(m_programID, _uniformName.c_str());
}

void ABFramework::ShaderObject::Bind() const
{
	glUseProgram(m_programID);
}

void ABFramework::ShaderObject::Unbind() const
{
	glUseProgram(0U);
}

//********************************************************************************//
//                                Setters                                         //
//********************************************************************************//

void ABFramework::ShaderObject::SetUniform(int _uniformLocation, const glm::vec4& _vec)
{
	glUniform4f(_uniformLocation, _vec.x, _vec.y, _vec.z, _vec.w);
}

void ABFramework::ShaderObject::SetUniformTexture(int _uniformLocation, int _textureSlot)
{
	glUniform1i(_uniformLocation, _textureSlot);
}

void ABFramework::ShaderObject::SetUniformMatrix(int _uniformLocation, const Matrix& _mat)
{
	glUniformMatrix4fv(_uniformLocation, 1, GL_FALSE, &_mat[0][0]);
}

//********************************************************************************//
//                                Getters                                         //
//********************************************************************************//



//********************************************************************************//
//                             Private Helpers                                    //
//********************************************************************************//

int ABFramework::ShaderObject::privCompile(unsigned int _type, const ABFramework::Buffer& _buffer)
{
	unsigned int hShader = glCreateShader(_type);
	const char* src = _buffer.GetData();
	CHECK_NULL(src);
	glShaderSource(hShader, 1, &src, nullptr);
	glCompileShader(hShader);

	int result;
	glGetShaderiv(hShader, GL_COMPILE_STATUS, &result);
	if (result == GL_FALSE)
	{
		int length;
		glGetShaderiv(hShader, GL_INFO_LOG_LENGTH, &length);
		char* message = new char[length];
		memset(&message, 0, length);
		glGetShaderInfoLog(hShader, length, &length, message);

		printf("ERROR: Failed to compile shader.\n");
		printf("LOG: %s\n", message);
		delete[] message;

		glDeleteShader(hShader);
		hShader = 0;
	}

	return hShader;
}

