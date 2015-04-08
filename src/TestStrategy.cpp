// TestStrategy.cpp
#include "TestStrategy.h"
#include <iostream>

using namespace std;

TestStrategy::TestStrategy()
{
	strategy = new WorstFitStrategy();
    manager = new MemoryManager();

    intptr_t b1 = manager->executeStrategy(strategy, 128);
    intptr_t b2 = manager->executeStrategy(strategy, 128);
    intptr_t b3 = manager->executeStrategy(strategy, 128);
    intptr_t b4 = manager->executeStrategy(strategy, 128);
    intptr_t b5 = manager->executeStrategy(strategy, 128);
    intptr_t b6 = manager->executeStrategy(strategy, 128);
    intptr_t b7 = manager->executeStrategy(strategy, 128);
    intptr_t b8 = manager->executeStrategy(strategy, 128);

    manager->liberemem(b2);
    manager->liberemem(b4);
    manager->liberemem(b6);
    manager->liberemem(b8);

    affiche_etat_memoire();

    intptr_t b9 = manager->executeStrategy(strategy, 64);
    intptr_t b10 = manager->executeStrategy(strategy, 63);
    // intptr_t b11 = manager->executeStrategy(strategy, 63);

    // manager->liberemem(b1);
    // intptr_t b12 = manager->executeStrategy(strategy, 2);

    cout << "\n";
}

void TestStrategy::affiche_etat_memoire()
{
	manager->vMem->print_list();
}
void TestStrategy::affiche_parametres_memoire(size_t _maxTaillePetit)
{
	cout << "\n";
	cout << "Plus grand bloc libre: " << manager->mem_pgrand_libre() << " octets\n";
	cout << "Mémoire libre: " << manager->memlibre() << " octets\n";
	cout << "Blocs libres: " << manager->nbloclibres() << "\n";
    cout << "Blocs alloués: " << manager->nblocalloues() << "\n";
    cout << "Nombre blocs libres plus petits que " << _maxTaillePetit << " octets: " << manager->mem_small_free(_maxTaillePetit) << "\n";
}