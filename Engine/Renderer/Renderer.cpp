
#include "Renderer.h"

#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"
#include "glad/glad.h"
#include "OpenGL/ShaderObject/ShaderObject.h"
#include "OpenGL/DataStructures/VertexArray/VertexArray.h"
#include "OpenGL/DataStructures/IndexBuffer/IndexBuffer.h"
#include "OpenGL/GraphicsObject/GraphicsObject.h"
#include "../Engine/Core/GameObject/GameObject.h"
#include "../ABFramework/Debugging/Assert/Assert.h"
#include "../ABFramework/Codes/ABCode.h"
#include "../Engine/Core/Window/Window.h"

//********************************************************************************//
//                        Constructors / Destructor                                //
//********************************************************************************//

ABFramework::Renderer::Renderer()
{

}

ABFramework::Renderer::~Renderer()
{

}


ABFramework::Window* ABFramework::Renderer::Init(const char* _pName, int _width, int _height)
{
	ABFramework::Code retCode = ABFramework::Code::SUCCESS;
	// ----- Initialize GLFW
	if (!glfwInit())
		retCode = ABFramework::Code::FAILED_TO_INIT;
	CHECK_SUCCESS(retCode);

	glfwWindowHint(GLFW_SAMPLES, 4);					            // anti-aliasing
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);					// We want OpenGL 4.0 and greater
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);                  // Set Minor version 4.x
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);			// To make MacOS happy; should not be needed
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);	// We don't want the old OpenGL 
	
	ABFramework::Window* pWindow = new ABFramework::Window(_pName, _width, _height);
	pWindow->MakeContextCurrent();

	gladLoadGL();

	return pWindow;
}


void ABFramework::Renderer::Destroy()
{
	glfwTerminate();

}

//********************************************************************************//
//                               Operators                                        //
//********************************************************************************//




//********************************************************************************//
//                                Utility                                         //
//********************************************************************************//

void ABFramework::Renderer::ClearScreen()
{
	glClear(GL_COLOR_BUFFER_BIT);
}


//********************************************************************************//
//                                Setters                                         //
//********************************************************************************//

void ABFramework::Renderer::SetClearScreenColor(float _r, float _g, float _b, float _a /*= 1.0f*/)
{
	glClearColor(_r, _g, _b, _a);
}

const char* ABFramework::Renderer::GetOpenGLVersionStr()
{
	return (const char*)glGetString(GL_VERSION);
}

//********************************************************************************//
//                                Getters                                         //
//********************************************************************************//



//********************************************************************************//
//                             Private Helpers                                    //
//********************************************************************************//




