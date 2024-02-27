
#ifndef ABFRAMEWORK_AABB_H
#define ABFRAMEWORK_AABB_H

#include "../Engine/Core/Math/Math.h"

namespace ABFramework
{
	class AABB
	{
	public:
		// ----- Constructor / Destructor ----- //

		AABB();
		AABB(const Point3D& _centerPoint, const Scale& _scale);
		AABB(const Point2D& _centerPoint, const Scale& _scale);
		~AABB();

		// ----- Operators ----- //

		// ------ Utility ----- //

		bool CollidesWith(const AABB& _other);
		bool CollidesWith(AABB* const _other);

		// ----- Setters ----- //

		void Set(const Point3D& _centerPoint, const Scale& _scale);
		void Set(const Point2D& _centerPoint, const Scale& _scale);

		// ----- Getters ----- //

		const class Rect* GetRect() const { return pR; }
		float GetMaxX() const;
		float GetMaxY() const;
		float GetMinX() const;
		float GetMinY() const;

	private:
		class Rect* pR;

	};
}

#endif // !ABFRAMEWORK_AABB_H

