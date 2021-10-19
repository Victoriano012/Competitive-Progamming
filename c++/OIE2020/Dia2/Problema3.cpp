#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

using ll = long long;

int main() {
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<pair<ll, ll>> piezas(n);
        vector<ll> tiradas(n, 0);
        for(ll i = 0; i < n; i++){
            cin >> piezas[i].first >> piezas[i].second;
            piezas[i].second += piezas[i].first;
        }
        if(piezas[0].second <= piezas[1].first) cout << "Pep" << endl;
        else{
            int k = 0;
            for(ll i = 2; i < n && piezas[0].second > piezas[i].first; i++) tiradas[i]++;
            for(ll i = 2; i < n && piezas[1].second > piezas[i].first; i++) tiradas[i]++;
            for(ll j = 2; j < n; j++){
                if(tiradas[j] == 0){
                    k = 2;
                    break;
                }
                if(k == 0 && tiradas[j] == 1) k = 1;
                for(ll i = j + 1; i < n && piezas[j].second > piezas[i].first; i++) tiradas[i]++;
            }
            if(k == 0) cout << "Cesc" << endl;
            else if(k == 1) cout << "Ivet" << endl;
            else cout << "Pep" << endl;
        }
    }
    return 0;
}
