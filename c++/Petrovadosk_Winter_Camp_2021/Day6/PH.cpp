#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;

ll p;
vi fact;
vi inv_fact;
ll n, m;

ll pow(ll a, ll b){
    if(b == 0) return 1;
    ll aux = pow(a, b/2);
    if(b&1){
        return (((aux*aux)%p)*a)%p;
    }
    return (aux*aux)%p;
}

void factorial(){
    fact = vi(n*m+1);
    inv_fact = vi(n*m+1);
    fact[0] = 1;
    inv_fact[0] = 1;
    for(int i = 1; i <= n*m; ++i){
        fact[i] = (fact[i-1]*i)%p;
    }
    inv_fact[n*m] = pow(fact[n*m], p-2);
    for(int i = n*m-1; i > 0; --i){
        inv_fact[i] = inv_fact[i+1]*(i+1)%p;
    }
}

int main(){
    cin >> n >> m >> p;
    // auto start = chrono::high_resolution_clock::now();
    factorial();
    // auto stop = chrono::high_resolution_clock::now();
    // auto duration = chrono::duration_cast<chrono::seconds>(stop - start);
    // cout << duration.count() << endl; 

    vvi dp(n+1, vi(m+1));
    dp[n][m] = 1;
    for(int i = n-1; i > 0; --i)
        dp[i][m] = fact[(n-i)*m];
    
    for(int j = m-1; j > 0; --j)
        dp[n][j] = fact[n*(m-j)];
    
    for(ll i = n-1; i > 0; --i){
        for(ll j = m-1; j > 0; --j){
            ll k = n*m-i*j;
            dp[i][j] = ((dp[i+1][j]*j*(n-i))%p)*((fact[k-1]*inv_fact[k-j])%p) + ((dp[i][j+1]*i*(m-j))%p)*((fact[k-1]*inv_fact[k-i])%p);
            dp[i][j] %= p;
        }
    }
    cout << ((n*m*dp[1][1])%p+p)%p << endl;
    
    // stop = chrono::high_resolution_clock::now();
    // duration = chrono::duration_cast<chrono::seconds>(stop - start);
    // cout << duration.count() << endl;
}