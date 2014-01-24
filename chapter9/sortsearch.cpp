/* sortsearch.cpp
 * A collection of sorting and searching problems
 */

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <set>

// 9-1 merge two sorted arrays
void merge(int A[], int sA, int B[], int sB) {
    int i, j;
    i = 0;
    for (j = 0; j < sB; j++) {
        int n;
        while(A[i] <= B[j] && i < sA) i++;
        if (i == sA) 
            break;
        for (n = sA - 1; n >= i; n--) 
            A[n + 1] = A[n];
        A[i] = B[j];
        sA++;
    }
    if (i == sA) {
        for (; j < sB; j++) 
            A[i++] = B[j];
    }
}

// 9-2 sort an array of strings so that anagrams are next to each other
// version 1. Brute force search and compare
// helper function: isAnagram
bool isAnagram(const std::string& s1, const std::string& s2) {
    if (s1.size() != s2.size())
        return false; 
    
    int count[80];
    int i;
    memset(count, 0, 80 * sizeof(int));
    for (i = 0; i < s1.size(); i++)
        count[s1[i] - 'A']++;
    for (i = 0; i < s2.size(); i++) 
        count[s2[i] - 'A']--;
    for (i = 0; i < 80; i++) {
        if (count[i])
            return false;
    }
    return true;
}

void bruteForceAnagram(std::vector<std::string>& svec) {
    int i, j;
    for (i = 0; i < svec.size() - 1; i++) {
        for (j = i + 1; j < svec.size(); j++) {
            if (isAnagram(svec[i], svec[j])) {
                i++;
                std::string tmp = svec[i];
                svec[i] = svec[j];
                svec[j] = tmp;
            }
        }
    }
}

// 9-2 version 2. Use hash function
void hashAnagram(std::vector<std::string>& sv) {
    // build up a map from each lower case character to a prime number
    int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};
    std::map<int, int> pmap;
    int i;
    for (i = 0; i < 26; i++)
        pmap['a' + i] = primes[i];

    std::map<long long, std::set<std::string>* > anamap;
    // compute hash value of each string in the string vector
    for (i = 0; i < sv.size(); i++) {
        int j;
        long long val = 1;
        for (j = 0; j < sv[i].size(); j++) 
            val *= pmap[sv[i][j]];
        
        if (anamap[val] == nullptr) {
            std::set<std::string>* s = new std::set<std::string>();
            s->insert(sv[i]);
            anamap[val] = s;
        } 
        else 
            anamap[val]->insert(sv[i]);
    }
    
    for (auto &x : anamap) {
        for (auto &y : *x.second)
            std::cout << y << ", ";
    }
    std::cout << std::endl;
}

int main() {
    int A[30] = {1, 3, 5, 6, 9, 10, 24, 56, 79, 100};
    int B[] = {2, 4, 5, 7, 8, 25, 45, 46, 78, 101, 102};
    merge(A, 10, B, 11);
    std::cout << "9-1 merge two sorted arrays:" << std::endl;
    int i;
    for (i = 0; i < 30; i++) 
        std::cout << A[i] << ", ";
    std::cout << std::endl;

    std::ifstream inputFile("strarr.input");
    if (!inputFile.is_open()) {
        std::cout << "Input file can not be opened!" << std::endl;
        return 1;
    }
    
    std::vector<std::string> sv;
    std::string str;
    while (std::getline(inputFile, str))
        sv.push_back(str);
    
    hashAnagram(sv);
    bruteForceAnagram(sv);
    std::cout << "9-2 Anagrams" << std::endl;
    for (auto &s : sv)
        std::cout << s << ", ";
    std::cout << std::endl;
    
    
    return 0;
}
