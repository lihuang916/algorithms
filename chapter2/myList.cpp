/* myList.cpp
 * Implementation of class MyList
 */

#include <iostream>
#include <cstdlib>
#include <cstring>
#include "myList.h"

MyList::MyList() {
    Node* dummy = new Node;
    dummy->next = nullptr;
    head_ = dummy;
    size_ = 0;
}
 
MyList::MyList(const MyList& list) {
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

MyList::MyList(int data, size_t len) {
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

MyList::~MyList() {
    Node* tmp = head_->next;
    while (tmp != nullptr) {
        Node* tmp1 = tmp;
        tmp = tmp->next;
        delete tmp1;
    }
}

size_t MyList::size() const {
    return size_;
}

bool MyList::isEmpty() const {
    return size_ == 0;
}

int MyList::getAt(size_t index) const {
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

void MyList::pushFront(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = head_->next;
    head_->next = newNode;
    size_++;
}

void MyList::pushBack(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;

    Node* tmp = head_;
    while (tmp->next != nullptr)
        tmp = tmp->next;

    tmp->next = newNode;
    size_++;
}

int MyList::popFront() {
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

int MyList::popBack() {
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

void MyList::insertAt(size_t index, int data) {
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

void MyList::removeAt(size_t index) {
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

MyList MyList::rmDup() {

}

void MyList::sort(bool isAscend) {

}

MyList MyList::subList(size_t pos, size_t len) const {


}

bool MyList::isCircular() {

}

Node* loopStartAt() {

}

void MyList::printList() const {
    if (head_->next == nullptr) {
        std::cout << "printList error: empty list!" << std::endl;
        return;
    }

    std::cout << "Printing list:" << std::endl;
    Node* tmp = head_->next;
    while (tmp != nullptr) {
        std::cout << tmp->data << ", ";    
        tmp = tmp->next;
    }
    std::cout << std::endl;
}





