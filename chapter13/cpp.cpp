/* cpp.cpp
 * A collection of c++ problems
 */

#include <iostream>
#include <fstream>
#include <string>
#include <list>


// 13-1 Print the last K lines of an input file
void printLastKLines(std::string filename, int k) {
    std::ifstream ifs;
    std::string s;
    std::list<std::string> strList;
    ifs.open(filename, std::ifstream::in);
    
    while (std::getline(ifs, s)) {
        strList.push_back(s);
        if (strList.size() > k)
            strList.pop_front();
    }
    
    while (!strList.empty()) {
        std::cout << strList.front() << std::endl;
        strList.pop_front();
    }
}

// 13-2 Compare and contrast a hash table vs an STL map.
// Hash table:
//     1. Implemented with a hash functions and an array. The hash function takes the key as input 
//        and compute an index into the array where value is saved.
//     2. Keys in hash table are not in order. Support O(1) time search, insert, delete. 
//     3. Need to handle collision, either by open addressing or chaining.
//     4. No support for ordered traversal of keys.
// STL map:
//     1. Implemented by a balanced binary search tree. 
//     2. Order of keys is kept by BST. Support O(logN) time search, insert, delete.
//     3. No collision. Each key resides in one node.
//     4. Support traversing the keys in ascending or decending order, finding the next nearest key, etc. 
//
// When number of elements is small, or operations based order is needed, then STL map is a good choice.
// When number of elements is large, internal order is not needed and performance is a top concern, then 
// hash table is a better choice.



// 13-3 Virtual functions
class Base {
public:
    int a = 1;
    virtual void print() { std::cout << a << std::endl; }
};

class Derived : public Base {
public:
    int b = 2;
    void print() { std::cout << b << std::endl; }
};


// 13-4 Difference between deep copy and shallow copy
// Shallow copy just copies the value of pointers, while not copying the objects pointed to by pointers
// Deep copy also copies the objects pointed to by pointers


// 13-5 Keyword volatile in C
// Tell the compiler that the variable can be changed outside

// 13-6 Name hiding in C++
// Encapsulation

// 13-7 Why does a destructor in base class need to be declared virtual?

// 13-8 Clone a tree

// 13-9 Smart pointer class
template<typename T>
class SP {
public:
    SP() : ptr(nullptr) { }

    SP(T* p) : ptr(p) { rc++; }

    SP(const SP<T>& sp) : ptr(sp.ptr) { rc++; } 

    ~SP() {
        if (--rc == 0) {
            std::cout << "I'm gone )-:" << std::endl;
            delete ptr;
            ptr = nullptr;
        }
    }

    SP& operator= (const SP& sp) {
        if (*sp != this) {
            ptr = sp.ptr;
            rc = sp.rc;
            rc++;
        }
        return *this;
    }

    T& operator* () {
        return *ptr;
    }

    T* operator-> () {
        return ptr;
    }

private:
    T* ptr;
    static unsigned int rc;
};

template<typename T>
unsigned int SP<T>::rc = 0;

int main() {
    std::cout << "Print last k lines of file: " << std::endl;
    printLastKLines("abc", 5);

    std::cout << "Virtual function: " << std::endl;
    Base* base = new Base();
    Derived* derived = new Derived();
    base->print();
    derived->print();
    derived->Base::print();
    Base* b = static_cast<Base*>(derived);
    b->print();

    SP<std::string> sp(new std::string("Hello, I'm a smart pointer!"));
    sp->append(" Yeah!");
    SP<std::string> sp1 = sp;
    
    std::cout << *sp1 << std::endl;
    return 0;
}
