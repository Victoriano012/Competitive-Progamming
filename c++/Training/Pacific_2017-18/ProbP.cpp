#include <iostream>

using namespace std;

typedef long long ll;

int main(){
    ll a, b;
    while(cin >> a >> b){
    ll Ans = 0;
    for(ll i = 1; i*i <= b; i++){
        ll i2 = i*i;
        ll k = a;
        ll t = a%i;
        if(t != 0) k += i-t;
        for(; k <= b; k += i){
            if(i2 <= k) Ans += i;
            if(i2 < k) Ans += k/i;
        }
    }
    cout << Ans << endl;
}
}