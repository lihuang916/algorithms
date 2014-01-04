/* test.cpp
 * test cases for MyList
 */

#include <iostream>
#include "myList.h"

int main() {
    MyList list1;
    size_t i;

    for (i = 0; i < 2000; i++) {
        list1.pushBack(i);
    }
 
    for (i = 0; i < 1990; i++) {
        list1.popBack();
    }
  
    std::cout << "list size: " << list1.size() << std::endl;
    list1.printList(); 

    MyList* list2 = new MyList(list1);
    list2->printList();
    delete list2;

    return 0;
}
