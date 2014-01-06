/* myList.cpp
 * Implementation of class MyList
 */

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <set>

template <typename ElemType>
MyList<ElemType>::MyList() {
    Node* dummy = new Node;
    dummy->next = nullptr;
    head_ = dummy;
    size_ = 0;
}
 
template <typename ElemType>
MyList<ElemType>::MyList(const MyList<ElemType>& list) {
    Node* dummy = new Node;
    dummy->next = nullptr;
    head_ = dummy;

    Node* tmp = head_;
    int i;
    for (i = 0; i < list.size(); i++) {
        Node* newNode = new Node;
        newNode->data = list.getAt(i);
        newNode->next = nullptr;
        tmp->next = newNode;
        tmp = tmp->next;
    }

    size_ = list.size();
}

template <typename ElemType>
MyList<ElemType>::MyList(ElemType data, size_t len) {
    Node* dummy = new Node;
    dummy->next = nullptr;
    head_ = dummy;
    Node* tmp = head_;
    int i;
    for (i = 0; i < len; i++) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = nullptr;
        tmp->next = newNode;
        tmp = newNode;
    }
    
    size_ = len;
}

template <typename ElemType>
MyList<ElemType>::~MyList() {
    Node* tmp = head_->next;
    int size = size_;
    while (tmp != nullptr && size > 0) {
        Node* tmp1 = tmp;
        tmp = tmp->next;
        delete tmp1;
        size--;
    }
}

template <typename ElemType>
size_t MyList<ElemType>::size() const {
    return size_;
}

template <typename ElemType>
bool MyList<ElemType>::isEmpty() const {
    return size_ == 0;
}

template <typename ElemType>
ElemType MyList<ElemType>::getAt(size_t index) const {
    if (index >= size_) {
        std::cout << "getAt error: out of range!" << std::endl;
        exit(1);
    }

    Node* tmp = head_;
    int i;
    for (i = 0; i < index; i++)
        tmp = tmp->next;
    
    return tmp->next->data;
}

template <typename ElemType>
void MyList<ElemType>::setAt(size_t index, ElemType data) {
    if (index >= size_) {
        std::cout << "setAt error: out of range!" << std::endl;
        exit(1);
    }

    Node* tmp = head_;
    int i;
    for (i = 0; i < index; i++)
        tmp = tmp->next;
    
    tmp->next->data = data;
}

template <typename ElemType>
void MyList<ElemType>::pushFront(ElemType data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = head_->next;
    head_->next = newNode;
    size_++;
}

template <typename ElemType>
void MyList<ElemType>::pushBack(ElemType data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;

    Node* tmp = head_;
    while (tmp->next != nullptr)
        tmp = tmp->next;

    tmp->next = newNode;
    size_++;
}

template <typename ElemType>
ElemType MyList<ElemType>::popFront() {
    if (head_->next == nullptr) {
        std::cout << "popFront error: list is empty!" << std::endl;
        exit(1);
    }

    int retVal = head_->next->data;
    Node* tmp = head_->next;
    head_->next = head_->next->next;
    delete tmp;
    size_--;
    return retVal;
}

template <typename ElemType>
ElemType MyList<ElemType>::popBack() {
   if (head_->next == nullptr) {
        std::cout << "popBack error: list is empty!" << std::endl;
        exit(1);
    }
 
    Node* tmp = head_;
    while (tmp->next->next != nullptr)
        tmp = tmp->next;

    Node* tmp1 = tmp->next;
    int retVal = tmp1->data;
    tmp->next = nullptr;
    delete tmp1;
    size_--;
    return retVal;
}

template <typename ElemType>
void MyList<ElemType>::insertAt(size_t index, ElemType data) {
   if (index >= size_) {
        std::cout << "insertAt error: out of range!" << std::endl;
        exit(1);
    }

    Node* tmp = head_;
    int i;
    for (i = 0; i < index + 1; i++)
        tmp = tmp->next;

    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = tmp->next;
    tmp->next = newNode;
    size_++;
}

template <typename ElemType>
void MyList<ElemType>::removeAt(size_t index) {
    if (index >= size_) {
        std::cout << "removeAt error: out of range!" << std::endl;
        exit(1);
    }

    Node* tmp = head_;
    int i;
    for (i = 0; i < index; i++)
        tmp = tmp->next;

    Node* tmp1 = tmp->next;
    tmp->next = tmp1->next;
    delete tmp1;
    size_--;
}

