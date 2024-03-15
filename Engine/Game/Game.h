
#ifndef GAME_H
#define GAME_H

#include "Codes/ABCode.h"

namespace ABFramework
{
	class Window;
	class String;
	class Renderer;

	class Game
	{
	public:

		// ----- Constructor / Destructor ----- //
		
		Game() = delete;
		Game(const char* _pName, int _width, int _height);
		virtual ~Game();

		// ----- Operators ----- //

		// ------ Utility ----- //
		virtual void InitializeSystems();
		virtual void LoadContent() = 0;
		virtual void UnloadContent() = 0;
		virtual void CloseSystems();
		virtual void Update();
		virtual void Draw();
		Code Run();

		// ----- Setters ----- //

		// ----- Getters ----- //

	protected:
		void GameLoop();
		void privPrintOpenGLVersion() const;
		virtual void SubUpdateRoutine() {}

	protected:
		Window* pWindow;
		String* pOpenGLVersion;
		bool bRunning;

	};
}

#endif // !GAME_H

