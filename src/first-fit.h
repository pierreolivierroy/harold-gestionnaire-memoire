// initmem() :
// Initialise les structures de données du gestionnaire.

// pBloc = alloumem() :
// Cette fonction alloue un nouveau bloc de mémoire.

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