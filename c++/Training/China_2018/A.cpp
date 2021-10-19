#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

    int t;
    cin >> t;
    for(int c = 1; c <= t; ++c){
        int Ans = 0;
        int n, m;
        cin >> n >> m; 
        vector<pair<int, int>> prob(n);
        for(int i = 0; i < n; ++i){
            cin >> prob[i].first;
        }
        for(int i = 0; i < n; ++i){
            cin >> prob[i].second;
        }
        sort(prob.begin(), prob.end());
        for(int p = 0; m > 0 && p < n; ++p){
            m -= prob[p].second;
            if(m >= 0) ++Ans;
        }

        cout << "Case " << c << ": " << Ans << endl;
    }

}