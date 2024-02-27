
#include "ABFile.h"
#include "../Codes/ABCode.h"
#include "../ABString/ABString.h"
#include "../Buffer/Buffer.h"
#include <stdio.h>

ABFramework::Code ABFramework::File::Load(char* buffer, size_t _bufSize, const char* _filePath)
{
	ABFramework::Code code = ABFramework::Code::FAILURE;

	FILE* hFile;
	errno_t err = fopen_s(&hFile, _filePath, "r+");
	if (err == 0)
	{
		printf("File opened\n");
		fseek(hFile, 0, SEEK_END);
		long len = ftell(hFile);
		rewind(hFile);
		fread_s(buffer, _bufSize, sizeof(char), len - 1, hFile);
		rewind(hFile);
		fclose(hFile);
		code = ABFramework::Code::SUCCESS;
	}

	return code;
}



ABFramework::Code ABFramework::File::Load(char* buffer, size_t _bufSize, const ABFramework::String& _filePath)
{
	ABFramework::Code code = ABFramework::Code::FAILURE;

	FILE* hFile;
	errno_t err = fopen_s(&hFile, _filePath.c_str(), "r+");
	if (err == 0)
	{
		printf("File opened\n");
		fseek(hFile, 0, SEEK_END);
		long len = ftell(hFile);
		rewind(hFile);
		fread_s(buffer, _bufSize, sizeof(char), len - 1, hFile);
		rewind(hFile);
		fclose(hFile);
		code = ABFramework::Code::SUCCESS;
	}

	return code;
}

ABFramework::Code ABFramework::File::Load(ABFramework::Buffer& _buffer, const ABFramework::String& _filePath)
{
	ABFramework::Code code = ABFramework::Code::FAILURE;

	FILE* hFile;
	errno_t err = fopen_s(&hFile, _filePath.c_str(), "r+");
	if (err == 0)
	{
		printf("File opened\n");
		fseek(hFile, 0, SEEK_END);
		size_t len = (size_t)ftell(hFile);
		rewind(hFile);
		_buffer.Fill(hFile, len);
		rewind(hFile);
		fclose(hFile);
		code = ABFramework::Code::SUCCESS;
	}

	return code;
}

