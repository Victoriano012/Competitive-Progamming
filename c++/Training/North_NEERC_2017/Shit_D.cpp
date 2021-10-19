#include <iostream>
#include <set>
#include <map>
#include <vector>

using namespace std;

set<int> x;
map<set<int>, int> m;

int log2(int n){
    if(n == -1) return -1;
    if(n == 1) return 0;
    return 1+log2((n+1)/2);
}

int solve(){
    if(x.size() == 1 && *x.begin() == 1) return 0;
    if(m[x] != 0) return m[x];
    int Ans = 1000000;
    auto z = x;
    auto p = x;
    for(int i: z){
        x.erase(i);
        for(int j = 1; j <= i/2; ++j){
            auto cop = x;
            x.insert(j);
            x.insert(i-j);
            Ans = min(Ans, solve());
            x = cop;
        }
        x.insert(i);
    }
    m[z] = Ans+1;

    /*cout << '(';
    bool t = false;
    for(int k: z){
        if(t) cout << ", ";
        else t = true;
        cout << k;
    }
    cout << ") -> " << Ans+1 << endl;*/
    
    return Ans+1;
}

int pow2(int n){
    if(n == 0) return 1;
    int x = pow2(n/2);
    return x*x*(n%2 + 1);
}

string bin(int n){
    if(n == 1) return "1";
    if(n == 0) return "0";
    return bin(n/2) + char('0' + n%2);
}

int main(){
    set<int> r;
    r.insert(1);
    m[r] = 0;
    map<pair<int, string>, int> s;
    for(int a = 0; a < 4; a++){
        for(int b = a; b < 4; b++){
            for(int c = b; c < 5; c++){
                for(int d = c; d < 5; ++d){
                    int i = pow2(a) + pow2(b) + pow2(c) + pow2(d);
                    x.clear();
                    x.insert(i);
                    s[make_pair(i, bin(i))] = solve();
                }
            }
        }
    }
    for(auto k: s){
        cout << k.first.second << " -> " << k.second << endl;
    }
    int a;
    cin >> a;
}