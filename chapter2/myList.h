/* myList.h 
 * Linked list
 */

#ifndef MYLIST_H
#define MYLIST_H

struct Node {
    int data;
    Node* next;
};

class MyList {
  public:
    MyList();

    MyList(const MyList& list); 

    MyList(int data, size_t len);

    ~MyList();

    size_t size() const;

    bool isEmpty() const;

    int getAt(size_t index) const;

    void setAt(size_t index, int data);

    void pushFront(int data);

    void pushBack(int data);

    int popFront();

    int popBack();

    void insertAt(size_t index, int data);

    void removeAt(size_t index);

    void rmDup();

    void sort(bool isAscend = true);

    MyList subList(size_t pos = 0, size_t len = -1) const;

    bool isCircular();

    int loopStartAt();

    void makeCircular(size_t pos = 0);

    void printList(size_t maxlen = -1) const;
      
  private:
    Node* head_;
    int size_;
};

#endif
