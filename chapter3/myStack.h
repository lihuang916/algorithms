/* myStack.h 
 * class MyStack
 */

#ifndef MYSTACK_H
#define MYSTACK_H

class MyStack {
  public:
    MyStack();

    ~MyStack();
    
    int size() const;

    bool isEmpty() const;

    void push(int elem);

    int pop();

    int peek() const;

    void printStack() const;

  private:
    int stackSize;

    int arrlen;

    int* arr;
    
    void doubleMem();

    void halfMem();
};

#endif

