#include "Vertex.h"

//********************************************************************************//
//                        Constructors / Destructor                                //
//********************************************************************************//

ABFramework::Vertex::Vertex()
	:m_Point(0.0f, 0.0f, 0.0f, 1.0f), m_TexCoord(0.0f, 0.0f)
{

}

ABFramework::Vertex::Vertex(const Point& _point)
	: m_Point(_point), m_TexCoord(0.0f, 0.0f)
{

}

ABFramework::Vertex::Vertex(const Point& _point, const TextureCoord& _texCoord)
	: m_Point(_point), m_TexCoord(_texCoord)
{

}

ABFramework::Vertex::~Vertex()
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

void ABFramework::Vertex::Set(const Point& _point)
{
	this->m_Point = _point;
}

void ABFramework::Vertex::Set(const Point& _point, const TextureCoord& _texCoord)
{
	this->m_Point = _point;
	this->m_TexCoord = _texCoord;
}

//********************************************************************************//
//                             Private Helpers                                    //
//********************************************************************************//

