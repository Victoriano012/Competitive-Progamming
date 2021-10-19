#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    long t;
    cin >> t;
    for(long t1 = 0; t1 < t; t1++){
        char ant, este;
        long n;
        cin >> n;
        long i = 0;
        long Ans = 0;
        cin >> este;
        if(este == '?'){
            while(este == '?' && i < n){
                cin >> este;
                i++;
            }
        }
        while(i<n){
            if(este != '?'){
                Ans++;
                ant = este;
                i++;
                if(i<n) cin >> este;
            } else {
                cin >> este;
                i++;
                if(este != ant){
                    while(este == '?' && i < n){
                        cin >> este;
                        i++;
                    }
                    if(i != n) Ans++;
                }
            }
        }
        cout << Ans << endl;
    }
    return 0;
}