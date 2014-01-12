/* test.cpp */

#include <iostream>
#include "BST.h"

int main() {
    int list2[] = {50, 25, 80, 10, 35, 60, 90, 5, 15, 27, 45, 55, 65, 85, 95, 82, 88, 100};
    int list1[] = {50, 25, 80, 10, 35, 90, 27, 45, 85, 95, 82, 88};
    std::vector<int> vec(list1, list1 + sizeof(list1) / sizeof(int));
    BST<int> myBST;
    myBST.insert(vec);

    std::cout << "BST size: " << myBST.size() << std::endl;
    std::cout << "BST height: " << myBST.height() << std::endl;
    std::cout << "search result: " << myBST.search(88) << std::endl;

    
  //  for (i = 0; i < 70; i++) 
   //     myBST.recursiveRemove(i);
    myBST.preorderTraversal(std::cout);
    myBST.iterativePreorder(std::cout);
    myBST.inorderTraversal(std::cout);
    myBST.iterativeInorder(std::cout);
    myBST.postorderTraversal(std::cout);
    myBST.iterativePostorder(std::cout);

    std::cout << "tree is balanced? " << myBST.isBalance() << std::endl;
    
    std::vector<std::list<int> *>* listVec = myBST.createLists();
    for (std::vector<std::list<int> *>::iterator it = listVec->begin(), ite = listVec->end(); it != ite; ++it) {
        std::cout << "list:" << std::endl;
        for (std::list<int>::iterator lit = (*it)->begin(), lite = (*it)->end(); lit != lite; ++lit) {
        std::cout << *lit << ", ";
        }
        std::cout << std::endl;
    }

    std::cout << "find first common ancestor: " << myBST.findFirstCommonAncestor(45, 88) << std::endl;
    return 0;
}
