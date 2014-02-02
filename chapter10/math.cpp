/* math.cpp
 * A collection of mathematical problems
 */

#include <iostream>
#include <list>
#include <vector>
#include <set>

#define NUMBUCKETS 50

// greatest common divisor(gcd) and least common multiple(lcm)
int gcd(int a, int b) {
    if (a < b) {
        int tmp = a;
        a = b;
        b = tmp;
    }
    while (b) {
        int rem = a % b;    
        a = b;
        b = rem;
    }
    return a;
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

// test if two line segments intersect
bool intersect(double l1_x1, double l1_y1, double l1_x2, double l1_y2, double l2_x1, double l2_y1, double l2_x2, double l2_y2) {
    double a1 = ((l1_x2 - l1_x1) * l2_y1 - (l1_y2 - l1_y1) * (l2_x1 - l1_x1) - l1_y1 * (l1_x2 - l1_x1));
    double b1 = ((l1_x2 - l1_x1) * l2_y2 - (l1_y2 - l1_y1) * (l2_x2 - l1_x1) - l1_y1 * (l1_x2 - l1_x1)); 
    double a2 = ((l2_x2 - l2_x1) * l1_y1 - (l2_y2 - l2_y1) * (l1_x1 - l2_x1) - l2_y1 * (l2_x2 - l2_x1)); 
    double b2 = ((l2_x2 - l2_x1) * l1_y2 - (l2_y2 - l2_y1) * (l1_x2 - l2_x1) - l2_y1 * (l2_x2 - l2_x1)); 
    std::cout << "a1, b1, a2, b2: " << a1 << ", " << b1 << ", " << a2 << ", " << b2 << std::endl;

    if (a1 * b1 <= 0 && a2 * b2 <= 0)
        return true;
    return false;
}


// find a line that passes through the most number of points
// O(n^2) solution: for each pair of points, write the line function: Ax + By + C = 0, 
// hash tuple (A, B, C) to a set of points. Save the pair of points to that set of points.
// Go through the hashmap to find the largest set.
/*
struct Line {
    int A;
    int B;
    int C;
    Line() {}
    Line(int a, int b, int c) : A(a), B(b), C(c) {}
    inline bool operator==(const Line& l) { return l.A == A && l.B == B && l.C == C; }
};

struct Node {
    Line L;
    std::set<std::pair<int, int> >* s;
};

// helper hash function: int hash(const Line& L)
int hash(const Line& L) {
    long long p = 2764437L;
    return (L.A + L.B * p + L.C * p * p) % NUMBUCKETS;
}

Line findColinearPoints(const std::vector<std::pair<int, int> >& points) {
    std::vector<std::list<Node>* > hmap(NUMBUCKETS, nullptr);
    for (int i = 0; i < points.size(); i++) {
        for (int j = 0; j < points.size(); j++) {
            if (i == j) 
                continue;
            int x1, y1, x2, y2, A, B, C;
            if (points[i].first < points[j].first) {
                x1 = points[i].first;
                y1 = points[i].second;
                x2 = points[j].first;
                y2 = points[j].second;
            }
            else {
                x2 = points[i].first;
                y2 = points[i].second;
                x1 = points[j].first;
                y1 = points[j].second;
            }

            A = x2 - x1;
            B = y2 - y1;
            C = x1 * B - y1 * A;
            Line line(A, B, C);
            int bkt = hash(line);
            if (hmap[bkt] == nullptr) {
                std::list<Node>* l = new std::list<Node>();
                std::set<std::pair<int, int> >* s = new std::set<std::pair<int, int> >();
                s->insert(points[i]);
                s->insert(points[j]);
                Node n;
                n.L = line;
                n.s = s;
                l->push_back(n);
                hmap[bkt] = l;
            }
            else {
                Node* tmp = nullptr;
                std::cout << "########## size: " << hmap[bkt]->size() << std::endl;
                for (auto &n : *(hmap[bkt])) {
                    std::cout << "################ " << n.L.A << std::endl;
                    if (n.L.A == line.A) {
                        tmp = &n;
                        break;
                    }
                }
                if (tmp) {
                    tmp->s->insert(points[i]);
                    tmp->s->insert(points[j]);
                }
                else {
                    Node n; 
                    std::set<std::pair<int, int> >* s = new std::set<std::pair<int, int> >();
                    s->insert(points[i]);
                    s->insert(points[j]);
                    n.L = line;
                    n.s = s;
                    hmap[bkt]->push_back(n);
                    std::cout << "I'm here ########## size: " << hmap[bkt]->size() << std::endl;
                }
            }
        }
    }
    
    int num = 0;
    Node* most = nullptr;
    for (auto &l : hmap) {
        if (l) {
            for (auto &n : *l) {
                if (n.s->size() > num) {
                    num = n.s->size();
                    most = &n;
                }
            }
        }
    }
    
    return most->L;
}
*/

// find kth number such that the only prime factors are 3, 5, 7
// helper funciton: isPrime(int n)
bool isPrime(int n, std::vector<int>& primes) {
    for (int i = 0; primes[i] * primes[i] <= n && i < primes.size(); i++) {
        if (n % primes[i] == 0)
            return false;
    }
    primes.push_back(n);
    return true;
}

// helper function: isWanted. Check if n satisfies the requirement
bool isWanted(int n, const std::vector<int>& primes) {
    if (n % 3 && n % 5 && n % 7) 
        return false;
    for (int i = 0; i < primes.size(); i++) {
        if (primes[i] > 2 && primes[i] < 8)
            continue;
        if (n % primes[i] == 0)
            return false;
    }
    return true;
}

int findkth(int k) {
    std::vector<int> primes;
    primes.push_back(2);
    int count = 0;
    int i = 2;
    while (count < k) {
        i++;
        isPrime(i, primes);
        if (isWanted(i, primes))
            count++;
    }
    return i;
}



int main() {
    std::cout << "gcd of two numbers: " << gcd(4, 6) << std::endl;
    std::cout << "lcm of two numbers: " << lcm(4, 6) << std::endl;

    std::cout << "test if two line segments intersect: " << intersect(1, 1, 3, 3, 2, 1, 3, 1) << std::endl;

    std::vector<std::pair<int, int> > points;
    points.push_back(std::make_pair(0, 0));
    points.push_back(std::make_pair(1, 1));
    points.push_back(std::make_pair(2, 2));
    points.push_back(std::make_pair(5, 3));
    points.push_back(std::make_pair(10, 1));

//    Line L = findColinearPoints(points);

    std::cout << "find kth number with prime factors 3, 5, 7: " << std::endl;
    for (int i = 1; i < 200; i++)
        std::cout << findkth(i) << ", ";
    std::cout << std::endl;

    return 0;
}
