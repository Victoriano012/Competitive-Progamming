#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll mod = 1000000000;

ll pow(ll a, int b){
    if(b == 1) return a;
    if(b == 0) return 1;
    ll Ans;
    ll k = pow(a, b/2);
    if(b % 2 == 0) Ans = (k*k)%mod;
    else Ans = (k*k*a)%mod;
    return Ans;
}

int main(){
    ll n;
    int k;
    cin >> n >> k;
    ll Ans = 0;
    for(ll i = n; i > 0; i--){
        ll y = pow(i, k);
        y *= (n/i);
        y %= mod;
        Ans += y;
        Ans %= mod;
    }
    if(Ans < 0) Ans += mod;
    cout << Ans << endl;
}