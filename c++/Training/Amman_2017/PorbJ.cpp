#include <iostream>

using namespace std;

int main(){
    int t;
    cin >> t;
    string s;
    getline(cin, s);
    for(int i = 0; i < t; i++){
        getline(cin, s);
        int l = s.length();
        bool t = true;
        for(int x = 2; x < l; x++){
            if( (l-x+1) % x == 0){
                int r = (l-x+1) / x + 1;
                bool b = true;
                for(int j = 1; j < x; j++){
                    if(s[r*j-1] != ' '){
                        b = false;
                        break;
                    }
                }
                if(b){
                    cout << "YES" << endl;
                    t = false;
                    break;
                }
            }
        }
        if(t) cout << "NO" << endl;
    }
}