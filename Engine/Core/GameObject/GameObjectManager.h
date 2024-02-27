
#ifndef ABFRAMEWORK_GAMEOBJECT_MANAGER_H
#define ABFRAMEWORK_GAMEOBJECT_MANAGER_H

#include "../ABFramework/ManagedObjects/ManagedObjects.h"
#include "Sprite/Sprite.h"

namespace ABFramework
{
	//class GameObject;
	typedef ManagedObjects<Sprite> t_ManagedSprites;

	class GameObjectManager
	{
	private:
		// ----- Constructor / Destructor ----- //
		GameObjectManager();

	public:
		~GameObjectManager();

		static bool Init();
		static void Destroy();

		// ----- Operators ----- //

		// ------ Utility ----- //

		static void Draw();
		static void Update();

		// ----- Setters ----- //

		static t_handle AddSprite(const class String& _name);//, class Mesh* _mesh, const Point3D& _position, float _scale, t_handle _textureHandle);

		// ----- Getters ----- //

		static class Sprite* GetSprite(t_handle _handle);
		static class Sprite* GetSprite(const class String& _name);

		static class AABB* GetCollider(t_handle _handle);

	private:
		static GameObjectManager* privGetInstance();

	private:
		static GameObjectManager* pInstance;

		t_ManagedSprites m_Sprites;

	};
}

#endif // !ABFRAMEWORK_GAMEOBJECT_MANAGER_H


