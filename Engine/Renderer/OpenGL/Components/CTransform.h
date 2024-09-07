
#ifndef OGL_COMPONENT_CTRANSFORM_H
#define OGL_COMPONENT_CTRANSFORM_H

#include "../Vendor/glm/glm.hpp"
#include "../Vendor/glm/ext.hpp"

namespace OGL
{
	class CTransform
	{
	public:
		CTransform();
		~CTransform();

		void Set(glm::vec3 _translation, glm::vec3 _rotation, float _degrees, glm::vec3 _scale);
		void SetTranslation(glm::vec3 _translation);
		void SetRotation(glm::vec3 _rotationAxis, float _degrees);
		void SetScale(glm::vec3 _scale);

		glm::mat4 GetMatrix();
		glm::vec3 GetTranslation() const;
		glm::quat GetRotation() const;
		glm::vec3 GetScale() const;

	private:
		glm::mat4 m_Transform;
		glm::vec3 m_Translation;
		glm::quat m_Rotation;
		glm::vec3 m_Scale;
	};
}



#endif // !OGL_COMPONENT_CTRANSFORM_H


