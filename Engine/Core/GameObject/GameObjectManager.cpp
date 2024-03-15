
#include "GameObjectManager.h"
#include "../Engine/Core/Camera/Camera.h"
#include "../Engine/Renderer/OpenGL/Mesh/Mesh.h"
#include "../Engine/Core/AssetManager/AssetManager.h"
#include "../Engine/Core/Collision/Collider/AABB.h"

ABFramework::GameObjectManager* ABFramework::GameObjectManager::pInstance = nullptr;

//********************************************************************************//
//                        Constructors / Destructor                               //
//********************************************************************************//

ABFramework::GameObjectManager::GameObjectManager()
	:m_Sprites(), p_Objects(new ObjContainer[8]()), currentOpenIndex(-1)
{

}

ABFramework::GameObjectManager::~GameObjectManager()
{
	delete[] p_Objects;
}

bool ABFramework::GameObjectManager::Init()
{
	return privGetInstance() != nullptr;
}

void ABFramework::GameObjectManager::Destroy()
{

	for (int i = privGetInstance()->currentOpenIndex; i > -1; --i)
	{
		delete privGetInstance()->p_Objects[i].pObj;
		privGetInstance()->p_Objects[i].pObj = nullptr;
	}
	//delete[] privGetInstance()->p_Objects;

	delete GameObjectManager::pInstance;
	GameObjectManager::pInstance = nullptr;

	

}

//********************************************************************************//
//                               Operators                                        //
//********************************************************************************//




//********************************************************************************//
//                                Utility                                         //
//********************************************************************************//

void ABFramework::GameObjectManager::Draw()
{
	std::unordered_map<size_t, Sprite*>::iterator iterator = privGetInstance()->m_Sprites.GetMap()->begin();
	std::unordered_map<size_t, Sprite*>::iterator End = privGetInstance()->m_Sprites.GetMap()->end();
	while (iterator != End)
	{
		iterator->second->Draw(Camera::GetViewProjectionMatrix());
		++iterator;
	}

	for (int i = 0; i < 8; i++)
	{
		if (privGetInstance()->p_Objects[i].pObj == nullptr)
			break;
		privGetInstance()->p_Objects[i].pObj->Draw(Camera::GetViewProjectionMatrix());
	}

}


void ABFramework::GameObjectManager::Update()
{
	std::unordered_map<size_t, Sprite*>::iterator iterator = privGetInstance()->m_Sprites.GetMap()->begin();
	std::unordered_map<size_t, Sprite*>::iterator End = privGetInstance()->m_Sprites.GetMap()->end();
	while (iterator != End)
	{
		iterator->second->Update();
		++iterator;
	}

	for (int i = 0; i < 8; i++)
	{
		if (privGetInstance()->p_Objects[i].pObj == nullptr)
			break;
		privGetInstance()->p_Objects[i].pObj->Update();
	}
}

//********************************************************************************//
//                                Setters                                         //
//********************************************************************************//


ABFramework::t_handle ABFramework::GameObjectManager::AddSprite(const class String& _name)//, Mesh* _mesh, const Point3D& _position, float _scale, ABFramework::t_handle _textureHandle)
{
	t_handle handle = privGetInstance()->m_Sprites.Add<Sprite>(_name);
	return handle;
}



ABFramework::t_handle ABFramework::GameObjectManager::AddGameObject(ABFramework::GameObject* const _pObj)
{
	++privGetInstance()->currentOpenIndex;
	privGetInstance()->p_Objects[privGetInstance()->currentOpenIndex].pObj = _pObj;
	return privGetInstance()->currentOpenIndex;
}

//********************************************************************************//
//                                Getters                                         //
//********************************************************************************//

ABFramework::Sprite* ABFramework::GameObjectManager::GetSprite(t_handle _handle)
{
	Sprite* ptr = nullptr;

	if (privGetInstance()->m_Sprites.Exists(_handle))
		ptr = privGetInstance()->m_Sprites.GetObject(_handle);

	return ptr;
}



ABFramework::GameObject* ABFramework::GameObjectManager::GetObject(t_handle _handle)
{
	GameObject* pObj = nullptr;
	pObj = privGetInstance()->p_Objects[_handle].pObj;
	return pObj;
}

ABFramework::Sprite* ABFramework::GameObjectManager::GetSprite(const class String& _name)
{
	Sprite* ptr = nullptr;
	t_handle handle = _name.GetHash();

	if (privGetInstance()->m_Sprites.Exists(handle))
		ptr = privGetInstance()->m_Sprites.GetObject(handle);

	return ptr;
}

ABFramework::AABB* ABFramework::GameObjectManager::GetCollider(ABFramework::t_handle _handle)
{
	AABB* ptr = nullptr;

	if (privGetInstance()->m_Sprites.Exists(_handle))
		ptr = privGetInstance()->m_Sprites.GetObject(_handle)->GetCollider();

	return ptr;
}

//********************************************************************************//
//                             Private Helpers                                    //
//********************************************************************************//

ABFramework::GameObjectManager* ABFramework::GameObjectManager::privGetInstance()
{
	if (GameObjectManager::pInstance == nullptr)
		GameObjectManager::pInstance = new GameObjectManager();
	return GameObjectManager::pInstance;
}



