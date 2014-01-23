/* sortsearch.cpp
 * A collection of sorting and searching problems
 */

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>


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
bool isAnagram(const string& s1, const string& s2) {
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

void bruteForceAnagram(string s[], int size) {
    int i, j;
    for (i = 0; i < size - 1; i++) {
        for (j = i; j < size; j++) {
            if (isAnagram(s[i], s[j]) && j > i + 1) {
                string tmp = s[i];
                s[i] = s[j];
                s[j] = tmp;
            }
        }
    }
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
        
    ofstream outputFile("strarr.output");
    if (!outputFile.is_open()) {
        std::cout << "Output file can not be opened!" << std::endl;
        return 1;
    }



    return 0;
}
