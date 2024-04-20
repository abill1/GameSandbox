
#ifndef ENGINE_RENDERER_H
#define ENGINE_RENDERER_H

//======================================================================
// Includes
//======================================================================

#include "OpenGL/OpenGL.h"
#include "../Vendor/SDL2/SDL.h"

namespace Engine
{
	class Renderer
	{
	public:
		
		enum class GraphicsAPI : unsigned char
		{
			UNDEFINED,
			OPENGL
		};

		static void Initialize(GraphicsAPI _gapi = GraphicsAPI::OPENGL)
		{
			switch (_gapi)
			{
			case Engine::Renderer::GraphicsAPI::UNDEFINED:
				break;
			case Engine::Renderer::GraphicsAPI::OPENGL:
				privOpenGLInitialization();
				break;
			default:
				break;
			}
		}

	private:
		static void privOpenGLInitialization()
		{
			OGL::OpenGLAttributes oglAttr;
			SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, oglAttr.m_MajorVersion);
			SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, oglAttr.m_MinorVersion);
			SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, oglAttr.m_Profile);
			SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, oglAttr.m_DoubleBuffer);
			SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, oglAttr.m_DepthBufferSize);
			SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, oglAttr.m_AntiAliasing);

		}

	};
}


#endif // !ENGINE_RENDERER_H

