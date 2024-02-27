
#ifndef OPENGL_SHADER_OBJECT_H
#define OPENGL_SHADER_OBJECT_H

#include "../Engine/Core/Math/Math.h"

namespace ABFramework
{
	class ShaderObject
	{
	public:
		// ----- Constructor / Destructor ----- //

		ShaderObject();
		ShaderObject(const ShaderObject&) = delete;
		ShaderObject(ShaderObject&&) = delete;
		~ShaderObject();

		// ----- Operators ----- //

		ShaderObject& operator=(const ShaderObject&) = delete;
		ShaderObject& operator=(ShaderObject&&) = delete;

		// ------ Utility ----- //

		enum class Code Load(const class String& _vertexShader, const class String& _fragmentShader);
		int FindUniformLocation(const class String& _uniformName) const; // Could store all uniforms in map
		void Bind() const;
		void Unbind() const;

		// ----- Setters ----- //

		void SetUniform(int _uniformLocation, const glm::vec4& _vec);
		void SetUniformTexture(int _uniformLocation, int _textureSlot);
		void SetUniformMatrix(int _uniformLocation, const Matrix& _mat);

		// ----- Getters ----- //


	private:

		int privCompile(unsigned int _type, const class Buffer& _buffer);

	private:
		unsigned int m_programID;

	};
}

#endif // !OPENGL_SHADER_OBJECT_H


