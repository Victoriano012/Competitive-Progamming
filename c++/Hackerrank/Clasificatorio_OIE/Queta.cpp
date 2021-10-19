#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int t, n, a, k, Ans;
    vector<vector<long long> > m;
    cin >> t;
    for(int i = 0; i < t; i++){
        k = 0, Ans = 0;
        cin >> n >> a >> a;
        m = vector<vector<long long> >(n, vector<long long>(2));
        for(int x = 0; x < n; x++) cin >> m[x][0];
        for(int x = 0; x < n; x++) cin >> m[x][1];
        for(int x = 0; x < n; x++){
            if(m[x][1] == 1){
                if(k == 0) Ans++;
                else k--;
            } else {
                k++;
            }
        }
        Ans += k;
        cout << Ans << endl << endl;
    }
    return 0;
}
