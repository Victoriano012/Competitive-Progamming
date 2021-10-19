#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
    
    int t;
    cin >> t;
    for(int i = 0; i < t; ++i){
        int l;
        char c;
        string a, b;
        cin >> l >> c >> a >> b;
        if(a >= b){
            cout << "NO" << endl;
            continue;
        }
        bool used = false;
        int x;
        for(x = 0; x < l; ++x){
            if(a[x] < b[x]) break;
            if(a[x] == c) used = true;
        }

        if(x == l-1 && a[x] == b[x] -1){
            cout << "NO" << endl;
            continue;
        }
        if(used){
            if(a[x] != b[x]-1){
                a[x]++;
                cout << a << endl;
                continue;
            } else {
                if(a[x+1] != 'z'){
                    a[x+1]++;
                } else {
                    a[x]++;
                    a[x+1] = 'a';
                }
                cout << a << endl;
                continue;
            }
        } else {
            if(x == l-1){
                if(a[x] >= c || b[x] <= c){
                    cout << "NO" << endl;
                    continue;
                } else {
                    a[x] = c;
                    cout << a << endl;
                    continue;
                }
            } else {
                if(a[x] != b[x] -1){
                    a[x]++;
                    a[x+1] = c;
                    cout << a << endl;
                    continue;
                } else {
                    if(x != l-2){
                        if(a[x+1] != 'z'){
                            a[x+1]++;
                        } else {
                            a[x]++;
                            a[x+1] = 'a';
                        }
                        a[x+2] = c;
                        cout << a << endl;
                        continue;
                    } else {
                        if(a[x] == c){
                            a[x+1]++;
                            cout << a << endl;
                            continue;
                        } else if(b[x] == c){
                            b[x+1]--;
                            cout << b << endl;
                            continue;
                        } else if(a[x+1] < c){
                            a[x+1] = c;
                            cout << a << endl;
                            continue;
                        } else if(b[x+1] > c){
                            b[x+1] = c;
                            cout << b << endl;
                            continue;
                        } else {
                            cout << "NO" << endl;
                            continue;
                        }
                    }
                }
            }
        }
    }
}