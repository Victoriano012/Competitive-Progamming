#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int t;
    cin >> t;
    while(t--){
        int n, b, a;
        cin >> n;
        int min_a;
        cin >> min_a;
        vector<int> diferencias(n-1);
        for(int i = 0; i < n-1; i++){
            cin >> b >> a;
            diferencias[i] = a - b;
        }
        sort(diferencias.rbegin(), diferencias.rend());
        cin >> b;
        int Ans = b - min_a;
        for(int i: diferencias){
            cout << Ans << ' ';
            Ans -= i;
        }
        cout << Ans << endl;
    }
    return 0;
}
