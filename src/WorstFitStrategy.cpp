// WorstFitStrategy.cpp
#include "WorstFitStrategy.h"

#include <iostream>

using namespace std;

intptr_t WorstFitStrategy::alloumem(VirtualMemory* vm, size_t size)
{
	bool found = false;
	size_t lowestSize = 0;
	list<Block*>::iterator iter, bestIter;
	iter = vm->l.begin();

    while(iter != vm->l.end())
    {
    	if(size <= (*iter)->size && (*iter)->isFree())
    	{
    		found = true;
    		if(lowestSize == 0)
    		{
    			lowestSize = (*iter)->size;
				bestIter = iter;
    		}
			else if((*iter)->size > lowestSize)
			{
				lowestSize = (*iter)->size;
				bestIter = iter;
			}
    	}
    	iter++;
    }

    if(found)
    {
    	size_t sizeRemaining = (*bestIter)->size - size;
		intptr_t newAddress = (*bestIter)->address + size;
		intptr_t oldAddress = (*bestIter)->address;

		Block* b = new Block(size, oldAddress, false);

		vm->l.insert(bestIter, b);
		
		if(sizeRemaining == 0)
		{
			vm->l.erase(bestIter);
		}
		else
		{
			(*bestIter)->address = newAddress;
			(*bestIter)->size = sizeRemaining;
			(*bestIter)->free = true;
		}
	
		return b->address;
    }
	return 0;
}