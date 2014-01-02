/* 1-8.cpp
 * Given two strings s1 and s2, check if s2 is a rotation of s1
 */

#include <iostream>
#include <string>

bool isRotation(const std::string& s1, const std::string& s2) {
  std::string s(s1);
  s.append(s1);
  return s1.size() == s2.size() && s.find(s2) != std::string::npos; 
}

int main() {
  std::string s1("abcde");
  std::string s2("deabc");

  std::cout << "s2 is a rotation of s1? " << isRotation(s1, s2) << std::endl;
  return 0;
}
