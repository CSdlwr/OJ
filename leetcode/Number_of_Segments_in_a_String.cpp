// Copyright [2016] <luming.lv>

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

int countSegments(string s) {
  int ans = 0;
  string::size_type slow = 0;
  string::size_type fast = slow + 1;

  while (slow < s.length()) {
    if (s[slow] != ' ' && fast >= s.length()) {
      ++ans;
    } else if (s[slow] != ' ' && s[fast] == ' ') {
      ++ans;
    }

    ++slow;
    ++fast;
  }
  return ans;
}

int main() {
  cout << countSegments(string(" ")) << endl;
}
