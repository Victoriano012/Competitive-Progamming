#include <iostream>
#include <vector>

using namespace std;

int main(){
    string s, t;
    while(cin >> s >> t){
        int l = t.length();

        vector<int> kmp(l);
        kmp[0] = 0;
        for(int i = 1; i < l; i++){
            int j = i;
            while(t[kmp[j-1]] != t[i]){
                j = kmp[j-1];
                if(j == 0){
                    break;
                }
            }
            if(j == 0){
                if(t[0] == t[i]) kmp[i] = 1;
                else kmp[i] = 0;
            } else {
                kmp[i] = kmp[j-1] + 1;
            }
        }

        int Ans = 0;
        int prev = 0;
        for(int i = 0; i < l; i++){
            while(t[prev] != s[i]){
                prev = kmp[prev];
                if(prev == 0){
                    break;
                }
            }
            if(prev == 0){
                if(t[0] == s[i]) prev++;
            } else {
                prev++;
            }
            if(prev == l) Ans++, prev = kmp[l-1];
        }
        for(int i = 0; i < l-1; i++){
            while(t[prev] != s[i]){
                prev = kmp[prev];
                if(prev == 0){
                    break;
                }
            }
            if(prev == 0){
                if(t[0] == s[i]) prev++;
            } else {
                prev++;
            }
            if(prev == l) Ans++, prev = kmp[l-1];
        }
        cout << Ans << endl;
    }
}