
#include "CTransform.h"
#include "../Vendor/glm/ext.hpp"

OGL::CTransform::CTransform()
	:m_Transform(glm::identity<glm::mat4>()), m_Translation(), m_Rotation(), m_Scale()
{

}

OGL::CTransform::~CTransform()
{

}

void OGL::CTransform::Set(glm::vec3 _translation, glm::vec3 _rotation, float _degrees, glm::vec3 _scale)
{

	m_Transform = glm::translate(glm::mat4(1.0f), _translation) * glm::rotate(glm::mat4(1.0f), glm::radians(_degrees), _rotation) * glm::scale(glm::mat4(1.0f), _scale);

	m_Translation = _translation;
	m_Rotation = glm::angleAxis(glm::radians(_degrees), _rotation);
	m_Scale = _scale;
	
	//glm::mat4 uTranslation = glm::translate(glm::identity<glm::mat4>(), m_Translation);
	//glm::mat4 uRotation = glm::mat4_cast((const glm::quat)m_Rotation);
	//glm::mat4 uScaled = glm::scale(glm::identity<glm::mat4>(), m_Scale);

	//m_Transform = m_Transform = glm::translate(glm::mat4(1.0f), _translation) * glm::rotate(glm::mat4(1.0f), glm::radians(_degrees), _rotation) * glm::scale(glm::mat4(1.0f), _scale); //uTranslation * uRotation * uScaled;

}

void OGL::CTransform::SetTranslation(glm::vec3 _translation)
{
	m_Translation = _translation;

}

void OGL::CTransform::SetRotation(glm::vec3 _rotation, float _degrees)
{
	m_Rotation = glm::angleAxis(glm::radians(_degrees), _rotation);
}

void OGL::CTransform::SetScale(glm::vec3 _scale)
{
	m_Scale = _scale;

}

glm::mat4 OGL::CTransform::GetMatrix()
{
	return m_Transform;
}

glm::vec3 OGL::CTransform::GetTranslation() const
{
	return m_Translation;
}

glm::quat OGL::CTransform::GetRotation() const
{
	return m_Rotation;
}

glm::vec3 OGL::CTransform::GetScale() const
{
	return m_Scale;
}

