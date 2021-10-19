#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<map<int, int>> vmii;

int n, a;
vi seen;
vmii wires;
priority_queue<vi> s;

void dfs(){
    if(s.empty()){
        a = 0;
        return;
    }
    vi t = s.top();
    s.pop();
    if(seen[t[1]] != -1){
        dfs();
        return;
    }
    seen[t[1]] = t[2];
    if(t[1] == n-1){
        a = t[0];
        return;
    }
    for(auto it = wires[t[1]].begin(); it != wires[t[1]].end(); it++){
        if(it->second != 0){
            s.emplace(vi{min(it->second, t[0]), it->first, t[1]});
        }
    }
    dfs();
    return;
}

void do_dfs(){
    seen = vi(n, -1);
    s = priority_queue<vi>();
    for(auto it = wires[0].begin(); it != wires[0].end(); it++){
        if(it->second != 0){
            s.emplace(vi{it->second, it->first, 0});
        }
    }
    dfs();
    if(a == 0) return;
    int b = n-1;
    while(b != 0){
        wires[seen[b]][b] -= a;
        b = seen[b];
    }
    return;
}

int main(){
    int m;
    while(cin >> n >> m){
        seen = vi(n, -1);
        wires = vmii(n);
        for(int i = 0; i < m; i++){
            int a, b, c;
            cin >> a >> b >> c;
            if(b != 0 && a != n-1) wires[a][b] += c;
        }
        long long Ans = 0;
        for(do_dfs(); a != 0; do_dfs()) Ans += a;
        cout << Ans << endl;
    }
}