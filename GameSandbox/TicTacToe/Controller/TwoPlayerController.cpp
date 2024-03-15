
#include "TwoPlayerController.h"
#include "../GameBoard/GameBoard.h"
#include "../Engine/Core/Collision/Collision.h"
#include "../Engine/Core/Input/Input.h"
#include "../GameBoard/Tile/Tile.h"
#include "../Engine/Core/Collision/Collider/AABB.h"
#include "../GameSandbox/TicTacToe/TicTacToe.h"
#include "../Scenes/ScenePlayerTwo.h"

//********************************************************************************//
//                        Constructors / Destructor                               //
//********************************************************************************//

ABFramework::TwoPlayerController::TwoPlayerController(ABFramework::GameBoard* _pBoard)
	:pBoard(_pBoard)
{

}


ABFramework::TwoPlayerController::~TwoPlayerController()
{
	pBoard = nullptr;

}

//********************************************************************************//
//                               Operators                                        //
//********************************************************************************//




//********************************************************************************//
//                                Utility                                         //
//********************************************************************************//

void ABFramework::TwoPlayerController::OnClickLeft()
{
	privClickLeftPlayerOne();
	privClickLeftPlayerTwo();

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

void ABFramework::TwoPlayerController::privClickLeftPlayerOne()
{
	if (ScenePlayerTwo::GetCurrentTurn() == ScenePlayerTwo::TurnPlayer::ONE)
	{
		for (int i = 0; i < pBoard->GetBoardSize(); i++)
		{
			if (pBoard->GetTile(i)->GetState() == Tile::State::EMPTY && Collision::Check(pBoard->GetTile(i)->GetCollider(), Input::GetMouseCollider()))
			{
				CursorCoord coord = Input::GetCursorPosition();
				printf("[Mouse Coord] X: %f, Y: %f\n", coord.x, coord.y);
				pBoard->GetTile(i)->SetState(Tile::State::X);
				ScenePlayerTwo::NextPlayer();
				break;
			}
		}
	}
}

void ABFramework::TwoPlayerController::privClickLeftPlayerTwo()
{
	if (ScenePlayerTwo::GetCurrentTurn() == ScenePlayerTwo::TurnPlayer::TWO)
	{
		for (int i = 0; i < pBoard->GetBoardSize(); i++)
		{
			if (pBoard->GetTile(i)->GetState() == Tile::State::EMPTY && Collision::Check(pBoard->GetTile(i)->GetCollider(), Input::GetMouseCollider()))
			{
				CursorCoord coord = Input::GetCursorPosition();
				printf("[Mouse Coord] X: %f, Y: %f\n", coord.x, coord.y);
				pBoard->GetTile(i)->SetState(Tile::State::O);
				ScenePlayerTwo::NextPlayer();
				break;
			}
		}
	}
}


