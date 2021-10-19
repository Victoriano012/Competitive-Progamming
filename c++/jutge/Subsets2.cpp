#include <iostream>
#include <vector>

using namespace std;

using vs = vector<string>;
using ll = long long;

vs o, w;
ll m, n;

void Ans(ll po, ll pw){
    if(po == m){
        cout << '{';
        cout << o[0];
        for(ll i = 1; i < m; i++) cout << ',' << o[i];
        cout << '}' << endl;
    } else {
        for(ll i = pw; i <= n-m+po; i++){
            o[po] = w[i];
            Ans(po+1, i+1);
        }
    }
}

int main(){
    string a;
    cin >> m >> n;
    o = vs(m);
    w = vs(0);
    for(ll i = 0; i < n; i++){
        cin >> a;
        w.push_back(a);
    }
    if(m > 0) Ans(0, 0);
    return 1;
}