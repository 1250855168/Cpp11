#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <utility>

using namespace std;

void test() {
  string s;

  std::getline(std::cin, s);

  map<char, int> m;

  for (int i = 0; i < s.size(); i++) {
    if (m[s[i] == 0]) {
      m.insert(make_pair(s[i], 1));
    }
    m[s[i]]++;
  }

  int max = 0;
  for (auto i : m) {
    if (i.second > max) {
      max = i.second;
    }
  }

  for (auto i : m) {
    if (i.second == max) {
      cout << i.first << " " << i.second << endl;
    }
  }
}

void test_() {

  int keys[26] = {};

  char ch[26] = {'A', 'B', 'C', 'E', 'D', 'E', 'F', 'G', 'H',
                 'I', 'J', 'K', 'L', 'N', 'O', 'P', 'Q', 'R',
                 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

  char *ch1 = (char *)"ASASFAFASFAS";

  for (int i = 0; i < strlen(ch1); i++) {
    keys[ch1[i] - 'A']++;
  }

  for (int i = 0; i < 26; i++) {
    if (keys[i]==0) {
    continue;
    }
    printf("%d %c\n", keys[i], ch[i]);
  }
}

int main() {
  test_();
  return 0;
}
