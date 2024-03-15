#include "ScenePlayerTwo.h"
#include "../Engine/Core/GameObject/GameObjectManager.h"
#include "../Engine/Core/AssetManager/AssetManager.h"
#include "../Engine/Renderer/OpenGL/Texture/Texture.h"
#include "../Engine/Renderer/OpenGL/SimpleMeshes/SquareMesh/SquareMesh.h"
#include "../Engine/Core/Camera/Camera.h"
#include "../Engine/Core/Window/Window.h"
#include "../Engine/Core/AssetManager/AssetDef/AssetDef.h"
#include "../Engine/Core/GameObject/Sprite/Sprite.h"
#include "../Engine/Core/Collision/Collider/AABB.h"
#include "../GameBoard/GameBoard.h"
#include "../Engine/Core/Input/Input.h"
#include "../GameBoard/Tile/Tile.h"
#include "../Controller/TwoPlayerController.h"
#include "../CurrentPlayerIcon/CurrentPlayerIcon.h"
#include "../Scenes/SceneManager.h"

ABFramework::ScenePlayerTwo::TurnPlayer ABFramework::ScenePlayerTwo::s_PlayerTurn = ABFramework::ScenePlayerTwo::TurnPlayer::ONE;
ABFramework::ScenePlayerTwo::GameState ABFramework::ScenePlayerTwo::s_GameState = ABFramework::ScenePlayerTwo::GameState::NONE;


//********************************************************************************//
//                        Constructors / Destructor                               //
//********************************************************************************//

ABFramework::ScenePlayerTwo::ScenePlayerTwo()
	:Scene(), pBoard(nullptr), pController(nullptr), pCurrentPlayerIcon(nullptr)
{
	AssetManager::AddTexture(defaultTexture);
	AssetManager::AddTexture(EmptySquare);
	AssetManager::AddTexture(XSquare);
	AssetManager::AddTexture(OSquare);
	pBoard = new GameBoard();
	pController = new TwoPlayerController(pBoard);
	pCurrentPlayerIcon = new CurrentPlayerIcon();
	pCurrentPlayerIcon->SetPosition(CurrentPlayerIcon::Player::ONE, Point3D(-400.0f, 400.0f, 0.0f));
	pCurrentPlayerIcon->SetScale(CurrentPlayerIcon::Player::ONE, Scale(200.0f, 200.0f, 0.0f));
	pCurrentPlayerIcon->SetPosition(CurrentPlayerIcon::Player::TWO, Point3D(400.0f, 400.0f, 0.0f));
	pCurrentPlayerIcon->SetScale(CurrentPlayerIcon::Player::TWO, Scale(200.0f, 200.0f, 0.0f));

}


ABFramework::ScenePlayerTwo::~ScenePlayerTwo()
{
	delete pController;
	pController = nullptr;
	delete pCurrentPlayerIcon;
	pCurrentPlayerIcon = nullptr;
	delete pBoard;
	pBoard = nullptr;

}

//********************************************************************************//
//                               Operators                                        //
//********************************************************************************//




//********************************************************************************//
//                                Utility                                         //
//********************************************************************************//

void ABFramework::ScenePlayerTwo::SetupScene()
{
	Input::BindAction(MouseCode::BUTTON_LEFT, &PlayerController::OnClickLeft, pController);
}

void ABFramework::ScenePlayerTwo::CleanUpScene()
{
	Input::UnbindAction(MouseCode::BUTTON_LEFT);
}

void ABFramework::ScenePlayerTwo::Update()
{
	if (UpdateGameState() != GameState::NONE)
	{
		switch (ScenePlayerTwo::s_GameState)
		{
		case GameState::WIN_PLAYER_ONE:
			ScenePlayerTwo::s_GameState = GameState::WIN_PLAYER_ONE;
			printf("Player One Wins!\n");
			SceneManager::NextScene();
			break;
		case GameState::WIN_PLAYER_TWO:
			ScenePlayerTwo::s_GameState = GameState::WIN_PLAYER_TWO;
			printf("Player Two Wins!\n");
			SceneManager::NextScene();
			break;
		case GameState::DRAW:
			ScenePlayerTwo::s_GameState = GameState::DRAW;
			printf("Draw!\n");
			SceneManager::NextScene();
			break;
		case GameState::NONE:
		default:
			printf("Error! Incorrect Game State\n");
			break;
		}
	}
	pBoard->Update();
	pCurrentPlayerIcon->Update();
	
}

void ABFramework::ScenePlayerTwo::Draw()
{
	pBoard->Draw(Camera::GetViewProjectionMatrix());
	pCurrentPlayerIcon->Draw(Camera::GetViewProjectionMatrix());

}

