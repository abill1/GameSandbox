#include "SceneManager.h"
#include "SceneMainMenu.h"
#include "ScenePlayerTwo.h"

ABFramework::SceneManager* ABFramework::SceneManager::pInstance = nullptr;

//********************************************************************************//
//                        Constructors / Destructor                               //
//********************************************************************************//

ABFramework::SceneManager::SceneManager()
	:pMainMenu(new SceneMainMenu()), pTwoPlayer(new ScenePlayerTwo()), pActiveScene(nullptr)
{
	pMainMenu->SetNextScene(pTwoPlayer);
	pTwoPlayer->SetNextScene(pMainMenu);
	pActiveScene = pMainMenu;

}

ABFramework::SceneManager::~SceneManager()
{
	pActiveScene = nullptr;

	delete pMainMenu;
	pMainMenu = nullptr;
	delete pTwoPlayer;
	pTwoPlayer = nullptr;
	
}

void ABFramework::SceneManager::Init()
{
	CHECK_NULL(privGetInstance());
	privGetInstance()->pActiveScene->SetupScene();
}

void ABFramework::SceneManager::Destroy()
{
	delete SceneManager::pInstance;
	SceneManager::pInstance = nullptr;
}

void ABFramework::SceneManager::NextScene()
{
	SceneManager* pInst = privGetInstance();
	pInst->pActiveScene->CleanUpScene();
	pInst->pActiveScene = pInst->pActiveScene->NextScene();
	pInst->pActiveScene->SetupScene();

}

void ABFramework::SceneManager::Update()
{
	privGetInstance()->pActiveScene->Update();
}

void ABFramework::SceneManager::Draw()
{
	privGetInstance()->pActiveScene->Draw();
}

//********************************************************************************//
//                               Operators                                        //
//********************************************************************************//




//********************************************************************************//
//                                Utility                                         //
//********************************************************************************//




//********************************************************************************//
//                                Setters                                         //
//********************************************************************************//



//********************************************************************************//
//                                Getters                                         //
//********************************************************************************//



//********************************************************************************//
//                             Private Helpers                                    //
//********************************************************************************//

ABFramework::SceneManager* ABFramework::SceneManager::privGetInstance()
{
	if (SceneManager::pInstance == nullptr)
		SceneManager::pInstance = new SceneManager();
	return SceneManager::pInstance;
}

