#include "ABString.h"

#include <string>

//********************************************************************************//
//                                 Constants                                      //
//********************************************************************************//

static const size_t HASH_MOD = (size_t)1e9 + 9U;
static const size_t HASH_P = 257U;
//static const size_t HASH_POW = 1;

//********************************************************************************//
//                        Constructors / Destructor                                //
//********************************************************************************//

Framework::String::String()
	:pStr(nullptr), m_capacity(0U), m_length(0U), m_hash(0U)
{
	m_capacity = (size_t)String::Capacity::SIZE_1024;
	pStr = new char[m_capacity];
	memset(pStr, 0, m_capacity);
	privFindHash();

}

Framework::String::String(const char* _pStr)
	:pStr(nullptr), m_capacity(0U), m_length(0U), m_hash(0U)
{
	m_capacity = (size_t)String::Capacity::SIZE_1024;
	pStr = new char[m_capacity];
	memset(pStr, 0, m_capacity);
	memcpy_s(pStr, m_capacity, _pStr, m_capacity);
	privFindLength();
	privFindHash();

}

Framework::String::String(const String& src)
	:pStr(nullptr), m_capacity(0U), m_length(0U), m_hash(0U)
{
	m_capacity = (size_t)String::Capacity::SIZE_1024;
	pStr = new char[m_capacity];
	strcpy_s(this->pStr, m_capacity, src.pStr);
	privFindLength();
	privFindHash();

}

Framework::String::~String()
{
	delete[] pStr;
	pStr = nullptr;
	m_length = 0;
	m_hash = 0U;

}

//********************************************************************************//
//                               Operators                                        //
//********************************************************************************//

bool Framework::String::operator==(const Framework::String& rhs) const
{
	return this->m_hash == rhs.m_hash;
}

Framework::String& Framework::String::operator+=(const Framework::String& rhs)
{
	this->privConcatenate(rhs.c_str());
	this->privFindHash();
	return *this;
}

Framework::String& Framework::String::operator+=(const char* rhs)
{
	this->privConcatenate(*this, rhs);
	this->privFindLength();
	this->privFindHash();
	return *this;
}

Framework::String& Framework::String::operator=(const Framework::String& rhs)
{
	if (&this->pStr != &rhs.pStr)
	{
		delete[] this->pStr;
		this->pStr = new char[m_capacity];
		strcpy_s(this->pStr, this->m_capacity, rhs.pStr);
		this->privFindLength();
		this->privFindHash();
	}
	return *this;
}


//********************************************************************************//
//                                Utility                                         //
//********************************************************************************//




//********************************************************************************//
//                                Setters                                         //
//********************************************************************************//

void Framework::String::Copy(const String* _rhs)
{
	this->privCopy(_rhs->c_str());
}

void Framework::String::Copy(const char* const _rhs)
{
	this->privCopy(_rhs);
}

//********************************************************************************//
//                             Private Helpers                                    //
//********************************************************************************//


void Framework::String::privFindHash()
{	
	// ----- Polynomial rolling hash function
	size_t value = 0U;
	size_t pow = 1;

	for (int index = 0; index < this->m_length; index++)
	{
		size_t tmp = (size_t)this->pStr[index];
		value = (value + tmp * pow) % HASH_MOD;
		pow = (pow * HASH_P) % HASH_MOD;
	}

	this->m_hash = value;

}

void Framework::String::privFindLength()
{
	this->m_length = strlen(this->pStr);

}

void Framework::String::privClear()
{
	memset(this->pStr, '\0', (size_t)String::Capacity::SIZE_1024);

}

void Framework::String::privCopy(const char* _pStr)
{
	size_t cap = (size_t)String::Capacity::SIZE_1024;
	if (this->pStr != _pStr)
	{
		this->privClear();
		strcpy_s(this->pStr, cap, _pStr);
	}

}

void Framework::String::privCopy(Framework::String& dest, const char* src) const
{
	size_t cap = (size_t)String::Capacity::SIZE_1024;
	memset(dest.pStr, 0, cap);
	strcpy_s(dest.pStr, cap, src);

}

void Framework::String::privConcatenate(const char* src)
{
	size_t len = this->m_length;
	len += strlen(src);

	if (len <= (size_t)String::Capacity::SIZE_1024)
	{
		strcat_s(this->pStr, (size_t)String::Capacity::SIZE_1024, src);
		this->m_length = len;
	}
	else
	{
		printf("ERROR: Concatenation exceeds string length.\n");
	}

}

void Framework::String::privConcatenate(Framework::String& dest, const char* src) const
{
	size_t len = dest.GetLength();
	len += strlen(src);

	if (len <= (size_t)String::Capacity::SIZE_1024)
	{
		strcat_s(dest.pStr, (size_t)String::Capacity::SIZE_1024, src);
	}
	else
	{
		printf("ERROR: Concatenation exceeds string length.\n");
	}

}
