#include <bits/stdc++.h>

using namespace std;

#define D(v)                                                                   \
  for (auto i : v)                                                             \
    cerr << i << ' ';                                                          \
  cerr << endl;
#define Dpair(v)                                                               \
  for (auto i : v)                                                             \
    cerr << "(" << i.first << ", " << i.second << ") ";                        \
  cerr << endl;
#define Dmap(m)                                                                \
  for (auto i : m)                                                             \
    cerr << i.first.first << " " << i.first.second << ": " << i.second         \
         << ", ";                                                              \
  cerr << endl;
#define x first
#define y second

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<pdd, double> pddd;
typedef pair<int, pii> piii;
typedef pair<char, int> pci;
using vs = vector<string>;
using qs = queue<string>;
using vvs = vector<vs>;
using vqs = vector<queue<string>>;

const int INF = 1e9 + 1;
const int MOD = 1000000007;

struct street {
  int starts_at;
  int ends_at;
  string name;
  int L;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  string line;
  getline(cin, line);
  int D, I, S, V, F;
  istringstream iss(line);
  iss >> D >> I >> S >> V >> F;
  vector<street> city(S, {0, 0, "", 0});
  for (street &temp : city) {
    getline(cin, line);
    iss = istringstream(line);
    iss >> temp.starts_at >> temp.ends_at >> temp.name >> temp.L;
  }
  int size_of_route;
  vqs routes;
  for (int i = 0; i < V; ++i) {
    getline(cin, line);
    iss >> size_of_route;
    qs temp;
    string s;
    for (int i = 0; i < size_of_route; ++i) {
      cin >> s;
      temp.push(s);
    }
    routes.push_back(temp);
  }
}
