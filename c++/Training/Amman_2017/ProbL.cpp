#include <iostream>
#include <vector>
 
using namespace std;
 
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
 
int main(){
    int n, m, t, a, b, c;
    cin >> t;
    while(t--){
        cin >> n >> m;
        vi v(n, 1e6 + 1);
        vector<vector<int>> aristas(m, vector<int>(3, 0));
        bool inf = false;
        for(int i = 0; i < m; i++){
            cin >> aristas[i][0] >> aristas[i][1] >> aristas[i][2];
            aristas[i][0]--;
            aristas[i][1]--;
            v[aristas[i][1]] = min(v[aristas[i][1]], aristas[i][2]);
        }
        bool t = true;
        int o = 0;
        while(t){
            if(o > 1+n){
                inf = true;
                break;
            }
            o++;
            t = false;
            for(vector<int> p : aristas){
                if(v[p[1]] > p[2] + v[p[0]]){
                    v[p[1]] = p[2] + v[p[0]];
                    t = true;
                }
            }
        }
        if(!inf){
            int Ans = 1e7;
            for(int i = 0; i < n; i++){
                Ans = min(Ans, v[i]);
            }
            cout << Ans << endl;
        } else cout << "-inf" << endl;
    }
}