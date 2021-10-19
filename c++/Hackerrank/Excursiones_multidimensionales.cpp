#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

using ll = long long;
using vvll = vector<vector<ll>>;
using vll = vector<ll>;

vvll Ans;
vll fact, inv_fact, quad_fact, inv_quad_fact;
ll mod;

void crear_factorials(){
    fact = vll(201);
    fact[0] = 1;
    ll f = 1;
    for(ll i = 1; i < 201; i++){
        f *= i;
        f %= mod;
        fact[i] = f;
    }
}

void crear_factorials_inversos(){
    inv_fact = vll(201);
    for(ll i = 0; i < 201; i++){
        for(ll j = 0; j < mod-1; j++){
            if(fact[i]*j%mod == 1){
                inv_fact[i] = j;
                break;
            }
        }
    }
}

void crear_factorials_quadrats(){
    quad_fact = vll(201);
    for(ll i = 0; i < 201; i++){
        quad_fact[i] = i*i%mod;
    }
}

void crear_factorials_quadrats_inversos(){
    inv_quad_fact = vll(201);
    for(ll i = 0; i < 201; i++){
        for(ll j = 0; j < mod-1; j++){
            if(quad_fact[i]*j%mod == 1){
                inv_quad_fact[i] = j;
                break;
            }
        }
    }
}

void crear_coses(){
    crear_factorials();
    crear_factorials_inversos();
    crear_factorials_quadrats();
    crear_factorials_quadrats_inversos();
}

ll resposta(long n, ll k){
    if(k == 1){
        while(Ans[1].size() < (unsigned)n+1) Ans[1].push_back(-1);
        if(Ans[1][n] == -1) Ans[1][n] = fact[2*n]*inv_quad_fact[n] % mod;
    } else {
        ll add = 0;
        while(Ans.size() < (unsigned)k+1) Ans.push_back(vll(0));
        while(Ans[k].size() < (unsigned)n+1) Ans[k].push_back(-1);
        if(Ans[k][n] == -1){
            ll add = 0;
            for(ll i = 0; i <= n; i++){
                add += resposta(i, k-1)*fact[2*n]*inv_fact[2*i]*inv_quad_fact[n-i];
            }
            Ans[k][n] = add;
        }
    }
    return Ans[k][n];
}

int main() {
    mod = 998244353;
    crear_coses();
    ll t, n, k;
    cin >> t;
    Ans = vvll(2);
    for(ll x = 0; x < t; x++){
        cin >> n >> k;
        cout << resposta(n, k) << endl;
    }
    return 0;
}
