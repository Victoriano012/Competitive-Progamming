#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

using vi = vector<int>;
using vpii = vector<pair<int, int>>;
using ll = long long;

int main() {
    int n, m, t;
    cin >> t;
    for(int g = 0; g < t; g++){
        cin >> n >> m;
        vi v(n);
        vpii f(m);
        for(ll i = 0; i < n; i++) cin >> v[i];
        for(ll i = 0; i < m; i++){
            ll h, r;
            cin >> h >> r;
            f[i].first = h-r;
            f[i].second = h+r;
        }
        sort(f.begin(), f.end());
        sort(v.begin(), v.end());
    
        int it = 0;
        bool pos = true;
        int Ans = 0;
        int ma = -1;
        for(int i = 0; i < n; i++){
            if(ma < v[i]){
                while(it < ma && (v[i] < f[it].first || f[it].second > v[i])){
                    it++;
                    if(f[it].first > v[i]){
                        cout << "imposible" << endl;
                        pos = false;
                        break;
                    }
                }
                if(it == ma){
                    cout << "imposible" << endl;
                    pos = false;
                    break;
                }
                Ans++;
                ma = f[it].second;
            }
        }
        if (pos) cout << Ans << endl;
    }
    return 0;
}
