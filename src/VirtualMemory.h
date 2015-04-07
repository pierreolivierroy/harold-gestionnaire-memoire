// VirtualMemory.h
#ifndef VirtualMemory_h
#define VirtualMemory_h

#include <list>
#include "Block.h"

using namespace std;

class VirtualMemory
{    
	public:
	    list<Block*> l;
	    list<Block*>::iterator it;
	    VirtualMemory(void);
	    VirtualMemory(size_t size);
	    ~VirtualMemory(void);
	    void print_list();
};

#endif