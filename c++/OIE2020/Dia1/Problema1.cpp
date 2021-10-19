#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_set>
using namespace std;

using ll = long long;

int main() {
    ll t;
    cin >> t;
    while(t--){
        map<string, unordered_set<pair<ll, ll>>> ips;
        ll tipo, q, tiempo, info, alfa, beta, gamma;
        string ip;
        cin >> q;
        while(q--){
            cin >> tipo;
            if(tipo == 2) cin >> alfa >> beta >> gamma;
            else{
                cin >> ip >> tiempo >> info;
                auto it = ips.find(ip);
                if(it == ips.end()){
                    ips[ip].insert({tiempo , info});
                    cout << "ac" << endl;
                } else {
                    bool can = true;
                    ll mint = tiempo - gamma;
                    ll a = 0, b = 0, to_erase = 0;
                    for(auto r = it->second.begin(); r != it->second.end(); r++){
                        if(r->first <= mint) to_erase++;
                        else {
                            a += 1, b += r->second;
                            if(a >= alfa || b >= beta){
                                cout << "ig" << endl;
                                break;
                            }
                        }
                    }
                    for(int i = 0; i < to_erase; i++) it->second.erase(it->second.begin());
                    if(can){
                        cout << "ac" << endl;
                        it->second.insert({tiempo, info});
                    }
                }
            }
        }
        cout << "--" << endl;
    }
    return 0;
}
