#include "Collision.h"

#include "Collider/AABB.h"

bool ABFramework::Collision::Check(ABFramework::AABB* const _pObjA, ABFramework::AABB* const _pObjB)
{
	return _pObjA->CollidesWith(_pObjB);
}
