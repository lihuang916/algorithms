/* test.cpp 
 * test cases for class MyStack and MyQueue
 */

#include <iostream>
#include "myStack.h"
#include "myQueue.h"

int main() {
    MyStack stack1;

    int i;
    for (i = 0; i < 100000000L; i++)
        stack1.push(i);

    for (i = 0; i < 99999900L; i++)
        stack1.pop();
    
    stack1.printStack();
    
    return 0;
}
