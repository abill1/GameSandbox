
#include "Sprite.h"

#include "../Engine/Renderer/OpenGL/SimpleMeshes/SquareMesh/SquareMesh.h"
#include "../Engine/Renderer/OpenGL/Texture/Texture.h"
#include "../Engine/Renderer/OpenGL/GraphicsObject/GraphicsObject.h"
#include "../Engine/Core/Collision/Collider/AABB.h"
#include "../Engine/Core/AssetManager/AssetManager.h"
#include "../Engine/Core/Input/Input.h"
#include "../Engine/Core/Collision/Collision.h"


//********************************************************************************//
//                        Constructors / Destructor                                //
//********************************************************************************//

ABFramework::Sprite::Sprite()
	:GameObject(), m_transform(1.0f), m_position(0.0f), m_scale(1.0f), 
	pGraphicObj(new GraphicsObject()), pMesh(nullptr), pTexture(nullptr), 
	pCollider(new AABB(m_position, m_scale)), pTextureHandles(new t_handle[16]()),
	m_currentOpenIndex(0)
{

}

ABFramework::Sprite::Sprite(Square_Mesh* const _pMesh)
	: GameObject(), m_transform(1.0f), m_position(0.0f), m_scale(1.0f),
	pGraphicObj(new GraphicsObject()), pMesh(nullptr), pTexture(nullptr),
	pCollider(new AABB(m_position, m_scale)), pTextureHandles(new t_handle[16]()),
	m_currentOpenIndex(0)
{
	pGraphicObj->Set(_pMesh);

}

ABFramework::Sprite::~Sprite()
{
	pTexture = nullptr;
	pMesh = nullptr;
	delete pCollider;
	delete pGraphicObj;
	delete pTextureHandles;
	m_currentOpenIndex = 0;

}


//********************************************************************************//
//                               Operators                                        //
//********************************************************************************//




//********************************************************************************//
//                                Utility                                         //
//********************************************************************************//

void ABFramework::Sprite::Update()
{
	Matrix pos = glm::translate(Matrix(1.0f), m_position);
	Matrix scale = glm::scale(Matrix(1.0f), m_scale);
	m_transform = pos * scale;


}

void ABFramework::Sprite::Draw(const Matrix& _viewProj)
{
	pGraphicObj->SetActiveTexture(pTexture);
	pGraphicObj->Draw(_viewProj, m_transform);
}

//********************************************************************************//
//                                Setters                                         //
//********************************************************************************//

void ABFramework::Sprite::SetPosition(const Point3D& _position)
{
	m_position = _position;
	pCollider->Set(m_position, m_scale);
}

void ABFramework::Sprite::SetScale(const Scale& _scale)
{
	m_scale = _scale;
	pCollider->Set(m_position, m_scale);
}

void ABFramework::Sprite::SetScale(float _scale)
{
	m_scale = Scale(_scale);
	pCollider->Set(m_position, m_scale);
}

void ABFramework::Sprite::SetTexture(ABFramework::Texture* const _pTexture)
{
	pTexture = _pTexture;
}

void ABFramework::Sprite::SetTexture(size_t _handle)
{
	pTexture = AssetManager::FindTexture(_handle);
}

void ABFramework::Sprite::SetMesh(ABFramework::Mesh* _pMesh)
{
	pGraphicObj->Set(_pMesh);
}

void ABFramework::Sprite::AddTextureHandle(t_handle _textureHandle)
{
	if (m_currentOpenIndex != 16)
	{
		pTextureHandles[m_currentOpenIndex] = _textureHandle;
		++m_currentOpenIndex;
	}
}

//********************************************************************************//
//                                Getters                                         //
//********************************************************************************//

ABFramework::AABB* ABFramework::Sprite::GetCollider() const
{
	return pCollider;
}

//********************************************************************************//
//                             Private Helpers                                    //
//********************************************************************************//

