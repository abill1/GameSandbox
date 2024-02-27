
#ifndef ABFILE_H
#define ABFILE_H

namespace ABFramework
{
	class File
	{
	public:

		static enum class Code Load(char* buffer, size_t _bufSize, const char* _filePath);
		static enum class Code Load(char* buffer, size_t _bufSize, const class String& _filePath);
		static enum class Code Load(class Buffer& _buffer, const class String& _filePath);

	private:

	};
}

#endif // !ABFILE_H