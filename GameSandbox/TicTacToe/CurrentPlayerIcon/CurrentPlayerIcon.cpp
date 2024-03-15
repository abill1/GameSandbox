#include "CurrentPlayerIcon.h"
#include "../Engine/Core/Collision/Collider/AABB.h"
#include "../Engine/Core/GameObject/Sprite/Sprite.h"
#include "../Engine/Renderer/OpenGL/SimpleMeshes/SquareMesh/SquareMesh.h"
#include "../Engine/Core/AssetManager/AssetManager.h"
#include "../Engine/Core/Camera/Camera.h"
#include "../Scenes/ScenePlayerTwo.h"

//********************************************************************************//
//                        Constructors / Destructor                               //
//********************************************************************************//

ABFramework::CurrentPlayerIcon::CurrentPlayerIcon()
	:pPlayerOneIcon(new Sprite()), pPlayerTwoIcon(new Sprite()), pCurrentPlayer(nullptr)
{
	pPlayerOneIcon->SetMesh(AssetManager::GetSquareMesh());
	t_handle h_PlayerOne = AssetManager::AddTexture(PlayerOneText);
	pPlayerOneIcon->SetTexture(h_PlayerOne);

	pPlayerTwoIcon->SetMesh(AssetManager::GetSquareMesh());
	t_handle h_PlayerTwo = AssetManager::AddTexture(PlayerTwoText);
	pPlayerTwoIcon->SetTexture(h_PlayerTwo);

	pCurrentPlayer = pPlayerOneIcon;

}


ABFramework::CurrentPlayerIcon::~CurrentPlayerIcon()
{
	pCurrentPlayer = nullptr;
	delete pPlayerOneIcon;
	pPlayerOneIcon = nullptr;
	delete pPlayerTwoIcon;
	pPlayerTwoIcon = nullptr;

}


//********************************************************************************//
//                               Operators                                        //
//********************************************************************************//




//********************************************************************************//
//                                Utility                                         //
//********************************************************************************//

void ABFramework::CurrentPlayerIcon::Update()
{
	if (ScenePlayerTwo::GetCurrentTurn() == ScenePlayerTwo::TurnPlayer::ONE)
		pCurrentPlayer = pPlayerOneIcon;
	else if (ScenePlayerTwo::GetCurrentTurn() == ScenePlayerTwo::TurnPlayer::TWO)
		pCurrentPlayer = pPlayerTwoIcon;

	pCurrentPlayer->Update();
}

void ABFramework::CurrentPlayerIcon::Draw(const Matrix& _viewProj)
{
	pCurrentPlayer->Draw(_viewProj);
}

//********************************************************************************//
//                                Setters                                         //
//********************************************************************************//

void ABFramework::CurrentPlayerIcon::SetPosition(Player _player, const Point3D& _position)
{
	switch (_player)
	{
	case ABFramework::CurrentPlayerIcon::Player::ONE:
		pPlayerOneIcon->SetPosition(_position);
		break;
	case ABFramework::CurrentPlayerIcon::Player::TWO:
		pPlayerTwoIcon->SetPosition(_position);
		break;
	default:
		break;
	}
	
}

void ABFramework::CurrentPlayerIcon::SetScale(Player _player, const Scale& _scale)
{
	switch (_player)
	{
	case ABFramework::CurrentPlayerIcon::Player::ONE:
		pPlayerOneIcon->SetScale(_scale);
		break;
	case ABFramework::CurrentPlayerIcon::Player::TWO:
		pPlayerTwoIcon->SetScale(_scale);
		break;
	default:
		break;
	}
}

void ABFramework::CurrentPlayerIcon::SwapPlayer(Player _player)
{
	switch (_player)
	{
	case ABFramework::CurrentPlayerIcon::Player::ONE:
		pCurrentPlayer = pPlayerOneIcon;
		break;
	case ABFramework::CurrentPlayerIcon::Player::TWO:
		pCurrentPlayer = pPlayerTwoIcon;
		break;
	default:
		break;
	}
}

//********************************************************************************//
//                                Getters                                         //
//********************************************************************************//



//********************************************************************************//
//                             Private Helpers                                    //
//********************************************************************************//



