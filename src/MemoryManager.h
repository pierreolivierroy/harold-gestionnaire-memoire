// MemoryManager.h
#ifndef MemoryManager_h
#define MemoryManager_h

#include <stdlib.h>
#include "IMemoryManagerStrategy.h"
#include "VirtualMemory.h"

class MemoryManager
{
private:
	static const size_t size = 1024;
	VirtualMemory* vMem;

public:
	MemoryManager();
	// MemoryManager(IMemoryManagerStrategy _strategy);
	void initmem();
	intptr_t executeStrategy(IMemoryManagerStrategy *strategy, int _size);
	void liberemem();
	int nbloclibres();
	int nblocalloues();
	int memlibre();
	int mem_pgrand_libre();
	int mem_small_free(int _maxTaillePetit);
	bool mem_est_alloue(/*pOctet*/);
};

#endif

// initmem() :
// Initialise les structures de données du gestionnaire.

// SEULE FONCTION QUI VA CHANGER SELON LA STRATÉGIE
// pBloc = alloumem() :

// liberemem(pBloc) :
// Cette fonction libère un bloc de mémoire similaire à free().

// nBlocs = nbloclibres() :
// Cette fonction retourne le nombre de blocs de mémoire libres

// nBlocAll = nblocalloues() :
// Cette fonction retourne le nombre de blocs alloués présentement

// mLib = memlibre() :
// Combien de mémoire libre (non allouée) au total.

// tGraBloc = mem_pgrand_libre() : 
// Taille du plus grand bloc libre.

// mem_small_free(maxTaillePetit) :
// Combien de petits blocs (plus petit que maxTaillePetit) non alloués y a-t-il présentement en mémoire?

// mem_est_alloue(pOctet) :
// Est-ce qu’un octet (byte) particulier est allouée