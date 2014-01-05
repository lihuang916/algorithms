/* myQueue.h
 * A queue implemented using two stacks
 */

#include "myStack.h"

#ifndef MYQUEUE_H
#define MYQUEUE_H

class MyQueue {
  public:
    MyQueue();

    ~MyQueue();

    int size() const;

    bool isEmpty() const;

    void enqueue(int elem);

    int dequeue();

    int front();

    int back();

    void printQueue();

  private:
    MyStack enqStack;
    MyStack deqStack;
    int size_;

    void moveDataTodeq();
    void moveDataToenq();
};

#endif

