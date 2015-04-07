// source: http://stackoverflow.com/questions/318064/how-do-you-declare-an-interface-in-c
// IMemoryManagerStrategy.h
#ifndef IMemoryManagerStrategy_h
#define IMemoryManagerStrategy_h

#include "VirtualMemory.h"

class IMemoryManagerStrategy
{
	public:
		virtual ~IMemoryManagerStrategy() {}
		virtual intptr_t alloumem(VirtualMemory* vm, size_t size) = 0;
};

#endif