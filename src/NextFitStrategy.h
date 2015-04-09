// NextFitStrategy.h
#ifndef NextFitStrategy_h
#define NextFitStrategy_h

#include "IMemoryManagerStrategy.h"
#include "VirtualMemory.h"

class NextFitStrategy : public IMemoryManagerStrategy
{
    public:
    	list<Block*>::iterator currentIter;
    	NextFitStrategy(VirtualMemory* vm);
    	~NextFitStrategy();
        intptr_t alloumem(VirtualMemory* vm, size_t size);
};

#endif