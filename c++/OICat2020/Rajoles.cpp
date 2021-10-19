#include <bits/stdc++.h>

using namespace std;

int main(){
    long long n, a, b, Ans;
    string s;
    while(cin >> n){
        cin >> s;
        a = 0, b = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == 'V') a++;
            else b++;
        }
        Ans = min(a, b);
        for(int i = 0; i < n; i++){
            if(s[i] == 'V'){
                a--;
                b++;
                Ans = min(a, Ans);
            } else {
                b--;
                a++;
                Ans = min(b, Ans);
            }
        }
        cout << Ans << endl;
    }
}