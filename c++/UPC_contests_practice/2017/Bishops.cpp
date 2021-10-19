#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
  int n;
  while (cin >> n) {
    vector<string> taula(n);
    vector<bool> suma(2 * n - 1, true), resta(2 * n - 1, true);
    for (int i = 0; i < n; i++) {
      cin >> taula[i];
      for (int j = 0; j < n; j++) {
        if (taula[i][j] == 'B') {
          suma[i + j] = false;
          resta[j - i + n - 1] = false;
        }
      }
    }

    queue<pair<int, int>> visit;
    visit.push(make_pair(0, 0));
    visit.push(make_pair(n-1, 0));
    visit.push(make_pair(n-1, n-1));
    visit.push(make_pair(0, n-1));
    vector<vector<bool>> vist(n, vector<bool>(n, false));
    while(!visit.empty()){
      int i = visit.front().first, j = visit.front().second;
      visit.pop();
      if (vist[i][j]) continue;
      vist[i][j] = true;
      if(suma[i+j] && resta[j - i + n - 1]){
        resta[j - i + n - 1] = false;
        suma[i+j] = false;
        taula[i][j] = 'W';
      }
      if(i > 0 && !vist[i-1][j]) visit.push(make_pair(i-1, j));
      if(i < n-1 && !vist[i+1][j]) visit.push(make_pair(i+1, j));
      if(j < n-1 && !vist[i][j+1]) visit.push(make_pair(i, j+1));
      if(j > 0 && !vist[i][j-1]) visit.push(make_pair(i, j-1));
    }

    for (int i = 0; i < n; i++) {
      cout << taula[i] << endl;
    }
    for (int i = 0; i < 20; i++)
      cout << '-';
    cout << endl;
  }
}
