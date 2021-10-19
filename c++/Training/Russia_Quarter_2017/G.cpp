#include <iostream>
#include <fstream>

using namespace std;

typedef long long ll;

bool ans(int n){
    bool t = true;
    for(int i = 2; i*i <= n; i++){
        if(n % i == 0){
            n /= i;
            if(n % i == 0) return false;
            t = false;
            break;
        }
    }
    if(t) return false;
    t = true;
    for(int i = 2; i*i <= n; i++){
        if(n % i == 0){
            n /= i;
            if(n % i == 0) return false;
            t = false;
            break;
        }
    }
    if(t) return false;
    for(int i = 2; i*i <= n; i++){
        if(n % i == 0){
            return false;
            break;
        }
    }
    if(n == 1) return false;
    return true;
}

int main(){
    ifstream file1;
    file1.open ("input.txt");
    int n;
    file1 >> n;
    file1.close();

    ofstream file2;
    file2.open ("output.txt");
    if(ans(n)) file2 << "YES" << endl;
    else file2 << "NO" << endl;
    file2.close();
    
}