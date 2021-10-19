#include <iostream>
#include <map>

using namespace std;

using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n;
    cin >> t;
    for(int j = 0; j < t; ++j){
        cin >> n;
        map<int, int> a, c;
        int a1, b1, c1, d1;
        ll Ans = 0;
        for(int i = 0; i < n; ++i){
            cin >> a1 >> c1 >> b1 >> d1;
            ++a[a1];
            ++a[b1];
            ++c[c1];
            ++c[d1];
            Ans += a1 + c1;
        }

        int curr_hb = -n;
        Ans += 2*curr_hb;

        int curr_vb = curr_hb;
        
        int prev_pos = 1; //horitzontal
        for(auto it: a){
            Ans += (it.first - prev_pos)*curr_hb;
            curr_hb += it.second;
            
            if(curr_hb >= 0) break;
            prev_pos = it.first;
        }

        prev_pos = 1; //vertical
        for(auto it: c){
            Ans += (it.first - prev_pos)*curr_vb;
            curr_vb += it.second;
            
            if(curr_vb >= 0) break;
            prev_pos = it.first;
        }

        cout << Ans << endl;
    }
}