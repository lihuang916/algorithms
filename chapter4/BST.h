/* BST.h
 * Binary Search Tree
 */

#ifndef BST_H
#define BST_H

#include <ostream>
#include <iostream>
#include <cstdlib>
#include <stack>
#include <vector>
#include <list>
#include <queue>

template <class ET>
class BST {
private:
    struct Node {
        ET elem;
        Node* left;
        Node* right;
    };
    
public:
    BST();

    BST(const std::vector<ET>& vec);

    ~BST();

    int size() const;
    
    bool isEmpty() const;

    int height() const;

    bool search(const ET& elem) const;

    void insert(const ET& elem);

    void insert(std::vector<ET>& elemVec);

    void remove(const ET& elem);

    void recursiveRemove(const ET& elem);

    void preorderTraversal(std::ostream& out) const;

    void inorderTraversal(std::ostream& out) const;

    void postorderTraversal(std::ostream& out) const;

    void iterativePreorder(std::ostream& out) const;
    
    void iterativeInorder(std::ostream& out) const;
    
    void iterativePostorder(std::ostream& out) const;

    bool isBalance() const;

    void balance();

    std::vector<std::list<ET> *>* createLists() const;

    ET findFirstCommonAncestor(const ET& elem1, const ET& elem2) const;

private:
    Node* root_;
    int size_;

    int getHeight(Node* root) const;

    Node* searchNode(Node* root, const ET& elem) const;

    std::vector<Node*>* searchPath(const ET& elem) const;
    
    void preorderAt(Node* root, std::ostream& out) const;
    
    void inorderAt(Node* root, std::ostream& out) const;
    
    void postorderAt(Node* root, std::ostream& out) const;
    
    void removeFrom(Node*& root, const ET& elem);
    
    void deleteTree(Node*& root);
    
    Node* buildTree(const std::vector<ET>& vec, int begin, int end);
};

template <class ET>
inline BST<ET>::BST() : root_(nullptr), size_(0) { }

template <class ET>
BST<ET>::BST(const std::vector<ET>& vec) {
    root_ = buildTree(vec, 0, vec.size() - 1);
    size_ = vec.size();
}

template <class ET>
BST<ET>::~BST() {
    deleteTree(root_);
    root_ = nullptr;
}

template <class ET>
int BST<ET>::size() const {
    return size_;
}

template <class ET>
bool BST<ET>::isEmpty() const {
    return root_ == nullptr;
}

template <class ET>
int BST<ET>::height() const {
    return getHeight(root_);   
}

template <class ET>
int BST<ET>::getHeight(Node* root) const {
    if (root == nullptr)
        return 0;
    
    int a = getHeight(root->left);
    int b = getHeight(root->right);
    return a > b ? a + 1 : b + 1;
}

template <class ET>
bool BST<ET>::search(const ET& elem) const {
   return searchNode(root_, elem) != nullptr;
}

template <class ET>
class BST<ET>::Node* BST<ET>::searchNode(Node* root, const ET& elem) const {
    Node* tmp = root;
    while (tmp != nullptr) {
        if (tmp->elem == elem)
            return tmp;
        if (tmp->elem < elem)
            tmp = tmp->right;
        else
            tmp = tmp->left;
    }
    
    return nullptr;
}

template <class ET>
std::vector<class BST<ET>::Node*>* BST<ET>::searchPath(const ET& elem) const {
    std::vector<Node*>* path = new std::vector<Node*>;
    Node* tmp = root_;
    while (tmp != nullptr) {
        path->push_back(tmp);
        if (tmp->elem == elem)
            return path;
        if (tmp->elem < elem)
            tmp = tmp->right;
        else
            tmp = tmp->left;
    }
    
    delete path;
    return nullptr;
}

template <class ET>
void BST<ET>::insert(const ET& elem) {
    Node* tmp = root_;
    Node* parent = nullptr;
    Node* newNode = new Node;
    newNode->elem = elem;
    newNode->left = nullptr;
    newNode->right = nullptr;

    if (root_ == nullptr)
        root_ = newNode;
    else {
        while(tmp != nullptr) {
            parent = tmp;
            if (tmp->elem <= elem)
                tmp = tmp->right;
            else 
                tmp = tmp->left;
        }
        if (parent->elem <= elem)
            parent->right = newNode;
        else
            parent->left = newNode;
    }
    size_++;
}

template <class ET>
void BST<ET>::insert(std::vector<ET>& elemVec) {
    int i;
    for (i = 0; i < elemVec.size(); i++) 
        insert(elemVec[i]);
}

