// VirtualMemory.cpp
#include "VirtualMemory.h"
#include <iostream>

using namespace std;

VirtualMemory::VirtualMemory()
{
 
}

VirtualMemory::VirtualMemory(size_t size)
{
	Block* b = new Block(size);
	l.push_back(b);
}

VirtualMemory::~VirtualMemory()
{

}

void VirtualMemory::print_list()
{
	for (it=l.begin(); it!=l.end(); ++it)
	{
  		(*it)->printBlock();
	}

    cout << endl;
}