ABFramework::ScenePlayerTwo::GameState ABFramework::ScenePlayerTwo::UpdateGameState()
{
	privTestRowWin();
	privTestColWin();
	privTestDiagonalWin();
	privTestDraw();

	return ScenePlayerTwo::s_GameState;
}

//********************************************************************************//
//                                Setters                                         //
//********************************************************************************//

void ABFramework::ScenePlayerTwo::NextPlayer()
{
	bool state = (bool)ScenePlayerTwo::s_PlayerTurn;
	state = !state;
	ScenePlayerTwo::s_PlayerTurn = (TurnPlayer)state;

}

//********************************************************************************//
//                                Getters                                         //
//********************************************************************************//

ABFramework::ScenePlayerTwo::TurnPlayer ABFramework::ScenePlayerTwo::GetCurrentTurn()
{
	return ScenePlayerTwo::s_PlayerTurn;
}

ABFramework::ScenePlayerTwo::GameState ABFramework::ScenePlayerTwo::GetGameState()
{
	return ScenePlayerTwo::s_GameState;
}

//********************************************************************************//
//                             Private Helpers                                    //
//********************************************************************************//

bool ABFramework::ScenePlayerTwo::privTestRowWin()
{
	bool bOver = false;
	CHECK_NULL(pBoard);

	for (int i = 0; i < pBoard->GetBoardSize(); i += 3)
	{
		Tile::State tileState = pBoard->GetTile((int)GameBoard::Position::TOP_LEFT + i)->GetState();
		if (tileState != Tile::State::EMPTY && tileState == pBoard->GetTile((int)GameBoard::Position::TOP_CENTER + i)->GetState() && tileState == pBoard->GetTile(((int)GameBoard::Position::TOP_RIGHT + i))->GetState())
		{
			privSetState((int)tileState);
			bOver = true;
			break;

		}
	}

	return bOver;
}

bool ABFramework::ScenePlayerTwo::privTestColWin()
{
	bool bOver = false;
	CHECK_NULL(pBoard);

	for (int i = 0; i < 3; i++)
	{
		Tile::State tileState = pBoard->GetTile((int)GameBoard::Position::TOP_LEFT + i)->GetState();
		if (tileState != Tile::State::EMPTY && tileState == pBoard->GetTile((int)GameBoard::Position::MID_LEFT + i)->GetState() && tileState == pBoard->GetTile((int)GameBoard::Position::BOTTOM_LEFT + i)->GetState())
		{
			privSetState((int)tileState);
			bOver = true;
			break;

		}
	}

	return bOver;
}

bool ABFramework::ScenePlayerTwo::privTestDiagonalWin()
{
	bool bOver = false;
	CHECK_NULL(pBoard);

	Tile::State centerState = pBoard->GetTile(GameBoard::Position::MID_CENTER)->GetState();
	Tile::State topLeftCorner = pBoard->GetTile(GameBoard::Position::TOP_LEFT)->GetState();
	Tile::State topRightCorner = pBoard->GetTile(GameBoard::Position::TOP_RIGHT)->GetState();
	Tile::State bottomLeftCorner = pBoard->GetTile(GameBoard::Position::BOTTOM_LEFT)->GetState();
	Tile::State bottomRightCorner = pBoard->GetTile(GameBoard::Position::BOTTOM_RIGHT)->GetState();

	if (centerState != Tile::State::EMPTY && centerState == topLeftCorner && centerState == bottomRightCorner)
	{
		privSetState((int)centerState);
	}
	else if (centerState != Tile::State::EMPTY && centerState == topRightCorner && centerState == bottomLeftCorner)
	{
		privSetState((int)centerState);
	}

	return bOver;
}

bool ABFramework::ScenePlayerTwo::privTestDraw()
{
	bool bOver = false;
	CHECK_NULL(pBoard);

	if (ScenePlayerTwo::s_GameState == GameState::NONE)
	{
		bOver = true;
		for (int i = 0; i < pBoard->GetBoardSize(); i++)
		{
			if (pBoard->GetTile(i)->GetState() == Tile::State::EMPTY)
			{
				bOver = false;
				break;
			}

		}

		if (bOver)
			ScenePlayerTwo::s_GameState = GameState::DRAW;

	}

	return bOver;
}

void ABFramework::ScenePlayerTwo::privSetState(int _state)
{
	Tile::State state = (Tile::State)_state;
	switch (state)
	{
	case Tile::State::X:
		ScenePlayerTwo::s_GameState = ScenePlayerTwo::GameState::WIN_PLAYER_ONE;
		break;
	case Tile::State::O:
		ScenePlayerTwo::s_GameState = ScenePlayerTwo::GameState::WIN_PLAYER_TWO;
		break;
	case Tile::State::EMPTY:
	default:
		break;
	}

}


