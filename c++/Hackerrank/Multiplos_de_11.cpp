#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        vector<int> oldmod(11), newmod(11);
        int n;
        string s;
        cin >> n >> s;
        int Ans = 0;
        for(int j = 0; j < n; j++){
            int c = s[j] - '0';
            for(int x = 0; x < 11; x++){
                newmod[(x-c+11)%11] = oldmod[x];
            }
            newmod[c]++;
            oldmod = newmod;
            Ans += newmod[0];
        }
        cout << Ans << endl;
    }  
    return 0;
}
