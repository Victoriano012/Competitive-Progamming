#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;

ll s = 2;
vll fibo(s);

ll c = 100000000;
ll mod = 1000000123;
ll s1 = 1;
vll factorial(1, 701242570);

/*ll fact(ll a){
    if(s1 <= a){
        factorial.push_back(((c + a)*fact(a-1))%mod);
        s1++;
    }
    return factorial[a];
}*/

ll fib(ll a){
    if(s <= a){
        fibo.push_back(fib(a-1) + fib(a-2));
        s++;
    }
    return fibo[a];
}

ll pow(ll a){
    if(a == 0) return 1;
    ll k = pow(a/2);
    if(a%2 == 0) return k*k;
    return k*k*2;
}

int main(){
    fibo[0] = 1;
    fibo[1] = 2;

    ll n;
    for(int i = 1; i <= 31; i++){
        ll k = pow(i) - fib(i);
        ll s = 701242570;
        for(ll j = c+1; j < k+c+1; j++){
            s *= j;
            s %= mod;
        }
        cout << i << " -> " << s << endl;
    }
    while(cin >> n){
        vll dies(32, 0);
        ll a;
        for(ll i = 0; i < n; i++){
            cin >> a;
            dies[a]++;
        }
        a = 1;
        for(int i = 2; i < 32; i++){
            if(dies[i] > dies[a]) a = i;
        }
        ll e = pow(a) - fib(a);
        //cout << fact(e) << endl;
    }
}