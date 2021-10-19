#include <iostream>
#include <map>

using namespace std;

int main(){
    int n, m, t;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> n >> m;
        if(n%2 == 0 && m%2 == 0){
            cout << "abdullah" << endl;
        } else {
            cout << "hasan" << endl;
        }
    }
}