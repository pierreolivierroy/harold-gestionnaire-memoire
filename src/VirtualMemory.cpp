// VirtualMemory.cpp
#include "VirtualMemory.h"
#include <iostream>

using namespace std;

VirtualMemory::VirtualMemory()
{
 
}

VirtualMemory::VirtualMemory(size_t size)
{
	// malloc
	// cout << "malloc\n";
	// head = new Block(size);
	Block* b = new Block(size);
	l.push_back(b);
	
	// print_list();
}

VirtualMemory::~VirtualMemory()
{
    /*
     * Leave it empty temporarily.
     * It will be described in detail in the example "How to delete a linkedlist".
     */
}

void VirtualMemory::print_list()
{
    // cout << "printlist\n";
	for (it=l.begin(); it!=l.end(); ++it)
	{
  		(*it)->printBlock();
	}

    cout << endl;
}