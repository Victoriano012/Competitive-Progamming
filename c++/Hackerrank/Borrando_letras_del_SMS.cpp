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
        int n, k;
        cin >> n >> k;
        vector<pair<char, int>> vec(n, {0,0}), oldcheck, newcheck;
        for(int i = 0; i < n; i++){
            cin >> vec[i].first;
            vec[i].second = i;
        }
        sort(vec.begin(), vec.end());
        
        int r = 0, min = -1;
        for(int y = 0; y < k; y++){
            bool b = false;
            for(pair<char, int> p: oldcheck){
                if(!b){
                    if(p.second <= n-k+y){
                        cout << p.first;
                        b = true;
                    } else newcheck.push_back(p);
                } else {
                    if(p.second > n-k+y) newcheck.push_back(p);
                }
            }
            if(b){
                oldcheck = newcheck;
                newcheck = vector<pair<char, int>>(0);
                continue;
            }
            while(vec[r].second > n-k+y || vec[r].second <= min){
                if(vec[r].second > n-k+y) newcheck.push_back(vec[r]);
                r++;
            }
            cout << vec[r].first;
            min = vec[r].second;
            r++;
            oldcheck = newcheck;
            newcheck = vector<pair<char, int>>(0);
        }
        cout << endl;
    }
    return 0;
}
