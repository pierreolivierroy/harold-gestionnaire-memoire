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
	list<Block*>::iterator lastIter, startIter;
	startIter = currentIter;
	lastIter = vm->l.end();
	// cout << "\n";
	// cout << "list size " << vm->l.size() << "\n";
	// cout << "distance " << distance(currentIter, lastIter) << "\n";
	// cout << "size " << size << "\n";
	
    while(currentIter != vm->l.end())
    {
    	// if(distance(currentIter, lastIter) == 0)
			// currentIter = vm->l.begin();
    	// cout << "distance " << distance(currentIter, lastIter) << "\n";
    	
    	// cout << "currentIter1 ";
    	// (*currentIter)->printBlock();
    	
    	if(size <= (*currentIter)->size && (*currentIter)->isFree())
    	{
    		// cout << "big if\n";
    		// cout << "currentIter2 ";
    		// (*currentIter)->printBlock();
			size_t sizeRemaining = (*currentIter)->size - size;
			intptr_t newAddress = (*currentIter)->address + size;
			intptr_t oldAddress = (*currentIter)->address;
			// cout << "sizeRemaining " << sizeRemaining << "\n";
			// cout << "newAddress " << newAddress << "\n";
			// cout << "oldAddress " << oldAddress << "\n";

			// cout << "currentIter3 ";
    		// (*currentIter)->printBlock();

			Block* b = new Block(size, oldAddress, false);
			(*currentIter)->address = newAddress;
			(*currentIter)->size = sizeRemaining;
			(*currentIter)->free = true;

			// cout << "currentIter4 ";
    		// (*currentIter)->printBlock();
			// Block* remainingBlock = new Block(sizeRemaining, newAddress, true);
			// b->printBlock();
	
			// cout << "avant insert\n";
			// cout << "currentIter5 ";
			// (*currentIter)->printBlock();

			vm->l.insert(currentIter, b);
			// cout << "après insert\n";

			// vm->l.erase(currentIter);

			// vm->l.push_back(newBlock);
			// if(sizeRemaining > 0)
			// 	vm->l.push_back(remainingBlock);

			// cout << "distance " << distance(currentIter, lastIter) << "\n";
			if(sizeRemaining == 0)
			{
				vm->l.erase(currentIter);
			}
			// else
			// {
			// 	(*currentIter)->address = newAddress;
			// 	(*currentIter)->size = sizeRemaining;
			// 	(*currentIter)->free = true;
			// }

			return b->address;
    	}

    	// list<Block*>::iterator nextIter;
    	// nextIter = currentIter;
    	// nextIter++;

    	currentIter++;

    	if(currentIter == vm->l.end())
    	{
			// cout << "THIS IS THE END\n";
    		currentIter = vm->l.begin();
    	}		
		else if(currentIter == startIter)
		{
			// cout << "tour complet\n";
			return 0;
		}
		
    }

	return 0;
}