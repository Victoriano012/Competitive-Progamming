#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef long long ll;

vi sieve;
ll a, b, mod = 1e9 +7;

vi divisores(int a){
    if(sieve[a] == a){
        int i = a*a;
        if(i <= b && sieve[i] == i){
            for(; i <= b; i += a){
                sieve[i] = a;
            }
        }
        return vi(1, 1);
    }
    
    vi v = divisores(a / sieve[a]);
    int l = v.size();
    for(int i = 0; i < l; i++) v.push_back(v[i]*sieve[a]);
    v.push_back(sieve[a]);
    return v;
}

int main(){
    cin >> a >> b;
    vi dp(2, a);
    ll p = a, s = a;
    sieve = vi(1, 0);
    for(int i = 1; i <= b; i++) sieve.push_back(i);
    for(ll i = 2; i <= b; i++){
        p *= a;
        p %= mod;
        dp.push_back(p);
        for(int j: divisores(i)){
            dp[i] -= dp[j];
            if(dp[i] < 0) dp[i] += mod;
        }
        s += dp[i];
        s %= mod;
    }
    cout << s << endl;
    cin >> s;
}