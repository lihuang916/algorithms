/* 1-3.cpp
 * Remove duplicate characters in a string
 */

#include <iostream>
#include <string>

void rmDup(std::string& s) {
  int i = 0, j = 1;
  for (; j < s.size(); i++, j++)
    while(s[i] == s[j])
      s.erase(j, 1);
}

int main() {
  std::string s("aajdsaodoizfioehajjdfjjjdoaoiewapqpppqqppqppcmxcmmmmmmmmzksjdfsjfdsjkfdafsokfdskaffdskdsfdkkdkdkdkdkdoiiiiiiiiiiiiiiiiiiiiiiiiiiiiiwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww98329999999999999999999999048bcde");
  rmDup(s);
  std::cout << "trimmed string: " << s << std::endl;

  return 0;
}
