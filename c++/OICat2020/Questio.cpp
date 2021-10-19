#include <bits/stdc++.h>

using namespace std;

int main(){
    long long a, b, c, d, n;
    n = 0;
    d = 1;
    c = 1;
    while(d < 7776000000){
        n++;
        a = b, b = c, c = 5*(a+b);
        d += c;
    }
    cout << n << endl;
    cout << "x";
}