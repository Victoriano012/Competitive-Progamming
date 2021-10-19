#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int t, n, c;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> n >> c;
        vector<int> piedras;
        int a, b, c;
        cin >> b >> c;
        if(b == 0 || c == 0) piedras.push_back(b);
        for(int j = 1; j < n-1; j++){
            a = b, b = c;
            cin >> c;
            if(a == 0 || b == 0 || c == 0) piedras.push_back(b);
        }
        if(b == 0 || c == 0) piedras.push_back(c);
        
        int Ans = 1, ant, p = 1, z = 1;
        if(piedras[0] != 0) ant = piedras[0];
        else{
            while(p < n && piedras[p] == 0) p++, z++;
            if(p == n) Ans = c*pow(c-1, z-1);
            else Ans = pow(c-1, z), z = 1;;
        }
        while(p < n){
            if(piedras[p] != 0) ant = piedras[0];
            else{
                p++;
                while(p < n && piedras[p] == 0) p++, z++;
                if(p == n) Ans *= pow(c-1, z);
                else{
                    if(ant == piedras[p]) Ans *= (c-1)*(pow(-1, (z-1)%2) + pow(c-1, z))/(c);
                    else Ans *= (pow(-1, z%2) + pow(c-1, z+1))/(c);
                    z = 1;
                }
            }
            p++;
        }
        cout << Ans << endl;
    }
    return 0;
}
