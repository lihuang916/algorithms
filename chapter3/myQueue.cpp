/* myQueue.cpp
 * Implementation of class MyQueue
 */

#include <iostream>
#include <cstdlib>
#include "myQueue.h"

MyQueue::MyQueue() : size_(0) { }

MyQueue::~MyQueue() { }

int MyQueue::size() const {
    return size_;
}

bool MyQueue::isEmpty() const {
    return size_ == 0;
}

void MyQueue::enqueue(int elem) {
    if (enqStack.isEmpty())
        moveDataToenq();

    enqStack.push(elem);
    size_++;
}

int MyQueue::dequeue() {
    if (size_ == 0) {
        std::cout << "dequeue error: queue is empty!" << std::endl;
        exit(1);
    }

    if (deqStack.isEmpty())
        moveDataTodeq();        
    size_--;
    return deqStack.pop();
}

int MyQueue::front() {
    if (size_ == 0) {
        std::cout << "front error: queue is empty!" << std::endl;
        exit(1);
    }

    if (enqStack.isEmpty())
        moveDataToenq();    

    return enqStack.peek();
}

int MyQueue::back() {
    if (size_ == 0) {
        std::cout << "back error: queue is empty!" << std::endl;
        exit(1);
    }

    if (deqStack.isEmpty())
        moveDataTodeq();      
    
    return deqStack.peek();
}

void MyQueue::printQueue() {
    if (enqStack.isEmpty())
        moveDataToenq();

    std::cout << "Printing queue:" << std::endl;
    enqStack.printStack();
}

void MyQueue::moveDataTodeq() {
    while (!enqStack.isEmpty())
        deqStack.push(enqStack.pop());
}

void MyQueue::moveDataToenq() {
    while (!deqStack.isEmpty())
        enqStack.push(deqStack.pop());
}
