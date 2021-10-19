#include <iostream>
#include <vector>

using namespace std;

int main() {
  string s, r;
  while (cin >> s) {
    r = "";
    long long l = s.length();
    for (long long i = l - 1; i >= 0; i--) {
      r += s[i];
    }
    r += '$';
    r += s;
    l *= 2;
    ++l;

    vector<long long> kmp(l);
    kmp[0] = 0;
    for (long long i = 1; i < l; i++) {
      long long j = i;
      while (r[kmp[j - 1]] != r[i]) {
        j = kmp[j - 1];
        if (j == 0) {
          break;
        }
      }
      if (j == 0) {
        if (r[0] == r[i])
          kmp[i] = 1;
        else
          kmp[i] = 0;
      } else {
        kmp[i] = kmp[j - 1] + 1;
      }
    }
    cout << min(kmp[l - 1], l / 2) << endl;
  }
}
