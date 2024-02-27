
#include "ManagedObjects.h"
#include "../ABString/ABString.h"

//********************************************************************************//
//                        Constructors / Destructor                               //
//********************************************************************************//

template<class Obj>
ABFramework::ManagedObjects<Obj>::ManagedObjects()
	:m_Objects()
{

}

template<class Obj>
ABFramework::ManagedObjects<Obj>::~ManagedObjects()
{
	typename std::unordered_map<size_t, Obj*>::iterator pIt = m_Objects.begin();
	while (pIt != m_Objects.end())
	{
		delete pIt->second;
		++pIt;
	}
}


//********************************************************************************//
//                               Operators                                        //
//********************************************************************************//




//********************************************************************************//
//                                Utility                                         //
//********************************************************************************//

template<class Obj>
bool ABFramework::ManagedObjects<Obj>::Exists(t_handle _handle) const
{
	return m_Objects.find(_handle) != m_Objects.end();
}

template<class Obj>
std::unordered_map<size_t, Obj*>* ABFramework::ManagedObjects<Obj>::GetMap()
{
	return &m_Objects;
}


//********************************************************************************//
//                                Setters                                         //
//********************************************************************************//


template<class Obj>
ABFramework::t_handle ABFramework::ManagedObjects<Obj>::Add(const ABFramework::String& _name, Obj* _pObj)
{
	t_handle handle = _name.GetHash();
	if (m_Objects.find(handle) == m_Objects.end())
		m_Objects[handle] = _pObj;
	else
		handle = 0;

	return handle;
}

template<class Obj>
template<class Child>
ABFramework::t_handle ABFramework::ManagedObjects<Obj>::Add(const class String& _name)
{
	t_handle handle = _name.GetHash();
	if (m_Objects.find(handle) == m_Objects.end())
		m_Objects[handle] = new Child();
	else
		handle = 0;

	return handle;
}

//********************************************************************************//
//                                Getters                                         //
//********************************************************************************//

template<class Obj>
Obj* ABFramework::ManagedObjects<Obj>::GetObject(t_handle _handle)
{
	Obj* ptr = nullptr;
	if (m_Objects.find(_handle) != m_Objects.end())
		ptr = m_Objects[_handle];
	return ptr;
}

template<class Obj>
Obj* ABFramework::ManagedObjects<Obj>::GetObject(const class String& _name)
{
	Obj* ptr = nullptr;
	t_handle handle = _name.GetHash();
	if (m_Objects.find(handle) != m_Objects.end())
		ptr = m_Objects[handle];
	return ptr;
}


//********************************************************************************//
//                             Private Helpers                                    //
//********************************************************************************//


