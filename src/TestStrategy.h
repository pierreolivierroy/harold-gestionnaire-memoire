// TestStrategy.h
#ifndef TestStrategy_h
#define TestStrategy_h

#include <stdlib.h>
#include "IMemoryManagerStrategy.h"
#include "MemoryManager.h"
#include "FirstFitStrategy.h"
#include "BestFitStrategy.h"

class TestStrategy
{

public:
	MemoryManager* manager;
	IMemoryManagerStrategy* strategy;
	TestStrategy();
	void affiche_etat_memoire();
	void affiche_parametres_memoire(size_t _maxTaillePetit);
};

#endif