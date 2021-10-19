#include <bits/stdc++.h>

using namespace std;

vector<long long> factorial(1e5+1), inv_factorial(1e5+1);

long long mod = 1e9 + 7;

long long power(long long n, long long p){
    if(p == 0) return 1;
    long long aux = power(n, p/2);
    if(p%2 == 0) return (aux*aux)%mod;
    return (((aux*aux)%mod)*n)%mod;
}

long long inversa(long long n){
    return power(n, 1e9 + 5);
}

void calcular_factorials(){
    factorial[0] = 1;
    for(int i = 1; i <= 1e5; ++i)
        factorial[i] = (factorial[i-1]*i)%mod;
    
    inv_factorial[1e5] = inversa(factorial[1e5]);
    for(int i = 1e5-1; i >= 0; --i)
        inv_factorial[i] = (inv_factorial[i+1]*(i+1))%mod;

}

long long over(int n, int k){
    return (((factorial[n]*inv_factorial[k])%mod)*inv_factorial[n-k])%mod;
}

long long solve(vector<int>& v, int min, int max, int minus){
    if(min == max-1 && v[min] != minus+1) return 0;
    if(min >= max-1) return 1;
    for(int i = max-1; i >= min; --i){
        if(v[i] == 1+minus){
            long long left = solve(v, min, i, minus);
            long long right = solve(v, i+1, max, minus+1);
            long long mid = over(max-min-1, i-min);
            return (((left * mid)%mod) * right) % mod;
        }
    }
    return 0;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

    int T;
    cin >> T;
    calcular_factorials();

    for(int c = 1; c <= T; ++c){
        int n; cin >> n;
        vector<int> v(n);
        for(int i = 0; i < n; ++i){
            cin >> v[i];
        }
        cout << "Case #" << c << ": " << solve(v, 0, n, 0) << endl;
    }
}
