
#ifndef ABCODE_H
#define ABCODE_H

namespace Framework
{
	enum class Code : int 
	{
		FAILURE = 0,
		SUCCESS = 1,
		INSUFFICIENT_SIZE = 2,
		FAILED_TO_INIT=3
	};
}

#endif // !ABCODE_H


