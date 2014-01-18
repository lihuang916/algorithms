/* recursion.cpp
 * A collection of problems that can be solved by recursion
 */

#include <iostream>
#include <set>
#include <string>

#define DIM 3

// 8-1 Fibonacci number generator
int Fibonacci(int n) {
    if (n <= 1)
        return 0;
    if (n == 2)
        return 1;
    return Fibonacci(n - 1) + Fibonacci(n - 2);
}

// 8-2 number of paths 
int path(int M, int N) {
    if (M <= 0 || N <= 0)
        return 1;
    return path(M - 1, N) + path(M, N - 1);
}

// 8-3 subsets of set
// helper function: find subsets of size n
template <typename ET>
void subsets(std::set<std::set<ET> >& result, std::set<ET>& s, int size) {

}

template <typename ET>
void findSubsets(std::set<ET>& s) {
    

}

// 8-4 permutation of string
void permutation(std::string& prefix, std::string& suffix) {
    if (suffix.size() <= 1) {
        std::cout << prefix + suffix << std::endl;
        return;
    }
    int i;
    for (i = 0; i < suffix.size(); i++) {
        prefix.push_back(suffix[i]);
        suffix.erase(i, 1);
        permutation(prefix, suffix);
        suffix.insert(i, 1, prefix.back());
        prefix.pop_back();
    }
}

// 8-5 all valid combinations of n-pairs of parentheses
// helper function
void parenComb(std::string& paren, int open, int close) {
    if (open == 0) {
        std::cout << paren + std::string(close, ')') << std::endl;
        return;
    }
   
    if (open <= close) {
        paren.push_back('(');
        parenComb(paren, open - 1, close);
        paren.pop_back();
    }
    if (open < close) {
        paren.push_back(')');
        parenComb(paren, open, close - 1);
        paren.pop_back();
    }
}

void printParens(int n) {
    std::string s1("");
    parenComb(s1, n, n);
}

// 8-6 parint fill
void paintFill(int A[][DIM], const int rows, const int columns, int m, int n, int oldVal, int newVal) {
    A[m][n] = newVal;
    int i, j;
    for (i = -1; i < 2; i++)
        for (j = -1; j < 2; j++) {
            if ((i != 0 || j != 0) && m + i >= 0 && m + i < rows && n + j >= 0 && n + j < columns) {
                if (A[m + i][n + j] == oldVal)
                    paintFill(A, rows, columns, m + i, n + j, oldVal, newVal);
            }
        }
}

// 8-7 number of ways of representing n cents
// helper recursive function
int centsRep(int n, int usableCoins, int* selectedCoins) {
    int i;
    int ways = 0;
    switch(usableCoins) {
    case 4:
        for (i = 0; i <= n; i += 25) {
            selectedCoins[0] = i / 25;
            ways += centsRep(n - i, 3, selectedCoins);
        }
        break;
    case 3:
        for (i = 0; i <= n; i += 10) {
            selectedCoins[1] = i / 10;
            ways += centsRep(n - i, 2, selectedCoins);
        }
        break;
    case 2:
        for (i = 0; i <= n; i += 5) {
            selectedCoins[2] = i / 5;
            ways += centsRep(n - i, 1, selectedCoins);
        }
        break;
    case 1:
        selectedCoins[3] = n;
        /*      for (i = 0; i < 4; i++) 
            std::cout << selectedCoins[i] << ", ";
        std::cout << std::endl;
        */
        ways += 1;
        break;
    }

    return ways;
}

int numWaysRepCents(int n) {
    int selectedCoins[4];
    int i;
    for (i = 0; i < 4; i++) 
        selectedCoins[i] = 0;
    return centsRep(n, 4, selectedCoins); 
}

// 8-8 arrange eight queens on a chess board
// helper recursive function
int waysToArrange(int pos[], int nextrow) {
    int ways = 0;
    int i;
    if (nextrow == 8) {
        for (i = 0; i < 8; i++) 
            std::cout << pos[i] << ", ";
        std::cout << std::endl;
        return 1;
    }
    for (i = 0; i < 8; i++) {
        int j;
        bool conflict = false;
        for (j = 0; j < nextrow; j++) {
            if (i == pos[j] || nextrow - j == i - pos[j] || nextrow - j == pos[j] - i) {
                conflict = true;
                break;
            }
        }
        if (conflict) 
            continue;
        else {
            pos[nextrow] = i;
            ways += waysToArrange(pos, nextrow + 1);
        }
    }

    return ways;
}
 
void arrangeQueens() {
    int pos[8];
    int ways = waysToArrange(pos, 0);
    std::cout << "number of ways to arrange queens: " << ways << std::endl;
}




int main () {
    int i, j;
    std::cout << "8-1 Fibonacci number: " << std::endl;
    for (i = 1; i < 10; i++) 
        std::cout <<  Fibonacci(i) << ", ";
    std::cout << std::endl;

    std::cout << "8-2 number of paths: " << path(2, 2) << std::endl;
    
    std::cout << "8-4 permutations of string: " << std::endl;
    std::string s1("");
    std::string s2("abc");
    permutation(s1, s2);

    std::cout << "8-5 combinations of parentheses: " << std::endl;
    printParens(3);
    
    int A[][DIM] = {{0, 0, 0}, 
                    {0, 0, 0},
                    {0, 0, 0}};
    paintFill(A, DIM, DIM, 0, 0, 1, 1);
    paintFill(A, DIM, DIM, 1, 1, 0, 2);
    paintFill(A, DIM, DIM, 0, 0, 1, 3);
    paintFill(A, DIM, DIM, 2, 2, 1, 3);
    paintFill(A, DIM, DIM, 1, 1, 1, 3);
    paintFill(A, DIM, DIM, 0, 0, 3, 100);
    paintFill(A, DIM, DIM, 3, 1, 2, 50);
    std::cout << "8-6 paint fill: " << std::endl;
    for (i = 0; i < DIM; i++) {
        for (j = 0; j < DIM; j++)
            std::cout << A[i][j] << ", ";
        std::cout << std::endl;
    }

    int ways;
    std::cout << "8-7 ways to represent cents: " << std::endl;
    ways = numWaysRepCents(100);
    std::cout << "number of ways: " << ways << std::endl;

    std::cout << "8-8 ways to arrange queens" << std::endl;
    arrangeQueens();

    return 0;
}
