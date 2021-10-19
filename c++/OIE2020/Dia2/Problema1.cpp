#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_set>
using namespace std;

using ll = long long;

int main() {
    int n;
    cin >> n;
    int k = (n*(n-1))/2;
    bool b = true;
    for(int i = 0; i < n; i++){
        int r = k;
        if(!b) r -= n-2+i;
        k = n-1+i; 
        for(int j = 0; j < i; j++){
            cout << r << ' ';
            if (b) r--;
            else r++;
        }
        bool b = !b;
        cout << endl;
    }
    return 0;
}
