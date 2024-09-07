#include "Buffer.h"
#include "../Constants/Constants.h"
#include "../Codes/ABCode.h"

#include <string>
#include <stdio.h>

//********************************************************************************//
//                        Constructors / Destructor                                //
//********************************************************************************//

Framework::Buffer::Buffer()
	:pData(nullptr), m_capacity(0U)
{
	m_capacity = MemorySize::KILOBYTE;
	pData = new char[m_capacity];
	memset(pData, 0, m_capacity);

}

Framework::Buffer::Buffer(size_t _size)
	:pData(nullptr), m_capacity(_size)
{
	pData = new char[m_capacity];
	memset(pData, 0, m_capacity);
}

Framework::Buffer::~Buffer()
{
	delete[] pData;
	pData = nullptr;
	m_capacity = 0U;
}

// ----- UBuffer

Framework::UBuffer::UBuffer()
	:pData(nullptr), m_capacity(0U)
{
	m_capacity = MemorySize::KILOBYTE;
	pData = new unsigned char[m_capacity];
	memset(pData, 0, m_capacity);

}

Framework::UBuffer::UBuffer(size_t _size)
	:pData(nullptr), m_capacity(_size)
{
	pData = new unsigned char[m_capacity];
	memset(pData, 0, m_capacity);
}

Framework::UBuffer::~UBuffer()
{
	delete[] pData;
	pData = nullptr;
	m_capacity = 0U;
}

//********************************************************************************//
//                               Operators                                        //
//********************************************************************************//




//********************************************************************************//
//                                Utility                                         //
//********************************************************************************//




//********************************************************************************//
//                                Setters                                         //
//********************************************************************************//

Framework::Code Framework::Buffer::Fill(FILE* _pFile, size_t _length)
{
	Code code = Code::FAILURE;

	// Else Resize?

	if (_length > m_capacity)
	{
		code = Code::INSUFFICIENT_SIZE;
	}
	else
	{
		fread_s(this->pData, this->m_capacity, sizeof(char), _length - 1, _pFile);
		rewind(_pFile);
		code = Code::SUCCESS;
	}

	return code;
}

Framework::Code Framework::UBuffer::Fill(FILE* _pFile, size_t _length)
{
	Code code = Code::FAILURE;

	// Else Resize?

	if (_length > m_capacity)
	{
		code = Code::INSUFFICIENT_SIZE;
	}
	else
	{
		fread_s(this->pData, this->m_capacity, sizeof(char), _length - 1, _pFile);
		rewind(_pFile);
		code = Code::SUCCESS;
	}

	return code;
}

Framework::Code Framework::UBuffer::Fill(unsigned char* _src, size_t _length)
{
	Code code = Code::FAILURE;

	// Else Resize?

	if (_length > m_capacity)
	{
		code = Code::INSUFFICIENT_SIZE;
	}
	else
	{
		memset(pData, 0, m_capacity);
		memcpy_s(pData, m_capacity, _src, _length);
		code = Code::SUCCESS;
	}

	return code;
}

const unsigned char* Framework::UBuffer::GetDataAt(size_t _index)
{
	return &pData[_index];
}

//********************************************************************************//
//                             Private Helpers                                    //
//********************************************************************************//


