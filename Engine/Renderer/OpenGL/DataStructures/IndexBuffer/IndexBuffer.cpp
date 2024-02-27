
#include "IndexBuffer.h"
#include "glad/glad.h"
#include "../Engine/Renderer/OpenGL/Mesh/Mesh.h"

//********************************************************************************//
//                        Constructors / Destructor                                //
//********************************************************************************//

ABFramework::IndexBuffer::IndexBuffer()
	:m_ID(0U), m_IndexCount(0U)
{
	glGenBuffers(1, &m_ID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ID);
}

ABFramework::IndexBuffer::~IndexBuffer()
{
	glDeleteBuffers(1, &m_ID);
}


//********************************************************************************//
//                               Operators                                        //
//********************************************************************************//




//********************************************************************************//
//                                Utility                                         //
//********************************************************************************//

void ABFramework::IndexBuffer::Bind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ID);
}

void ABFramework::IndexBuffer::Unbind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

//********************************************************************************//
//                                Setters                                         //
//********************************************************************************//

void ABFramework::IndexBuffer::SetData(const Mesh& _mesh)
{
	m_IndexCount = _mesh.GetIndexCount();
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, _mesh.GetIndexSize(), _mesh.GetIndices(), GL_STATIC_DRAW);
}

void ABFramework::IndexBuffer::SetData(const Mesh* _pMesh)
{
	m_IndexCount = _pMesh->GetIndexCount();
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, _pMesh->GetIndexSize(), _pMesh->GetIndices(), GL_STATIC_DRAW);
}

//********************************************************************************//
//                                Getters                                         //
//********************************************************************************//



//********************************************************************************//
//                             Private Helpers                                    //
//********************************************************************************//

