// FirstFitStrategy.cpp
#include "FirstFitStrategy.h"

#include <iostream>

using namespace std;

intptr_t FirstFitStrategy::alloumem(VirtualMemory* vm, size_t size)
{
	list<Block*>::iterator iter;
	iter = vm->l.begin();
    while(iter != vm->l.end())
    {
    	if(size <= (*iter)->size && (*iter)->isFree())
    	{
			size_t sizeRemaining = (*iter)->size - size;
			intptr_t newAddress = (*iter)->address + size;
			intptr_t oldAddress = (*iter)->address;

			Block* b = new Block(size, oldAddress, false);

			vm->l.insert(iter, b);
			
			if(sizeRemaining == 0)
			{
				vm->l.erase(iter);
			}
			else
			{
				(*iter)->address = newAddress;
				(*iter)->size = sizeRemaining;
				(*iter)->free = true;
			}

			return b->address;
    	}
    	iter++;
    }
    
	return NULL;
}