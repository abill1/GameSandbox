
#ifndef ABFRAMEWORK_RECT_H
#define ABFRAMEWORK_RECT_H

#include "../Engine/Core/Math/Math.h"

namespace ABFramework
{
	class Rect
	{
	public:
		// ----- Constructor / Destructor ----- //
		
		Rect();
		Rect(const Point3D& _centerPoint, const Scale& _scale);
		Rect(const Point2D& _centerPoint, const Scale& _scale);
		~Rect();

		// ----- Operators ----- //

		// ------ Utility ----- //

		// ----- Setters ----- //

		void Set(const Point3D& _centerPoint, const Scale& _scale);
		void Set(const Point2D& _centerPoint, const Scale& _scale);

		// ----- Getters ----- //

		const Point2D* GetMin() const { return&m_minPoint; }
		const Point2D* GetMax() const { return&m_maxPoint; }

	private:
		Point2D m_minPoint;
		Point2D m_maxPoint;

	};
}

#endif // !ABFRAMEWORK_RECT_H



