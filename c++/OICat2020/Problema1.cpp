#include <bits/stdc++.h>

using namespace std;

int main(){
    int m, g, q, a, k, b;
    while(cin >> m >> g >> q >> a >> k >> b){
        if(m%a == 0 && m/a <= q && g%b == 0 && g/b <= k){
            cout << "Enviat" << endl;
            continue;
        }
        if(g%a == 0 && g/a <= q && m%b == 0 && m/b <= k){
            cout << "Enviat" << endl;
            continue;
        }
        cout << "Error" << endl;
    }
}