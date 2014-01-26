/* hashmap.cpp
 * A simple implementation of a hashmap with string key
 */

#include <iostream>
#include <cstdlib>
#include <vector>


#define INITIALBUCKETS 10

template<typename V>
class Hashmap {
    public:
        Hashmap();

        ~Hashmap();

        int size() const;

        bool isEmpty() const;

        void add(const std::string& key, const V& val);

        void remove(const std::string& key);

        V& find(const std::string& key) const;

        void rehash();

        void printMap() const;

    private:
        struct Node {
            std::string K;
            V val;
            Node* next;
        };
        std::vector<Node*> bkts_;
        int size_;
        int num_bkts_;
        
        int hash(const std::string& s) const;
};



template<typename V>
Hashmap<V>::Hashmap() {
    size_ = 0;
    num_bkts_ = INITIALBUCKETS;
    for (int i = 0; i < num_bkts_; i++)
        bkts_.push_back(nullptr);
}

template<typename V>
Hashmap<V>::~Hashmap() { }

template<typename V>
inline int Hashmap<V>::size() const { return size_;}

template<typename V>
inline bool Hashmap<V>::isEmpty() const { return size_ == 0; }

template<typename V>
void Hashmap<V>::add(const std::string& key, const V& val) {
    // first, search the key
    int index = hash(key);
    Node* tmp = bkts_[index];
    Node* prev = tmp;
    while (tmp) {
        if (!key.compare(tmp->K))
            break;
        prev = tmp;
        tmp = tmp->next;
    }

    // if the key is already in map, change the val, otherwise add the (key, val) pair
    if (!tmp) {
        Node* newNode = new Node;
        newNode->K = key;
        newNode->val = val;
        newNode->next = nullptr;
        if (!prev) 
            bkts_[index] = newNode;
        else
            prev->next = newNode;
        size_++;
    } 
    else {
        tmp->val = val;
    }
}

template<typename V>
void Hashmap<V>::remove(const std::string& key) {
    int index = hash(key);
    Node* tmp = bkts_[index];
    Node* prev = tmp;
    while (tmp) {
        if (!key.compare(tmp->K))
            break;
        prev = tmp;
        tmp = tmp->next;
    }
    
    if (tmp == nullptr) {
        std::cout << "Key is not in map!" << std::endl;
        exit(1);
    }   
    else {
        if (prev == tmp)
            bkts_[index] = tmp->next;
        else {
            prev->next = tmp->next;
            delete tmp;
        }
        size_--;
    }
}

template<typename V>
V& Hashmap<V>::find(const std::string& key) const {
    int index = hash(key);
    Node* tmp = bkts_[index];
    while (tmp) {
        if (!key.compare(tmp->K))
            break;
        tmp = tmp->next;
    }
    
    if (tmp == nullptr) {
        std::cout << "Key is not in map!" << std::endl;
        exit(1);
    }   
    else 
        return tmp->val;
}

template<typename V>
void Hashmap<V>::rehash() {

}

template<typename V>
int Hashmap<V>::hash(const std::string& s) const {
    int i;
    unsigned int hashAddr = -19765324L;
    for (i = 0; i < s.size(); i++) {
        hashAddr = ((hashAddr << 5) + hashAddr) + hashAddr * s[i];
    }

    return hashAddr % num_bkts_;   
}

template<typename V>
void Hashmap<V>::printMap() const {
    for (int i = 0; i < bkts_.size(); i++) {
        Node* tmp = bkts_[i];
        std::cout << "Bucket " << i << ": ";
        if (tmp == nullptr) 
            std::cout << "NULL" << std::endl;
        while (tmp) {
            std::cout << tmp->K << " <-> " << tmp->val << ",  ";
            tmp = tmp->next;
        }
        std::cout << std::endl;
    }
}
    


int main() {
    Hashmap<int> myMap;
    myMap.add(std::string("Li Huang"), 100);
    myMap.add(std::string("Daniel"), 10);
    myMap.add(std::string("Aron"), 1003);
    myMap.add(std::string("Jack"), 1);
    myMap.add(std::string("Wellsley"), 140);
    myMap.add(std::string("Williams"), 100);
    myMap.add(std::string("Bob"), 1050);
    myMap.add(std::string("Steve"), 0);
    
    //myMap.remove("Li Huang");
    myMap.remove("Daniel");
    
    myMap.printMap();
    
    std::cout << "search for key: " << myMap.find("Aron") << std::endl;

    return 0;
}
