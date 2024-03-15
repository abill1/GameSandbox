
#ifndef GAMESANDBOX_TIC_TAC_TOE_MAIN_MENU_CONTROLLER_H
#define GAMESANDBOX_TIC_TAC_TOE_MAIN_MENU_CONTROLLER_H

#include "../Engine/Core/Controller/PlayerController.h"

namespace ABFramework
{
	class MainMenuController : public PlayerController
	{
	public:
		// ----- Constructor / Destructor ----- //

		MainMenuController() = delete;
		MainMenuController(class SceneMainMenu* _pScene);
		virtual ~MainMenuController();

		// ----- Operators ----- //

		// ------ Utility ----- //

		void OnClickLeft() override;

		// ----- Setters ----- //

		// ----- Getters ----- //

	private:
		class SceneMainMenu* pMainMenuScene;

	};
}


#endif // !GAMESANDBOX_TIC_TAC_TOE_MAIN_MENU_CONTROLLER_H


