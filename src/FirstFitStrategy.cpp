// FirstFitStrategy.cpp
#include "FirstFitStrategy.h"

#include <iostream>

using namespace std;

intptr_t FirstFitStrategy::alloumem(VirtualMemory* vm, size_t size)
{
	//do stuff
    // cout << "alloumem\n";

    for (vm->it=vm->l.begin(); vm->it!=vm->l.end(); ++vm->it)
	{
  		// (*vm->it)->printBlock();
		if (size <= (*vm->it)->size && (*vm->it)->free)
		{
			// cout << "Partition trouvée!\n";

			// Prendre la place du bloc
			size_t sizeRemaining = (*vm->it)->size - size;
			intptr_t newAddress = (*vm->it)->address + size;

			// Créer un nouveau bloc vide avec l'espace du bloc précédent - size
			Block* b = new Block(sizeRemaining, newAddress, true);
			vm->l.push_back(b);

			// Ajuster le bloc précédent (size et free)
			(*vm->it)->size = size;
			(*vm->it)->free = false;

			// (*vm->it)->printBlock();
			// b->printBlock();

			// return b->address;
			return (*vm->it)->address;
			// break;
		}
	}
	return NULL;
}