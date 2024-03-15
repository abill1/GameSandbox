
#ifndef GAMESANDBOX_TIC_TAC_TOE_SCENEPLAYERTWO_H
#define GAMESANDBOX_TIC_TAC_TOE_SCENEPLAYERTWO_H

#include "../Engine/Core/Scene/Scene.h"
#include "../Engine/Core/AssetManager/AssetDef/AssetDef.h"

namespace ABFramework
{
	class ScenePlayerTwo : public Scene 
	{
	public:
		enum class TurnPlayer : bool
		{
			ONE = true,
			TWO = false
		};

		enum class GameState : int
		{
			NONE = -2,
			WIN_PLAYER_ONE = -1,
			DRAW = 0,
			WIN_PLAYER_TWO = 1
		};

	public:

		// ----- Constructor / Destructor ----- //

		ScenePlayerTwo();
		virtual ~ScenePlayerTwo();

		// ----- Operators ----- //

		// ------ Utility ----- //

		void SetupScene() override;
		void CleanUpScene() override;
		void Update() override;
		void Draw() override;
		GameState UpdateGameState();

		// ----- Setters ----- //

		static void NextPlayer();

		// ----- Getters ----- //

		static TurnPlayer GetCurrentTurn();
		static GameState GetGameState();

	private:
		bool privTestRowWin();
		bool privTestColWin();
		bool privTestDiagonalWin();
		bool privTestDraw();
		void privSetState(int _state);

	private:
		static TurnPlayer s_PlayerTurn;
		static GameState s_GameState;
		const AssetDef defaultTexture = { "..\\Engine\\Assets\\DefaultTexture.tga","DefaultAsset" };
		const AssetDef EmptySquare = { "..\\GameSandbox\\Assets\\Textures\\Empty.tga","Empty" };
		const AssetDef XSquare = { "..\\GameSandbox\\Assets\\Textures\\xsquare.tga","XSquare" };
		const AssetDef OSquare = { "..\\GameSandbox\\Assets\\Textures\\osquare.tga","OSquare" };
		class GameBoard* pBoard;
		class TwoPlayerController* pController;
		class CurrentPlayerIcon* pCurrentPlayerIcon;

	};
}

#endif // !GAMESANDBOX_TIC_TAC_TOE_SCENEPLAYERTWO_H


