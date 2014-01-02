/* 1-2.cpp
 * Reverse a c-style string
 */

#include <iostream>
#include <string>
#include <cstring>

void reverse(char* s) {
  int len = strlen(s);
  int i = 0, j = len - 1;
  char tmp;
  for (; i < j; i++, j--) {
    tmp = s[i];
    s[i] = s[j];
    s[j] = tmp;
  }
}

int main() {
  char s[] = "abc";
  reverse(s);
  std::cout << s << std::endl;

  return 0;
}
