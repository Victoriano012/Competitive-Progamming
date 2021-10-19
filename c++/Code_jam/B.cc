#include <bits/stdc++.h>

using namespace std;

bool check(vector<int> u, int m, int a, int b){
    int l = u.size();
    map<int, int> mapa;
    mapa[m] = 1;
    while(!mapa.empty()){
        pair<int, int> p = *mapa.rbegin();
        mapa.erase(--mapa.end());
        if(p.first < l){
            if(u[p.first] > 0){
                if(u[p.first] > p.second) return false;
                p.second -= u[p.first];
                u[p.first] = 0;
                if(p.second == 0) continue;
            }
        }
        if(p.first >= a) {
            mapa[p.first-a] += p.second;
            if(p.first >= b) {
                mapa[p.first-b] += p.second;
            }
        }
    }
    for(int i: u) if(i != 0) return false;
    return true;
}

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

int main(){
    int t;
    cin >> t;
    for(int c = 1; c <= t; ++c){
        int n, a, b;
        cin >> n >> a >> b;
        vector<int> u(n);
        for(int i = 0; i < n; ++i){
            cin >> u[i];
        }

        bool k = false;
        int g = gcd(a, b);
        if(g != 1){
            for(int i = 0; i < n; ++i){
                if(u[i] != 0){
                    auto aux_u = u;
                    for(int j = i; j < n; j += g){
                        aux_u[j] = 0;
                    }
                    for(int j = 0; j < n; ++j){
                        if(aux_u[j] != 0){
                            k = true;
                            cout << "Case #" << c << ": IMPOSSIBLE" << endl;
                            break;
                        }
                    }
                    break;
                }
            }
        }

        if(k) continue;

        bool t = true;
        for(int i = 1; true; ++i){
            if(check(u, i-1, a, b)){
                cout << "Case #" << c << ": " <<  i << endl;
                t = false;
                break;
            }
        }
        if(t) cout << "Case #" << c << ": IMPOSSIBLE" << endl;
    }
}