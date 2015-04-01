// Block.cpp
#include "Block.h"
#include <iostream>

using namespace std;

Block::Block(size_t _size)
{
	size = _size;
	address = (intptr_t) malloc(size);
	free = true;
	// next = NULL;
}

Block::Block(size_t _size, intptr_t _address, bool _free)
{
	size = _size;
	address = _address;
	free = _free;
}

Block::~Block()
{

}

void Block::printBlock()
{
	cout << "Size: " << size << " octets Address: " << address << " Free: " << free << "\n";
}

void Block::getValue()
{

}

size_t Block::getSize()
{
	return size;
}
intptr_t Block::getAddress()
{
	return address;
}
bool Block::isFree()
{
	return free;
}

// Block* Block::getNext()
// {
// 	return next;
// }