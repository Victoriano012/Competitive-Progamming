#include <iostream>
#include <vector>

using namespace std;

int main(){
    cout << "2 3" << endl;
    int n, n2, m = 0;
    cin >> n;
    n2 = n;
    while(n2 > 0){
        m++;
        n2 >>= 1;
    }
    cout << n + (1<<m) << " " << n << " 0" << endl;
    cout << (1<<m) << " " << n + (1<<m) << " " << n;
}