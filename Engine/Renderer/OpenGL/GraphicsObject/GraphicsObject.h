
/*
* Currently going to hard code this class to work just for texture objects since
* I only want to render 2D object right now. In the future, I should make this
* class more flexible. Not sure I want to use inheritance or create a data 
* structure which allows the user to add attributes. 
*/

#ifndef OPENGL_GRAPHICS_OBJECT_H
#define OPENGL_GRAPHICS_OBJECT_H

#include "../Engine/Core/Math/Math.h"

namespace ABFramework
{
	class GraphicsObject
	{
	public:
		// ----- Constructor / Destructor ----- //

		GraphicsObject();
		~GraphicsObject();

		// ----- Operators ----- //

		// ------ Utility ----- //

		void Draw(const Matrix& _vp, const Matrix& _transform) const;

		// ----- Setters ----- //

		void Set(const class Mesh& _mesh);
		void Set(const class Mesh* _mesh);
		void SetActiveTexture(class Texture* const _pTexture);
		//void SetDefaultTexture();

		// ----- Getters ----- //


	private:
		const char* const DEFAULT_TEXTURE_FILE_PATH = "..\\Engine\\Assets\\DefaultTexture.tga";
		const char* const DEFAULT_VERTEX_SHADER_PATH = "..\\Engine\\Renderer\\OpenGL\\Shaders\\Default.vs.glsl";
		const char* const DEFAULT_FRAGMENT_SHADER_PATH = "..\\Engine\\Renderer\\OpenGL\\Shaders\\Default.fs.glsl";
		const char* const VIEW_PROJECTION_UNIFORM = "u_VP";
		const char* const MODEL_UNIFORM = "u_Model";
		class ShaderObject*	pShader;
		class VertexArray*	pVAO;
		class VertexBuffer*	pVertBuf;
		class IndexBuffer*	pIndexBuf;
		class Texture*		pActiveTexture;
		//class Texture*		pDefaultTexture;
		int m_ViewProjUniformLoc;
		int m_ModelUniformLoc;

	};
}

#endif // !OPENGL_GRAPHICS_OBJECT_H

