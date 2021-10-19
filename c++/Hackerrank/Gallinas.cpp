#include <cmath>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;

using vi = vector<int>;

int main() {
    int t, n, a, newp, oldp;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> n >> a;
        map<int, vector<int>> x;
        oldp = 0;
        cin >> oldp;
        for(int j = 1; j < n; j++){
            cin >> newp;
            x[newp - oldp].push_back(j);
            oldp = newp;
        }
        int parelles = 0;
        auto it = x.begin();
        vector<int> amigues(n, 1);
        while(parelles < a){
            for(int w: it->second){
                parelles += amigues[w]*amigues[w-1];
                amigues[w-1+amigues[w]] = amigues[w] + amigues[w-1];
                amigues[w-amigues[w-1]] = amigues[w] + amigues[w-1];
            }
            it++;
        }
        it--;
        cout << it->first << endl;
    }
    return 0;
}
