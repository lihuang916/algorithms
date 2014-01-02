/* 1-4.cpp
 * Check if two strings are anagrams or not
 */

#include <iostream>
#include <string>
#include <cstring>

bool isAnagram(const std::string& s1, const std::string& s2) {
  char a1[256], a2[256];
  memset(a1, 0, 256);
  memset(a2, 0, 256);
  
  int i;
  for (i = 0; i < s1.size(); i++) {
    a1[s1[i]]++;
    a2[s2[i]]++;
  }

  for (i = 0; i < 256; i++)
    if(a1[i] != a2[i]) return false;
  
  return true;
}

int main() {
  std::string s1("abcde");
  std::string s2("ecbad");
  std::cout << "Two strings are anagrams? " << isAnagram(s1, s2) << std::endl;
  return 0;
}
