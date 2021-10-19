#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

bool is_perfect_prime(int n){
    if(n == 1 || n == 0) return false;
    int t = n;
    if(n>399) t = sqrt(n)+1;
    vector<int> first(t+1, 0);
    for(int i = 2; i < t; i++){
        if(first[i] == 0){
            if(n%i == 0) return false;
            first[i] = i;
            for(int j = i*i; j <= n; j += i) if(first[j] == 0) first[j] = i;
        }
    }

    while(n > 9){
        string k = to_string(n);
        n = 0;
        for(char w: k) n += w-48;
        if(first[n]!=n) return false;
    }
    return true;
}

int main(){
    int n;
    while(cin >> n) cout << is_perfect_prime(n) << endl;
    cout << 1;
    return 1;
}