
#ifndef ABFRAMEWORK_RENDERER_H
#define ABFRAMEWORK_RENDERER_H

#include "../Engine/Core/Math/Math.h"

namespace ABFramework
{
	class Renderer
	{
	private:
		// ----- Constructor / Destructor ----- //
		
		Renderer();

	public:
		~Renderer();	

		static class Window* Init(const char* _pName, int _width, int _height);
		static void Destroy();

		// ----- Operators ----- //

		
		// ------ Utility ----- //
		
		static void ClearScreen();

		// ----- Setters ----- //

		static void SetClearScreenColor(float _r, float _g, float _b, float _a = 1.0f);

		// ----- Getters ----- //
		static const char* GetOpenGLVersionStr();

	private:

	};
}

#endif // !ABFRAMEWORK_RENDERER_H

