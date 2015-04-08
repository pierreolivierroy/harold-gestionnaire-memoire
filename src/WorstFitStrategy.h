// WorstFitStrategy.h
#ifndef WorstFitStrategy_h
#define WorstFitStrategy_h

#include "IMemoryManagerStrategy.h"
#include "VirtualMemory.h"

class WorstFitStrategy : public IMemoryManagerStrategy
{
    public:
    	WorstFitStrategy(){}
    	~WorstFitStrategy(){}
        intptr_t alloumem(VirtualMemory* vm, size_t size);
};

#endif