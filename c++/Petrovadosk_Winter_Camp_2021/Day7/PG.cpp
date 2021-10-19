#include <iostream>

using namespace std;

typedef long long ll;

ll mod = 998244353;

int main(){
    int n, k; cin >> n >> k;
    string s; cin >> s;
    ll one_w = 0, one_wa = 0, one_a = 0, one_ac = 0, one_c = 0, one_wac = 0;
    for(int i = 0; i < n; ++i){
        if(s[i] == 'W') ++one_w;
        else if(s[i] == 'A'){
            ++one_a;
            one_wa += one_w;
            one_wa %= mod;
        } else if(s[i] == 'C'){
            ++one_c;
            one_wac += one_wa;
            one_wac %= mod;
            one_ac += one_a;
        }
    }
    ll w = one_w, wa = one_wa, wac = one_wac;
    for(int i = 1; i < k; ++i){
        wac += one_wac + w*one_ac + wa*one_c;
        wac %= mod;
        wa += w*one_a + one_wa;
        wa %= mod;
        w += one_w;
        w %= mod;
    }
    cout << wac << endl;
}