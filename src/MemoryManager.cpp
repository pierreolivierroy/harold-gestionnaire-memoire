// MemoryManager.cpp
#include "MemoryManager.h"
#include <iostream>

using namespace std;

MemoryManager::MemoryManager()
{
	initmem();
}

void MemoryManager::initmem()
{
	vMem = new VirtualMemory(size);
}

intptr_t MemoryManager::executeStrategy(IMemoryManagerStrategy* _strategy, int _size)
{
	return _strategy->alloumem(vMem, _size);
}

void MemoryManager::liberemem(intptr_t _pBloc)
{
	list<Block*>::iterator iter, iter2;
	iter = vMem->l.begin();
    while(iter != vMem->l.end())
    {
    	if((*iter)->address == _pBloc && !(*iter)->isFree())
    	{
    		(*iter)->free = true;
    		break;
    	}
    	iter++;
    }

    iter = vMem->l.begin();
    iter2 = vMem->l.begin();
   
    while(iter != vMem->l.end())
    {
    	int diff = 1;
    	iter2++;
			if(iter != iter2 && iter2 != vMem->l.end())
    		{
    			if((*iter)->isFree() && (*iter2)->isFree())
    			{
    				Block* b = new Block((*iter)->size + (*iter2)->size, (*iter)->address, true);
    				vMem->l.insert(iter, b);
    
    				iter = vMem->l.erase(iter);
    				vMem->l.erase(iter);
    				iter--;	
    			}    			
    		}
    	iter++;
    	iter2 = iter;
    }
}	

int MemoryManager::nbloclibres()
{
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
	for (vMem->it=vMem->l.begin(); vMem->it!=vMem->l.end(); ++vMem->it)
	{
		if (!(*vMem->it)->isFree() && ((*vMem->it)->address <= _pOctet && _pOctet <= ((*vMem->it)->size + (*vMem->it)->address)))
			return true;
	}
	return false;
}