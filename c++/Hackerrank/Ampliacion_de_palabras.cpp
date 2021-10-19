#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;

int main() {
    string s1, s2;
    while(cin >> s1){
        long long k, j, l = 0;
        cin >> k >> j;
        vector<pair<string, int>> oldtrans(26, make_pair("", 0)), newtrans(26, make_pair("", 0));
        for(int i = 0; i < 26; i++){
            cin >> oldtrans[i].first;
            oldtrans[i].second = oldtrans[i].first.length();
        }
        
        string bin0 = bitset<64>(k).to_string(), bin;
        for(int i = bin0.length()-1; i > 0; i--) bin += bin0[i];
        for(char c: bin){
            if(c == '1'){
                for(char c: s1){
                    s2 += oldtrans[c-'a'].first;
                    l += oldtrans[c-'a'].second;
                    if(l > j) break;
                }
                s1 = s2;
                s2 = "";
                l = 0;
            }
            for(int i = 0; i < 26; i++){
                for(char d: oldtrans[i].first){
                    newtrans[i].second += oldtrans[d-'a'].second;
                    newtrans[i].first += oldtrans[d-'a'].first;
                }
            }
            oldtrans = newtrans;
            newtrans = vector<pair<string, int>>(26, make_pair("", 0));
        }
        for(char c: s1){
            s2 += oldtrans[c-'a'].first;
            l += oldtrans[c-'a'].second;
            if(l > j) break;
        }
        s1 = s2;
        s2 = "";
        l = 0;
        
        cout << s1[j-1] << endl;
    }
    return 0;
}
