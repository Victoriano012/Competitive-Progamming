#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

using ll = long long;

int main() {
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<ll> h(n);
        for(int i = 0; i < n; i++) cin >> h[i];
        ll p = n-1;
        ll Ans = 0;
        for(ll i = 0; i < n; i++){
            while(h[p] < i+1) p--;
            while(h[i] < p+1){
                Ans += h[p] - i;
                h[p] = i;
                p--;
            }
            h[i] =  p + 1;
            Ans += h[i] - p - 1;
        }
        cout << Ans << endl;
    }
    return 0;
}