template <typename ElemType>
void MyList<ElemType>::rmDup() {
    /* traverse the list and keep a set of traversed, remove duplicate data */
    Node* tmp = head_;
    std::set<int> dataSet;
    while (tmp->next != nullptr) {
        if (dataSet.find(tmp->next->data) != dataSet.end()) {
            // if already contained in set, remove the node
            Node* tmp1 = tmp->next;
            tmp->next = tmp1->next;
            delete tmp1;
            size_--;
        } else {
            dataSet.insert(tmp->next->data);
            tmp = tmp->next;
        }
    }
}

template <typename ElemType>
void MyList<ElemType>::sort(bool isAscend) {
    /* use selection sort to sort the list */
    Node* p = head_;
    Node* tmp;
    while (p->next != nullptr) {
        Node* mNode;
        ElemType m;
        tmp = p->next;
        m = tmp->data;
        mNode = tmp;
        while (tmp != nullptr) {
            if (isAscend ? tmp->data < m : tmp->data > m) {
                mNode = tmp;
                m = tmp->data;
            }
            tmp = tmp->next;
        }

        mNode->data = p->next->data;
        p->next->data = m;
        p = p->next;
    }
}

template <typename ElemType>
MyList<ElemType> MyList<ElemType>::subList(size_t pos, size_t len) const {
    if (pos >= size_ || pos > len) {
        std::cout << "subList error: wrong position!" << std::endl;
        exit(1);
    }

    int last = len > size_ - 1 ? size_ - 1 : len;
    MyList<ElemType> newList;
    Node* tmp = head_;
    int i = 0;
    for (; i < pos + 1; i++)
        tmp = tmp->next;
    for (; i < last + 2; i++) {
        newList.pushBack(tmp->data);
        tmp = tmp->next;
    }
    
    return newList;
}

template <typename ElemType>
bool MyList<ElemType>::isCircular() {
    Node* tmp = head_;
    Node* tmp1 = tmp;
    while (tmp1->next != nullptr && tmp1->next->next != nullptr) {
        tmp = tmp->next;
        tmp1 = tmp1->next->next;
        if (tmp == tmp1) return true;
    }

    return false;
}

template <typename ElemType>
ElemType MyList<ElemType>::loopStartAt() {
    // if not circular, return -1
    if (!isCircular())
        return -1;

    // keep a set of pointers to Node
    std::set<Node *> nodeSet;
    Node* tmp = head_->next;
    while (tmp != nullptr) {
        if (nodeSet.find(tmp) == nodeSet.end())
            nodeSet.insert(tmp);
        else
            break;
        tmp = tmp->next;
    }   
    
    int i = 0;
    Node* p = head_->next;
    while (p != tmp) {
        i++;
        p = p->next;
    }

    return i;
}

template <typename ElemType>
void MyList<ElemType>::makeCircular(size_t pos) {
    if (pos >= size_) {
        std::cout << "makeCircular error: out of range!" << std::endl;
        exit(1);
    }

    Node* tmp = head_;
    Node* tmp1 = head_;

    int i;
    for (i = 0; i < pos; i++)
        tmp = tmp->next;
    while (tmp1->next != nullptr)
        tmp1 = tmp1->next;
    
    tmp1->next = tmp->next; 
}

template <typename ElemType>
MyList<ElemType> MyList<ElemType>::operator+(const MyList<ElemType>& list) const {
    int len = list.size() > size_ ? size_ : list.size();
    MyList<ElemType> sumList;
    int i;
    for (i = 0; i < len; i++)
        sumList.pushBack(list.getAt(i) + getAt(i));

    return sumList;
}

template <typename ElemType>
void MyList<ElemType>::printList(size_t maxlen) const {
    if (head_->next == nullptr) {
        std::cout << "printList error: empty list!" << std::endl;
        return;
    }

    std::cout << "Printing list:" << std::endl;
    Node* tmp = head_->next;
    while (tmp != nullptr && maxlen > 0) {
        std::cout << tmp->data << ", ";    
        tmp = tmp->next;
        maxlen--;
    }
    std::cout << std::endl;
}


