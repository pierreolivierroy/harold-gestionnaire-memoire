// BestFitStrategy.h
#ifndef BestFitStrategy_h
#define BestFitStrategy_h

#include "IMemoryManagerStrategy.h"
#include "VirtualMemory.h"

class BestFitStrategy : public IMemoryManagerStrategy
{
    public:
    	BestFitStrategy(){}
    	~BestFitStrategy(){}
        intptr_t alloumem(VirtualMemory* vm, size_t size);
};

#endif