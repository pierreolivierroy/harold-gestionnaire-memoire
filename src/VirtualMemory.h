// source: http://runnable.com/Us5yYIzciVFWAAYA/how-to-create-a-new-linked-list-for-c%2B%2B
// VirtualMemory.h
#ifndef VirtualMemory_h
#define VirtualMemory_h

#include <list>
#include "Block.h"

using namespace std;

// class Node
// {
//     friend class VirtualMemory;
// 	private:
// 	    int _value; /* data, can be any data type, but use integer for easiness */
// 	    Node *_pNext; /* pointer to the next node */
	    
// 	public:
// 	    /* Constructors with No Arguments */
// 	    Node(void)
// 	    : _pNext(NULL)
// 	    { }
	    
// 	    /* Constructors with a given value */
// 	    Node(int val)
// 	    : _value(val), _pNext(NULL)
// 	    { }
	    
// 	    /* Constructors with a given value and a link of the next node */
// 	    Node(int val, Node* next)
// 	    : _value(val), _pNext(next)
// 	    {}
	    
// 	    /* Getters */
// 	    int getValue(void)
// 	    { return _value; }
	    
// 	    Node* getNext(void)
// 	    { return _pNext; }
// };

/* definition of the linked list class */
class VirtualMemory
{
	private:
	    // /* pointer of head node */
	    // Node *_pHead;
	    // /* pointer of tail node */
	    // Node *_pTail;
	    
	public:
		// Block* head;
	    list<Block*> l;
	    list<Block*>::iterator it;
	    /* Constructors with No Arguments */
	    VirtualMemory(void);
	    /* Constructors with a given value of a list node */
	    VirtualMemory(int val);
	    /* Constructors with size_t argument */
	    VirtualMemory(size_t size);
	    /* Destructor */
	    ~VirtualMemory(void);
	    
	    /* Traversing the list and printing the value of each node */
	    void print_list();
};

#endif