#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s) {
  int ans = 0;
  sort(g.begin(), g.end());
  sort(s.begin(), s.end());

  vector<int>::size_type i = 0;
  vector<int>::size_type j = 0;

  while (i < g.size() && j < s.size()) {
    if (s[j] >= g[i]) {
      ++i;
      ++j;
      ++ans;
    } else {
      ++j;
    }
  }

  return ans;
}

int main() {
  return 0;
}

