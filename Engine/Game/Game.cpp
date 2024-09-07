#include "Game.h"
#include "../Engine/Engine.h"
#include "../Vendor/stb/stb_image.h"

Engine::Game::Game()
	:m_ClearColor(0.0f, 0.0f, 0.0f, 1.0f), m_DisplayMode{}, pWindow(nullptr), m_Register{}
{
	
}

Engine::Game::~Game()
{
	m_Register.clear();

};

struct WindowDimensions
{
	int xPixels;
	int yPixels;
	int aspectX;
	int aspectY;
	float aspectRatioX;
	float aspectRatioY;
};

constexpr WindowDimensions _1080HD = { 1920, 1080, 16, 9, 1.7778f, 1.0f };
constexpr WindowDimensions _APPLEII = { 280, 192, 35, 24, 1.45833f, 1.0f };

void Engine::Game::Run()
{
	// ----- Initialize SDL
	SDL_Init(SDL_INIT_EVERYTHING);

	// ----- Query to find the current display settings
	SDL_GetCurrentDisplayMode(0, &this->m_DisplayMode);
	SDL_Log("Resolution: %d x %d | Refresh Rate: %d | Pixel Format: %s\n", m_DisplayMode.w, m_DisplayMode.h, m_DisplayMode.refresh_rate, SDL_GetPixelFormatName(m_DisplayMode.format));

	// ----- Create window and renderer 
	Engine::Renderer::Initialize();
	WindowDimensions windowDimensions = _1080HD;
	this->pWindow = SDL_CreateWindow("SDL Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowDimensions.xPixels, windowDimensions.yPixels, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
	SDL_GLContext openGLContext = SDL_GL_CreateContext(this->pWindow);
	gladLoadGLLoader(SDL_GL_GetProcAddress);
	glClearColor(m_ClearColor.r, m_ClearColor.g, m_ClearColor.b, m_ClearColor.a);
	
	// ----- Entity
	Engine::Entity test(m_Register);
	Engine::Entity eTileMap(m_Register);
	OGL::CRectMesh* mesh0 = test.AddComponent<OGL::CRectMesh>();
	
	

	// ----- Textures
	
	// // ----- Query Hardware capabilities
	// int texture_units = 0;
	// glGetIntegerv(GL_MAX_TEXTURE_IMAGE_UNITS, &texture_units); // Should be 32 for modern PC hardware I believe
	// printf("Max Texture Units: %d\n", texture_units);

	// ----- TILE MAP USING TRANSFORMS AND SSBO BUFFERS
	const int scaleMultiplier = 3;
	const int xTileCount = _1080HD.aspectX * scaleMultiplier;
	const int yTileCount = _1080HD.aspectY * scaleMultiplier;
	const int NUM_OF_TILES = xTileCount * yTileCount;
	glm::mat4 transformMatrices[NUM_OF_TILES];

	float tileScale = 2.0f / yTileCount;
	glm::vec3 rectScalar(tileScale, tileScale, tileScale);
	glm::vec3 rectRotation(0.0f, 0.0f, 1.0f);
	float tileStartXPos = -_1080HD.aspectRatioX + (rectScalar.x / 2.0f);
	float tileXPos = tileStartXPos;
	float tileYPos = -_1080HD.aspectRatioY + (rectScalar.y / 2.0f);

	for (int y = 0; y < yTileCount; y++)
	{	
		for (int x = 0; x < xTileCount; x++)
		{
			glm::vec3 _translation = glm::vec3(tileXPos, tileYPos, 0.0f);
			transformMatrices[(y * xTileCount)+x] = glm::translate(glm::mat4(1.0f), _translation) * glm::rotate(glm::mat4(1.0f), glm::radians(0.0f), rectRotation) * glm::scale(glm::mat4(1.0f), rectScalar);
			tileXPos += rectScalar.x;
		}
		tileXPos = tileStartXPos;
		tileYPos += rectScalar.y;
	}

	// glm::vec4 tileColors[NUM_OF_TILES];
	// float rDif = (1.0f / (float)xTileCount);
	// float gDif = (1.0f / (float)yTileCount);
	// float r = 1.0f;
	// float g = 1.0f;
	// glm::vec4 defaultColor(0.0f, 0.0f, 0.0f, 1.0f);
	// glm::vec4 wall(0.8f, 0.8f, 0.8f, 1.0f);
	// memcpy_s(tileColors, sizeof(tileColors), &defaultColor, sizeof(glm::vec4));

	int tileState[NUM_OF_TILES];
	memset(tileState, 0, sizeof(tileState));
	const int TILE_STATE_EMPTY = 0;
	const int TILE_STATE_WALL = 1;
	const int TILE_STATE_SNAKE_HEAD = 2;
	const int TILE_STATE_SNAKE_BODY = 3;
	const int TILE_STATE_FOOD = 4;
	bool bFoodSpawned = false;
	const char* pFileLocation_TextureEmpty = "..\\GameSandbox\\Assets\\SnakeGame\\Wall\\Empty.tga";
	const char* pFileLocation_TextureWall = "..\\GameSandbox\\Assets\\SnakeGame\\Wall\\Wall.tga";
	const char* pFileLocation_TextureSnakeHead = "..\\GameSandbox\\Assets\\SnakeGame\\Snake\\SnakeHead.tga";
	const char* pFileLocation_TextureSnakeBody = "..\\GameSandbox\\Assets\\SnakeGame\\Snake\\SnakeBody.tga";
	const char* pFileLocation_TextureFood = "..\\GameSandbox\\Assets\\SnakeGame\\Food\\Fruit.tga";
	const char* pFileLocation_Test = "..\\GameSandbox\\Assets\\SnakeGame\\Food\\osquare.tga";
	

	for (int y = 2; y < 26; y++)
	{
		// tileColors[(y * xTileCount) + 1] = wall;
		// tileColors[(y * xTileCount) + 46] = wall;
	
		tileState[(y * xTileCount) + 1] = TILE_STATE_WALL;
		tileState[(y * xTileCount) + 46] = TILE_STATE_WALL;
	}
	
	for (int x = 1; x < 47; x++)
	{
		// tileColors[(2 * xTileCount) + x] = wall;
		// tileColors[(25 * xTileCount) + x] = wall;
	
		tileState[(2 * xTileCount) + x] = TILE_STATE_WALL;
		tileState[(25 * xTileCount) + x] = TILE_STATE_WALL;
	}

	int currentSnakeLength = 2;
	const int MAX_SNAKE_LENGTH = 31;
	struct PlayerPosition
	{
		int x;
		int y;
	};
	PlayerPosition SnakeBodyPositions[MAX_SNAKE_LENGTH];
	memset(SnakeBodyPositions, -1, sizeof(SnakeBodyPositions));

	PlayerPosition SnakeHeadPosition = { 0 };
	SnakeHeadPosition.x = 24;
	SnakeHeadPosition.y = 13;
	const float SNAKE_HEAD_RIGHT = 90.0f;
	const float SNAKE_HEAD_LEFT = -90.0f;
	const float SNAKE_HEAD_UP = 0.0f;
	const float SNAKE_HEAD_DOWN = 180.0f;
	float SnakeHeadRotation = SNAKE_HEAD_RIGHT;

	// glm::vec4 foodColor(1.0f, 0.0f, 0.0f, 1.0f);
	// glm::vec4 snakeHead(0.0f, 1.0f, 0.0f, 1.0f);
	// glm::vec4 snakeBody(0.5f, 1.0f, 0.8f, 1.0f);
	// tileColors[(SnakeHeadPosition.y * xTileCount) + SnakeHeadPosition.x] = snakeHead;
	tileState[(SnakeHeadPosition.y * xTileCount) + SnakeHeadPosition.x] = TILE_STATE_SNAKE_HEAD;

	glm::vec3 _translation;// = glm::vec3(SnakeHeadPosition.x, SnakeHeadPosition.y, 0.0f);
	//transformMatrices[(SnakeHeadPosition.y * xTileCount) + SnakeHeadPosition.x] *= glm::rotate(glm::mat4(1.0f), glm::radians(SnakeHeadRotation), rectRotation); //glm::translate(glm::mat4(1.0f), _translation) * glm::rotate(glm::mat4(1.0f), glm::radians(SnakeHeadRotation), rectRotation) * glm::scale(glm::mat4(1.0f), rectScalar);
	

	for (int i = currentSnakeLength; i > 0; i--)
	{
		SnakeBodyPositions[i-1].x = SnakeHeadPosition.x - i;
		SnakeBodyPositions[i-1].y = SnakeHeadPosition.y;
		// tileColors[(SnakeBodyPositions[i-1].y * xTileCount) + SnakeBodyPositions[i-1].x] = snakeBody;
		tileState[(SnakeBodyPositions[i-1].y * xTileCount) + SnakeBodyPositions[i-1].x] = TILE_STATE_SNAKE_BODY;
	}
	
	// ----- Projection View Matrix (Camera)
	float left   = -windowDimensions.aspectRatioX;
	float right  = windowDimensions.aspectRatioX;
	float top    = -windowDimensions.aspectRatioY;
	float bottom = windowDimensions.aspectRatioY;
	float Near = 1.0f;
	float far = -1.0;
	glm::mat4 projection = glm::ortho(left, right, bottom, top, Near, far);
	glm::vec3 cameraPosition(0.0f, 0.0f, -1.0f);
	float cameraRotation = 0.0f;
	glm::vec3 cameraRoationAxis(0.0f, 0.0f, 1.0f);
	glm::mat4 view = glm::translate(glm::mat4(1.0f), cameraPosition) * glm::rotate(glm::mat4(1.0f), glm::radians(cameraRotation), cameraRoationAxis);
	glm::mat4 uProjection = projection * glm::inverse(view);

	// ----- Tile Map Renderer Setup
	const size_t TRIANGLE = 3;
	OGL::Shader batchShader = OGL::OpenGL::LoadShader("../Engine/Renderer/OpenGL/Shaders/Batch.vs.glsl", "../Engine/Renderer/OpenGL/Shaders/Batch.fs.glsl");
	OGL::OpenGL::BindShader(batchShader);

	OGL::VertexArray tileVertArr;
	OGL::OpenGL::LinkVertexArray(tileVertArr);
	OGL::OpenGL::BindVertexArray(tileVertArr);

	OGL::VertexBuffer tileVertBuf;
	OGL::OpenGL::LinkVertexBuffer(tileVertBuf);
	OGL::OpenGL::BindVertexBuffer(tileVertBuf);
	OGL::OpenGL::SetVertexBufferData(mesh0->GetVertexSize(), mesh0->GetVertices());
	OGL::OpenGL::BindVertexArrayLayout(tileVertArr);

	OGL::IndexBuffer tileIndexBuf;
	OGL::OpenGL::LinkIndexBuffer(tileIndexBuf);
	OGL::OpenGL::BindIndexBuffer(tileIndexBuf);
	OGL::OpenGL::SetIndexBufferData(mesh0->GetIndexSize(), mesh0->GetIndices());

	// ----- Set SSBOs

	OGL::SSBO ssboTransforms;
	OGL::OpenGL::LinkSSBO(ssboTransforms);
	OGL::OpenGL::BindSSBO(ssboTransforms);
	OGL::OpenGL::SubmitSSBOData(sizeof(transformMatrices), nullptr);
	OGL::OpenGL::UnlinkSSBO();
	OGL::OpenGL::SetSSBOBufferSize(0, ssboTransforms, 0, sizeof(transformMatrices));

	OGL::SSBO ssboTileState;
	OGL::OpenGL::LinkSSBO(ssboTileState);
	OGL::OpenGL::BindSSBO(ssboTileState);
	OGL::OpenGL::SubmitSSBOData(sizeof(tileState), nullptr);
	OGL::OpenGL::UnlinkSSBO();
	OGL::OpenGL::SetSSBOBufferSize(1, ssboTileState, 0, sizeof(tileState));

	int uEmptyTextureLocation = 0;
	glUniform1i(glGetUniformLocation(batchShader, "s_Empty"), uEmptyTextureLocation);
	int uWallTextureLocation = 1;
	glUniform1i(glGetUniformLocation(batchShader, "s_Wall"), uWallTextureLocation);
	int uSnakeHeadTextureLocation = 2;
	glUniform1i(glGetUniformLocation(batchShader, "s_SnakeHead"), uSnakeHeadTextureLocation);
	int uSnakeBodyTextureLocation = 3;
	glUniform1i(glGetUniformLocation(batchShader, "s_SnakeBody"), uSnakeBodyTextureLocation);
	int uFallTextureLocation = 4;
	glUniform1i(glGetUniformLocation(batchShader, "s_Food"), uFallTextureLocation);

	//-------------------------------------------------------------------------------------------------------
	// Load Textures
	//-------------------------------------------------------------------------------------------------------
	int width;
	int height;
	int channels;

	// ----- Texture - Empty
	unsigned char* pTextureData = stbi_load(pFileLocation_TextureEmpty, &width, &height, &channels, 4);
	CHECK_NULL(pTextureData);
	glBindTexture(GL_TEXTURE_2D, 0);
	unsigned int TextureID_Empty;
	glGenTextures(1, &TextureID_Empty);
	glBindTexture(GL_TEXTURE_2D, TextureID_Empty);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA32F, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, pTextureData);
	glBindTexture(GL_TEXTURE_2D, 0);
	stbi_image_free(pTextureData);

	// ----- Texture - Wall
	pTextureData = stbi_load(pFileLocation_TextureWall, &width, &height, &channels, 4);
	CHECK_NULL(pTextureData);
	glBindTexture(GL_TEXTURE_2D, 0);
	unsigned int TextureID_Wall;
	glGenTextures(1, &TextureID_Wall);
	glBindTexture(GL_TEXTURE_2D, TextureID_Wall);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA32F, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, pTextureData);
	glBindTexture(GL_TEXTURE_2D, 0);
	stbi_image_free(pTextureData);

	// ----- Texture - Snake Head
	pTextureData = stbi_load(pFileLocation_TextureSnakeHead, &width, &height, &channels, 4);
	CHECK_NULL(pTextureData);
	glBindTexture(GL_TEXTURE_2D, 0);
	unsigned int TextureID_SnakeHead;
	glGenTextures(1, &TextureID_SnakeHead);
	glBindTexture(GL_TEXTURE_2D, TextureID_SnakeHead);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA32F, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, pTextureData);
	glBindTexture(GL_TEXTURE_2D, 0);
	stbi_image_free(pTextureData);

	// ----- Texture - Snake Body
	pTextureData = stbi_load(pFileLocation_TextureSnakeBody, &width, &height, &channels, 4);
	CHECK_NULL(pTextureData);
	glBindTexture(GL_TEXTURE_2D, 0);
	unsigned int TextureID_SnakeBody;
	glGenTextures(1, &TextureID_SnakeBody);
	glBindTexture(GL_TEXTURE_2D, TextureID_SnakeBody);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA32F, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, pTextureData);
	glBindTexture(GL_TEXTURE_2D, 0);
	stbi_image_free(pTextureData);

	// ----- Texture - Food
	pTextureData = stbi_load(pFileLocation_TextureFood, &width, &height, &channels, 4);
	CHECK_NULL(pTextureData);
	glBindTexture(GL_TEXTURE_2D, 0);
	unsigned int TextureID_Food;
	glGenTextures(1, &TextureID_Food);
	glBindTexture(GL_TEXTURE_2D, TextureID_Food);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA32F, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, pTextureData);
	glBindTexture(GL_TEXTURE_2D, 0);
	stbi_image_free(pTextureData);

	// ----- Game Loop
	bool bRunning = true;
	Framework::Timer timer;
	int framecount = 0;
	float timeElapsed = 0.0f;
	float ms_per_sec = 1000.0f;
	int Snake_Velocity_X = 1;
	int Snake_Velocity_Y = 0;
	PlayerPosition SnakeDirection = {0};
	SnakeDirection.x = 1;

	std::random_device rd;
	// seed value designed specifically to be different across app executions
	std::mt19937::result_type seed = rd() ^ (
		(std::mt19937::result_type)
		std::chrono::duration_cast<std::chrono::seconds>(
			std::chrono::system_clock::now().time_since_epoch()
			).count() +
		(std::mt19937::result_type)
		std::chrono::duration_cast<std::chrono::microseconds>(
			std::chrono::high_resolution_clock::now().time_since_epoch()
			).count());

	std::mt19937 genx(seed);
	std::mt19937 geny(seed);
	std::uniform_int_distribution<> distribY(4, 23);
	std::uniform_int_distribution<> distribX(3, 44);

	float nextMoveCmd = timer.GetTotalTimeElapsed() + 0.25f;
	int playerScore = 0;
	const int FOOD_SCORE = 10;
	
	while (bRunning)
	{
		framecount++;
		timer.Tick();
		
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
		if (state[SDL_SCANCODE_A] && SnakeDirection.x != 1)
		{
			SnakeDirection.x = -1;
			SnakeDirection.y = 0;
			SnakeHeadRotation = SNAKE_HEAD_LEFT;
		}
		else if (state[SDL_SCANCODE_D] && SnakeDirection.x != -1)
		{
			SnakeDirection.x = 1;
			SnakeDirection.y = 0;
			SnakeHeadRotation = SNAKE_HEAD_RIGHT;
		}
		else if (state[SDL_SCANCODE_S] && SnakeDirection.y != -1)
		{
			SnakeDirection.x = 0;
			SnakeDirection.y = 1;
			SnakeHeadRotation = SNAKE_HEAD_DOWN;
		}
		else if (state[SDL_SCANCODE_W] && SnakeDirection.y != 1)
		{
			SnakeDirection.x = 0;
			SnakeDirection.y = -1;
			SnakeHeadRotation = SNAKE_HEAD_UP;
		}
		
		// ----- Update Game State
		
		if (timer.GetTotalTimeElapsed() >= nextMoveCmd)
		{
			// ----- Find Frames Per Second
			float frameTime = ms_per_sec / (float)framecount;
			printf("FPS: %d | ", framecount);
			printf("Frame time: %.4f (ms)\n", frameTime);
			framecount = 0;
		
			// ----- Update Snake
			// -- This code is needed to reset the tile TRS because issue when we return to this tile or spawn food
			float shxp = (-_1080HD.aspectRatioX + (rectScalar.x / 2.0f)) + (rectScalar.x * SnakeHeadPosition.x);
			float shyp = (-_1080HD.aspectRatioY + (rectScalar.y / 2.0f)) + (rectScalar.y * SnakeHeadPosition.y);
			_translation = glm::vec3(shxp, shyp, 0.0f);
			transformMatrices[(SnakeHeadPosition.y * xTileCount) + SnakeHeadPosition.x] = glm::translate(glm::mat4(1.0f), _translation) * glm::rotate(glm::mat4(1.0f), glm::radians(0.0f), rectRotation) * glm::scale(glm::mat4(1.0f), rectScalar);

			// tileColors[(SnakeBodyPositions[currentSnakeLength - 1].y * xTileCount) + SnakeBodyPositions[currentSnakeLength - 1].x] = defaultColor;
			tileState[(SnakeBodyPositions[currentSnakeLength - 1].y * xTileCount) + SnakeBodyPositions[currentSnakeLength - 1].x] = TILE_STATE_EMPTY;
		
			// ----- Reset the last head position Rotation to default position
			//_translation = glm::vec3(SnakeHeadPosition.x, SnakeHeadPosition.y, 0.0f);
			//transformMatrices[(SnakeHeadPosition.y * xTileCount) + SnakeHeadPosition.x] *= glm::rotate(glm::mat4(1.0f), glm::radians(-SnakeHeadRotation), rectRotation); //glm::translate(glm::mat4(1.0f), _translation) * glm::rotate(glm::mat4(1.0f), glm::radians(SnakeHeadRotation), rectRotation) * glm::scale(glm::mat4(1.0f), rectScalar);
			
			// ----- Update player position
			PlayerPosition lastHeadPosition = SnakeHeadPosition;
			SnakeHeadPosition.x += SnakeDirection.x;
			SnakeHeadPosition.y += SnakeDirection.y;

			// ----- Check if new position results in a food consumed
			if (tileState[(SnakeHeadPosition.y * xTileCount) + SnakeHeadPosition.x] == TILE_STATE_FOOD)
			{
				bFoodSpawned = false;
				playerScore += FOOD_SCORE;
				printf("Player Score: %d\n", playerScore);
				if (currentSnakeLength < MAX_SNAKE_LENGTH)
					currentSnakeLength++;
			}
			
			// ----- Update snake body location
			for (int i = currentSnakeLength - 1; i > 0; i--)
			{
				SnakeBodyPositions[i] = SnakeBodyPositions[i - 1];
				// tileColors[(SnakeBodyPositions[i].y * xTileCount) + SnakeBodyPositions[i].x] = snakeBody;
				tileState[(SnakeBodyPositions[i].y * xTileCount) + SnakeBodyPositions[i].x] = TILE_STATE_SNAKE_BODY;
			}
			SnakeBodyPositions[0] = lastHeadPosition;
			// tileColors[(SnakeBodyPositions[0].y * xTileCount) + SnakeBodyPositions[0].x] = snakeBody;
			tileState[(SnakeBodyPositions[0].y * xTileCount) + SnakeBodyPositions[0].x] = TILE_STATE_SNAKE_BODY;
			
			// ----- Update snake head
			// tileColors[(SnakeHeadPosition.y * xTileCount) + SnakeHeadPosition.x] = snakeHead;
			tileState[(SnakeHeadPosition.y * xTileCount) + SnakeHeadPosition.x] = TILE_STATE_SNAKE_HEAD;
			// ----- Rotate Head Texture as needed
			shxp = (-_1080HD.aspectRatioX + (rectScalar.x / 2.0f)) + (rectScalar.x * SnakeHeadPosition.x);
			shyp = (-_1080HD.aspectRatioY + (rectScalar.y / 2.0f)) + (rectScalar.y * SnakeHeadPosition.y);
			_translation = glm::vec3(shxp, shyp, 0.0f);
			transformMatrices[(SnakeHeadPosition.y * xTileCount) + SnakeHeadPosition.x] = glm::translate(glm::mat4(1.0f), _translation) * glm::rotate(glm::mat4(1.0f), glm::radians(SnakeHeadRotation), rectRotation) * glm::scale(glm::mat4(1.0f), rectScalar);

			if (!bFoodSpawned)
			{
				unsigned int index = (distribY(geny) * xTileCount) + distribX(genx);
				if (tileState[index] == TILE_STATE_EMPTY)
				{
					//tileColors[index] = foodColor;
					tileState[index] = TILE_STATE_FOOD;
					bFoodSpawned = true;
				}
			}
			nextMoveCmd = timer.GetTotalTimeElapsed() + 0.5f;
		}

		// ----- Render
		glDisable(GL_DEPTH_TEST);
		glDisable(GL_CULL_FACE);
		glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
		glEnable(GL_BLEND);
		glBlendFuncSeparate(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA, GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glBlendEquationSeparate(GL_FUNC_ADD, GL_FUNC_ADD);

		//------------------------------------------------------------------------------------------------
		// Draw
		//------------------------------------------------------------------------------------------------
		OGL::OpenGL::BindShader(batchShader);
		OGL::OpenGL::BindVertexArray(tileVertArr);
		OGL::OpenGL::BindIndexBuffer(tileIndexBuf);
		OGL::OpenGL::SetUniformBuffer(batchShader, "uProjection", 1, uProjection);
		OGL::OpenGL::BindSSBO(ssboTransforms);
		OGL::OpenGL::SubmitDynamicSSBOData(sizeof(transformMatrices), transformMatrices);
		OGL::OpenGL::BindSSBO(ssboTileState);
		OGL::OpenGL::SubmitDynamicSSBOData(sizeof(tileState), tileState);
		
		// ----- Set Textures
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, TextureID_Empty);
		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, TextureID_Wall);
		glActiveTexture(GL_TEXTURE2);
		glBindTexture(GL_TEXTURE_2D, TextureID_SnakeHead);
		glActiveTexture(GL_TEXTURE3);
		glBindTexture(GL_TEXTURE_2D, TextureID_SnakeBody);
		glActiveTexture(GL_TEXTURE4);
		glBindTexture(GL_TEXTURE_2D, TextureID_Food);

		glDrawElementsInstanced(GL_TRIANGLES, mesh0->GetIndexCount()*TRIANGLE, GL_UNSIGNED_INT, nullptr, NUM_OF_TILES);

		glBindVertexArray(0);
		glUseProgram(0);

		SDL_GL_SwapWindow(this->pWindow);
		SDL_ResetKeyboard();

	}

	// ----- Clean up
	//OGL::OpenGL::UnlinkIndexBuffer(indexBuf);
	//OGL::OpenGL::UnlinkVertexBuffer(veBuf);
	//OGL::OpenGL::UnlinkVertexArray(vao);
	// mesh0 = nullptr;
	// OGL::OpenGL::DestroyShader(constantColorShader);
	OGL::OpenGL::UnlinkSSBO(ssboTransforms);
	OGL::OpenGL::UnlinkSSBO(ssboTileState);
	glDeleteTextures(1, &TextureID_Empty);
	glDeleteTextures(1, &TextureID_Wall);
	glDeleteTextures(1, &TextureID_SnakeHead);
	glDeleteTextures(1, &TextureID_SnakeBody);
	glDeleteTextures(1, &TextureID_Food);
	OGL::OpenGL::DestroyShader(batchShader);
	openGLContext = nullptr;
	SDL_DestroyWindow(this->pWindow);
	SDL_Quit();

}

