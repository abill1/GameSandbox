#include "MainMenuController.h"
#include "../Engine/Core/Collision/Collision.h"
#include "../Engine/Core/Input/Input.h"
#include "../Engine/Core/Collision/Collider/AABB.h"
#include "../Engine/Core/GameObject/Sprite/Sprite.h"
#include "../Scenes/SceneMainMenu.h"
#include "../Scenes/SceneManager.h"

//********************************************************************************//
//                        Constructors / Destructor                               //
//********************************************************************************//

ABFramework::MainMenuController::MainMenuController(SceneMainMenu* _pScene)
	:pMainMenuScene(_pScene)
{

}


ABFramework::MainMenuController::~MainMenuController()
{
	pMainMenuScene = nullptr;

}



//********************************************************************************//
//                               Operators                                        //
//********************************************************************************//




//********************************************************************************//
//                                Utility                                         //
//********************************************************************************//

void ABFramework::MainMenuController::OnClickLeft()
{
	if (Collision::Check(pMainMenuScene->GetExitBtn()->GetCollider(), Input::GetMouseCollider()))
	{
		SceneManager::NextScene();
	}
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


