#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    int t, n, b;
    char a;
    string p;
    cin >> t >> n >> b >> p;
    int bn = b*n;
    while(t--){
        vector<int> h(n, 0);
        int curr = 0, pre = 0, last = 0;
        for(int i = 0; i < b*n; ++i){
            if(curr < n && h[curr] == b-2) ++curr;
            cin >> a;
            if(a == 57){
                if(last < pre){
                    cout << last+1 << endl;
                    ++last;
                } else if(pre < curr){
                    cout << pre+1 << endl;
                    ++pre;
                } else {
                    cout << curr+1 << endl;
                    ++h[curr];
                }
            } else if(a == 56){
                if(pre < curr){
                    cout << pre+1 << endl;
                    ++pre;
                } else {
                    cout << curr+1 << endl;
                    ++h[curr];
                }
            } else {
                if(curr != n){
                    cout << curr+1 << endl;
                    ++h[curr];
                } else {
                    if(pre < curr){
                        cout << pre+1 << endl;
                        ++pre;
                    } else {
                        cout << last+1 << endl;
                        ++last;
                    }
                }
            }
        }
    }
    cin >> t;
}