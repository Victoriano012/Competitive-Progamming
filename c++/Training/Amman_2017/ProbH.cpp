#include <iostream>
#include <map>

using namespace std;

int main(){
    int n, m, t;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> n >> m;
        if(n % 2 == 0 && m % 2 == 1 || m == 1 && n != 1 || m > 9*n || m == 0) cout << -1 << endl;
        else{
            string s;
            int l = 0;
            while(m >= 18){
                l++;
                s += '9';
                m -= 18;
            }
            if(m != 0 && l != n/2){
                s += '0' + m/2;
                m -= (m/2)*2;
                l++;
            }
            for(; l < n/2; l++) s += '0';
            cout << s;
            if(n%2 == 1){
                cout << m;
            }
            for(auto it = s.rbegin(); it != s.rend(); it++) cout << *it;
            cout << endl;
        }
    }
}