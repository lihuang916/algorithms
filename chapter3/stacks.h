/* stacks.h 
 * extensions from basic stack
 */

#include "myStack.h"

#ifndef STACKS_H
#define STACKS_H

class MaxMinStack : public MyStack {
  public:
    MaxMinStack();

    ~MaxMinStack();

    void push(int elem);

    int pop();

    int getMin() const;

    int getMax() const;

  private:
    MyStack minStack;
    MyStack maxStack;
};

#endif
