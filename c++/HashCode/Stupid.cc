#include <iostream>
#include <vector>

using namespace std;

int main() {
  int d, i, s, v, f;
  cin >> d >> i >> s >> v >> f;
  vector<vector<string>> intersection(i);

  for (int k = 0; k < s; ++k) {
    string name;
    int begin, end, time;
    cin >> begin >> end >> name >> time;
    intersection[end].push_back(name);
  }

  cout << i << endl;
  for (int k = 0; k < i; ++k) {
    cout << k << endl;
    cout << intersection[k].size() << endl;
    for (string str : intersection[k]) {
      cout << str << ' ' << 1 << endl;
    }
  }
}
