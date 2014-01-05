/* setofstacks.cpp
 * Implementation of class SetOfStacks
 */

#include <iostream>
#include <cstdlib>
#include "setofstacks.h"

SetOfStacks::SetOfStacks() : size_(0) {

}

SetOfStacks::~SetOfStacks() {
    for (std::vector<MyStack*>::iterator it = stackArr.begin(), ite = stackArr.end(); it != ite; ++it) {
        delete (*it);
    }
}

int SetOfStacks::size() const {
    return size_;
}

bool SetOfStacks::isEmpty() const {
    return size_ == 0;
}

void SetOfStacks::push(int elem) {
    if (stackArr.empty() || stackArr.back()->size() == CAPACITY) {
        MyStack* newStack = new MyStack;
        newStack->push(elem);
        stackArr.push_back(newStack);
    }
    else
        stackArr.back()->push(elem);
    size_++;
}

int SetOfStacks::pop() {
    if (size_ == 0) {
        std::cout << "pop error: stack is empty!" << std::endl;
        exit(1);
    }
    
    int retVal = stackArr.back()->pop();
    if (stackArr.back()->isEmpty()) 
        stackArr.pop_back();
    size_--;
    return retVal;
}

int SetOfStacks::popAt(int index) {
    if (index >= stackArr.size()) {
        std::cout << "popAt error: out of range!" << std::endl;
        exit(1);
    }
    
    int retVal = stackArr[index]->pop();
    if (stackArr[index]->isEmpty()) {
        delete stackArr[index];
        stackArr.erase(stackArr.begin() + index);
    }
    return retVal;
}

int SetOfStacks::peek() const {
    return stackArr.back()->peek();
}

void SetOfStacks::printStack() const {
    std::cout << "Printing set of stacks: " << std::endl;
    for (std::vector<MyStack*>::const_iterator it = stackArr.begin(), ite = stackArr.end(); it != ite; ++it) {
        (*it)->printStack();
    }
}   

