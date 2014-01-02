/* 1-6.cpp 
 * Rotate an N*N matrix by 90 degrees
 */

#include <iostream>

#define N 3

int** rotate(int (*m)[N]) {
  int** nm = new int*[N];
  int i, j;
  for (i = 0; i < N; i++)
    nm[i] = new int[N];

  for (i = 0; i < N; i++)
    for (j = 0; j < N; j++)
      //   nm[j][N-1-i] = m[i][j]; // clockwise
      nm[N-1-j][i] = m[i][j]; //  counter-clockwise
  /*
  for (i = 0; i < N; i++)
    delete [] m[i];
  
  delete [] m;
  */

  return nm;
}

int main() {
  int m[][N] = {{1, 2, 3},
		 {4, 5, 6},
		 {7, 8, 9}};
  int** nm = rotate(m);
  int i, j;

  std::cout << "reversed matrix: " << std::endl;
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++)
      std::cout << nm[i][j] << ", ";
    std::cout << std::endl;
  }
  
  return 0;
}
