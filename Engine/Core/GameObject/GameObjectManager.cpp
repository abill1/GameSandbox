
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
	:m_Sprites()
{

}


ABFramework::GameObjectManager::~GameObjectManager()
{

}

bool ABFramework::GameObjectManager::Init()
{
	return privGetInstance() != nullptr;
}

void ABFramework::GameObjectManager::Destroy()
{
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
}

//********************************************************************************//
//                                Setters                                         //
//********************************************************************************//


ABFramework::t_handle ABFramework::GameObjectManager::AddSprite(const class String& _name)//, Mesh* _mesh, const Point3D& _position, float _scale, ABFramework::t_handle _textureHandle)
{
	t_handle handle = privGetInstance()->m_Sprites.Add<Sprite>(_name);
	//if (handle != 0)
	//{
	//	GameObject* pObj = privGetInstance()->m_GameObjects[handle];
	//	pObj->SetMesh(_mesh);
	//	pObj->SetTexture(AssetManager::FindTexture(_textureHandle));
	//	pObj->SetPosition(_position);
	//	pObj->SetScale(_scale);
	//}
	return handle;
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



