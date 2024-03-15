
#include "TicTacToe.h"
#include "../Engine/Core/GameObject/GameObjectManager.h"
#include "../Engine/Core/AssetManager/AssetManager.h"
#include "../Engine/Renderer/Renderer.h"
#include "../Engine/Renderer/OpenGL/SimpleMeshes/Triangle_Equilateral/Triangle_Equilateral.h"
#include "../Engine/Renderer/OpenGL/SimpleMeshes/SquareMesh/SquareMesh.h"
#include "../Engine/Renderer/OpenGL/DataStructures/IndexBuffer/IndexBuffer.h"
#include "../Engine/Renderer/OpenGL/DataStructures/VertexBuffer/VertexBuffer.h"
#include "../Engine/Renderer/OpenGL/DataStructures/VertexArray/VertexArray.h"
#include "../Engine/Renderer/OpenGL/ShaderObject/ShaderObject.h"
#include "../Engine/Renderer/OpenGL/Texture/Texture.h"
#include "../Engine/Renderer/OpenGL/GraphicsObject/GraphicsObject.h"
#include "../Engine/Core/Camera/Camera.h"
#include "../Engine/Core/Window/Window.h"
#include "../Engine/Core/AssetManager/AssetDef/AssetDef.h"
#include "../Engine/Core/GameObject/Sprite/Sprite.h"
#include "../Engine/Core/Collision/Collider/AABB.h"
#include "../TicTacToe/GameBoard/GameBoard.h"
#include "../Engine/Core/Input/Input.h"
#include "../TicTacToe/GameBoard/Tile/Tile.h"
#include "../TicTacToe/Scenes/ScenePlayerTwo.h"
#include "../TicTacToe/Scenes/SceneManager.h"

//********************************************************************************//
//                        Constructors / Destructor                               //
//********************************************************************************//

ABFramework::TicTacToe::TicTacToe(const char* _pName, int _width, int _height)
	:Game(_pName, _width, _height), m_GameBoard(0) //pScenePlayerTwo(new ScenePlayerTwo()),
{

}


ABFramework::TicTacToe::~TicTacToe()
{
	//delete pScenePlayerTwo;
	//pScenePlayerTwo = nullptr;
}

//********************************************************************************//
//                               Operators                                        //
//********************************************************************************//




//********************************************************************************//
//                                Utility                                         //
//********************************************************************************//

void ABFramework::TicTacToe::InitializeSystems()
{
	Game::InitializeSystems();
	

}

void ABFramework::TicTacToe::LoadContent()
{
	// ----- Initialize Camera
	glm::vec3 centerViewPos((float)pWindow->GetResolution().width / 2.0f, (float)pWindow->GetResolution().height / 2.0f, 0.0f);
	Camera::Init(Point2D(pWindow->GetResolution().width, pWindow->GetResolution().height), centerViewPos);
	//pScenePlayerTwo->SetupScene();
	SceneManager::Init();

}

void ABFramework::TicTacToe::UnloadContent()
{
	
}

void ABFramework::TicTacToe::CloseSystems()
{
	SceneManager::Destroy();
	Game::CloseSystems();
}

void ABFramework::TicTacToe::Update()
{
	Input::Process();
	SceneManager::Update();
	//if (pScenePlayerTwo->GetGameState() != ScenePlayerTwo::GameState::NONE)
	//	bRunning = false;
	//else
	//	pScenePlayerTwo->Update();
}

void ABFramework::TicTacToe::Draw()
{
	Renderer::ClearScreen();
	SceneManager::Draw();
	//pScenePlayerTwo->Draw();
}

void ABFramework::TicTacToe::SubUpdateRoutine()
{

}

//********************************************************************************//
//                                Setters                                         //
//********************************************************************************//


//********************************************************************************//
//                                Getters                                         //
//********************************************************************************//


//********************************************************************************//
//                             Private Helpers                                    //
//********************************************************************************//


