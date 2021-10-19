#include <iostream>
#include <fstream>

using namespace std;

typedef long long ll;

int main(){
    ifstream file1;
    file1.open ("input.txt");
    int n, k;
    file1 >> n >> k;
    file1.close();

    ofstream file2;
    file2.open ("output.txt");
    if(k >= n) file2 << 2 << endl;
    else {
        file2 << (2*n-1)/k + 1 << endl;
    }
    file2.close();
}