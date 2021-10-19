#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int t, n, m;
    cin >> t;
    //for(int x = 0; x < t; x++){
        //cin >> n >> m;
    while(cin >> n >> m){
        long long k = 0;
        vector<int> equips(n + 1, 0);
        vector<vector<long long> > odi(m, vector<long long>(3));
        for(int y = 0; y < m; y++) cin >> odi[y][1] >> odi[y][2] >> odi[y][0];
        sort(odi.rbegin(), odi.rend());
        int m = 1;
        
        for(vector<long long> v: odi){
            int uno = equips[v[1]], dos = equips[v[2]];
            if(uno == 0 && dos == 0){
                equips[v[1]] = m, m++, equips[v[2]] = m, m++;
                continue;
            } else if(uno == dos){
                k = v[0];
                break;
            } else if(uno > 0 && dos > 0){
                if(uno != dos + 1 && uno != dos - 1){
                    int r;
                    if(uno < dos){
                        if(uno % 2 == 0){
                            r = uno - 1;
                        } else {
                            r = uno + 1;
                        }
                        for(int y = 1; y <= n ; y++) if(equips[y] == dos) equips[y] = r;
                    } else {
                        if(dos % 2 == 0){
                            r = dos - 1;
                        } else {
                            r = dos + 1;
                        }
                        for(int y = 1; y <= n ; y++) if(equips[y] == uno) equips[y] = r;
                    }
                }
                continue;
            } else if(uno == 0){
                if(dos % 2 == 0) equips[v[1]] = dos - 1;
                else equips[v[1]] = dos + 1;
            } else {//dos == 0
                if(uno % 2 == 0) equips[v[2]] = uno - 1;
                else equips[v[2]] = uno + 1;
            }
        }
        cout << k << endl;
    }   
    return 0;
}
