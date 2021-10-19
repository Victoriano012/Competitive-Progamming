#include <iostream>
#include <vector>

using namespace std;

using ll = long long;
using vi = vector<ll>;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll t, n, a, b, c;
    ll Ans;
    cin >> t;
    for(ll k = 0; k < t; ++k){
        cin >> n;
        vi m(n+1, 1e9), l(n+1, -2);
        Ans = 0;
        for(ll i = 1; i < n; ++i){
            cin >> a >> b >> c;
            Ans += c;
            if(c < m[a]) m[a] = c;
            if(c < m[b]) m[b] = c;
            ++l[a];
            ++l[b];
        }
        Ans *= 2;
        for(ll i = 1; i < n+1; ++i){
            Ans += m[i]*l[i];
        }
        cout << Ans << endl;
    }
}