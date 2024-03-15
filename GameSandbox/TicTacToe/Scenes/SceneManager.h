
#ifndef GAMESANDBOX_TIC_TAC_TOE_SCENE_MANAGER_H
#define GAMESANDBOX_TIC_TAC_TOE_SCENE_MANAGER_H

namespace ABFramework
{
	class SceneManager
	{
		// ----- Constructor / Destructor ----- //

	private:
		SceneManager();

	public:
		~SceneManager();

		static void Init();
		static void Destroy();

		// ----- Operators ----- //

		// ------ Utility ----- //

		static void NextScene();
		static void Update();
		static void Draw();

		// ----- Setters ----- //

		// ----- Getters ----- //

	private:
		static SceneManager* privGetInstance();

	private:
		static SceneManager* pInstance;

		class SceneMainMenu* pMainMenu;
		class ScenePlayerTwo* pTwoPlayer;
		class Scene* pActiveScene;

	};
}

#endif // !GAMESANDBOX_TIC_TAC_TOE_SCENE_MANAGER_H


