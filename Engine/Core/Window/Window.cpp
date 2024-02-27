#include "Window.h"
#include "GLFW\glfw3.h"
#include "ABString\ABString.h"
#include "Debugging\Assert\Assert.h"

#include <string.h>

//********************************************************************************//
//                        Constructors / Destructor                                //
//********************************************************************************//

ABFramework::Window::Window(const char* _pName, int _width, int _height)
	:pWindow(nullptr), pName(new ABFramework::String(_pName)), mResolution()
{
	mResolution.width = _width;
	mResolution.height = _height;
	CHECK_NULL(pName);
	pWindow = glfwCreateWindow(mResolution.width, mResolution.height, pName->c_str(), NULL, NULL);
	CHECK_NULL(pWindow);

}

ABFramework::Window::~Window()
{
	delete pName;
	pName = nullptr;

	glfwDestroyWindow(pWindow);
	pWindow = nullptr;

	memset(&mResolution, 0, sizeof(ABFramework::Window::Resolution));

}

//********************************************************************************//
//                               Operators                                        //
//********************************************************************************//




//********************************************************************************//
//                                Utility                                         //
//********************************************************************************//

void ABFramework::Window::MakeContextCurrent()
{
	glfwMakeContextCurrent(pWindow);
	glfwSwapInterval(1); // sets to current refresh rate
}

void ABFramework::Window::PollEvents()
{
	glfwPollEvents();

}

bool ABFramework::Window::ShouldClose()
{
	bool bClose = false;
	if(glfwWindowShouldClose(pWindow))
		bClose = true;
	if(glfwGetKey(pWindow, GLFW_KEY_ESCAPE) == GLFW_PRESS) 
		bClose = true;
	return bClose;
}

void ABFramework::Window::SwapBuffers()
{
	/* Swap front and back buffers */
	glfwSwapBuffers(pWindow);

}


//********************************************************************************//
//                                Setters                                         //
//********************************************************************************//


//********************************************************************************//
//                             Private Helpers                                    //
//********************************************************************************//


