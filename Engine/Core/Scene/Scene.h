
/*
* What should a scene control?
* GameObjects
* Assets
* InputControllers
* 
*/

#ifndef ABFRAMEWORK_SCENE_H
#define ABFRAMEWORK_SCENE_H

namespace ABFramework
{
	class Scene
	{
	public:

		// ----- Constructor / Destructor ----- //

		Scene();
		virtual ~Scene();

		// ----- Operators ----- //

		// ------ Utility ----- //

		virtual void SetupScene();
		virtual void CleanUpScene();
		virtual void Update();
		virtual void Draw();

		// ----- Setters ----- //

		void SetNextScene(Scene* const _pNextScene);

		// ----- Getters ----- //

		inline Scene* NextScene() { return pNextScene; }

	private:
		Scene* pNextScene;

	};
}

#endif // !ABFRAMEWORK_SCENE_H

