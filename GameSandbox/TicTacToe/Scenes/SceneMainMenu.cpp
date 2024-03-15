#include "SceneMainMenu.h"
#include "../Engine/Core/GameObject/GameObjectManager.h"
#include "../Engine/Core/AssetManager/AssetManager.h"
#include "../Engine/Renderer/OpenGL/Texture/Texture.h"
#include "../Engine/Renderer/OpenGL/SimpleMeshes/SquareMesh/SquareMesh.h"
#include "../Engine/Core/Camera/Camera.h"
#include "../Engine/Core/Window/Window.h"
#include "../Engine/Core/AssetManager/AssetDef/AssetDef.h"
#include "../Engine/Core/GameObject/Sprite/Sprite.h"
#include "../Engine/Core/Collision/Collider/AABB.h"
#include "../Engine/Core/Input/Input.h"
#include "../Controller/MainMenuController.h"

//********************************************************************************//
//                        Constructors / Destructor                               //
//********************************************************************************//

ABFramework::SceneMainMenu::SceneMainMenu()
	:Scene(), pExitBtn(new Sprite()), pController(nullptr)
{
	t_handle h_exitBtn = AssetManager::AddTexture(ExitBtn);
	pExitBtn->SetMesh(AssetManager::GetSquareMesh());
	pExitBtn->SetTexture(AssetManager::FindTexture(h_exitBtn));
	pExitBtn->SetPosition(Point3D(0.0f, 0.0f, 0.0f));
	pExitBtn->SetScale(Scale(640.0f, 48.0f, 0.0f));
	pController = new class MainMenuController(this);

}

ABFramework::SceneMainMenu::~SceneMainMenu()
{
	delete pExitBtn;
	pExitBtn = nullptr;
	delete pController;
	pController = nullptr;

}

//********************************************************************************//
//                               Operators                                        //
//********************************************************************************//




//********************************************************************************//
//                                Utility                                         //
//********************************************************************************//

void ABFramework::SceneMainMenu::SetupScene()
{
	Input::BindAction(MouseCode::BUTTON_LEFT, &PlayerController::OnClickLeft, pController);
}

void ABFramework::SceneMainMenu::CleanUpScene()
{
	Input::UnbindAction(MouseCode::BUTTON_LEFT);

}

void ABFramework::SceneMainMenu::Update()
{
	pExitBtn->Update();
}

void ABFramework::SceneMainMenu::Draw()
{
	pExitBtn->Draw(Camera::GetViewProjectionMatrix());
}


//********************************************************************************//
//                                Setters                                         //
//********************************************************************************//



//********************************************************************************//
//                                Getters                                         //
//********************************************************************************//

ABFramework::Sprite* ABFramework::SceneMainMenu::GetExitBtn() const
{
	return pExitBtn;
}

//********************************************************************************//
//                             Private Helpers                                    //
//********************************************************************************//

