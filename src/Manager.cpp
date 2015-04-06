#include <iostream>
// #include "MemoryManager.h"
// #include "IMemoryManagerStrategy.h"
// #include "FirstFitStrategy.h"
// #include "LinkedList.h"
// #include <list>
#include "TestStrategy.h"

using namespace std;

int main()
{
  cout << "Hello World\n";

  TestStrategy* ts = new TestStrategy();

  ts->affiche_etat_memoire();
  ts->affiche_parametres_memoire(64);

  return 0;
}