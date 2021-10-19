#include <iostream>
#include <vector>

using namespace std;

using vb = vector<bool>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using pii = pair<int, int>;
using vpii = vector<pii>;
using vvpii = vector<vector<pii>>;
using ll = long long;
using vll = vector<ll>;
using vplli = vector<pair<ll, int>>;

vb seen;
int n, m;
vvpii edges;
vi v;
vplli dp;
ll mod = 998244353;
vvi major;
vvi menor;
vll fact(101);
vll inv_fact(101);

bool dfs(int a, int b){
    if(a == b) return true;
    for(pii i: edges[a]){
        if(!seen[i.first]){
            seen[i.first] = true;
            if(dfs(i.first, b)){
                v.push_back(i.second);
                return true;
            }
        }
    }
    return false;
}

void conect(int a, int b){
    seen = vb(n, false);
    seen[a] = true;
    v = vi(0);
    dfs(a, b);
}

void dps(int a){
    if(dp[a].first != -1) return;
    dp[a].first = 0;
    for(int i = 0; i < n-1; ++i){
        if(a & (1<<i)){
            dps(a^(1<<i));
            pair<ll, int> k = dp[a^(1<<i)];
            ll majors = 0;
            for(int r: menor[i]){
                bool t = true;
                for(int j: major[r]){
                    if(j != i && a&(1 << j)){
                        t = false;
                        break;
                    }
                }
                if(t) ++majors;
            }
            ll mult = (fact[k.second+majors]*inv_fact[k.second])%mod;

            dp[a].first += (k.first*mult)%mod;
            dp[a].first %= mod;
            dp[a].second = k.second+majors+1;
        }
    }
}

ll fast(ll a, ll b){
    if(b == 0) return 1;
    ll x = fast(a, b/2);
    if(b%2 == 0) return (x*x)%mod;
    else return (((x*x)%mod)*a)%mod;
}

void factors(){
    fact[0] = 1;
    inv_fact[0] = 1;
    for(int i = 1; i <= 100; ++i){
        fact[i] = (fact[i-1]*i)%mod;
        inv_fact[i] = fast(fact[i], mod-2);
    }
}

int main(){
    factors();
    cin >> n >> m;
    edges = vvpii(n);
    for(int i = 0; i < n-1; ++i){
        int a, b; cin >> a >> b;
        edges[a-1].push_back(make_pair(b-1, i));
        edges[b-1].push_back(make_pair(a-1, i));
    }
    for(int i = n; i <= m; ++i){
        int a, b; cin >> a >> b;
        conect(a-1, b-1);
        major.push_back(v);
    }
    menor = vvi(n-1);
    for(int i = 0; i < m-n+1; ++i){
        for(int j: major[i]){
            menor[j].push_back(i);
        }
    }

    dp = vplli(1<<(n-1), make_pair(-1, 0));
    dp[0] = make_pair(1, 0);

    dps((1<<(n-1))-1);
    auto p = dp[(1<<(n-1))-1];
    cout << (p.first*((fact[m]*inv_fact[p.second])%mod))%mod << endl;
    cin >> p.first;
}