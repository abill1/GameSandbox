
#ifndef ABFRAMEWORK_GAME_OBJECT_H
#define ABFRAMEWORK_GAME_OBJECT_H

#include "../Engine/Core/Math/Math.h"

namespace ABFramework
{
	class GameObject
	{
	public:
		// ----- Constructor / Destructor ----- //

		GameObject() = default;
		virtual ~GameObject() = default;

		// ----- Operators ----- //

		// ------ Utility ----- //

		virtual void Update() = 0;
		virtual void Draw(const Matrix& _viewProj) = 0;

		// ----- Setters ----- //

		virtual void SetPosition(const Point3D& _position) = 0;
		virtual void SetScale(const Scale& _scale) = 0;
		virtual void SetScale(float _scale) = 0;
		virtual void SetTexture(class Texture* const _pTexture) = 0;
		virtual void SetTexture(size_t _handle) = 0;
		virtual void SetMesh(class Mesh* _pMesh) = 0;

		// ----- Getters ----- //

		virtual class AABB* GetCollider() const = 0;

	private:
		

	};
}

#endif // !ABFRAMEWORK_GAME_OBJECT_H

