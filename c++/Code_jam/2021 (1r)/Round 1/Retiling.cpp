#include <bits/stdc++.h>

using namespace std;

int main(){
    int T;
    for(int t = 1; t <= T; ++t){
        int r, c, f, s;
        cin >> r >> c >> f >> s;
        vector<vector<bool>> curr(r), obj(r);
        for(int i = 0; i <= r; ++i){
            string s;
            for(int j = 0; j < c; ++j){
                if(s[j] == 'M') curr[i][j] = false;
                else curr[i][j] = true;
            }
        }
        for(int i = 0; i <= r; ++i){
            string s;
            for(int j = 0; j < c; ++j){
                if(s[j] == 'M') obj[i][j] = false;
                else obj[i][j] = true;
            } 
        }

        int ans = 0;

        bool bol = true;
        while(bol){
            bol = false;
            for(int i = 0; i < r; ++i){
                for(int j = 0; j < c; ++j){
                    if(curr[i][j] != obj[i][j]){
                        // int w = count_neigh(curr, obj, i, j, r, c);
                        // if(w == 0){
                        //     ++ans;
                        //     curr[i][j] = !curr[i][j];
                        //     bol = true;
                        // } else if(w == 1){
                        //     ans += 2;
                        //     curr[i+1][j] = !curr[i+1][j];
                        //     bol = true;
                        // }
                    }
                }
            }
        }

        cout << "Case #" << t << ": " << ans << endl;
    }
}
