#include <iostream>
#include <map>
#include <vector>

using namespace std;

using ll = long long;

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    ll n, k, maxim = 0; cin >> n >> k;
    map<ll, ll> m;
    m[k] = 0;
    for(ll i = 1; i < n; ++i){
        cin >> k;
        if(k == 0) continue;
        ll best = 0;
        for(auto p: m){
            best = max(best, p.second + (p.first&k));
        }
        m[k] = best;
        if(best > maxim){
            maxim = best;
            vector<ll> to_erase(0);
            for(auto p: m){
                if(p.second + p.first <= maxim){
                    to_erase.push_back(p.first);
                }
            }
            for(ll o: to_erase) m.erase(o);
        }
    }
    cout << maxim << endl;
} 
