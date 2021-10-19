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
        ll n, c, k, p;
        cin >> n >> c >> k >> p;
        if(c == p){
            cout << 0 << endl;
            continue;
        }
        c %= p;
        vector<ll> piedras(k, 0);
        piedras[0] = c;
        for(int i = 1; i < n; i++){
            int j = i%k;
            if(j == 0) piedras[0] = ((piedras[k-1]-piedras[1])*(c-1))%p;
            else if(j == k-1) piedras[k-1] = ((piedras[k-2]-piedras[0])*(c-1))%p;
            else piedras[j] = ((piedras[j-1]-piedras[j+1])*(c-1))%p;
        }
        ll Ans = 0;
        for(ll i: piedras) Ans += i;
        cout << Ans%p << endl;
    }
    return 0;
}
