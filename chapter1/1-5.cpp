/* 1-5.cpp
 * Replace all spaces in a string with "%20"
 */

#include <iostream>
#include <string>

void replaceSpace(std::string& s) {
  int index = 0;
  char c[] = "%100";
  index = s.find_first_of(' ');
  while (index != -1) {
    s.erase(index, 1);
    s.insert(index, c);
    index = s.find_first_of(' ');
  }
}

int main() {
  std::string s("I love you!");
  replaceSpace(s);
  std::cout << "new string: " << s << std::endl;

  return 0;
}
