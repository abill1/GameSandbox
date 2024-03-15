
#ifndef GAMESANDBOX_TIC_TAC_TOE_PLAYERONECONTROLLER_H
#define GAMESANDBOX_TIC_TAC_TOE_PLAYERONECONTROLLER_H

#include "../Engine/Core/Controller/PlayerController.h"

namespace ABFramework
{
	class TwoPlayerController : public PlayerController
	{
	public:
		// ----- Constructor / Destructor ----- //

		TwoPlayerController() = delete;
		TwoPlayerController(class GameBoard* _pBoard);
		~TwoPlayerController();

		// ----- Operators ----- //

		// ------ Utility ----- //

		void OnClickLeft() override;

		// ----- Setters ----- //

		// ----- Getters ----- //

	private:
		void privClickLeftPlayerOne();
		void privClickLeftPlayerTwo();

	private:
		class GameBoard* pBoard;

	};
}

#endif // !GAMESANDBOX_TIC_TAC_TOE_PLAYERONECONTROLLER_H