template <class ET>
void BST<ET>::remove(const ET& elem) {
    Node* tmp = root_;
    Node* parent = nullptr;
    Node* subtree;

    while (tmp != nullptr) {
        if (tmp->elem == elem)
            break;
        parent = tmp;
        if (tmp->elem < elem)
            tmp = tmp->right;
        else
            tmp = tmp->left;
    }
    
    if (tmp == nullptr) {
        std::cout << "remove error: no such element!" << std::endl;
        exit(1);
    }

    if (tmp->left != nullptr && tmp->right != nullptr) {
        Node* inSuc = tmp->right;
        parent = tmp;
        while (inSuc->left != nullptr) {
            parent = inSuc;
            inSuc = inSuc->left;
        }

        tmp->elem = inSuc->elem;
        tmp = inSuc;
    }

    subtree = tmp->left;
    if (subtree == nullptr)
        subtree = tmp->right;
    if (parent == nullptr)
        root_ = subtree;
    else if (parent->elem <= elem)
        parent->right = subtree;
    else 
        parent->left = subtree;
    delete tmp;
    size_--;
}

template <class ET>
void BST<ET>::recursiveRemove(const ET& elem) {
    removeFrom(root_, elem);
    size_--;
}

template <class ET>
void BST<ET>::removeFrom(Node*& root, const ET& elem) {
    if (root == nullptr) {
        std::cout << "remove error: no such element!" << std::endl;
        exit(1);
    }
    
    if (root->elem == elem) {
        if (root->left == nullptr) {
            Node* tmp = root;
            root = root->right;
            delete tmp;
        }
        else if (root->right == nullptr) {
            Node* tmp = root;
            root = root->left;
            delete tmp;
        }
        else {
            Node* tmp = root->right;
            while (tmp->left != nullptr)
                tmp = tmp->left;
            root->elem = tmp->elem;
            removeFrom(root->right, tmp->elem);
        }           
    }
    else if (root->elem < elem)
        removeFrom(root->right, elem);
    else
        removeFrom(root->left, elem);
}
    
template <class ET>
void BST<ET>::preorderTraversal(std::ostream& out) const {
    std::cout << "preorder traversal: " << std::endl;
    preorderAt(root_, out);
    std::cout << std::endl;
}

template <class ET>
void BST<ET>::preorderAt(Node* root, std::ostream& out) const {
    if (root != nullptr) {
        out << root->elem << ", ";
        preorderAt(root->left, out);
        preorderAt(root->right, out);
    }
}

template <class ET>
void BST<ET>::inorderTraversal(std::ostream& out) const {
    std::cout << "inorder traversal: " << std::endl;
    inorderAt(root_, out);
    std::cout << std::endl;
}

template <class ET>
void BST<ET>::inorderAt(Node* root, std::ostream& out) const {
    if (root != nullptr) {
        inorderAt(root->left, out);
        out << root->elem << ", ";
        inorderAt(root->right, out);
    }
}

template <class ET>
void BST<ET>::postorderTraversal(std::ostream& out) const {
    std::cout << "postorder traversal: " << std::endl;
    postorderAt(root_, out);
    std::cout << std::endl;
}

template <class ET>
void BST<ET>::postorderAt(Node* root, std::ostream& out) const {
    if (root != nullptr) {
        postorderAt(root->left, out);
        postorderAt(root->right, out);
        out << root->elem << ", ";
    }
}

template <class ET>
void BST<ET>::iterativePreorder(std::ostream& out) const {
    std::stack<Node*> nodeStack;
    nodeStack.push(root_);
    
    out << "Iterative preorder traversal:" << std::endl;
    while (!nodeStack.empty()) {
        Node* top = nodeStack.top();
        if (top) {
            out << top->elem << ", ";
            nodeStack.pop();
            nodeStack.push(top->right);
            nodeStack.push(top->left);
        }
        else
            nodeStack.pop();
    }
    out << std::endl;
}

template <class ET>
void BST<ET>::iterativeInorder(std::ostream& out) const {
    std::stack<Node*> nodeStack;

    out << "Iterative inorder traversal:" << std::endl;
    nodeStack.push(root_);
    while (!nodeStack.empty()) {
        Node* top = nodeStack.top();
        if (top) {
            while (top) {
                top = top->left;
                nodeStack.push(top);
            }
        }
        else {
            nodeStack.pop();
            if (nodeStack.empty())
                break;
            top = nodeStack.top();
            nodeStack.pop();
            out << top->elem << ", ";
            nodeStack.push(top->right);
        }
    }
    out << std::endl;
}

