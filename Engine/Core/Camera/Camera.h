
#ifndef ABFRAMEWORK_CAMERA_H
#define ABFRAMEWORK_CAMERA_H

#include "../Engine/Core/Math/Math.h"

namespace ABFramework
{
	class Camera
	{
	private:
		// ----- Constructor / Destructor ----- //

		Camera();
		Camera(const Point2D& _ScrnResolution, const Point3D& _CenterPoint);

	public:
		~Camera();

		static void Init(const Point2D& _ScrnResolution, const Point3D& _CenterPoint);
		static void Destroy();

		// ----- Operators ----- //

		// ------ Utility ----- //

		// ----- Setters ----- //
		
		// ----- Getters ----- //

		static Matrix& GetViewProjectionMatrix();

	private:
		void privSet(const Point2D& _ScrnResolution, const Point3D& _CenterPoint);
		static Camera* privGetInstance();

	private:
		static Camera* pInstance;

		Matrix m_Projection;
		Matrix m_View;
		Matrix m_ViewProj;
	};
}

#endif // !ABFRAMEWORK_CAMERA_H

