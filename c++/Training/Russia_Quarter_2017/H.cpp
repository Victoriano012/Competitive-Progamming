#include <iostream>
#include <fstream>

using namespace std;

typedef long long ll;

ll pow(int n){
    if(n == 0) return 1;
    int k = pow(n/2);
    k *= k;
    if(n %2 == 0) return k;
    return k*9;
}

int mod = 1e9+7;

int main(){
    ifstream file1;
    file1.open ("input.txt");
    int n;
    file1 >> n;
    file1.close();

    ofstream file2;
    file2.open ("output.txt");
    file2 << 8*pow(min(n-1, 8));
    for(int i = 9; i < n; i++) file2 << 0;
    file2 << endl;
    file2.close();
}