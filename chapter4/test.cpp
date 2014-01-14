/* test.cpp */

#include <iostream>
#include "BST.h"
#include "Graph.h"

int main() {
    int list2[] = {50, 25, 80, 10, 35, 60, 90, 5, 15, 27, 45, 55, 65, 85, 95, 82, 88, 100};
    int list1[] = {50, 25, 80, 10, 35, 90, 27, 45, 85, 95, 82, 88};
    int list3[] = {0, 10, 20, 30, 40, 50, 60, 70, 80};
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



    std::vector<int> vec1(list3, list3 + sizeof(list3) / sizeof(int));
    Digraph<int> g1(vec1);
    g1.addEdge(0,1);
    g1.addEdge(0,3);
    g1.addEdge(0,4);
    g1.addEdge(1,5);
    g1.addEdge(2,1);
    g1.addEdge(2,3);
    g1.addEdge(3,2);
    g1.addEdge(3,7);
    g1.addEdge(4,7);
    g1.addEdge(5,6);
    g1.addEdge(5,8);
    g1.addEdge(6,1);
    g1.addEdge(6,2);
    g1.addEdge(8,7);

    std::cout << "depth first search: " << g1.depthFirstSearch(20, 0) << std::endl;
    g1.printGraph();
    std::cout << "depth first traversal: " << std::endl;
    g1.depthFirstTraversal(0);
  
    std::cout << "breadth first traversal: " << std::endl;
    g1.breadthFirstTraversal(0);
  
    std::cout << "get distance by DFS: " << g1.getDistanceByDFS(1, 7) << std::endl;
    std::cout << "get min distance by BFS: " << g1.getMinDistanceByBFS(1, 7) << std::endl;
   

    return 0;
}
