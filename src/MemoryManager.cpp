// MemoryManager.cpp
#include "MemoryManager.h"
#include <iostream>

using namespace std;

MemoryManager::MemoryManager()
{
	initmem();
}

void MemoryManager::affiche_etat_memoire()
{
	vMem->print_list();
}

void MemoryManager::affiche_parametres_memoire(size_t _maxTaillePetit)
{
	cout << "\n";
	cout << "Plus grand bloc libre: " << mem_pgrand_libre() << " octets\n";
	cout << "Mémoire libre: " << memlibre() << " octets\n";
	cout << "Blocs libres: " << nbloclibres() << "\n";
    cout << "Blocs alloués: " << nblocalloues() << "\n";
    cout << "Nombre blocs libres plus petits que " << _maxTaillePetit << " octets: " << mem_small_free(_maxTaillePetit) << "\n";
}

void MemoryManager::initmem()
{
	// cout << "initmem\n";

	vMem = new VirtualMemory(size);
}

intptr_t MemoryManager::executeStrategy(IMemoryManagerStrategy* _strategy, int _size)
{
	return _strategy->alloumem(vMem, _size);
}

void mergeBlocks(Block* _b1, Block* _b2)
{
	// cout << (*block)->address << "\n";
	// if(iter != vMem->l.end()) 
	// {

	// }
	_b1->printBlock();
	_b2->printBlock();
}

void MemoryManager::liberemem(intptr_t _pBloc)
{
	// cout << "liberemem\n";
	// list<Object*>::iterator iter;

    // iter = this->objectlist.begin();

    // while(iter != this->objectlist.end())
    // {
    //     iter->print();
    // }


	list<Block*>::iterator iter, iter2;
	iter = vMem->l.begin();
    while(iter != vMem->l.end())
    {
    	// cout << (*iter)->address << "\n";
    	if((*iter)->address == _pBloc && !(*iter)->isFree())
    	{
    		free((*iter));
    		(*iter)->free = true;
    		// vMem->l.erase(iter);
    	}
    	iter++;
    }

    vMem->print_list();

    iter = vMem->l.begin();
    iter2 = vMem->l.begin();
   
    while(iter != vMem->l.end())
    {
    	while(iter2 != vMem->l.end())
    	{
    		if(iter != iter2)
    		{
    			// cout << "Pas égal yo\n";
    			// (*iter)->printBlock();
    			// (*iter2)->printBlock();
    			if((*iter)->isFree() && (*iter2)->isFree())
    			{
    				// cout << "\n2 Blocs libres\n";
    				// Block* b1 = (*iter);
    				// Block* b2 = (*iter2);
    				// mergeBlocks(b1, b2);
    				Block* b = new Block((*iter)->size + (*iter2)->size, (*iter)->address, true);
    				vMem->l.insert(iter, b);
    				// list<Block*>::iterator iter3 = iter--;

    				// (*iter)->printBlock();
    				// (*iter2)->printBlock();
    				// (*iter3)->printBlock();

    				iter = vMem->l.erase(iter);
    				vMem->l.erase(iter);
    				
    				// cout << "après erase\n";
    				// (*iter)->printBlock();	
    			}    			
    		}

    		iter2++;
    	}
    	iter++;
    	iter2 = iter;
    }
}	

int MemoryManager::nbloclibres()
{
	// cout << "nbloclibres\n";

	int n = 0;
	for (vMem->it=vMem->l.begin(); vMem->it!=vMem->l.end(); ++vMem->it)
	{
		if ((*vMem->it)->isFree())
			n++;
	}
	return n;
}

int MemoryManager::nblocalloues()
{
	// cout << "nblocalloues\n";

	int n = 0;
	for (vMem->it=vMem->l.begin(); vMem->it!=vMem->l.end(); ++vMem->it)
	{
		if (!(*vMem->it)->isFree())
			n++;
	}
	return n;
}

size_t MemoryManager::memlibre()
{
	// cout << "memlibre\n";
	
	size_t freeMem = 0;
	for (vMem->it=vMem->l.begin(); vMem->it!=vMem->l.end(); ++vMem->it)
	{
		if ((*vMem->it)->isFree())
			freeMem += (*vMem->it)->size;
	}
	return freeMem;
}

int MemoryManager::mem_pgrand_libre()
{
	// cout << "mem_pgrand_libre\n";

	size_t highestMem = 0;
	for (vMem->it=vMem->l.begin(); vMem->it!=vMem->l.end(); ++vMem->it)
	{
		if ((*vMem->it)->isFree() && highestMem < (*vMem->it)->size)
			highestMem = (*vMem->it)->size;
	}
	return highestMem;
}

int MemoryManager::mem_small_free(size_t _maxTaillePetit)
{
	// cout << "mem_small_free\n";

	int n = 0;
	for (vMem->it=vMem->l.begin(); vMem->it!=vMem->l.end(); ++vMem->it)
	{
		if ((*vMem->it)->isFree() && (*vMem->it)->size < _maxTaillePetit)
			n++;
	}
	return n;
}

bool MemoryManager::mem_est_alloue(intptr_t _pOctet)
{
	// cout << "mem_est_alloue\n";
	for (vMem->it=vMem->l.begin(); vMem->it!=vMem->l.end(); ++vMem->it)
	{
		if (!(*vMem->it)->isFree() && ((*vMem->it)->address <= _pOctet && _pOctet <= ((*vMem->it)->size + (*vMem->it)->address)))
			return true;
	}
	return false;
}