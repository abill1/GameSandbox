
#ifndef ABCONSTANTS_H
#define ABCONSTANTS_H

namespace ABFramework
{
	class MemorySize
	{
	public:
		constexpr static size_t BYTE = 1u;
		constexpr static size_t KILOBYTE = 1024u;
		constexpr static size_t MEGABYTE = 1048576u;
		constexpr static size_t GIGABYTE = 1073741824u;
		constexpr static size_t TERRABYTE = 1099511627776u;
		constexpr static size_t PETABYTE = 1125899906842624u;
		constexpr static size_t EXABYTE = 1152921504606846976u;

	};

}

#endif // ABCONSTANTS_H

