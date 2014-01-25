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

// 9-3 search in a rotated sorted array
// helper function: binarySearch
template <typename ET>
int binarySearch(const std::vector<ET>& v, const ET& elem, int start, int end) {
    int loc;
    
    while (start <= end) {
        loc = (start + end) / 2;
        if (v[loc] == elem) 
            return loc;
        if (v[loc] > elem) 
            end = loc - 1;
        else 
            start = loc + 1;
    }
    return -1;
}

int searchRotated(const std::vector<int>& vec, int val, int start, int end) {
    int mid = (start + end) / 2;
    if (start > end)
        return -1;
    if (vec[mid] == val)
        return mid;
    if (vec[start] <= vec[mid]) {
        if (val < vec[mid] && val >= vec[start]) 
            return binarySearch<int>(vec, val, start, mid - 1);
        else
            return searchRotated(vec, val, mid + 1, end);
    }
    else {
        if (val > vec[mid] && val < vec[start])
            return binarySearch<int>(vec, val, mid + 1, end);
        else 
            return searchRotated(vec, val, start, mid - 1);
    }
}

// 9-4 sort 2GB file with one string per line
// My opinion: since the file is large and the cost of moving strings around is high, 
// it's better to choose a sorting algorithm that doesn't require much move.
// Quicksort and heapsort is a good choice, mergesort is a bad choice

// 9-5 search in an array of strings with empty strings
int searchWithEmpty(const std::vector<std::string>& sv, const std::string& s) {
    int start = 0;
    int end = sv.size() - 1;
    while (start <= end) {
        int mid = (start + end) / 2;
        int loc = mid;
        while(sv[loc].empty() && loc < end) loc++;
        if (loc == end) {
            loc = mid;
            while (sv[loc].empty() && loc > start) loc--;
            if (loc == start) {
                if (!sv[start].empty() && !sv[start].compare(s))
                    return start;
                else if (!sv[end].empty() && !sv[end].compare(s))
                    return end;
                else
                    return -1;
            }
        }
        if (!sv[loc].compare(s))
            return loc;
        if (sv[loc].compare(s) < 0)
            start = loc + 1;
        else
            end = loc - 1;
    }
    return -1;
}

// 9-6 search an element in a matrix
void searchMatrix(int (*A)[5], int val, int* row, int* col, int ulRow, int ulCol, int lrRow, int lrCol) {
    int midRow = (ulRow + lrRow) / 2;
    int midCol = (ulCol + lrCol) / 2;

    if (ulRow > lrRow || ulCol > lrCol) {
        *row = -1;
        *col = -1;
        return;
    }

    if (A[midRow][midCol] == val) {
        *row = midRow;
        *col = midCol;
        return;
    }

    if (A[midRow][midCol] < val) {
        searchMatrix(A, val, row, col, ulRow, midCol + 1, midRow, lrCol);
        if (*row != -1 && *col != -1)
            return;
        searchMatrix(A, val, row, col, midRow + 1, midCol + 1, lrRow, lrCol);
        if (*row != -1 && *col != -1)
            return;
        searchMatrix(A, val, row, col, midRow + 1, ulCol, lrRow, midCol);
    }
    else {
        searchMatrix(A, val, row, col, ulRow, midCol, midRow - 1, lrCol);
        if (*row != -1 && *col != -1)
            return;
        searchMatrix(A, val, row, col, ulRow, ulCol, midRow - 1, midCol - 1);
        if (*row != -1 && *col != -1)
            return;
        searchMatrix(A, val, row, col, midRow, ulCol, lrRow, midCol - 1);
    }
}

// 9-7 Human tower. Longest increasing subsequence

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
    //bruteForceAnagram(sv);
    std::cout << "9-2 Anagrams" << std::endl;
    for (auto &s : sv)
        std::cout << s << ", ";
    std::cout << std::endl;
    
    int C[] = {23, 35, 68, 99, 100, 1, 3, 5, 6, 14, 21};
    std::vector<int> rot(C, C + sizeof(C) / sizeof(int));
    std::cout << "9-3 search an rotated sorted array: " << searchRotated(rot, 5, 0, 10) << std::endl;

    std::cout << "9-5 search with empty string: " << searchWithEmpty(sv, std::string("zzzz")) << std::endl;

    int M[][5] = {{1, 2, 3, 4, 5}, 
                  {6, 7, 8, 9, 10},
                  {11, 12, 13, 14, 15},
                  {16, 17, 18, 19, 20},
                  {21, 22, 23, 24, 25}};
    int row, col;
    searchMatrix(M, 21, &row, &col, 0, 0, 4, 4);
    std::cout << "9-6 search matrix: " << row << ", " << col << std::endl;
    return 0;
}
