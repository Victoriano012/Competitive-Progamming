#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

using vi = vector<int>;
using vvi = vector<vector<int>>;
using pii = pair<int, int>;

vvi vecinos;
vi componente;

int main() {
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vecinos = vvi(n);
        for(int i = 0; i < m; i++){
            int a, b;
            cin >> a >> b;
            vecinos[a].push_back(b);
            vecinos[b].push_back(a);
        }
        componente = vi(0);
        for(int i = 0; i < n; i++) componente.push_back(i);
        for(int i = 0; i < n; i++){
            for(int k: vecinos[i]){
                if(k < i){
                    if(componente[k] < componente[i]){
                        componente[i] = componente[k];
                    } else componente[k] = componente[i];
                }
            }
        }
        continue;
    }
    return 1;
}
