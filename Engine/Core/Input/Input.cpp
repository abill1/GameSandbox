#include "Input.h"

#include "../Engine/Core/Window/Window.h"
#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"
#include "../Engine/Core/Collision/Collider/AABB.h"

ABFramework::Input* ABFramework::Input::pInstance = nullptr;

//********************************************************************************//
//                        Constructors / Destructor                                //
//********************************************************************************//

ABFramework::Input::Input()
	:pFocus(nullptr), m_MouseInputMappings(), m_KeyInputMappings(), m_MouseState(), m_KeyState(), pMouseCollider(new AABB())
{

}

ABFramework::Input::~Input()
{
	pFocus = nullptr;
	delete pMouseCollider;

}


bool ABFramework::Input::Init()
{
	return privGetInstance() != nullptr;
}

void ABFramework::Input::Destroy()
{
	delete pInstance;
	pInstance = nullptr;
}



//********************************************************************************//
//                               Operators                                        //
//********************************************************************************//




//********************************************************************************//
//                                Utility                                         //
//********************************************************************************//

void ABFramework::Input::Process()
{
	// ----- Need to loop through all input options
	std::unordered_map<int, int>::iterator kit = privGetInstance()->m_KeyState.begin();
	std::unordered_map<int, int>::iterator kEnd = privGetInstance()->m_KeyState.end();
	while (kit != kEnd)
	{
		if (privGetInstance()->IsPressed((KeyCode)kit->first))
			privGetInstance()->CallAction((KeyCode)kit->first);
		++kit;
	}

	std::unordered_map<int, int>::iterator mit = privGetInstance()->m_MouseState.begin();
	std::unordered_map<int, int>::iterator mEnd = privGetInstance()->m_MouseState.end();
	while (mit != mEnd)
	{
		if (privGetInstance()->IsPressed((MouseCode)mit->first))
			privGetInstance()->CallAction((MouseCode)mit->first);
		++mit;
	}

}

bool ABFramework::Input::IsPressed(ABFramework::KeyCode _key)
{
	bool bPressed = false;
	int state = glfwGetKey(privGetInstance()->pFocus->GetWindow(), Keyboard::ToInt(_key));
	if (privGetInstance()->m_KeyState[(int)_key] != GLFW_PRESS && state == GLFW_PRESS)
		bPressed = true;

	privGetInstance()->m_KeyState[(int)_key] = state;

	return bPressed;
}

bool ABFramework::Input::IsPressed(ABFramework::MouseCode _button)
{
	bool bPressed = false;
	int state = glfwGetMouseButton(privGetInstance()->pFocus->GetWindow(), Mouse::ToInt(_button));
	if (privGetInstance()->m_MouseState[(int)_button] != GLFW_PRESS && state == GLFW_PRESS)
		bPressed = true;

	privGetInstance()->m_MouseState[(int)_button] = state;

	return bPressed;
}

ABFramework::CursorCoord ABFramework::Input::GetCursorPosition()
{
	double x;
	double y;
	glfwGetCursorPos(privGetInstance()->pFocus->GetWindow(), &x, &y);
	Window::Resolution resolution = privGetInstance()->pFocus->GetResolution();
	return { ((float)x - (resolution.width / 2.0f)), ((float)y - (resolution.height / 2.0f)) };
}

ABFramework::CursorCoord ABFramework::Input::GetTrueCursorPosition()
{
	double x;
	double y;
	glfwGetCursorPos(privGetInstance()->pFocus->GetWindow(), &x, &y);
	return { (float)x, (float)y };
}

void ABFramework::Input::BindAction(MouseCode _code, t_inputAction _func, GameObject* _pObj)
{
	InputMapping tmp(_func, _pObj);
	privGetInstance()->m_MouseInputMappings[(int)_code] = tmp;
	privGetInstance()->m_MouseState[(int)_code] = GLFW_RELEASE;
}

void ABFramework::Input::BindAction(KeyCode _code, t_inputAction _func, GameObject* _pObj)
{
	InputMapping tmp(_func, _pObj);
	privGetInstance()->m_KeyInputMappings[(int)_code] = tmp;
	privGetInstance()->m_KeyState[(int)_code] = GLFW_RELEASE;
}

void ABFramework::Input::CallAction(MouseCode _code)
{
	privGetInstance()->m_MouseInputMappings[(int)_code]();
}

void ABFramework::Input::CallAction(KeyCode _code)
{
	privGetInstance()->m_KeyInputMappings[(int)_code]();
}


//********************************************************************************//
//                                Setters                                         //
//********************************************************************************//

void ABFramework::Input::SetFocus(ABFramework::Window* const _pFocus)
{

	privGetInstance()->pFocus = _pFocus;
}

//********************************************************************************//
//                                Getters                                         //
//********************************************************************************//

ABFramework::AABB* ABFramework::Input::GetMouseCollider()
{
	CursorCoord coord = privGetInstance()->GetCursorPosition();
	privGetInstance()->pMouseCollider->Set(Point2D(coord.x, coord.y), Scale(0.0f));
	return privGetInstance()->pMouseCollider;
}

//********************************************************************************//
//                             Private Helpers                                    //
//********************************************************************************//

ABFramework::Input* ABFramework::Input::privGetInstance()
{
	if (Input::pInstance == nullptr)
		Input::pInstance = new Input();
	CHECK_NULL(Input::pInstance);
	return Input::pInstance;
}


