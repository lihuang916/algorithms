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

    ~BST();

    int size() const;
    
    bool isEmpty() const;

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

private:
    Node* root_;
    int size_;

    void preorderAt(Node* root, std::ostream& out) const;
    void inorderAt(Node* root, std::ostream& out) const;
    void postorderAt(Node* root, std::ostream& out) const;
    void removeFrom(Node*& root, const ET& elem);
    void deleteTree(Node*& root);
};

template <class ET>
inline BST<ET>::BST() : root_(nullptr), size_(0) { }

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
bool BST<ET>::search(const ET& elem) const {
    Node* tmp = root_;
    while (tmp != nullptr) {
        if (tmp->elem == elem)
            return true;
        if (tmp->elem < elem)
            tmp = tmp->right;
        else
            tmp = tmp->left;
    }
    return false;
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
    while (tmp->left) {
        nodeStack.push(tmp->left);
        tmp = tmp->left;
    }
    while (!nodeStack.empty()) {
        Node* top = nodeStack.top();
        if (!top) {
            nodeStack.pop();
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

#endif
