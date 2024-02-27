
#include "VertexArray.h"

#include "glad/glad.h"
#include "../Engine/Renderer/OpenGL/DataStructures/Vertex/Vertex.h"

//********************************************************************************//
//                        Constructors / Destructor                                //
//********************************************************************************//

ABFramework::VertexArray::VertexArray()
	:m_ID(0U)
{
	glGenVertexArrays(1, &m_ID);
	glBindVertexArray(m_ID);

}

ABFramework::VertexArray::~VertexArray()
{
	glDeleteVertexArrays(1, &m_ID);
}

//********************************************************************************//
//                               Operators                                        //
//********************************************************************************//




//********************************************************************************//
//                                Utility                                         //
//********************************************************************************//

void ABFramework::VertexArray::Bind() const
{
	glBindVertexArray(m_ID);
}

void ABFramework::VertexArray::Unbind() const
{
	glBindVertexArray(0);
}


void ABFramework::VertexArray::BindLayout() const
{
	glEnableVertexAttribArray(m_positionAttribute);
	glEnableVertexAttribArray(m_textureAttribute);
	glVertexAttribPointer(m_positionAttribute, sizeof(Point) / sizeof(float), GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
	glVertexAttribPointer(m_textureAttribute, sizeof(TextureCoord) / sizeof(float), GL_FLOAT, GL_FALSE, sizeof(Vertex), (const void*)sizeof(Point));

}

//********************************************************************************//
//                                Setters                                         //
//********************************************************************************//



//********************************************************************************//
//                                Getters                                         //
//********************************************************************************//



//********************************************************************************//
//                             Private Helpers                                    //
//********************************************************************************//

