// source: http://stackoverflow.com/questions/318064/how-do-you-declare-an-interface-in-c
class IMemoryManager
{
	public:
		virtual ~IMemoryManager() {}
		virtual void initMem() = 0;
		virtual void memAlloc() = 0;
		virtual void freeMem(/*block*/) = 0;
		virtual int getFreeBlockCount() = 0;
		virtual int getBlockCount() = 0;
		virtual int getFreeMem() = 0;
		virtual int getBiggestFreeBlock() = 0;
		virtual int getSmallFreeBlockCount(int) = 0;
		virtual bool isMemAlloc() = 0;
};

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