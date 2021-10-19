#include <bits/stdc++.h>

using namespace std;

int main(){
    int T = 100, n = 100, k;
    cin >> T >> n;
    while(T--){
        for(int i = 1; i < n; ++i){
            cout << "M " << i << ' ' << n << endl;
            cin >> k;
            if(i < k){
                cout << "S " << i << ' ' << k << endl;
                cin >> k;
            }
        }
        cout << "D" << endl;
        cin >> k;
    }
}
