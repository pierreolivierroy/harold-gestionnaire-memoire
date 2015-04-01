#include <iostream>
#include "MemoryManager.h"
// #include "IMemoryManagerStrategy.h"
#include "FirstFitStrategy.h"
// #include "LinkedList.h"
#include <list>

using namespace std;

int main()
{
   cout << "Hello World\n";

   IMemoryManagerStrategy* strategy = new FirstFitStrategy();
   MemoryManager* manager = new MemoryManager();

   intptr_t b1 = manager->executeStrategy(strategy, 8);
   intptr_t b2 = manager->executeStrategy(strategy, 512);
   cout << "b1 " << b1;
   cout << "b2 " << b2;

   // ------------------------------------------------------
   // http://www.cplusplus.com/reference/list/list/insert/
   // list<int> maliste;
   // list<int>::iterator it;
   // maliste.push_back(99);
   // maliste.push_back(1201);

   //  cout << "mylist contains:";
   //  for (it=maliste.begin(); it!=maliste.end(); ++it)
   //    cout << ' ' << *it;
   //  cout << '\n';
    // ------------------------------------------------------

   // manager->executeStrategy(strategy);

   // /* Create an empty list */
   //  LinkedList list1;
   //  cout << "Created an empty list named list1." << endl;
   //  /* output the result */
   //  cout << "list1:" << endl;
   //  list1.print_list();
    
   //   Create a list with only one node 
   //  LinkedList list2(10);
   //  cout << "Created a list named list2 with only one node." << endl;
   //  /* output the result */
   //  cout << "list2:" << endl;
   //  list2.print_list();

   return 0;
}