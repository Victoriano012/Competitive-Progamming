#include <iostream>

using namespace std;

int main() {
  double l1, l2, p1, p2;
  while (cin >> l1 >> l2 >> p1 >> p2) {
    double a1 = l1 * p2;
    double a2 = l2 * (1 - p1 - p2);
    double a3 = p1;
    double a4 = p2 * (1 - l1);
    double a5 = p2 * (1 - l2);
    if (a1 + a2 == 1)
      cout << 10 * a1 + 15 * a2 << endl;
    else
      cout << (1 / (a1 + a2) - 1) * (5 * a3 + 10 * a4 + 15 * a5) /
                      (a3 + a4 + a5) +
                  (10 * a1 + 15 * a2) / (a1 + a2)
           << endl;
  }
}
