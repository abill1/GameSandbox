
#include "enTT/entt.hpp"
#include "glad/glad.h"
#include "SDL2/SDL.h"
#include "glm/glm.hpp"
#include <stdio.h>

struct OpenGLAttributes
{
	Uint8 Major;
	Uint8 Minor;
	Uint8 Profile;
	Uint8 DoubleBuffer;
	Uint8 DepthBufferSize;
};

int main(int argc, char* argv[])
{
	SDL_Init(SDL_INIT_EVERYTHING);
	entt::registry m_Registry;
	entt::entity test0 = m_Registry.create();
	SDL_Log("Entity ID: %u\n", test0);

	// ----- Query to find the current display settings
	SDL_DisplayMode displayMode;
	SDL_GetCurrentDisplayMode(0, &displayMode);
	SDL_Log("Resolution: %d x %d | Refresh Rate: %d | Pixel Format: %s\n", displayMode.w, displayMode.h, displayMode.refresh_rate, SDL_GetPixelFormatName(displayMode.format));

	// ----- Create window and renderer 
	OpenGLAttributes oglAttr = { 4, 0, 1, 1, 24 };
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, oglAttr.Major);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, oglAttr.Minor);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, oglAttr.Profile);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, oglAttr.DoubleBuffer);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, oglAttr.DepthBufferSize);
	SDL_Window* window = SDL_CreateWindow("SDL Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, displayMode.w / 2, displayMode.h / 2, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
	SDL_GLContext openGLContext = SDL_GL_CreateContext(window);
	gladLoadGLLoader(SDL_GL_GetProcAddress);
	glViewport(SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, displayMode.w / 2, displayMode.h / 2);
	glClearColor(0.5f, 0.5f, 0.5f, 1.0f);

	// ----- Game Loop
	bool bRunning = true;
	while (bRunning)
	{
		// ----- Handle System Events
		SDL_Event m_event = {};
		while (SDL_PollEvent(&m_event))
		{
			switch (m_event.type)
			{
			case SDL_QUIT:
				bRunning = false;
				break;
			default:
				break;
			}

		}
		
		// ----- Handle Input
		const Uint8* state = SDL_GetKeyboardState(nullptr);
		if (state[SDL_SCANCODE_ESCAPE])
			bRunning = false;

		// ----- Render
		glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
		SDL_GL_SwapWindow(window);

	}

	// ----- Clean up
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}

