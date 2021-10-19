#include <iostream>
#include <string>

using namespace std;

int par(string a){

    cout << a << endl;

    if (a.length() == 1){
        return stoi(a);
    }

    if(a[0] != '('){
        if (a[2] == '*'){
            return (par(a.substr(0,0)) * par(a.substr(4)));
        }
        if (a[2] == '+'){
            return (par(a.substr(0,0)) + par(a.substr(4)));
        }
        if (a[2] == '-'){
            return (par(a.substr(0,0)) - par(a.substr(4)));
        }
    }

    if(a[a.length() - 1] != ')'){
        if (a[a.length() - 3] == '*'){
            return (par(a.substr(0, a.length() - 5)) * par(a.substr(a.length() - 1, a.length() - 1)));
        }
        if (a[a.length() - 3] == '+'){
            return (par(a.substr(0, a.length() - 5)) * par(a.substr(a.length() - 1, a.length() - 1)));
        }
        if (a[a.length() - 3] == '-'){
            return (par(a.substr(0, a.length() - 5)) * par(a.substr(a.length() - 1, a.length() - 1)));
        }
    }

}

int main(){

    string a;
    cin >> a;

    cout << par(a.substr(2, a.length() - 3)) << endl;

}
