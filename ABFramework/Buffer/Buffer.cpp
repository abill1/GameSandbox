#include "Buffer.h"
#include "../Constants/Constants.h"
#include "../Codes/ABCode.h"

#include <string>
#include <stdio.h>

//********************************************************************************//
//                        Constructors / Destructor                                //
//********************************************************************************//

ABFramework::Buffer::Buffer()
	:pData(nullptr), m_capacity(0U)
{
	m_capacity = MemorySize::KILOBYTE;
	pData = new char[m_capacity];
	memset(pData, 0, m_capacity);

}

ABFramework::Buffer::~Buffer()
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

ABFramework::Code ABFramework::Buffer::Fill(FILE* _pFile, size_t _length)
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

//********************************************************************************//
//                             Private Helpers                                    //
//********************************************************************************//


