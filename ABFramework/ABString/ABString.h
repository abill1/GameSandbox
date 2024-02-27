
#ifndef ABSTRING_H
#define ABSTRING_H

namespace ABFramework
{
	class String
	{
	public:
		enum class Capacity : size_t
		{
			UNINITIALIZED = 0U,
			SIZE_1024 = 1024U
		};

	public:

		// ----- Constructor / Destructor ----- //

		String();
		String(const char* _pStr);
		String(const String& src);
		String(String&& src) = delete;
		~String();

		// ----- Operators ----- //

		bool operator==(const String& rhs) const;
		String& operator+=(const String& rhs);
		String& operator+=(const char* rhs);
		String& operator=(const String& rhs); 
		String& operator=(String&& rhs) = delete;

		// ------ Utility ----- //

		// ----- Setters ----- //

		void Copy(const String* _rhs);
		void Copy(const char* const _rhs);

		// ----- Getters ----- //

		inline char* c_str() const { return pStr; }
		inline size_t GetLength() const { return m_length; }
		inline size_t GetHash() const { return m_hash; }

	private:

		// ----- Helpers ----- //

		void privFindHash();
		void privFindLength();
		void privClear();
		void privCopy(const char* _pStr);
		void privCopy(String& dest, const char* src) const;
		void privConcatenate(const char* src);
		void privConcatenate(String& dest, const char* src) const;

	private:
		char* pStr;
		size_t m_capacity;
		size_t m_length;
		size_t m_hash;

	};
}

#endif // !ABSTRING_H

