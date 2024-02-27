
#include "AABB.h"

#include "../Engine/Core/Collision/Shapes/Rect.h"

//********************************************************************************//
//                        Constructors / Destructor                                //
//********************************************************************************//


ABFramework::AABB::AABB()
	:pR(new ABFramework::Rect())
{

}


ABFramework::AABB::AABB(const Point3D& _centerPoint, const Scale& _scale)
	:pR(new ABFramework::Rect(_centerPoint, _scale))
{

}

ABFramework::AABB::AABB(const Point2D& _centerPoint, const Scale& _scale)
	: pR(new ABFramework::Rect(_centerPoint, _scale))
{

}

ABFramework::AABB::~AABB()
{
	delete pR;
	pR = nullptr;

}


//********************************************************************************//
//                               Operators                                        //
//********************************************************************************//




//********************************************************************************//
//                                Utility                                         //
//********************************************************************************//

bool ABFramework::AABB::CollidesWith(const AABB& _other)
{
	bool bCollisionX = this->GetMaxX() >= _other.GetMinX() && _other.GetMaxX() >= this->GetMinX();
	bool bCollisionY = this->GetMaxY() >= _other.GetMinY() && _other.GetMaxY() >= this->GetMinY();
	return bCollisionX && bCollisionY;
}

bool ABFramework::AABB::CollidesWith(AABB* const _other)
{
	bool bCollisionX = this->GetMaxX() >= _other->GetMinX() && _other->GetMaxX() >= this->GetMinX();
	bool bCollisionY = this->GetMaxY() >= _other->GetMinY() && _other->GetMaxY() >= this->GetMinY();
	return bCollisionX && bCollisionY;
}

//********************************************************************************//
//                                Setters                                         //
//********************************************************************************//

void ABFramework::AABB::Set(const Point3D& _centerPoint, const Scale& _scale)
{
	this->pR->Set(_centerPoint, _scale);
}

void ABFramework::AABB::Set(const Point2D& _centerPoint, const Scale& _scale)
{
	this->pR->Set(_centerPoint, _scale);
}

//********************************************************************************//
//                                Getters                                         //
//********************************************************************************//

float ABFramework::AABB::GetMaxX() const { return pR->GetMax()->x; }
float ABFramework::AABB::GetMaxY() const { return pR->GetMax()->y; }
float ABFramework::AABB::GetMinX() const { return pR->GetMin()->x; }
float ABFramework::AABB::GetMinY() const { return pR->GetMin()->y; }

//********************************************************************************//
//                             Private Helpers                                    //
//********************************************************************************//


