
#include "SquareMesh.h"
#include "../Engine/Renderer/OpenGL/DataStructures/Vertex/Vertex.h"

//********************************************************************************//
//                        Constructors / Destructor                                //
//********************************************************************************//

ABFramework::Square_Mesh::Square_Mesh()
	:Mesh()
{
	m_VertexCount = 4U;
	m_IndexCount = 6U;
	pVertices = new Vertex[m_VertexCount];
	pVertices[0].Set({ -0.5f, -0.5f, 0.0f, 1.0f}, {0.0f, 0.0f});
	pVertices[1].Set({ 0.5f, -0.5f, 0.0f, 1.0f}, {1.0f, 0.0f});
	pVertices[2].Set({ 0.5f, 0.5f, 0.0f, 1.0f}, { 1.0f, 1.0f });
	pVertices[3].Set({ -0.5f, 0.5f, 0.0f, 1.0f},  { 0.0f, 1.0f });
	pIndices = new unsigned int[m_IndexCount];
	pIndices[0] = 0U;
	pIndices[1] = 1U;
	pIndices[2] = 2U;
	pIndices[3] = 0U;
	pIndices[4] = 2U;
	pIndices[5] = 3U;

}

ABFramework::Square_Mesh::~Square_Mesh()
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



//********************************************************************************//
//                             Private Helpers                                    //
//********************************************************************************//

