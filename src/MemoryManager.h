// MemoryManager.h
#ifndef MemoryManager_h
#define MemoryManager_h

#include <stdlib.h>
#include "IMemoryManagerStrategy.h"
#include "VirtualMemory.h"

class MemoryManager
{
private:
	static const size_t size = 1024;

public:
	VirtualMemory* vMem;
	MemoryManager();
	void initmem();
	intptr_t executeStrategy(IMemoryManagerStrategy *_strategy, int _size);
	void liberemem(intptr_t _pBloc);
	int nbloclibres();
	int nblocalloues();
	size_t memlibre();
	int mem_pgrand_libre();
	int mem_small_free(size_t _maxTaillePetit);
	bool mem_est_alloue(intptr_t _pOctet);
};

#endif