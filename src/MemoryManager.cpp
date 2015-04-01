// MemoryManager.cpp
#include "MemoryManager.h"
#include <iostream>

using namespace std;

// MemoryManager::MemoryManager(IMemoryStrategyManager _strategy)
// {
// 	strategy = _strategy;
// }

MemoryManager::MemoryManager()
{
	initmem();
}

void MemoryManager::initmem()
{
	cout << "initmem\n";

	vMem = new VirtualMemory(size);
}

intptr_t MemoryManager::executeStrategy(IMemoryManagerStrategy* strategy, int _size)
{
	return strategy->alloumem(vMem, _size);
}

void MemoryManager::liberemem()
{
	cout << "liberemem\n";
}
int MemoryManager::nbloclibres()
{
	cout << "nbloclibres\n";
	return 0;
}
int MemoryManager::nblocalloues()
{
	cout << "nblocalloues\n";
	return 0;
}
int MemoryManager::memlibre()
{
	cout << "memlibre\n";
	return 0;
}
int MemoryManager::mem_pgrand_libre()
{
	cout << "mem_pgrand_libre\n";
	return 0;
}
int MemoryManager::mem_small_free(int _maxTaillePetit)
{
	cout << "mem_small_free\n";
	return 0;
}
bool MemoryManager::mem_est_alloue(/*pOctet*/)
{
	cout << "mem_est_alloue\n";
	return 0;
}