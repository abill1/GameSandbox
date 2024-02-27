
#ifndef ABFRAMEWORK_SPRITE_H
#define ABFRAMEWORK_SPRITE_H

#include "../GameObject.h"

namespace ABFramework
{
	class Sprite : public GameObject
	{
	public:
		// ----- Constructor / Destructor ----- //

		Sprite();
		Sprite(class Square_Mesh* const _pMesh);
		virtual ~Sprite();

		// ----- Operators ----- //

		// ------ Utility ----- //

		void Update() override;
		void Draw(const Matrix& _viewProj) override;
		void OnLeftMouse();

		// ----- Setters ----- //

		void SetPosition(const Point3D& _position) override;
		void SetScale(const Scale& _scale) override;
		void SetScale(float _scale) override;
		void SetTexture(class Texture* const _pTexture) override;
		void SetTexture(size_t _handle) override;
		void SetMesh(class Mesh* _pMesh) override;
		void AddTextureHandle(t_handle _textureHandle);

		// ----- Getters ----- //

		class AABB* GetCollider() const override;

	private:
		Matrix m_transform;
		Point3D m_position;
		Point3D m_scale;
		class GraphicsObject* pGraphicObj;
		class Square_Mesh* pMesh;
		class Texture* pTexture;
		class AABB* pCollider;
		t_handle* pTextureHandles;
		int m_currentOpenIndex;

	};
}

#endif // !ABFRAMEWORK_SPRITE_H

