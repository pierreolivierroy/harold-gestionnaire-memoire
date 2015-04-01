// VirtualMemory.cpp
#include "VirtualMemory.h"
#include <iostream>

using namespace std;

VirtualMemory::VirtualMemory()
{
    /* Initialize the head and tail node */
    // _pHead = _pTail = NULL;
    // head = NULL;
}

VirtualMemory::VirtualMemory(int val)
{
    /* Create a new node, acting as both the head and tail node */
    // _pHead = new Node(val);
    // _pTail = _pHead;
}

VirtualMemory::VirtualMemory(size_t size)
{
	// malloc
	cout << "malloc\n";
	// head = new Block(size);
	Block* b = new Block(size);
	l.push_back(b);
	
	print_list();
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
    // Node *p = _pHead;
    
    // /* The list is empty? */
    // if (_pHead == NULL) {
    //     cout << "The list is empty" << endl;
    //     return;
    // }
    
    // cout << "VirtualMemory: ";
    //  A basic way of traversing a linked list 
    // while (p != NULL) { /* while there are some more nodes left */
    //     /* output the value */
    //     cout << p->_value;
    //     /* The pointer moves along to the next one */
    //     p = p->_pNext;
    // }
	int n = 0;
	for (it=l.begin(); it!=l.end(); ++it)
	{
  		(*it)->printBlock();
		// cout << ' ' << n;
		n++;
	}

    // list<Object*>::iterator iter;

    // iter = this->objectlist.begin();

    // while(iter != this->objectlist.end())
    // {
    //     iter->print();
    // }

    cout << endl;
}