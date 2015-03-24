#include <iostream>
#include "IMemoryManager.h"
#include "FirstFitManager.h"
#include "LinkedList.h"

using namespace std;

int main()
{
   cout << "Hello World\n";

   IMemoryManager* manager = new FirstFitManager();

   manager->memAlloc();

   /* Create an empty list */
    LinkedList list1;
    cout << "Created an empty list named list1." << endl;
    /* output the result */
    cout << "list1:" << endl;
    list1.print_list();
    
    /* Create a list with only one node */
    LinkedList list2(10);
    cout << "Created a list named list2 with only one node." << endl;
    /* output the result */
    cout << "list2:" << endl;
    list2.print_list();

   return 0;
}