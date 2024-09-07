
#ifndef BUFFER_H
#define BUFFER_H

struct _iobuf;
typedef _iobuf FILE;

namespace Framework
{
	enum class Code;

	class Buffer
	{
	public:
		// ----- Constructor / Destructor ----- //

		Buffer();
		Buffer(size_t _size);
		Buffer(const Buffer& _src) = delete;
		Buffer(Buffer&& _rVal) = delete;
		~Buffer();

		// ----- Operators ----- //

		Buffer& operator=(const Buffer& _rVal) = delete;
		Buffer& operator=(Buffer&& _rVal) = delete;

		// ------ Utility ----- //

		// ----- Setters ----- //

		Code Fill(FILE* _pFile, size_t _length);

		// ----- Getters ----- //

		inline const char* GetData() const { return pData; }

	private:
		char* pData;
		size_t m_capacity;

	};

	class UBuffer
	{
	public:
		// ----- Constructor / Destructor ----- //

		UBuffer();
		UBuffer(size_t _size);
		UBuffer(const UBuffer& _src) = delete;
		UBuffer(UBuffer&& _rVal) = delete;
		~UBuffer();

		// ----- Operators ----- //

		UBuffer& operator=(const UBuffer& _rVal) = delete;
		UBuffer& operator=(UBuffer&& _rVal) = delete;

		// ------ Utility ----- //

		// ----- Setters ----- //

		Code Fill(FILE* _pFile, size_t _length);
		Code Fill(unsigned char* _src, size_t _length);

		// ----- Getters ----- //

		inline const unsigned char* GetData() const { return pData; }
		const unsigned char* GetDataAt(size_t _index);

	private:
		unsigned char* pData;
		size_t m_capacity;

	};
}

#endif // !BUFFER_H


