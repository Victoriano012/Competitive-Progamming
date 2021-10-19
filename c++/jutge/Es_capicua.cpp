#include <iostream>
#include <vector>

using namespace std;

bool es_capicua(int n, int b){
    vector<int> base;
    int s = 0;
    while(n!=0){
        s++;
        base.push_back(n%b);
        n /= b;
    }
    for(int i = 0; i < s/2; i++) if(base[i] != base[s-i-1]) return false;
    return true;
}

int main(){
    int n, b;
    while(cin >> n >> b){
        bool c = es_capicua(n, b);
        if(c) cout << true << endl;
        else cout << "false" << endl;
    }
    return 1;
}