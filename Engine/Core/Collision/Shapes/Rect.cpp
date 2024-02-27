#include "Rect.h"

//********************************************************************************//
//                        Constructors / Destructor                                //
//********************************************************************************//

ABFramework::Rect::Rect()
	:m_minPoint(Point2D()), m_maxPoint(Point2D())
{

}

ABFramework::Rect::Rect(const Point3D& _centerPoint, const Scale& _scale)
	: m_minPoint(), m_maxPoint()
{
	m_minPoint.x = _centerPoint.x;
	m_maxPoint.x = _centerPoint.x;
	if (_scale.x > 0.000001f)
	{
		m_minPoint.x -= (_scale.x / 2.0f);
		m_maxPoint.x += (_scale.x / 2.0f);
	}

	m_minPoint.y = _centerPoint.y;
	m_maxPoint.y = _centerPoint.y;
	if (_scale.y > 0.000001f)
	{
		m_minPoint.y -= (_scale.y / 2.0f);
		m_maxPoint.y += (_scale.y / 2.0f);
	}
	
}

ABFramework::Rect::Rect(const Point2D& _centerPoint, const Scale& _scale)
	: m_minPoint(), m_maxPoint()
{
	m_minPoint.x = _centerPoint.x;
	m_maxPoint.x = _centerPoint.x;
	if (_scale.x > 0.000001f)
	{
		m_minPoint.x -= (_scale.x / 2.0f);
		m_maxPoint.x += (_scale.x / 2.0f);
	}

	m_minPoint.y = _centerPoint.y;
	m_maxPoint.y = _centerPoint.y;
	if (_scale.y > 0.000001f)
	{
		m_minPoint.y -= (_scale.y / 2.0f);
		m_maxPoint.y += (_scale.y / 2.0f);
	}
}

ABFramework::Rect::~Rect()
{

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

void ABFramework::Rect::Set(const Point3D& _centerPoint, const Scale& _scale)
{
	m_minPoint.x = _centerPoint.x;
	m_maxPoint.x = _centerPoint.x;
	if (_scale.x > 0.000001f)
	{
		m_minPoint.x -= (_scale.x / 2.0f);
		m_maxPoint.x += (_scale.x / 2.0f);
	}

	m_minPoint.y = _centerPoint.y;
	m_maxPoint.y = _centerPoint.y;
	if (_scale.y > 0.000001f)
	{
		m_minPoint.y -= (_scale.y / 2.0f);
		m_maxPoint.y += (_scale.y / 2.0f);
	}

}

void ABFramework::Rect::Set(const Point2D& _centerPoint, const Scale& _scale)
{
	m_minPoint.x = _centerPoint.x;
	m_maxPoint.x = _centerPoint.x;
	if (_scale.x > 0.000001f)
	{
		m_minPoint.x -= (_scale.x / 2.0f);
		m_maxPoint.x += (_scale.x / 2.0f);
	}

	m_minPoint.y = _centerPoint.y;
	m_maxPoint.y = _centerPoint.y;
	if (_scale.y > 0.000001f)
	{
		m_minPoint.y -= (_scale.y / 2.0f);
		m_maxPoint.y += (_scale.y / 2.0f);
	}
}

//********************************************************************************//
//                                Getters                                         //
//********************************************************************************//



//********************************************************************************//
//                             Private Helpers                                    //
//********************************************************************************//



