#include <bits/stdc++.h>
#include <math.h>

using namespace std;

bool primer(long long n){
    long long s = sqrt(n);
    for(int i = 2; i <= s; i++){
        if(n%i == 0){
            return false;
        }
    }
    return true;
}

int main(){
    queue<long long> q;
    long long a;
    q.push(2);
    q.push(3);
    q.push(5);
    q.push(7);
    while(!q.empty()){
        a = q.front();
        q.pop();
        for(int i = 1; i < 10; i+=2){
            if(primer(10*a+i)) q.push(10*a+i);
        }
    }
    cout << a << endl;
    cout << "taxa" << endl;
}