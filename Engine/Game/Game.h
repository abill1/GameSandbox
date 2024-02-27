
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
		virtual void LoadContent();
		virtual void UnloadContent();
		virtual void CloseSystems();
		virtual void Update();
		virtual void Draw();
		virtual Code Run();

		// ----- Setters ----- //

		// ----- Getters ----- //

	private:
		void privPrintOpenGLVersion() const;
		

	private:
		Window* pWindow;
		String* pOpenGLVersion;
		//Renderer* pRenderer;

	};
}

#endif // !GAME_H

