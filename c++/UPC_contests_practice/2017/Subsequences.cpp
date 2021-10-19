#include <iostream>

using namespace std;

typedef long long ll;

int main() {
  int a;
  while (cin >> a) {
    ll senar = 0, parell = 0;
    for (int i = 0; i < a; i++) {
      ll b;
      cin >> b;
      if (b % 2 == 0) {
        parell = max(parell, senar + b);
      } else {
        senar = max(senar, parell + b);
      }
    }
    cout << max(senar, parell) << endl;
  }
}
