
#ifndef GAMESANDBOX_TIC_TAC_TOE_SCENE_MAIN_MENU_H
#define GAMESANDBOX_TIC_TAC_TOE_SCENE_MAIN_MENU_H

#include "../Engine/Core/Scene/Scene.h"
#include "../Engine/Core/AssetManager/AssetDef/AssetDef.h"

namespace ABFramework
{
	class SceneMainMenu : public Scene 
	{
	public:
		// ----- Constructor / Destructor ----- //

		SceneMainMenu();
		virtual ~SceneMainMenu();

		// ----- Operators ----- //

		// ------ Utility ----- //

		void SetupScene() override;
		void CleanUpScene() override;
		void Update() override;
		void Draw() override;

		// ----- Setters ----- //

		// ----- Getters ----- //

		class Sprite* GetExitBtn() const;

	private:
		const AssetDef ExitBtn = { "..\\GameSandbox\\Assets\\Textures\\ExitBtn.tga","ExitBtn", true };
		class Sprite* pExitBtn;
		class MainMenuController* pController;

	};
}

#endif // !GAMESANDBOX_TIC_TAC_TOE_SCENE_MAIN_MENU_H

