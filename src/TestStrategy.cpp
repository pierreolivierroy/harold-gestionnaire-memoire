// TestStrategy.cpp
#include "TestStrategy.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

TestStrategy::TestStrategy()
{
    string input = "";
    int strategyNumber = 0;

    manager = new MemoryManager();

    while (true) {
        cout << "Veuillez choisir une stratétie parmi les suivantes: \n";
        cout << "[1] First-fit\n";
        cout << "[2] Best-fit\n";
        cout << "[3] Worst-fit\n";
        cout << "[4] Next-fit\n";
        getline(cin, input);

        stringstream selectedStrategy(input);
        if (selectedStrategy >> strategyNumber)
        {   
            switch(strategyNumber)
            {
                case 1:
                    cout << "Vous avez choisi la stratégie first-fit.\n" << endl;
                    strategy = new FirstFitStrategy();
                    break;
                case 2:
                    cout << "Vous avez choisi la stratégie best-fit.\n" << endl;
                    strategy = new BestFitStrategy();
                    break;
                case 3:
                    cout << "Vous avez choisi la stratégie worst-fit.\n" << endl;
                    strategy = new WorstFitStrategy();
                    break;
                case 4:
                    cout << "Vous avez choisi la stratégie next-fit.\n" << endl;
                    strategy = new NextFitStrategy(manager->vMem);
                    break;
            }
            if(strategyNumber <= 4)
                break;
        }
        cout << "Numéro invalide, essayez de nouveau." << endl;
    }

    cout << "Assignation de blocs de base\n";
    cout << "-------------------------------\n";
    intptr_t b1 = manager->executeStrategy(strategy, 128);
    intptr_t b2 = manager->executeStrategy(strategy, 64);
    intptr_t b3 = manager->executeStrategy(strategy, 128);
    intptr_t b4 = manager->executeStrategy(strategy, 64);
    intptr_t b5 = manager->executeStrategy(strategy, 128);
    intptr_t b6 = manager->executeStrategy(strategy, 64);
    intptr_t b7 = manager->executeStrategy(strategy, 128);
    intptr_t b8 = manager->executeStrategy(strategy, 64);

    manager->liberemem(b2);
    manager->liberemem(b3);
    manager->liberemem(b6);
    manager->liberemem(b7);
    affiche_etat_memoire();

    // ******************************************************************

    intptr_t b9 = manager->executeStrategy(strategy, 64);
    intptr_t b10 = manager->executeStrategy(strategy, 64);
    intptr_t b11 = manager->executeStrategy(strategy, 20);
    intptr_t b12 = manager->executeStrategy(strategy, 128);
    intptr_t b13 = manager->executeStrategy(strategy, 108);
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