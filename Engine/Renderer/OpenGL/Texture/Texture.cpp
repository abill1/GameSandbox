
#include "Texture.h"

#include "glad/glad.h"
#include "../Engine/Vendor/stb_image/stb_image.h"

//********************************************************************************//
//                        Constructors / Destructor                                //
//********************************************************************************//

ABFramework::Texture::Texture()
	:pName(new String()), pTextureBuffer(nullptr), m_width(0), m_height(0), m_BPP(0), m_textureID(0U)
{
	
}

ABFramework::Texture::Texture(const ABFramework::String& _textureFilePath, const char* const _name)
	: pName(new String(_name)), pTextureBuffer(nullptr), m_width(0), m_height(0), m_BPP(0), m_textureID(0U)
{
	stbi_set_flip_vertically_on_load(1);
	pTextureBuffer = stbi_load(_textureFilePath.c_str(), &m_width, &m_height, &m_BPP, 4);
	glGenTextures(1, &m_textureID);
	glBindTexture(GL_TEXTURE_2D, m_textureID);
	// ---- Define Parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	// ----- Load buffer data
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, pTextureBuffer);
	glBindTexture(GL_TEXTURE_2D, 0);

	if (*pName == " ")
		pName->Copy(&_textureFilePath);

	
}


ABFramework::Texture::~Texture()
{
	delete pName;
	pName = nullptr;

	if (pTextureBuffer)
	{
		stbi_image_free(pTextureBuffer);
		pTextureBuffer = nullptr;
	}
	m_width = 0;
	m_height = 0;
	m_BPP = 0;
	glDeleteTextures(1, &m_textureID);
}

//********************************************************************************//
//                               Operators                                        //
//********************************************************************************//

ABFramework::Texture& ABFramework::Texture::operator=(const Texture& _rhs)
{
	if (&*this != &_rhs)
	{
		*pName = *_rhs.pName;

		if (pTextureBuffer)
		{
			stbi_image_free(pTextureBuffer);
			pTextureBuffer = nullptr;
			glDeleteTextures(1, &m_textureID);
		}

		pTextureBuffer = stbi_load_from_memory(_rhs.pTextureBuffer, sizeof(_rhs.pTextureBuffer), (int*)&_rhs.m_width, (int*)&_rhs.m_height, (int*)&_rhs.m_BPP, 4);
		m_width = _rhs.m_width;
		m_height = _rhs.m_height;
		m_BPP = _rhs.m_BPP;
		m_textureID = _rhs.m_textureID;
	}
	
	return *this;
}


//********************************************************************************//
//                                Utility                                         //
//********************************************************************************//

void ABFramework::Texture::Bind(unsigned int _location /*= 0 */) const
{
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	// ----- TODO: Should include check for location not to exceed 32
	glActiveTexture(GL_TEXTURE0 + _location);
	glBindTexture(GL_TEXTURE_2D, m_textureID);
}

void ABFramework::Texture::Unbind() const
{
	glBindTexture(GL_TEXTURE_2D, 0);
}

//********************************************************************************//
//                                Setters                                         //
//********************************************************************************//

void ABFramework::Texture::Load(const class String& _textureFilePath, const char* const _name, bool _flip)
{
	if (pTextureBuffer)
	{
		stbi_image_free(pTextureBuffer); 
		pTextureBuffer = nullptr;
		glDeleteTextures(1, &m_textureID);
	}

	stbi_set_flip_vertically_on_load((int)_flip);
	pTextureBuffer = stbi_load(_textureFilePath.c_str(), &m_width, &m_height, &m_BPP, 4);
	glGenTextures(1, &m_textureID);
	glBindTexture(GL_TEXTURE_2D, m_textureID);
	// ---- Define Parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	// ----- Load buffer data
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, pTextureBuffer);
	glBindTexture(GL_TEXTURE_2D, 0);

	pName->Copy(_name);
	if (*pName == " ")
		pName->Copy(&_textureFilePath);

}


//********************************************************************************//
//                                Getters                                         //
//********************************************************************************//

size_t ABFramework::Texture::GetNameHash() const
{
	return pName->GetHash();
}


const ABFramework::String* ABFramework::Texture::GetNameStr() const
{
	return pName;
}

//********************************************************************************//
//                             Private Helpers                                    //
//********************************************************************************//


