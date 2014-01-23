/* bit.c
 * Bit manipulation problems
 */


#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

// 5.1 setbits
int setbits(int N, int M, int i, int j) {
    return (((~(-1 << (j + 1))) & (M << i)) | (N & ((~(-1 << i)) | (-1 << (j + 1)))));
} 


// 5.2 binary representation
void toBinary(const char *c) {
    double a;
    int int_part;
    char binary[64], binary1[64];
    int i, j;
    
    i = 0;
    sscanf(c, "%lf", &a);
    int_part = (int) a;
    while (int_part >= 1) {
        int tmp = int_part % 2;
        binary[i++] = tmp + '0';
        int_part = (int_part - tmp) / 2; 
    }
    
    for (j = 0; j < i; j++)
        binary1[j] = binary[i - 1 -j];
    binary1[j] = '\0';
    
    printf("binary rep: %s\n", binary1);
    
}

// 5.3 next smallest
// helper function: given an interger, return number of 1s in binary representation
int numOfOnes(int a) {
    int num = 0;
    while (a) {
        if (a & 1)
            num++;
        a = a >> 1;
    }
    return num;
}

int nextSmallest(int a) {
    return pow(2, numOfOnes(a)) - 1;
}

// 5.4 if n = 2 ^ m for some integer m >= 0 (only has one 1 in binary representation), then return true
int isPowerOf2(int n) {
    return (n & (n - 1)) == 0;
}

// 5.5 number of bits needed to convert one integer to another
int numCovBits(int a, int b) {
    int num = 0;
    while (a || b) {
        if ((a & 1) != (b & 1))
            num++;
        a = a >> 1;
        b = b >> 1;
    }
    return num;
}

// 5.6 swap odd and even bits in an integer
int swapOddEven(int a) {
    int b1, b2;
    b1 = 1431655765;
    b2 = b1 << 1;
    /*   int i, j;
    j = 1;
    b1 = 1;
    for (i = 0; i < 15; i++) {
        j = j << 2;
        b1 |= j;
    }
    printf("b1 = %d\n", b1);
    b2 = b1 << 1;
    */
    
    return ((a & b1) << 1) | ((a & b2) >> 1);
}

// 5.7 find the missing integer
// helper function: fetch the jth bit of A[i]
int fetch(int A[], int i, int j) {
    return ((1 << j) & A[i]) >> j;
}

int findMissInt(int A[], int n) {
    int* B = malloc((n + 1) * sizeof *B);
    int bitCount[32];
    int i, j;
    int missNum;
    for (i = 0; i <= n; i++) 
        B[i] = i;
    memset(bitCount, 0, 32 * sizeof *bitCount);
    for (i = 0; i < 32; i++) 
        for (j = 0; j <= n; j++)
            bitCount[i] += fetch(B, j, i);
 
    for (i = 0; i < 32; i++) 
        for (j = 1; j <= n; j++)
            bitCount[i] -= fetch(A, j, i);
    
    free(B);
    j = 1;
    missNum = 0;
    for (i = 0; i < 32; i++) {
        //       printf("bitCount = %d j = %d\n", bitCount[i], j);
        missNum += j * bitCount[i];
        j = j << 1;
    }
    return missNum;
}

int main() {
    printf("5.1 setbits: %d\n", setbits(1024, 21, 2, 6));
    printf("5.2 number of 1s in binary rep: %d\n", numOfOnes(100001));   
    toBinary("100001.72");
    printf("5.3 next smallest in binary rep: %d\n", nextSmallest(100001));
    printf("5.4 is n a power of 2? %d\n", isPowerOf2(8));
    printf("5.5 number of bits need to convert two integers: %d\n", numCovBits(10, 5));
    printf("5.6 swap odd and even: %d\n", swapOddEven(swapOddEven(342324)));

    int A[] = {3, 1, 2, 4, 0}; 
    printf("5.7 missing number: %d\n", findMissInt(A, 4));
    return 0;
}
