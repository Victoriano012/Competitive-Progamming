#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef pair<bool, bool> pbb;
typedef vector<pbb> vpbb;

typedef map<int, int> mii;

mii tau;

vll f = vll(2, 1);
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
    for(int x = 0; x < Q; x++){
        int t, i, j;
        cin >> t >> i >> j;
        j--;
        i--;
        if(t == 1){
            if(i == 0){
                tau[j] += 2;
                tau[j] %= 4;
            } else {
                tau[j] += 1;
                if(tau[j] % 2 ==1) tau[j] += 2;
                tau[j] %= 4;
            }
        } else {
            ll Ans = 1;
            int p;
            int h = 0;
            for(auto it = tau.begin(); it != tau.end(); it++){
                if(it->first > i){
                    if((h == 1 && it->second == 2) || (h == 2 && it->second == 3) || (h != 0 && it->second == 1)){
                        Ans == 0;
                        break;
                    }
                    if(it->second == 3){
                        if((it->first-p)%2 == 1){
                            if(h == 0) h = 1;
                            else h = 0;
                        }
                    } else if(it->second == 2){
                        if((it->first-p)%2 == 1){
                            if(h == 0) h = 2;
                            else h = 0;
                        }
                    } else if(it->second == 0){
                        if(h != 0){
                            if((it->first-p)%2 == 1) h = 3-h;
                        } else {
                            Ans = (Ans * fib(it->first-p)) % mod;
                        }
                    }
                }
                p = it->first;
            }
            if(h != 0) cout << 0 << endl;
            else cout << Ans << endl;
        }
    }
    return 0;
}