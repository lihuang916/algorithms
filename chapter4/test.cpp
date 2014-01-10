/* test.cpp */

#include <iostream>
#include "BST.h"

int main() {
    BST<int> myBST;
    int i;
    for (i = 46; i < 100; i++) 
        myBST.insert(i);

    for (i = 0; i < 46; i++) 
        myBST.insert(i);

    std::cout << "BST size: " << myBST.size() << std::endl;
    std::cout << "search result: " << myBST.search(45) << std::endl;

    
    for (i = 0; i < 70; i++) 
        myBST.recursiveRemove(i);
    myBST.preorderTraversal(std::cout);
    myBST.inorderTraversal(std::cout);
    myBST.~BST();
    myBST.postorderTraversal(std::cout);
    return 0;
}
