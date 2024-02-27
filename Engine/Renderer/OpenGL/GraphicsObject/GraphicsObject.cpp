
#include "GraphicsObject.h"

#include "../Engine/Renderer/OpenGL/ShaderObject/ShaderObject.h"
#include "../ABFramework/ABString/ABString.h"
#include "../Engine/Renderer/OpenGL/Texture/Texture.h"
#include "../Engine/Renderer/OpenGL/DataStructures/VertexArray/VertexArray.h"
#include "../Engine/Renderer/OpenGL/DataStructures/VertexBuffer/VertexBuffer.h"
#include "../Engine/Renderer/OpenGL/DataStructures/IndexBuffer/IndexBuffer.h"
#include "../ABFramework/Codes/ABCode.h"
#include "glad/glad.h"


//********************************************************************************//
//                        Constructors / Destructor                                //
//********************************************************************************//

ABFramework::GraphicsObject::GraphicsObject()
	:pShader(new ShaderObject()), pVAO(new VertexArray()),pVertBuf(new VertexBuffer()),pIndexBuf(new IndexBuffer()),pActiveTexture(nullptr),
	m_ViewProjUniformLoc(0), m_ModelUniformLoc(0)
{
	pShader->Load(DEFAULT_VERTEX_SHADER_PATH, DEFAULT_FRAGMENT_SHADER_PATH);
	pShader->Bind();
	m_ViewProjUniformLoc = pShader->FindUniformLocation(VIEW_PROJECTION_UNIFORM);
	m_ModelUniformLoc = pShader->FindUniformLocation(MODEL_UNIFORM);
	pActiveTexture = nullptr;

}

ABFramework::GraphicsObject::~GraphicsObject()
{
	pActiveTexture = nullptr;

	delete pShader;
	delete pVAO;
	delete pVertBuf;
	delete pIndexBuf;
	//delete pDefaultTexture;

	pShader = nullptr;
	pVAO = nullptr;
	pVertBuf = nullptr;
	pIndexBuf = nullptr;
	//pDefaultTexture = nullptr;

}


//********************************************************************************//
//                               Operators                                        //
//********************************************************************************//




//********************************************************************************//
//                                Utility                                         //
//********************************************************************************//


void ABFramework::GraphicsObject::Draw(const Matrix& _vp, const Matrix& _transform) const
{
	pShader->Bind();
	pVAO->Bind();
	pIndexBuf->Bind();
	CHECK_NULL(pActiveTexture);
	pActiveTexture->Bind();
	pShader->SetUniformMatrix(m_ViewProjUniformLoc, _vp);
	pShader->SetUniformMatrix(m_ModelUniformLoc, _transform);
	glDrawElements(GL_TRIANGLES, (GLsizei)pIndexBuf->GetCount(), GL_UNSIGNED_INT, nullptr);

}


//********************************************************************************//
//                                Setters                                         //
//********************************************************************************//

void ABFramework::GraphicsObject::Set(const class Mesh& _mesh)
{
	pVAO->Bind();
	pVertBuf->Bind();
	pVertBuf->SetData(_mesh);
	pVAO->BindLayout();
	pVertBuf->Bind();
	pIndexBuf->SetData(_mesh);
	pIndexBuf->Bind();
}



void ABFramework::GraphicsObject::Set(const class Mesh* _mesh)
{
	pVAO->Bind();
	pVertBuf->Bind();
	pVertBuf->SetData(_mesh);
	pVAO->BindLayout();
	pVertBuf->Bind();
	pIndexBuf->SetData(_mesh);
	pIndexBuf->Bind();
}


void ABFramework::GraphicsObject::SetActiveTexture(ABFramework::Texture* const _pTexture)
{
	pActiveTexture = _pTexture;

}

//void ABFramework::GraphicsObject::SetDefaultTexture()
//{
//	pActiveTexture = pDefaultTexture;
//
//}

//********************************************************************************//
//                                Getters                                         //
//********************************************************************************//



//********************************************************************************//
//                             Private Helpers                                    //
//********************************************************************************//


