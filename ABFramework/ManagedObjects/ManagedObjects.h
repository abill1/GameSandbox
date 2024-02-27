
#ifndef ABFRAMEWORK_MANAGED_OBJECTS_H
#define ABFRAMEWORK_MANAGED_OBJECTS_H

#include <unordered_map>

namespace ABFramework
{
	typedef size_t t_handle;

	template<class Obj>
	class ManagedObjects
	{
	public:
		// ----- Constructor / Destructor ----- //

		ManagedObjects();
		~ManagedObjects();

		// ----- Operators ----- //

		// ------ Utility ----- //

		bool Exists(t_handle _handle) const;

		// ----- Setters ----- //

		t_handle Add(const class String& _name, Obj* _pObj);

		template<class Child>
		t_handle Add(const class String& _name);

		// ----- Getters ----- //

		Obj* GetObject(t_handle _handle);
		Obj* GetObject(const class String& _name);

		std::unordered_map<size_t, Obj*>* GetMap();

	private:
		/*
		* Found a video how unordered_map has many performance drawbacks due to the constant 
		* rehashing. This class should be redesigned to use either a vector or just a normal
		* c-array. 
		* 
		* https://www.youtube.com/watch?v=fHNmRkzxHWs 
		* CppCon 2014: Chandler Carruth "Efficiency with Algorithms, Performance with Data Structures"
		* 
		*/

		std::unordered_map<size_t, Obj*> m_Objects; 

	};
	
}

#endif // !ABFRAMEWORK_MANAGED_OBJECTS_H

