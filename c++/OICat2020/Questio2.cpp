#include <bits/stdc++.h>
#include <math.h>

using namespace std;

void primer(long long n){
    long long s = sqrt(n);
    cout << n << endl;
    cout << s << endl;
    for(int i = 2; i <= s; i++){
        if(n%i == 0){
            cout << i << endl << endl;
            return;
        }
    }
}

int main(){
    primer(11111);
    primer(1111111);
    primer(11111111111);
    primer(1111111111111);
    primer(11111111111111111);
    primer(1111111111111111111);
    cout << "Aquests són tots" << endl;
    cout << "haha";
}