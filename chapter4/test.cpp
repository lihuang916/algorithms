/* test.cpp */

#include <iostream>
#include "BST.h"

int main() {
    BST<int> myBST;
    int list[] = {50, 25, 80, 10, 35, 90, 27, 45, 85, 95, 82, 88};
    std::vector<int> vec(list, list + sizeof(list) / sizeof(int));
    myBST.insert(vec);

    std::cout << "BST size: " << myBST.size() << std::endl;
    std::cout << "search result: " << myBST.search(45) << std::endl;

    
  //  for (i = 0; i < 70; i++) 
   //     myBST.recursiveRemove(i);
    myBST.preorderTraversal(std::cout);
    myBST.iterativePreorder(std::cout);
    myBST.inorderTraversal(std::cout);
    myBST.iterativeInorder(std::cout);
    myBST.postorderTraversal(std::cout);
    myBST.iterativePostorder(std::cout);
    return 0;
}
