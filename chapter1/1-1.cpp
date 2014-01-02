/* 1-1.cpp 
 * Check if a string has unique characters
 */

#include <iostream>
#include <string>
#include <cstring>

bool isUnique(std::string& s) {
  bool a[256];
  memset(a, 0, sizeof(a));

  int i;
  for(i = 0; i < s.size(); i++) {
    if (a[s[i]]) return false;
    a[s[i]] = true;
  }

  return true;
}

int main() {
  std::string s("abc0defghijklmnopqrstuvwxyz1234567890");
  std::cout << "String has unique characters? " << isUnique(s) << std::endl;
  return 0;
}
