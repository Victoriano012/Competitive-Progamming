#include <bits/stdc++.h>

using namespace std;

vector<int> divisors(int n){
    vector<int> ans(0);
    for(int i = 2; i*i <= n; ++i){
        if(n%i == 0){
            if(n/i != 2) ans.push_back(i);
            if(i != 2 && n != i*i) ans.push_back(n/i);
        }
    }
    return ans;
}

int main(){
    vector<int> ans_with2(1e6+1, 1);
    vector<int> ans_no2(1e6+1, 1);
    ans_with2[0] = -1;
    ans_with2[1] = -1;
    ans_no2[0] = -1;
    ans_no2[1] = -1;
    ans_no2[2] = -1;
    for(int i = 3; i <= 1e6+1; ++i){
        vector<int> div = divisors(i);
        for(int k: div){
            ans_no2[i] = max(ans_no2[i], 1+ans_with2[k-1]);
        }
        if(i%2 == 0) ans_with2[i] = max(ans_no2[i], 1+ans_with2[i/2 -1]);
        else ans_with2[i] = ans_no2[i];
    }

    int T;
    cin >> T;
    for(int t = 1; t <= T; ++t){
        int n; cin >> n;
        cout << "Case #" << t << ": " << ans_no2[n] << endl;
    }
}
