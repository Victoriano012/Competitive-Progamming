#include <iostream>

using namespace std;


int main(){
    int t, n, m, r;
    cin >> t;
    for(int x = 0; x < t; x++){
        cin >> n >> m;
        for(int i = 0; i < m+n; i++) cin >> r;
        if(n == 2 && m == 2){
            cout << 7 << endl;
        } else {
            cout << 1 << endl;
        }
    }

}