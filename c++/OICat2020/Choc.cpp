#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m, a;
    while(cin >> n >> m){
        long long Ans = 0;
        int c = 0, r = 0;
        vector<pair<int,char>> v;
        for(int i = 0; i < n; i++){
            cin >> a;
            v.push_back(make_pair(a, 'r'));
        }
        for(int i = 0; i < m; i++){
            cin >> a;
            v.push_back(make_pair(a, 'c'));
        }
        sort(v.begin(), v.end());
        for(int i = m+n-1; i >= 0; i--){
            if(v[i].second == 'c'){
                Ans += v[i].first*(n-r);
                c++;
            } else {
                Ans += v[i].first*(m-c);
                r++;
            }
        }
        cout << Ans << endl;
    }
}