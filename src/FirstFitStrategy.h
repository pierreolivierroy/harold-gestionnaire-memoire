// FirstFitStrategy.h
#ifndef FirstFitStrategy_h
#define FirstFitStrategy_h

#include "IMemoryManagerStrategy.h"
#include "VirtualMemory.h"

class FirstFitStrategy : public IMemoryManagerStrategy
{
    public:
    	FirstFitStrategy(){}
    	~FirstFitStrategy(){}
        intptr_t alloumem(VirtualMemory* vm, size_t size);
};

#endif