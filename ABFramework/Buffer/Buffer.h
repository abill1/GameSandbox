
#ifndef BUFFER_H
#define BUFFER_H

struct _iobuf;
typedef _iobuf FILE;

namespace ABFramework
{
	enum class Code;

	class Buffer
	{
	public:
		// ----- Constructor / Destructor ----- //

		Buffer();
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
}

#endif // !BUFFER_H


