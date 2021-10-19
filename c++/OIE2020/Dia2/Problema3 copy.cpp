#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

using ll = long long;

int main() {
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        ll p, h, d1, d2;
        cin >> p >> h;
        d2 = p+h;
        cin >> p >> h;
        if(p >= d2){
            cout << "Pep" << endl;
            for(ll i = 2; i < n; i++) cin >> p >> h;
        } else {
            bool w = false;
            if(p+h >= d2) w = true;
            d1 = min(d2, p+h);
            d2 = max(d2, p+h);
            bool b = true;
            bool c = true;
            ll i = 2;
            while(i++ < n){
                cin >> p >> h;
                if(p >= d2){
                    cout << "Pep" << endl;
                    c = false;
                    break;
                }
                if(w && p >= d1){
                    d2 = max(d2, p+h);
                    b = false;
                    break;
                }
                if(!w && p+h >= d2) w = true;
                if(p+h > d2) d1 = d2, d2 = p+h;
                else d1 = max(d1, p+h);
            }
            if(c && !b){
                while(i++ < n){
                    cin >> p >> h;
                    if(p >= d2){
                        cout << "Pep" << endl;
                        c = false;
                        break;
                    }
                    d2 = max(d2, p+h);
                }
                if(c) cout << "Ivet" << endl;
            } else if(c) cout << "Cesc" << endl;
            while(i++ < n) cin >> p >> h;
        }
    }
    return 0;
}
