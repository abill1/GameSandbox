
#ifndef OPENGL_TEXTURE_H
#define OPENGL_TEXTURE_H

namespace ABFramework
{
	class Texture
	{
	public:
		enum class FlipVertically : int
		{
			NO = 0,
			YES = 1
		};

	public:
		// ----- Constructor / Destructor ----- //

		Texture();
		Texture(const class String& _textureFilePath, const char* const _name = " ");
		~Texture();

		// ----- Operators ----- //

		Texture& operator=(const Texture& _rhs);

		// ------ Utility ----- //

		void Bind(unsigned int _location = 0) const;
		void Unbind() const;

		// ----- Setters ----- //
		
		void Load(const class String& _textureFilePath, const char* const _name = " ", bool _flip = false);

		// ----- Getters ----- //

		inline int GetWidth() const { return m_width; }
		inline int GetHeight() const { return m_height; }

		size_t GetNameHash() const ;
		const class String* GetNameStr() const;

	private:
		class String* pName;
		unsigned char* pTextureBuffer;
		int m_width;
		int m_height;
		int m_BPP;
		unsigned int m_textureID;

	};
}

#endif // !OPENGL_TEXTURE_H
