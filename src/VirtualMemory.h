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
	    /* Constructors with No Arguments */
	    VirtualMemory(void);
	    /* Constructors with size_t argument */
	    VirtualMemory(size_t size);
	    /* Destructor */
	    ~VirtualMemory(void);
	    
	    /* Traversing the list and printing the value of each node */
	    void print_list();
};

#endif