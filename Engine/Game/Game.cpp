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
	:pWindow(nullptr), pOpenGLVersion(nullptr)
{
    pWindow = Renderer::Init(_pName, _width, _height);
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

}



void ABFramework::Game::LoadContent()
{
	
}

void ABFramework::Game::UnloadContent()
{

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
    GameObjectManager::Update();
}

void ABFramework::Game::Draw()
{
	Renderer::ClearScreen();
	GameObjectManager::Draw();
}

ABFramework::Code ABFramework::Game::Run()
{
    InitializeSystems();
    ABFramework::Code retCode = ABFramework::Code::FAILURE;

    // ----- Initialize Camera
    glm::vec3 centerViewPos((float)pWindow->GetResolution().width / 2.0f, (float)pWindow->GetResolution().height / 2.0f, 0.0f);
    Camera::Init(Point2D(pWindow->GetResolution().width, pWindow->GetResolution().height), centerViewPos);
    

    if (pWindow != nullptr)
    {
        retCode = ABFramework::Code::SUCCESS;

        Renderer::SetClearScreenColor(0.3f, 0.3f, 0.3f);      

        // ===== Create Objects for the scene ===== /

        String stitchTexturePath("..\\GameSandbox\\Assets\\Textures\\stitch.tga");
        String defaultTexturePath("..\\Engine\\Assets\\DefaultTexture.tga");
        String texture0("Stitch");
        String texture1("Default");

        t_handle h_stichTexture = AssetManager::AddTexture(stitchTexturePath, texture0.c_str());
        t_handle h_defaultTexture = AssetManager::AddTexture(defaultTexturePath, texture1.c_str());

        Square_Mesh squareMesh;

        t_handle h_sprite00 = GameObjectManager::AddSprite("Sprite00");//, &squareMesh, Point3D(0.0f, 0.0f, 0.0f), 200.0f, h_defaultTexture);
        GameObjectManager::GetSprite(h_sprite00)->SetMesh(&squareMesh);
        GameObjectManager::GetSprite(h_sprite00)->SetPosition(Point3D(0.0f, 0.0f, 0.0f));
        GameObjectManager::GetSprite(h_sprite00)->SetScale(200.0f);
        GameObjectManager::GetSprite(h_sprite00)->SetTexture(h_defaultTexture);

		t_handle h_sprite01 = GameObjectManager::AddSprite("Sprite01");//, &squareMesh, Point3D(220.0f, 0.0f, 0.0f), 200.0f, h_defaultTexture);
        GameObjectManager::GetSprite(h_sprite01)->SetMesh(&squareMesh);
        GameObjectManager::GetSprite(h_sprite01)->SetPosition(Point3D(220.0f, 0.0f, 0.0f));
        GameObjectManager::GetSprite(h_sprite01)->SetScale(200.0f);
        GameObjectManager::GetSprite(h_sprite01)->SetTexture(h_defaultTexture);

        Input::SetFocus(pWindow);
        Input::BindAction(MouseCode::BUTTON_LEFT, std::bind(&Sprite::OnLeftMouse, GameObjectManager::GetSprite(h_sprite00)), GameObjectManager::GetSprite(h_sprite00));

        /* Loop until the user closes the window */
        while (!pWindow->ShouldClose())
        {
            // ----- Input System ----- //
            Input::Process();

            // ----- Update ----- //
            Update();
          
            // ---- Draw ----- //
            Draw();                      

            /* Swap front and back buffers */
            pWindow->SwapBuffers();
   
            /* Poll for and process events */
            pWindow->PollEvents();

        }

        CloseSystems();

    }

    return retCode;
}


//********************************************************************************//
//                                Setters                                         //
//********************************************************************************//



//********************************************************************************//
//                             Private Helpers                                    //
//********************************************************************************//

void ABFramework::Game::privPrintOpenGLVersion() const
{
    printf("OpenGL Version: %s\n", this->pOpenGLVersion->c_str());

}


