// Block.h
#ifndef Block_h
#define Block_h

#include <stdlib.h>

class Block
{
private:
	// size_t size;
	// intptr_t address;
	// bool free;
	// Block* next;

public:
	size_t size;
	intptr_t address;
	bool free;
	Block();
	Block(size_t _size);
	Block(size_t _size, intptr_t _address, bool _free);
	~Block();
	void printBlock();
	void getValue();
	size_t getSize();
	intptr_t getAddress();
	bool isFree();
	// Block* getNext();
};

#endif