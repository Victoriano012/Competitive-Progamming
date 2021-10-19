#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m;
    char a;
    while(cin >> n >> m){
        vector<int> prev(m), cur(m);
        for(int j = 0; j < n; j++){
            for(int i = 0; i < m; i++){
                if(i != 0) cur[i] = prev[i-1];
                cur[i] = max(cur[i], prev[i]);
                if(i != m-1) cur[i] = max(cur[i], prev[i+1]);
                cin >> a;
                if(a == '.') a = '0';
                a -= '0';
                cur[i] += a;
            }
            prev = cur;
            cur = vector<int>(m);
        }
        int r = 0;
        for(int i: prev) r = max(i,r);
        cout << r << endl;
    }
}