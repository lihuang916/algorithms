/* test.cpp 
 * test cases for class MyStack and MyQueue
 */

#include <iostream>
#include "myStack.h"
#include "stacks.h"
#include "setofstacks.h"
#include "myQueue.h"

int main() {
    MyStack stack1;
    int i;
    for (i = 0; i < 1000L; i++)
        stack1.push(i);
    for (i = 0; i < 990L; i++)
        stack1.pop();
    stack1.printStack();
 


    MaxMinStack stack2;
    stack2.push(1);
    stack2.push(3);
    stack2.push(2);
    stack2.push(200);
    stack2.push(-200);
    std::cout << "Max: " << stack2.getMax() << std::endl;
    std::cout << "Min: " << stack2.getMin() << std::endl;




    SetOfStacks* stack3 = new SetOfStacks;
    for (i = 0; i < 100000; i++)
        stack3->push(i);
    for (i = 0; i < 99900; i++)
        stack3->pop();
    stack3->printStack();
    for (i = 0; i < 55; i++)
        stack3->popAt(2);
    stack3->printStack();
    delete stack3;


    MyQueue queue1;
    for (i = 0; i < 10000; i++)
        queue1.enqueue(i);
    for (i = 0; i < 9990; i++)
        queue1.dequeue();

    queue1.printQueue();
    std::cout << "front: " << queue1.front() << std::endl;
    std::cout << "back: " << queue1.back() << std::endl;


    return 0;
}
