
#ifndef ABFRAMEWORK_INPUTMAPPING_H
#define ABFRAMEWORK_INPUTMAPPING_H

#include "../Engine/Core/GameObject/GameObject.h"

typedef std::function<void(ABFramework::GameObject*)> t_inputAction;

namespace ABFramework
{
	class InputMapping
	{
	public:

		InputMapping() = default;
		InputMapping(t_inputAction _func, GameObject* _obj) : function(_func), pObj(_obj) {}
		~InputMapping() { pObj = nullptr; }

		void operator()()
		{
			function(pObj);
		}

		void Call()
		{
			function(pObj);
		}

	private:
		t_inputAction function;
		GameObject* pObj;
	};

}

#endif // !ABFRAMEWORK_INPUTMAPPING_H

