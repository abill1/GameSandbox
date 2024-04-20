
#include "./Engine/Engine.h"
#include <stdio.h>

int main(int argc, char* argv[])
{
	Framework::MemoryTracker::Init();

	// ----- Initialize enTT 
	entt::registry m_Registry;
	entt::entity test0 = m_Registry.create();

	// ----- Initialize SDL
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Log("Entity ID: %u\n", test0);

	// ----- Query to find the current display settings
	SDL_DisplayMode displayMode;
	SDL_GetCurrentDisplayMode(0, &displayMode);
	SDL_Log("Resolution: %d x %d | Refresh Rate: %d | Pixel Format: %s\n", displayMode.w, displayMode.h, displayMode.refresh_rate, SDL_GetPixelFormatName(displayMode.format));
	SDL_GetCurrentVideoDriver();

	// ----- Create window and renderer 
	Engine::Renderer::Initialize();
	SDL_Window* window = SDL_CreateWindow("SDL Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, displayMode.w / 2, displayMode.h / 2, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
	SDL_GLContext openGLContext = SDL_GL_CreateContext(window);
	gladLoadGLLoader(SDL_GL_GetProcAddress);
	glm::vec4 clearColor = { 0.5f, 0.5f, 0.5f, 1.0f };
	glViewport(0, 0, displayMode.w, -displayMode.h);
	glClearColor(clearColor.r, clearColor.g, clearColor.b, clearColor.a);

	OGL::Shader constantColorShader = OGL::OpenGL::LoadShader("../Engine/Renderer/OpenGL/Shaders/Default.vs.glsl", "../Engine/Renderer/OpenGL/Shaders/Default.fs.glsl");
	assert(constantColorShader != 0);
	OGL::Vertex* pVerts = new OGL::Vertex[4];
	pVerts[0] = { {-0.5f, -0.5f, 0.0f, 1.0f }, { 0.8f, 0.4f, 0.5f, 1.0f }, { 0.0f, 0.0f } };
	pVerts[1] = { { 0.5f, -0.5f, 0.0f, 1.0f }, { 0.7f, 0.5f, 0.6f, 1.0f },  { 1.0f, 0.0f } };
	pVerts[2] = { { 0.5f, 0.5f, 0.0f, 1.0f },  { 0.6f, 0.5f, 0.7f, 1.0f },   { 1.0f, 1.0f } };
	pVerts[3] = { { -0.5f, 0.5f, 0.0f, 1.0f }, { 0.5f, 0.4f, 0.8f, 1.0f },  { 0.0f, 1.0f }};
	if (pVerts != nullptr)
		SDL_Log("Verts Init\n");
	OGL::IndexBuffer* pIndices = new OGL::IndexBuffer[6];
	pIndices[0] = 0U;
	pIndices[1] = 1U;
	pIndices[2] = 2U;
	pIndices[3] = 0U;
	pIndices[4] = 2U;
	pIndices[5] = 3U;
	if (pIndices != nullptr)
		SDL_Log("Indices Init\n");

	OGL::VertexArray vao;
	OGL::OpenGL::LinkVertexArray(vao);
	OGL::OpenGL::BindVertexArray(vao);

	OGL::VertexBuffer vertBuf = 0;
	OGL::OpenGL::LinkVertexBuffer(vertBuf);
	OGL::OpenGL::BindVertexBuffer(vertBuf);
	OGL::OpenGL::SetVertexBufferData(4 * sizeof(OGL::Vertex), pVerts);
	OGL::OpenGL::BindVertexArrayLayout(vao);

	OGL::IndexBuffer indexBuf;
	OGL::OpenGL::LinkIndexBuffer(indexBuf);
	OGL::OpenGL::BindIndexBuffer(indexBuf);
	OGL::OpenGL::SetIndexBufferData(6 * sizeof(OGL::IndexBuffer), pIndices);
	


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
		glDisable(GL_DEPTH_TEST);
		glDisable(GL_CULL_FACE);
		
		glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
		
		OGL::OpenGL::BindShader(constantColorShader);
		OGL::OpenGL::BindVertexArray(vao);
		OGL::OpenGL::BindIndexBuffer(indexBuf);
		glDrawElements(GL_TRIANGLES, (GLsizeiptr)6, GL_UNSIGNED_INT, nullptr);

		
		SDL_GL_SwapWindow(window);

	}

	// ----- Clean up
	OGL::OpenGL::UnlinkIndexBuffer(indexBuf);
	OGL::OpenGL::UnlinkVertexBuffer(vertBuf);
	OGL::OpenGL::UnlinkVertexArray(vao);
	delete[] pIndices;
	delete[] pVerts;
	OGL::OpenGL::DestroyShader(constantColorShader);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}

