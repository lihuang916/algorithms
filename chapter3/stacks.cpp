/* stacks.cpp
 * Implementations of different kinds of stacks extended from basic stack
 */

#include <iostream>
#include <cstdlib>
#include "stacks.h"

MaxMinStack::MaxMinStack() {

}

MaxMinStack::~MaxMinStack() {

}

void MaxMinStack::push(int elem) {
    MyStack::push(elem);
    if (minStack.isEmpty())
        minStack.push(elem);
    else {
        int n = minStack.peek();
        if (n > elem)
            minStack.push(elem);
        else 
            minStack.push(n);
    }

    if (maxStack.isEmpty())
        maxStack.push(elem);
    else {
        int n = maxStack.peek();
        if (n < elem)
            maxStack.push(elem);
        else 
            maxStack.push(n);
    }
}

int MaxMinStack::pop() {
    if (isEmpty()) {
        std::cout << "pop error: stack is empty!" << std::endl;
        exit(1);
    }
    minStack.pop();
    maxStack.pop();
    return MyStack::pop();
}

int MaxMinStack::getMin() const {
    return minStack.peek();
}

int MaxMinStack::getMax() const {
    return maxStack.peek();
}
