#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

    int n; cin >> n;
    int p2 = 1;
    while(p2 <= n) p2 *= 2;

    vector<pair<int, int>> edges(n-1);
    vector<bool> rep(n+1, false);
    vector<int> can(n+1, false);
    int x = n;
    for(int i = 1; i <= n; ++i) cin >> can[i];
    for(int i = 0; i < n-1; ++i){
        cin >> edges[i].first >> edges[i].second;
        rep[edges[i].first] = !rep[edges[i].first];
        rep[edges[i].second] = !rep[edges[i].second];
        x ^= edges[i].first^edges[i].second;
    }

    if(x == 0){
        cout << n << endl;
        for(auto p: edges){
            cout << p.first << ' ' << p.second << endl;
        }
        return 0;
    }

    vector<int> mine(n+1);
    for(int j = 1; j <= n; ++j) mine[j] = j;

    for(int i = 1; i <= n; ++i){
        if(can[i] and rep[i]){
            if((x^i) > n){
                mine[i] = x^i;
                cout << n << endl;
                for(auto p: edges){
                    cout << mine[p.first] << ' ' << mine[p.second] << endl;
                }
                return 0;
            } else if(can[x^i] and !rep[x^i]){
                mine[i] = x^i;
                mine[x^i] = p2;
                cout << n << endl;
                for(auto p: edges){
                    cout << mine[p.first] << ' ' << mine[p.second] << endl;
                }
                return 0;
            } 
        }
    }

    int perf = -1;
    for(int i = 1; i <= n; ++i){
        if(can[i] and rep[i]){
            if(perf != -1 and (x^perf) != i){
                mine[perf] = p2;
                mine[i] = x^p2^perf^i;
                cout << n << endl;
                for(auto p: edges){
                    cout << mine[p.first] << ' ' << mine[p.second] << endl;
                }
                return 0;
            } else {
                perf = i;
            }
        }
    }
    cout << -1 << endl;
}
