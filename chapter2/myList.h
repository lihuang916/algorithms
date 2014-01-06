/* myList.h 
 * Linked list
 */

#ifndef MYLIST_H
#define MYLIST_H

template <typename ElemType>
class MyList {
public:
    struct Node {
        ElemType data;
        Node* next;
    };

    MyList();

    MyList(const MyList<ElemType>& list); 

    MyList(ElemType data, size_t len);

    ~MyList();

    size_t size() const;

    bool isEmpty() const;

    ElemType getAt(size_t index) const;

    void setAt(size_t index, ElemType data);

    void pushFront(ElemType data);

    void pushBack(ElemType data);

    ElemType popFront();

    ElemType popBack();

    void insertAt(size_t index, ElemType data);

    void removeAt(size_t index);

    void rmDup();

    void sort(bool isAscend = true);

    MyList<ElemType> subList(size_t pos = 0, size_t len = -1) const;

    bool isCircular();

    ElemType loopStartAt();

    void makeCircular(size_t pos = 0);

    MyList<ElemType> operator+(const MyList<ElemType>& list) const; 

    void printList(size_t maxlen = -1) const;
      
private:
    Node* head_;
    int size_;
};

#include "myList.cpp"

#endif
