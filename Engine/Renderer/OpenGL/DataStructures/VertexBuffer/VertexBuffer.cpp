
#include "VertexBuffer.h"
#include "glad/glad.h"
#include "../Engine/Renderer/OpenGL/Mesh/Mesh.h"

//********************************************************************************//
//                        Constructors / Destructor                                //
//********************************************************************************//

ABFramework::VertexBuffer::VertexBuffer()
	:m_ID(0U)
{
	glGenBuffers(1, &m_ID);
	glBindBuffer(GL_ARRAY_BUFFER, m_ID);
}

ABFramework::VertexBuffer::~VertexBuffer()
{
	glDeleteBuffers(1, &m_ID);
}


//********************************************************************************//
//                               Operators                                        //
//********************************************************************************//




//********************************************************************************//
//                                Utility                                         //
//********************************************************************************//

void ABFramework::VertexBuffer::Bind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, m_ID);
}

void ABFramework::VertexBuffer::Unbind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

//********************************************************************************//
//                                Setters                                         //
//********************************************************************************//

void ABFramework::VertexBuffer::SetData(const Mesh& _mesh)
{
	glBufferData(GL_ARRAY_BUFFER, _mesh.GetVertexSize(), _mesh.GetVertices(), GL_STATIC_DRAW);
}

void ABFramework::VertexBuffer::SetData(const Mesh* _pMesh)
{
	glBufferData(GL_ARRAY_BUFFER, _pMesh->GetVertexSize(), _pMesh->GetVertices(), GL_STATIC_DRAW);
}

//********************************************************************************//
//                                Getters                                         //
//********************************************************************************//



//********************************************************************************//
//                             Private Helpers                                    //
//********************************************************************************//


