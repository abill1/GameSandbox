#include "Camera.h"

ABFramework::Camera* ABFramework::Camera::pInstance = nullptr;

//********************************************************************************//
//                        Constructors / Destructor                                //
//********************************************************************************//

ABFramework::Camera::Camera()
	:m_View(), m_Projection(), m_ViewProj()
{

}

ABFramework::Camera::Camera(const Point2D& _ScrnResolution, const Point3D& _CenterPoint)
	:m_View(), m_Projection(), m_ViewProj()
{
	m_Projection = glm::ortho(0.0f, _ScrnResolution.x, 0.0f, _ScrnResolution.y, -1.0f, 1.0f);
	m_View = glm::translate(glm::identity<Matrix>(), _CenterPoint);
	m_ViewProj = m_Projection * m_View;
}

ABFramework::Camera::~Camera()
{

}

void ABFramework::Camera::Init(const Point2D& _ScrnResolution, const Point3D& _CenterPoint)
{
	if (Camera::pInstance == nullptr)
	{
		privGetInstance()->privSet(_ScrnResolution, _CenterPoint);
	}
}

void ABFramework::Camera::Destroy()
{
	delete Camera::pInstance;
	Camera::pInstance = nullptr;
}

//********************************************************************************//
//                               Operators                                        //
//********************************************************************************//




//********************************************************************************//
//                                Utility                                         //
//********************************************************************************//




//********************************************************************************//
//                                Setters                                         //
//********************************************************************************//





//********************************************************************************//
//                                Getters                                         //
//********************************************************************************//

Matrix& ABFramework::Camera::GetViewProjectionMatrix()
{
	Camera* pInst = privGetInstance();
	pInst->m_ViewProj = pInst->m_Projection * pInst->m_View;
	return pInst->m_ViewProj;
}



//********************************************************************************//
//                             Private Helpers                                    //
//********************************************************************************//

void ABFramework::Camera::privSet(const Point2D& _ScrnResolution, const Point3D& _CenterPoint)
{
	m_Projection = glm::ortho(0.0f, _ScrnResolution.x, 0.0f, _ScrnResolution.y, -1.0f, 1.0f);
	m_View = glm::translate(glm::identity<Matrix>(), _CenterPoint);
	m_ViewProj = m_Projection * m_View;
}

ABFramework::Camera* ABFramework::Camera::privGetInstance()
{
	if (Camera::pInstance == nullptr)
		Camera::pInstance = new Camera();
	return Camera::pInstance;
}

