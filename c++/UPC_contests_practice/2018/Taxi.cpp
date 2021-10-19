#include <iostream>
#include <vector>

using namespace std;

int main(){
    string n;
    while(cin >> n){
        int s = n.length();
        if(s > 10) cout << "0 ";
        else{
            vector<bool> has(10, false);
            bool b = true;
            for(int i = 0; i < s; i++){
                int j = n[i] - '0';
                if(has[j]){
                    cout << "0 ";
                    b = false;
                    break;
                } else has[j] = true;
            }
            if(b){
                string m1 = n.substr(s-2);
                string m2 = n.substr(s-1) + n.substr(s-2, 1);
                cout << abs(stoi(m1) - stoi(m2)) << ' ';
            }
        }
        int d = 0;
        int p = 0;
        int m = max('9' - n[0], n[0] - '0');
        for(int i = 1; i < s; i++){
            int a = abs(n[0] - n[i]);
            if(d < a){
                d = a;
                p = i;
                if(d == m) break;
            }
        }
        if(d == 0) cout << 0 << endl;
        else{
            if(d>1) cout << d-1;
            cout << string(p-1, '9');
            cout << 10-d;
            cout << string(s-p-1, '0');
            cout << endl;
        }
    }
}