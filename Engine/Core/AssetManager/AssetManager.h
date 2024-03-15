
#ifndef ABFRAMEWORK_ASSETMANAGER_H
#define ABFRAMEWORK_ASSETMANAGER_H

#include "../ABFramework/ManagedObjects/ManagedObjects.h"

namespace ABFramework
{
	class Texture;
	class Square_Mesh;

	typedef ManagedObjects<Texture> t_ManagedTextures;

	class AssetManager
	{
	private:
		// ----- Constructor / Destructor ----- //

		AssetManager();

	public:

		~AssetManager();

		static bool Init();
		static void Destroy();

		// ----- Operators ----- //

		// ------ Utility ----- //

		// ----- Setters ----- //

		static t_handle AddTexture(const class String& _textureFilePath, const char* const _name = " ");
		static t_handle AddTexture(const struct AssetDef& _assetDef);

		// ----- Getters ----- //

		static Texture* FindTexture(t_handle _handle);
		static Square_Mesh* GetSquareMesh();

	private:
		static AssetManager* privGetInstance();

	private:
		static AssetManager* pInstance;

		t_ManagedTextures m_Textures;
		Square_Mesh* pSquareMesh;

	};
}

#endif // !ABFRAMEWORK_ASSETMANAGER_H


