#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef pair<bool, bool> pbb;
typedef vector<pbb> vpbb;

vll f = vll(2, 1);
vpbb tau;
int s = 1;
ll mod = 1000000007;
pbb tt = make_pair(true, true), ff = make_pair(false, false), ft = make_pair(false, true), tf = make_pair(true, false);

int fib(int n){
    if(s < n){
        f.push_back((fib(n-2) + fib(n-1)) % mod);
        s++;
    }
    return f[n];
}

int main(){
    int N, Q;
    cin >> N >> Q;
    tau = vpbb(N, make_pair(true, true));
    for(int x = 0; x < Q; x++){
        int t, i, j;
        cin >> t >> i >> j;
        j--;
        if(t == 1){
            if(i == 1) tau[j].first = !tau[j].first;
            else tau[j].second = !tau[j].second;
        } else {
            i--;
            ll Ans = 1;
            int p, h = 0;
            while(i <= j){
                if((h == 1 && tau[i] == ft) || (h == 2 && tau[i] == tf) || (h != 0 && tau[i] == ff)){
                    Ans == 0;
                    break;
                }
                p = i;
                while(i <= j && tau[i] == tau[p]) i++;
                if(tau[p] == tf){
                    if((i-p)%2 == 1){
                        if(h == 0) h = 1;
                        else h = 0;
                    }
                } else if(tau[p] == ft){
                    if((i-p)%2 == 1){
                        if(h == 0) h = 2;
                        else h = 0;
                    }
                } else if(tau[p] == tt){
                    if(h != 0){
                        if((i-p)%2 == 1) h = 3-h;
                    } else {
                        Ans = (Ans * fib(i-p)) % mod;
                    }
                }
            }
            if(h != 0) cout << 0 << endl;
            else cout << Ans << endl;
        }
    }
}