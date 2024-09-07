#include "CRectMesh.h"
#include "../Renderer/OpenGL/DataStructures/OGLDataStructures.h"

OGL::CRectMesh::CRectMesh()
	:pVertices(), pIndices(), m_vertexCount(4), m_indexCount(2)
{
	pVertices = new OGL::Vertex[m_vertexCount];
	pVertices[0] = {{-0.5f, -0.5f, 0.0f, 1.0f}, {0.63f, 0.75f, 0.25f, 1.0f}, {0.0f, 0.0f}};
	pVertices[1] = { { 0.5f, -0.5f, 0.0f, 1.0f }, { 0.7f, 0.5f, 0.6f, 1.0f }, { 1.0f, 0.0f } };
	pVertices[2] = { { 0.5f, 0.5f, 0.0f, 1.0f },  { 0.6f, 0.5f, 0.7f, 1.0f }, { 1.0f, 1.0f } };
	pVertices[3] = { { -0.5f, 0.5f, 0.0f, 1.0f }, { 0.5f, 0.4f, 0.8f, 1.0f }, { 0.0f, 1.0f } };
	

	pIndices = new OGL::TriangleIndex[m_indexCount];
	pIndices[0] = { 0U, 1U, 2U };
	pIndices[1] = { 0U, 2U, 3U };
}

OGL::CRectMesh::~CRectMesh()
{
	delete[] pVertices;
	delete[] pIndices;
	m_vertexCount = 0;
	m_indexCount = 0;
}

OGL::Vertex* OGL::CRectMesh::GetVertices() const
{
	return pVertices;
}

OGL::TriangleIndex* OGL::CRectMesh::GetIndices() const
{
	return pIndices;
}

size_t OGL::CRectMesh::GetVertexCount() const
{
	return m_vertexCount;
}

size_t OGL::CRectMesh::GetIndexCount() const
{
	return m_indexCount;
}

size_t OGL::CRectMesh::GetVertexSize() const
{
	return m_vertexCount * sizeof(OGL::Vertex);
}

size_t OGL::CRectMesh::GetIndexSize() const
{
	return m_indexCount * sizeof(OGL::TriangleIndex);
}
