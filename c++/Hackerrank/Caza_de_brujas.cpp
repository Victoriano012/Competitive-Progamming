#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

using vvi = vector<vector<int>>;
using vi = vector<int>;
using vpib = vector<pair<int, bool>>;
using vb = vector<bool>;

vvi amigos, enemigos;
vb visited, grup;
bool superbreak;
int cert, fals;

void dfs(int v){
    if(superbreak) return;
    if(visited[v]) return;
    visited[v] = true;
    for(int i: amigos[v]){
        if(!visited[i]){
            if(grup[v]){
                grup[i] = true;
                cert++;
            } else{
                grup[i] = false;
                fals++;
            }
            dfs(i);
        } else{
            if(grup[i] != grup[v]){
                superbreak = true;
                return;
            }
        }
    }
    for(int i: enemigos[v]){
        if(!visited[i]){
            if(!grup[v]){
                grup[i] = true;
                cert++;
            } else{
                grup[i] = false;
                fals++;
            }
            dfs(i);
        } else {
            if(grup[i] == grup[v]){
                superbreak = true;
                return;
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    for(int x = 0; x < t; x++){
        int n, m;
        cin >> n >> m;
        amigos = vvi(n), enemigos = vvi(n);
        for(int i = 0; i < m; i++){
            int c, a, b;
            cin >> c >> a >> b;
            if(c == 1) amigos[a].push_back(b), amigos[b].push_back(a);
            else enemigos[a].push_back(b), enemigos[b].push_back(a);
        }
        
        int Ans = 0;
        visited = vb(n, false);
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                grup = vb(n);
                grup[i] = 1;
                superbreak = false;
                cert = 1, fals = 0;
                dfs(i);
                if(superbreak){
                    break;
                }
                Ans += min(cert, fals);
            }
        }
        if(superbreak) cout << -1 << endl;
        else cout << Ans << endl;
    }
    return 0;
}
