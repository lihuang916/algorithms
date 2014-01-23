/* sortsearch.cpp
 * A collection of sorting and searching problems
 */

#include <iostream>

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

// 9-2 





int main() {
    int A[30] = {1, 3, 5, 6, 9, 10, 24, 56, 79, 100};
    int B[] = {2, 4, 5, 7, 8, 25, 45, 46, 78, 101, 102};
    merge(A, 10, B, 11);
    std::cout << "9-1 merge two sorted arrays:" << std::endl;
    int i;
   
    for (i = 0; i < 30; i++) 
        std::cout << A[i] << ", ";
    std::cout << std::endl;

    return 0;
}
