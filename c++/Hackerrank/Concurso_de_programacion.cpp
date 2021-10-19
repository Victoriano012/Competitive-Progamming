#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int t, n, x;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> n;
        vector<int> a(n), b(n);
        for(int j = 0; j < n; j++){
            cin >> a[j];
        }
        for(int j = 0; j < n; j++){
            cin >> b[j];
        }
        
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        
        int Ans = 0, pa = n-1, pb = n-1;
        while(pb>-1){
            while(pb>-1){
                if(b[pb] > a[pa]) pb--;
                else break;
            }
            Ans++;
            pa--;
            pb--;
        }

        if(pb == -2) Ans--;
        
        cout << Ans << endl;
    }
    return 0;
}