template <class ET>
void BST<ET>::iterativePostorder(std::ostream& out) const {
    std::stack<Node*> nodeStack;
    Node* prev;

    out << "Iterative postorder traversal:" << std::endl;
    nodeStack.push(root_);
    prev = nullptr;
    Node* tmp = root_;
    while (tmp && tmp->left) {
        nodeStack.push(tmp->left);
        tmp = tmp->left;
    }
    while (!nodeStack.empty()) {
        Node* top = nodeStack.top();
        if (!top) {
            nodeStack.pop();
            if (nodeStack.empty())
                break;
            prev = nodeStack.top();
            nodeStack.pop();
            out << prev->elem << ", ";
            continue;
        }
       
        if (prev && prev->right == top) {
            while (top->left) {
                nodeStack.push(top->left);
                top = top->left;
            }
        }

        if (prev == top->right) {
            out << top->elem << ", ";
            prev = nodeStack.top();
            nodeStack.pop();
        }
        else {
            prev = top;
            nodeStack.push(top->right);
        }
    }
    out << std::endl;
}

template <class ET>
bool BST<ET>::isBalance() const {
    int maxDepth = 0;
    int minDepth = 0;

    std::stack<Node*> nodeStack;
    std::stack<int> depthStack;
    nodeStack.push(root_);
    depthStack.push(1);
    while (!nodeStack.empty()) {
        Node* top = nodeStack.top();
        int dep = depthStack.top();
        if (top) {
            nodeStack.pop();
            depthStack.pop();
            nodeStack.push(top->right);
            depthStack.push(dep + 1);
            nodeStack.push(top->left);
            depthStack.push(dep + 1);
        }
        else {
            if (maxDepth == 0) {
                maxDepth = dep;
                minDepth = dep;
            }
            else {
                if (dep > maxDepth)
                    maxDepth = dep;
                if (dep < minDepth)
                    minDepth = dep;
                if (maxDepth - minDepth > 1)
                    return false;
            }
            nodeStack.pop();
            depthStack.pop();
        }
    }

    return true;
}

template <class ET>
void BST<ET>::balance() {
    
}

template <class ET>
void BST<ET>::deleteTree(Node*& root) {
    if (root != nullptr) {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
}

template <class ET>
class BST<ET>::Node* BST<ET>::buildTree(const std::vector<ET>& vec, int begin, int end) {
    if (begin > end)
        return nullptr;
    if (begin == end) {
        Node* newNode = new Node;
        newNode->elem = vec[begin];
        newNode->left = nullptr;
        newNode->right = nullptr;
        return newNode;
    }
    else {
        int mid = (begin + end) / 2;
        Node* newNode = new Node;
        newNode->elem = vec[mid];
        newNode->left = buildTree(vec, begin, mid - 1);
        newNode->right = buildTree(vec, mid + 1, end);
        return newNode;
    }
}


template <class ET>
std::vector<std::list<ET> *>* BST<ET>::createLists() const {
    std::vector<std::list<ET> *>* listVec = new std::vector<std::list<ET> *>;
    std::queue<Node*> nodeQ;
    int currLevel;
    int nodesLeft;
    int nextNodes;

    nodeQ.push(root_);
    currLevel = 0;
    nodesLeft = 1;
    nextNodes = 0;
    std::list<ET>* lst = new std::list<ET>;
    listVec->push_back(lst);
    while (!nodeQ.empty()) {
        Node* tmp = nodeQ.front();
        nodeQ.pop();
        listVec->at(currLevel)->push_back(tmp->elem);
        if (tmp->left) {
            nodeQ.push(tmp->left);
            nextNodes++;
        }
        if (tmp->right) {
            nodeQ.push(tmp->right);
            nextNodes++;
        }

        nodesLeft--;
        if (nodesLeft == 0 && !nodeQ.empty()) {
            std::list<ET>* lst = new std::list<ET>;
            listVec->push_back(lst);
            nodesLeft = nextNodes;
            nextNodes = 0;
            currLevel++;
        }
    }

    return listVec;
}

template <class ET>
ET BST<ET>::findFirstCommonAncestor(const ET& elem1, const ET& elem2) const {
    std::vector<Node*>* path1 = searchPath(elem1);  
    ET ret;
    if (path1 == nullptr) {
        std::cout << "elem1 not found!" << std::endl;
        return ret;
    }
    while (!path1->empty()) {
        if (searchNode(path1->back(), elem2))
            return path1->back()->elem;
        path1->pop_back();
    }
   
    return ret;
}

#endif
