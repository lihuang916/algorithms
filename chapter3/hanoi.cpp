/* hanoi.cpp 
 * The classic problem of Tower of Hanoi
 */

#include <iostream>
#include <cstdlib>
#include "myStack.h"

#define NUMSTICKS 30

void moveOneStick(MyStack* from, MyStack* to) {
    if (from->isEmpty() || (!to->isEmpty() && from->peek() > to->peek())) {
        std::cout << "move error!" << std::endl;
        exit(1);
    }
    
    to->push(from->pop());
}

void moveSticks(int num, MyStack* from, MyStack* to, MyStack* theOther) {
    if (num <= 0) 
        return;
    if (num == 1) {
        moveOneStick(from, to);
        return;
    }

    moveSticks(num - 1, from, theOther, to);
    moveOneStick(from, to);
    moveSticks(num - 1, theOther, to, from);
}

int main() {
    MyStack rod1;   
    MyStack rod2;   
    MyStack rod3;   
    
    int i;
    for (i = NUMSTICKS; i > 0; i--)
        rod1.push(i);
    
    moveSticks(25, &rod1, &rod3, &rod2);
    rod1.printStack();
    rod2.printStack();
    rod3.printStack();

    return 0;
}

