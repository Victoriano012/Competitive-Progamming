#include <iostream>

using namespace std;

using ll = long long;

ll p = 998244353;

ll pow(ll a, ll b){
    if(b == 0) return 1;
    ll aux = pow(a, b/2);
    if(b&1){
        return (((aux*aux)%p)*a)%p;
    }
    return (aux*aux)%p;
}

ll inv(ll a){ return pow(a, p-2); }

int main(){
    ll inv_2 = inv(2);
    while(true) cout << 5*inv_2%p << endl;
}