
#include "GameBoard.h"
#include "../Engine/Core/GameObject/Sprite/Sprite.h"
#include "../Engine/Renderer/OpenGL/SimpleMeshes/SquareMesh/SquareMesh.h"
#include "../Engine/Core/AssetManager/AssetManager.h"
#include "../Engine/Core/Camera/Camera.h"
#include "Tile/Tile.h"
#include "../Engine/Core/Input/Input.h"
#include "../Engine/Core/Collision/Collision.h"

//********************************************************************************//
//                        Constructors / Destructor                               //
//********************************************************************************//

ABFramework::GameBoard::GameBoard()
	:pTiles(nullptr)
{
	pTiles = new Tile[BOARD_SIZE]();
	float xpos = -120.0f;
	float xInc = 120.0f;
	float ypos0 = 120.0f;
	float ypos1 = 0.0f;
	float ypos2 = -120.0f;
	float scale = 100.0f;

	for (int i = 0; i < BOARD_SIZE; i += 3)
	{
		pTiles[i].SetPosition(Point3D(xpos, ypos0, 0.0f));
		pTiles[i].SetScale(scale);
		pTiles[i + 1].SetPosition(Point3D(xpos, ypos1, 0.0f));
		pTiles[i + 1].SetScale(scale);
		pTiles[i + 2].SetPosition(Point3D(xpos, ypos2, 0.0f));
		pTiles[i + 2].SetScale(scale);
		xpos += xInc;
	}
	
}

ABFramework::GameBoard::~GameBoard()
{
	delete[] pTiles;
	pTiles = nullptr;
}

//********************************************************************************//
//                               Operators                                        //
//********************************************************************************//




//********************************************************************************//
//                                Utility                                         //
//********************************************************************************//

void ABFramework::GameBoard::Update()
{
	for (int i = 0; i < 9; i++)
	{
		pTiles[i].Update();
	}
}

void ABFramework::GameBoard::Draw(const Matrix& _viewProj)
{
	for (int i = 0; i < 9; i++)
	{
		pTiles[i].Draw(Camera::GetViewProjectionMatrix());
	}
}


ABFramework::Tile* ABFramework::GameBoard::GetTile(int _index)
{
	CHECK_NULL(pTiles);
	return &pTiles[_index];
}

ABFramework::Tile* ABFramework::GameBoard::GetTile(GameBoard::Position _index)
{
	CHECK_NULL(pTiles);
	return &pTiles[(int)_index];
}

//********************************************************************************//
//                                Setters                                         //
//********************************************************************************//



//********************************************************************************//
//                                Getters                                         //
//********************************************************************************//

ABFramework::Tile* ABFramework::GameBoard::GetTile(int _row, int _col)
{
	Tile* pTile = nullptr;

	CHECK_LESS(_col, 3);
	CHECK_LESS(_row, 3);

	int index = (_row * 3) + _col;
	pTile = &pTiles[index];

	return pTile;
}



//********************************************************************************//
//                             Private Helpers                                    //
//********************************************************************************//



