
#include "AssetManager.h"
#include "../Engine/Renderer/OpenGL/Texture/Texture.h"
#include "../Engine/Renderer/OpenGL/SimpleMeshes/SquareMesh/SquareMesh.h"
#include "AssetDef/AssetDef.h"

ABFramework::AssetManager* ABFramework::AssetManager::pInstance = nullptr;

//********************************************************************************//
//                        Constructors / Destructor                                //
//********************************************************************************//

ABFramework::AssetManager::AssetManager()
	:m_Textures(), pSquareMesh(new Square_Mesh())
{

}

ABFramework::AssetManager::~AssetManager()
{
	delete pSquareMesh;
	pSquareMesh = nullptr;
}


//********************************************************************************//
//                               Operators                                        //
//********************************************************************************//




//********************************************************************************//
//                                Utility                                         //
//********************************************************************************//

bool ABFramework::AssetManager::Init()
{
	return privGetInstance() != nullptr;
}

void ABFramework::AssetManager::Destroy()
{
	delete AssetManager::pInstance;

}

//********************************************************************************//
//                                Setters                                         //
//********************************************************************************//

ABFramework::t_handle ABFramework::AssetManager::AddTexture(const class String& _textureFilePath, const char* const _name /*= " "*/)
{
	t_handle handle = 0;
	if (_name == " ")
		handle = _textureFilePath.GetHash();
	else
		handle = String(_name).GetHash();

	handle = privGetInstance()->m_Textures.Add<Texture>(_name);
	if (handle != 0)
		privGetInstance()->m_Textures.GetObject(handle)->Load(_textureFilePath, _name);

	return handle;
}

ABFramework::t_handle ABFramework::AssetManager::AddTexture(const AssetDef& _assetDef)
{
	t_handle handle = 0;
	if (_assetDef.m_name == " ")
		handle = _assetDef.m_filePath.GetHash();
	else
		handle = _assetDef.m_name.GetHash();

	handle = privGetInstance()->m_Textures.Add<Texture>(_assetDef.m_name);
	if (handle != 0)
		privGetInstance()->m_Textures.GetObject(handle)->Load(_assetDef.m_filePath, _assetDef.m_name.c_str(), _assetDef.m_FlipVertically);

	return handle;
}

//********************************************************************************//
//                                Getters                                         //
//********************************************************************************//

ABFramework::Texture* ABFramework::AssetManager::FindTexture(t_handle _handle)
{
	Texture* ptr = nullptr;

	if (privGetInstance()->m_Textures.Exists(_handle))
		ptr = privGetInstance()->m_Textures.GetObject(_handle);

	return ptr;
}

ABFramework::Square_Mesh* ABFramework::AssetManager::GetSquareMesh()
{
	return privGetInstance()->pSquareMesh;
}

//********************************************************************************//
//                             Private Helpers                                    //
//********************************************************************************//

ABFramework::AssetManager* ABFramework::AssetManager::privGetInstance()
{
	if (AssetManager::pInstance == nullptr)
		AssetManager::pInstance = new AssetManager();

	return AssetManager::pInstance;
}



