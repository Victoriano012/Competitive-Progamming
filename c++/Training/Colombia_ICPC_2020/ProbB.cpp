#include <iostream>

using namespace std;

int main(){
    string a, b;
    cin >> a >> b;
    int l = b.length();
    int bp = l-1;
    for(int i = l-2; i >= 0; i--){
        bool t = true;
        for(int j = 0; i+j < bp, bp+j < l; j++){
            if(b[i+j] < b[bp+j]){
                t = false;
                break;
            }
        }
        if(t) bp = i;
    }

    l = a.length();
    string c = "";
    c += a[l-1];
    int ap = l-1;
    for(int i = l-2; i >= 0; i--){
        bool t = true;
        int j = 0;
        for(; i+j < ap, ap+j < l; j++){
            if(a[i+j] != a[ap+j]){
                t = false;
                break;
            }
            if(a[i+j] < b[bp]){
                break;
            }
        }
        if(t && i+j == ap){
            ap = i;
            c = a.substr(i, ap-i)+c;
        } else {
            if(ap+j == l || a[i+j] > a[ap+j]){
                ap = i;
                c = a.substr(i, j+1);
                for(j++; i+j < l; j++){
                    if(b[bp] > a[i+j]) break;
                    c += a[i+j];
                }
            }
        }
    }
    cout << c + b.substr(bp) << endl;
}