#include <iostream>
 
using namespace std;
 
int main(){
    string a, b;
    cin >> a >> b;
    int i = 0;
    for(; ; i++){
        if(a[i] < 'a') break;
    }
    string as = a.substr(0, i), bs = b.substr(0, i);
    if(as < bs){
        cout << '<' << endl;
    } else if(as > bs) {
        cout << '>' << endl;
    } else {
        int al = a.length(), bl = b.length();
        if(al < bl){
            cout << '<' << endl;
        } else if(al > bl){
            cout << '>' << endl;
        } else {
            as = a.substr(i), bs =  b.substr(i);
            if(as < bs){
                cout << '<' << endl;
            } else if(as > bs) {
                cout << '>' << endl;
            } else cout << '=' << endl;
        }
    }
}