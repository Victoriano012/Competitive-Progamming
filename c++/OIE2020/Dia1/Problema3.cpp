#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

using ll = long long;

int main() {
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<ll> sec(n, 0);
        vector<ll> inc(n, 1);
        vector<ll> dec(n, 1);
        for(ll i = 0; i < n; i++){
            cin >> sec[i];
        }
        for(ll i = 1; i < n; i++){
            for(ll j = 0; j < i; j++){
                if(sec[j] <= sec[i]){
                    inc[i] = max(inc[i], inc[j]+1);
                }
            }
        }
        for(ll i = n-2; i >= 0; i--){
            for(ll j = n-1; j > i; j--){
                if(sec[j] <= sec[i]){
                    dec[i] = max(dec[i], dec[j]+1);
                }
            }
        }
        ll m = 0;
        for(ll i = 0; i < n; i++){
            m = max(m, inc[i] + dec[i]);
        }
        
        inc = vector<ll>(n+1, 1);
        dec = vector<ll>(n+1, 1);
        for(ll i = 1; i < n; i++){
            for(ll j = 0; j < i; j++){
                if(sec[j] >= sec[i]){
                    dec[i] = max(dec[i], dec[j]+1);
                }
            }
        }
        for(ll i = n-2; i >= 0; i--){
            for(ll j = n-1; j > i; j--){
                if(sec[j] >= sec[i]){
                    inc[i] = max(inc[i], inc[j]+1);
                }
            }
        }
        for(ll i = 0; i < n; i++){
            m = max(m, inc[i] + dec[i]);
        }
        cout << n-m+1 << endl;
    }
    return 0;
}
