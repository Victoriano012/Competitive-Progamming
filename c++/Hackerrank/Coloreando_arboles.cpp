#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

using vi = vector<int>;
using vvi = vector<vector<int>>;
using vb = vector<bool>;
using pii = pair<int, int>;

vb visited;
vvi conect;
vi color;

pii dfs(int v){
    pii Ans = {1, 1};
    visited[v] = true;
    for(int i: conect[v]) if(!visited[i]){
        pii p = dfs(i);
        int m = color[i] != color[v];
        Ans.first = max(Ans.first, max(p.first + m, Ans.second + p.second + m - 1));
        Ans.second = max(p.second + m, Ans.second);
    }
    return Ans;
}

int main() {
    int t;
    cin >> t;
    for(int x = 0; x < t; x++){
        int n;
        cin >> n;
        visited = vb(n, false), color = vi(n), conect = vvi(n);
        for(int i = 0; i < n-1; i++){
            int a, b;
            cin >> a >> b;
            conect[a].push_back(b);
            conect[b].push_back(a);
        }
        for(int i = 0; i < n; i++) cin >> color[i];
        pii Ans = dfs(0);
        cout << (Ans.first + 1)/2 << endl;
    }
    return 0;
}
