#include <iostream>
#include "TestStrategy.h"

using namespace std;

int main()
{
  TestStrategy* ts = new TestStrategy();

  ts->affiche_etat_memoire();
  ts->affiche_parametres_memoire(64);

  return 0;
}