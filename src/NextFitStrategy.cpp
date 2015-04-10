// NextFitStrategy.cpp
#include "NextFitStrategy.h"

#include <iostream>

using namespace std;

NextFitStrategy::NextFitStrategy(VirtualMemory* _vm) : IMemoryManagerStrategy()
{
	currentIter = _vm->l.begin();
}

NextFitStrategy::~NextFitStrategy()
{

}

intptr_t NextFitStrategy::alloumem(VirtualMemory* vm, size_t size)
{
	list<Block*>::iterator startIter;
	startIter = currentIter;

    while(currentIter != vm->l.end())
    {
    	if(size <= (*currentIter)->size && (*currentIter)->isFree())
    	{
			size_t sizeRemaining = (*currentIter)->size - size;
			intptr_t newAddress = (*currentIter)->address + size;
			intptr_t oldAddress = (*currentIter)->address;
			
			Block* b = new Block(size, oldAddress, false);
			(*currentIter)->address = newAddress;
			(*currentIter)->size = sizeRemaining;
			(*currentIter)->free = true;

			vm->l.insert(currentIter, b);
		
			if(sizeRemaining == 0)
			{
				vm->l.erase(currentIter);
			}

			return b->address;
    	}

    	currentIter++;

    	if(currentIter == vm->l.end())
    	{
    		currentIter = vm->l.begin();
    	}		
		else if(currentIter == startIter)
		{
			return 0;
		}
		
    }

	return 0;
}