#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;
typedef priority_queue<pii> ppii;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
typedef set<ll> sll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;

ll T = -1, L;
ppii pos;
vvvll par;
sll bad;

void bfs(){
    if(pos.empty()) return;
    pii now = pos.top();
    now.first = now.first;
    pos.pop();
    if(now.first < 0) return;
    if(now.second == 0){
        T = now.first;
        return;
    }
    if(bad.find(now.second) != bad.end()){
        bfs();
        return;
    }
    bad.insert(now.second);
    for(vll b: par[now.second]){
        ll k = (now.first - b[1] - b[2])/b[3];
        if(k >= 0){
            k = b[2] + k*b[3];
            pos.push(make_pair(k, b[0]));
        }
    }
    bfs();
    return;
}

int main(){
    ll N, M;
    cin >> N >> M >> L;
    par = vvvll(N, vvll(0));
    for(ll i = 0; i < M; i++){
        vll b(4);
        ll a;
        cin >> b[0] >> a >> b[1] >> b[2] >> b[3];
        par[a].push_back(b);
    }
    pos.push(make_pair(L, N-1));
    bfs();
    cout << T << endl;
    return 0;
}