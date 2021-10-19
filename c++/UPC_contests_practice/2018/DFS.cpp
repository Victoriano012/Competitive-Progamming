#include <iostream>
#include <set>
#include <vector>

using namespace std;

typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<int> vi;
typedef vector<vi> vvi;

vb seen;
vvb m_arestes;
vvi i_arestes;
vi suposed;
int n, k;

pair<bool, int> dfs(int pos, int next) {
  if(next != k){
    while(m_arestes[pos][suposed[next]]) {
      seen[suposed[next]] = true;
      pair<bool, int> a = dfs(suposed[next], next + 1);
      if (!a.first)
        return make_pair(false, -1);
      next = a.second;
      if(next == k) break;
    }
  }
  for(int i: i_arestes[pos]){
    if(!seen[i]) return make_pair(false, -1);
  } 
  return make_pair(true, next);
}

int main() {
  int m;
  while (cin >> n >> m) {
    m_arestes = vvb(n, vb(n, false));
    i_arestes = vvi(n, vi(0));
    seen = vb(n, false);
    suposed.clear();
    for (int i = 0; i < m; i++) {
      int a, b;
      cin >> a >> b;
      m_arestes[a][b] = true;
      m_arestes[b][a] = true;
      i_arestes[a].push_back(b);
      i_arestes[b].push_back(a);
    }
    cin >> k;
    for (int i = 0; i < k; i++) {
      int a;
      cin >> a;
      suposed.push_back(a);
    }

    if(suposed[0] != 0){
      cout << "no" << endl;
    } else {
      seen[0] = true;
      pair<bool, int> a = dfs(0, 1);
      if (a.first && a.second == k)
        cout << "yes" << endl;
      else
        cout << "no" << endl;
    }
  }
}
