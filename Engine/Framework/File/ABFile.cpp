
#include "ABFile.h"
#include "../Codes/ABCode.h"
#include "../String/ABString.h"
#include "../Buffer/Buffer.h"

#include <stdio.h>

Framework::Code Framework::File::Load(char* buffer, size_t _bufSize, const char* _filePath)
{
	Framework::Code code = Framework::Code::FAILURE;

	FILE* hFile;
	errno_t err = fopen_s(&hFile, _filePath, "r+");
	if (err == 0)
	{
		printf("File opened\n");
		fseek(hFile, 0, SEEK_END);
		long len = ftell(hFile);
		rewind(hFile);
		fread_s(buffer, _bufSize, sizeof(char), (size_t)(len - 1), hFile);
		rewind(hFile);
		fclose(hFile);
		code = Framework::Code::SUCCESS;
	}

	return code;
}

Framework::Code Framework::File::Load(Framework::Buffer& _buffer, const String& _filePath)
{
	Framework::Code code = Framework::Code::FAILURE;

	FILE* hFile;
	errno_t err = fopen_s(&hFile, _filePath.c_str(), "r+");
	if (err == 0)
	{
		//printf("File opened\n");
		fseek(hFile, 0, SEEK_END);
		size_t len = (size_t)ftell(hFile);
		rewind(hFile);
		_buffer.Fill(hFile, len);
		rewind(hFile);
		fclose(hFile);
		code = Framework::Code::SUCCESS;
	}

	return code;
}
