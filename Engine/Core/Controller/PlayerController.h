
#ifndef ABFRAMEWORK_PLAYERCONTROLLER_H
#define ABFRAMEWORK_PLAYERCONTROLLER_H

namespace ABFramework
{

	class PlayerController
	{
	public:
		// ----- Constructor / Destructor ----- //
		PlayerController() = default;
		~PlayerController() = default;

		// ----- Operators ----- //

		// ------ Utility ----- //

		virtual void MouseLeftButtonCLick() = 0;
		virtual void MouseRightButtonCLick() = 0;

		// ----- Setters ----- //

		// ----- Getters ----- //

	private:

	};
}

#endif // !ABFRAMEWORK_PLAYERCONTROLLER_H


