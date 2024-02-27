
#ifndef ABFRAMEWORK_WINDOW_H
#define ABFRAMEWORK_WINDOW_H

struct GLFWwindow;

namespace ABFramework
{
	class String;

	class Window
	{
	public:
		struct Resolution
		{
			int width;
			int height;
		};

	public:
		// ----- Constructor / Destructor ----- //

		Window() = default;
		Window(const char* _pName, int _width, int _height);
		~Window();

		// ----- Operators ----- //

		// ------ Utility ----- //

		void MakeContextCurrent();
		void PollEvents();
		bool ShouldClose();
		void SwapBuffers();

		// TODO: Add Resize method

		// ----- Setters ----- //

		// ----- Getters ----- //
		
		String* GetName() const { return pName; }
		const Resolution& GetResolution() const { return mResolution; }
		inline GLFWwindow* GetWindow() const { return pWindow; }

	private:
		GLFWwindow* pWindow;
		String* pName;
		Resolution mResolution;

	};
}


#endif // !ABFRAMEWORK_WINDOW_H


