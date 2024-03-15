#include "Game.h"


#include "../Core/Math/Math.h"
#include "../Renderer/Renderer.h"
#include "../Renderer/OpenGL/SimpleMeshes/Triangle_Equilateral/Triangle_Equilateral.h"
#include "../Renderer/OpenGL/SimpleMeshes/SquareMesh/SquareMesh.h"
#include "../Renderer/OpenGL/DataStructures/IndexBuffer/IndexBuffer.h"
#include "../Renderer/OpenGL/DataStructures/VertexBuffer/VertexBuffer.h"
#include "../Renderer/OpenGL/DataStructures/VertexArray/VertexArray.h"
#include "../Renderer/OpenGL/ShaderObject/ShaderObject.h"
#include "../Renderer/OpenGL/Texture/Texture.h"
#include "../Renderer/OpenGL/GraphicsObject/GraphicsObject.h"
#include "../Core/Window/Window.h"
#include "../Core/GameObject/Sprite/Sprite.h"
#include "../Core/Collision/Collider/AABB.h"
#include "../Core/Input/Input.h"
#include "../Core/Collision/Collision.h"
#include "../Core/AssetManager/AssetManager.h"
#include "../Core/Camera/Camera.h"
#include "../Core/GameObject/GameObjectManager.h"
#include "../Core/GameObject/GameObjectManager.cpp"


//********************************************************************************//
//                        Constructors / Destructor                               //
//********************************************************************************//

ABFramework::Game::Game(const char* _pName, int _width, int _height)
	:pWindow(nullptr), pOpenGLVersion(nullptr), bRunning(true)
{
    pWindow = Renderer::Init(_pName, _width, _height);
    Renderer::SetClearScreenColor(0.3f, 0.3f, 0.3f);
    pOpenGLVersion = new ABFramework::String(Renderer::GetOpenGLVersionStr());
    privPrintOpenGLVersion();
}

ABFramework::Game::~Game()
{
	delete pWindow;
	pWindow = nullptr;
    delete pOpenGLVersion;
    pOpenGLVersion = nullptr;
    Renderer::Destroy();

}

//********************************************************************************//
//                               Operators                                        //
//********************************************************************************//



//********************************************************************************//
//                                Utility                                         //
//********************************************************************************//

void ABFramework::Game::InitializeSystems()
{
    AssetManager::Init();
    GameObjectManager::Init();
    Input::Init();
    Input::SetFocus(pWindow); // Should move to init

}

void ABFramework::Game::CloseSystems()
{
    Camera::Destroy();
	Input::Destroy();
    GameObjectManager::Destroy();
	AssetManager::Destroy();
}

void ABFramework::Game::Update()
{
    Input::Process();
    SubUpdateRoutine();
    GameObjectManager::Update();
}

void ABFramework::Game::Draw()
{
	Renderer::ClearScreen();
	GameObjectManager::Draw();
}

ABFramework::Code ABFramework::Game::Run()
{
    ABFramework::Code retCode = ABFramework::Code::FAILURE;
    CHECK_NULL(pWindow);
    if(pWindow != nullptr)
        retCode = ABFramework::Code::SUCCESS;

    InitializeSystems();
    LoadContent();       
    GameLoop();
    CloseSystems();

    return retCode;
}


//********************************************************************************//
//                                Setters                                         //
//********************************************************************************//



//********************************************************************************//
//                             Private Helpers                                    //
//********************************************************************************//

void ABFramework::Game::GameLoop()
{
	while (!pWindow->ShouldClose() && bRunning)
	{
		Update();
		Draw();

		/* Swap front and back buffers */
		pWindow->SwapBuffers();

		/* Poll for and process events */
		pWindow->PollEvents();

	}
}

void ABFramework::Game::privPrintOpenGLVersion() const
{
    printf("OpenGL Version: %s\n", this->pOpenGLVersion->c_str());

}


