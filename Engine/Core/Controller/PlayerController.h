
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

		// ***** Mouse

		virtual void OnClickLeft() {}
		virtual void OnClickRight() {}

		// ***** Keyboard

		virtual void KeySpace() {}
		virtual void KeyApostrophe() {}
		virtual void KeyComma() {}
		virtual void KeyMinus() {}
		virtual void KeyPeriod() {}
		virtual void KeySlash() {}
		virtual void Key0() {}
		virtual void Key1() {}
		virtual void Key2() {}
		virtual void Key3() {}
		virtual void Key4() {}
		virtual void Key5() {}
		virtual void Key6() {}
		virtual void Key7() {}
		virtual void Key8() {}
		virtual void Key9() {}
		virtual void KeySemicolon() {}
		virtual void KeyEqual() {}
		virtual void KeyA() {}
		virtual void KeyB() {}
		virtual void KeyC() {}
		virtual void KeyD() {}
		virtual void KeyE() {}
		virtual void KeyF() {}
		virtual void KeyG() {}
		virtual void KeyH() {}
		virtual void KeyI() {}
		virtual void KeyJ() {}
		virtual void KeyK() {}
		virtual void KeyL() {}
		virtual void KeyM() {}
		virtual void KeyN() {}
		virtual void KeyO() {}
		virtual void KeyP() {}
		virtual void KeyQ() {}
		virtual void KeyR() {}
		virtual void KeyS() {}
		virtual void KeyT() {}
		virtual void KeyU() {}
		virtual void KeyV() {}
		virtual void KeyW() {}
		virtual void KeyX() {}
		virtual void KeyY() {}
		virtual void KeyZ() {}
		virtual void KeyBracketLeft() {}
		virtual void KeyBracketRight() {}
		virtual void KeyBackslash() {}
		virtual void KeyGraveAccent() {}
		virtual void KeyArrowUp() {}
		virtual void KeyArrowDown() {}
		virtual void KeyArrowRight() {}
		virtual void KeyArrowLeft() {}
		virtual void KeyEscape() {}
		virtual void KeyEnter() {}
		virtual void KeyTab() {}
		virtual void KeyBackspace() {}
		virtual void KeyDelete() {}
		virtual void KeyInsert() {}

		// ----- Setters ----- //

		// ----- Getters ----- //

	private:

	};
}

#endif // !ABFRAMEWORK_PLAYERCONTROLLER_H


