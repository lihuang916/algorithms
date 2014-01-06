/* test.cpp
 * test cases for MyList
 */

#include <iostream>
#include "myList.h"

int main() {
    MyList<double> list1;
    size_t i;

    for (i = 0; i < 2000; i++) {
        list1.pushFront(i/4.0);
    }
 
    for (i = 0; i < 1990; i++) {
        list1.popBack();
    }
  
    std::cout << "list size: " << list1.size() << std::endl;
    list1.printList(); 

    MyList<double>* list2 = new MyList<double>(list1);
    list2->sort(1);
    list2->printList();
    delete list2;

    MyList<double> list3 = list1.subList(0, 3) + list1;
    list3.printList();

    MyList<int> list4(1, 2);
    list4.pushBack(4);
    list4.pushBack(4);
    list4.pushBack(5);
    list4.pushBack(5);
    list4.pushBack(5);
    list4.pushBack(7);
    list4.pushBack(6);
    list4.pushBack(6);
    list4.pushBack(7);
    list4.printList();
    list4.rmDup();
    list4.setAt(1, 100);
    list4.sort();
    list4.printList();
    std::cout << "list is circular? " << list4.isCircular() << std::endl;
    list4.makeCircular(2);
    std::cout << "list is circular? " << list4.isCircular() << std::endl;
    std::cout << "list loop starts at: " << list4.loopStartAt() << std::endl;
    list4.printList(20);

    return 0;
}
