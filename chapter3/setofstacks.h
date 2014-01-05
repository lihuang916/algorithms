/* setofstacks.h
 * A class containing a set of stacks and act as a single stack
 * Implemented on top of std::vector
 */

#include <vector>
#include "myStack.h"

#ifndef SETOFSTACK_H
#define SETOFSTACK_H

#define CAPACITY 10

class SetOfStacks {
  public:
    SetOfStacks();

    ~SetOfStacks();

    int size() const;

    bool isEmpty() const;

    void push(int elem);

    int pop();

    int popAt(int index);

    int peek() const;

    void printStack() const;

  private:
    std::vector<MyStack *> stackArr;
    int size_;
};

#endif
