#include <iostream>
#include <vector>

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;
using vpii = vector<pair<int, int>>;

vvi v;
vpii Ans;
vi free_son;

void solve(int a, int dad){
    for(int k: v[a]) if(k != dad) solve(k, a);
    vi free;
    for(int k: v[a]){
        if(k != dad){
            if(free_son[k] != -1) Ans.push_back(make_pair(a, free_son[k]));
            else free.push_back(k);
        }
    }
    int l = free.size();
    if(l&1 == 1) free_son[a] = free[l-1];
    for(int i = 0; i < l-1; i+=2){
        Ans.push_back(make_pair(free[i], free[i+1]));
    }
}

int main(){
    int n; cin >> n;
    v = vvi(n+1);
    for(int i = 1; i < n; ++i){
        int a, b; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    Ans = vpii(0);
    free_son = vi(n+1, -1);
    solve(1, 0);
    cout << Ans.size() << endl;
    for(pair<int, int> p: Ans){
        cout << p.first << ' ' << p.second << endl;
    }
}