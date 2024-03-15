#include "Tile.h"
#include "../Engine/Core/Collision/Collider/AABB.h"
#include "../Engine/Core/GameObject/Sprite/Sprite.h"
#include "../Engine/Renderer/OpenGL/SimpleMeshes/SquareMesh/SquareMesh.h"
#include "../Engine/Core/AssetManager/AssetManager.h"
#include "../Engine/Core/Camera/Camera.h"

//********************************************************************************//
//                        Constructors / Destructor                               //
//********************************************************************************//

ABFramework::Tile::Tile()
	:m_Data(), pSprite(new Sprite()), m_State(State::EMPTY)
{
	pSprite->SetMesh(AssetManager::GetSquareMesh());
	Texture* pTexture = AssetManager::FindTexture(String::Hash(EMPTY_TEXTURE));
	CHECK_NULL(pTexture);
	pSprite->SetTexture(pTexture);

}


ABFramework::Tile::~Tile()
{
	delete pSprite;
	pSprite = nullptr;
}

//********************************************************************************//
//                               Operators                                        //
//********************************************************************************//




//********************************************************************************//
//                                Utility                                         //
//********************************************************************************//

void ABFramework::Tile::Update()
{
	pSprite->Update();
}

void ABFramework::Tile::Draw(const Matrix& _viewProj)
{
	pSprite->Draw(_viewProj);
}

//********************************************************************************//
//                                Setters                                         //
//********************************************************************************//

void ABFramework::Tile::SetPosition(const Point3D& _position)
{
	CHECK_NULL(pSprite);
	pSprite->SetPosition(_position);
}

void ABFramework::Tile::SetScale(float _scale)
{
	CHECK_NULL(pSprite);
	pSprite->SetScale(_scale);
}

void ABFramework::Tile::SetState(State _state)
{
	if (m_State == State::EMPTY)
	{
		if (_state == State::X)
		{
			m_State = State::X;
			pSprite->SetTexture(String::Hash(X_TEXTURE));
		}
		else if (_state == State::O)
		{
			m_State = State::O;
			pSprite->SetTexture(String::Hash(O_TEXTURE));
		}
	}

}


//********************************************************************************//
//                                Getters                                         //
//********************************************************************************//

ABFramework::AABB* ABFramework::Tile::GetCollider() const
{
	return pSprite->GetCollider();
}

//********************************************************************************//
//                             Private Helpers                                    //
//********************************************************************************//

