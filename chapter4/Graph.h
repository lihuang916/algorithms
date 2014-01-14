/* Graph.h */

#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <cstdlib>
#include <vector>
#include <set>
#include <stack>
#include <queue>


template <typename ET>
class Digraph {
public:
    Digraph();

    Digraph(int numVertices, const ET& data);

    Digraph(const std::vector<ET>& vec);

    ~Digraph();

    void addEdge(int start, int end);

    int depthFirstSearch(const ET& data, int start) const;

    void depthFirstTraversal(int start) const;

    void breadthFirstTraversal(int start) const;

    int getDistanceByDFS(int start, int end) const; 

    int getMinDistanceByBFS(int start, int end) const; 
    
    void printGraph() const;


private:
    struct Vertex {
        ET data;
        std::list<int> adjacencyList;
    };
    
    std::vector<Vertex> graph_;

    int depthFirstSearchFrom(int start, const ET& data, std::set<int>& visitedVertices) const;

};


template <typename ET>
Digraph<ET>::Digraph() {}

template <typename ET>
Digraph<ET>::Digraph(int numVertices, const ET& data) {
    int i;
    Vertex vtx;
    for (i = 0; i < numVertices; i++) {
        vtx.data = data;
        graph_.push_back(vtx);
    }
}

template <typename ET>
Digraph<ET>::Digraph(const std::vector<ET>& vec) {
    Vertex vtx;
    for (typename std::vector<ET>::const_iterator it = vec.begin(), ite = vec.end(); it != ite; ++it) {
        vtx.data = *it;
        graph_.push_back(vtx);
    }
}

template <typename ET>
Digraph<ET>::~Digraph() {
}

template <typename ET>
void Digraph<ET>::addEdge(int start, int end) {
    if (start < 0 || start >= graph_.size() || end < 0 || end >= graph_.size()) {
        std::cout << "addEdge error: out of range!" << std::endl;
        exit(1);
    }
    graph_.at(start).adjacencyList.push_back(end);
}

template <typename ET>
int Digraph<ET>::depthFirstSearch(const ET& data, int start) const {
    std::set<int> visitedVertices;
    return depthFirstSearchFrom(start, data, visitedVertices);
}

template <typename ET>
int Digraph<ET>::depthFirstSearchFrom(int start, const ET& data, std::set<int>& visitedVertices) const {
    if (graph_.at(start).data == data)
        return start;
    visitedVertices.insert(start);
    for (int i : graph_.at(start).adjacencyList) {
        if (visitedVertices.find(i) == visitedVertices.end()) {
            int n = depthFirstSearchFrom(i, data, visitedVertices);
            if (n != -1)
                return n;
        }
    }
    return -1;
}

template <typename ET>
void Digraph<ET>::depthFirstTraversal(int start) const {
    std::set<int> visitedVertices;
    std::stack<int> s;
    
    std::cout << "visiting node: " << start << std::endl;
    visitedVertices.insert(start);
    s.push(start);
    while (!s.empty()) {
        int curr = s.top();
        bool foundUnvisited = false;
        for (int i : graph_.at(curr).adjacencyList) {
            if (visitedVertices.find(i) == visitedVertices.end()) {
                s.push(i);
                std::cout << "visiting node: " << i << std::endl;
                visitedVertices.insert(i);
                foundUnvisited = true;
                break;
            }
        }
        if (!foundUnvisited)
            s.pop();
    }
}

template <typename ET>
void Digraph<ET>::breadthFirstTraversal(int start) const {
    std::set<int> visitedVertices;
    std::queue<int> q;

    std::cout << "visiting node: " << start << std::endl;
    visitedVertices.insert(start);
    q.push(start);
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        for (int i : graph_.at(curr).adjacencyList) {
            if (visitedVertices.find(i) == visitedVertices.end()) {
                std::cout << "visiting node: " << i << std::endl;
                visitedVertices.insert(i);
                q.push(i);
            }
        }
    }
}

template <typename ET>
int Digraph<ET>::getDistanceByDFS(int start, int end) const {
    if (start < 0 || start >= graph_.size() || end < 0 || end >= graph_.size()) {
        std::cout << "addEdge error: out of range!" << std::endl;
        exit(1);
    }
    
    if (start == end)
        return 0;

    std::set<int> visitedVertices;
    std::stack<int> s;
    int dist = 1;
    s.push(start);
    while (!s.empty()) {
        int curr = s.top();
        bool foundUnvisited = false;
        for (int i : graph_.at(curr).adjacencyList) {
            if (visitedVertices.find(i) == visitedVertices.end()) {
                if (i == end)
                    return dist;
                foundUnvisited = true;
                visitedVertices.insert(i);
                s.push(i);
                dist++;
                break;
            }
        }
        if (!foundUnvisited) {
            s.pop();
            dist--;
        }
    }
    
    return -1;
}
 
template <typename ET>
int Digraph<ET>::getMinDistanceByBFS(int start, int end) const {
    if (start < 0 || start >= graph_.size() || end < 0 || end >= graph_.size()) {
        std::cout << "addEdge error: out of range!" << std::endl;
        exit(1);
    }

    if (start == end)
        return 0;
    
    std::set<int> visitedVertices;
    std::queue<int> q;
    std::queue<int> distq;
    q.push(start);
    distq.push(0);
    while (!q.empty()) {
        int curr = q.front();
        int currDist = distq.front();
        q.pop();
        distq.pop();
        for (int i : graph_.at(curr).adjacencyList) {
            if (visitedVertices.find(i) == visitedVertices.end()) {
                if (i == end)
                    return currDist + 1;
                visitedVertices.insert(i);
                q.push(i);
                distq.push(currDist + 1);
            }
        } 
    }

    return -1;
} 

template <typename ET>
void Digraph<ET>::printGraph() const {
    int i = 0;
    for (typename std::vector<Vertex>::const_iterator it = graph_.begin(), ite = graph_.end(); it != ite; ++it) {
        std::cout << "Vertex " << i++ << " data: " << it->data << " adjacency list: ";
        for (std::list<int>::const_iterator lit = it->adjacencyList.begin(), lite = it->adjacencyList.end(); lit != lite; ++lit) {
            std::cout << *lit << ", ";
        }
        std::cout << std::endl;
    }
}


#endif
