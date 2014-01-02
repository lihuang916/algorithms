/* myList.cpp
 * Implementation of class MyList
 */

#include <iostream>
#include <cstdlib>
#include "myList.h"

MyList::MyList() {
  _head = nullptr;
  _size = 0;
}
 
MyList::MyList(const MyList& list) {
  

}

MyList::MyList(int data, unsigned int len) {


}

MyList::~MyList() {


}

unsigned int MyList::size() const {
  return _size;
}

int MyList::getAt(unsigned int index) const {
  if (index >= _size) {
    std::cout << "Error: out of range!" << std::endl;
    exit(1);
  }

  Node* tmp = _head;
  while
}

void MyList::pushFront(int data) {

}

void MyList::pushBack(int data) {

}

int MyList::popFront() {

}

int MyList::popBack() {

}

void MyList::insertAt(unsigned int index) {

}

void MyList::removeAt(unsigned int index) {

}

MyList MyList::rmDup() {

}

void MyList::sort(bool isAscend) {

}

MyList MyList::subList(unsigned int pos, unsigned int len) const {


}

bool MyList::isCircular() {

}

Node* loopStartAt() {

}

void MyList::printList() const {
  
}





