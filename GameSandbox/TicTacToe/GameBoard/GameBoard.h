
#ifndef GAMESANDBOX_TIC_TAC_TOE_GAME_BOARD_H
#define GAMESANDBOX_TIC_TAC_TOE_GAME_BOARD_H

#include "../Engine/Core/GameObject/GameObject.h"

namespace ABFramework
{
	class GameBoard : public GameObject 
	{
	public:
		enum class Position : int 
		{
			TOP_LEFT = 0,
			TOP_CENTER = 1,
			TOP_RIGHT = 2,
			MID_LEFT = 3,
			MID_CENTER = 4,
			MID_RIGHT = 5,
			BOTTOM_LEFT = 6,
			BOTTOM_CENTER = 7,
			BOTTOM_RIGHT = 8
		};

	public:
		
		// ----- Constructor / Destructor ----- //

		GameBoard();
		virtual ~GameBoard();

		// ------ Utility ----- //

		virtual void Update() override;
		virtual void Draw(const Matrix& _viewProj) override;

		// ----- Setters ----- //

		virtual void SetPosition(const Point3D& _position) override {}
		virtual void SetScale(const Scale& _scale) override {}
		virtual void SetScale(float _scale) override {}
		virtual void SetTexture(class Texture* const _pTexture) override {}
		virtual void SetTexture(size_t _handle)override {}
		virtual void SetMesh(class Mesh* _pMesh) override {}

		// ----- Getters ----- //

		virtual class AABB* GetCollider() const override { return nullptr; }
		class Tile* GetTile(int _index);
		class Tile* GetTile(int _row, int _col);
		class Tile* GetTile(GameBoard::Position _index);
		inline const int GetBoardSize() const { return BOARD_SIZE; }

	private:
		class Tile* pTiles;
		const int BOARD_SIZE = 9;
	};
}

#endif // !GAMESANDBOX_TIC_TAC_TOE_GAME_BOARD_H



