
#ifndef ABFRAMEWORK_MOUSE_H
#define ABFRAMEWORK_MOUSE_H

namespace ABFramework
{
	enum class MouseCode : int
	{
		BUTTON_1 = 0,
		BUTTON_2 = 1,
		BUTTON_3 = 2,
		BUTTON_4 = 3,
		BUTTON_5 = 4,
		BUTTON_6 = 5,
		BUTTON_7 = 6,
		BUTTON_8 = 7,
		BUTTON_LEFT = BUTTON_1,
		BUTTON_RIGHT = BUTTON_2,
		BUTTON_MIDDLE = BUTTON_3
	};

	struct CursorCoord
	{
		float x;
		float y;
	};

	class Mouse
	{
	public:
		static int ToInt(MouseCode _button) { return (int)_button; }

	};
}

#endif // !ABFRAMEWORK_MOUSE_H

