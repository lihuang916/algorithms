/* 1-7.cpp 
 * If an element in M*N matrix is 0, set its entire column and row to 0
 */

#include <iostream>
#include <cstring>

#define M 3
#define N 4

void setMatrix(int (*m)[N]) {
  bool rowsToClear[M], columnsToClear[N];
  int i, j;

  memset(rowsToClear, 0, sizeof(rowsToClear));
  memset(columnsToClear, 0, sizeof(columnsToClear));

  // first pass. Find rows and columns to clear
  for (i = 0; i < M; i++)
    for (j = 0; j < N; j++)
      if (m[i][j] == 0) {
	rowsToClear[i] = true;
	columnsToClear[j] = true;
      }
 
  // second pass. Clear rows and columns found in first pass
  for (i = 0; i < M; i++)
    for (j = 0; j < N; j++) 
      if (rowsToClear[i] | columnsToClear[j])
	m[i][j] = 0;
}

int main() {
  int m[][N] = {{0, 2, 3, 4},
		{4, 5, 6, 7},
		{7, 8, 0, 10}};
  setMatrix(m);

  int i, j;
  std::cout << "cleared matrix: " << std::endl;
  for (i = 0; i < M; i++) {
    for (j = 0; j < N; j++)
      std::cout << m[i][j] << ", ";
    std::cout << std::endl;
  }
  
  return 0;
}
