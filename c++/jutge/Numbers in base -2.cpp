#include <iostream>
#include <string>

using namespace std;

int divide(int a){

    if (a > 0){
        int c;
        c = a/2;
        c = -c;
        return c;
    }
    if (a == 0) return 0;
    return((1-a) / 2);

}

string modul(int a){

    int b = (-a) % 2;
    if (a > 0) b = a%2;
    if (a == 0) b = 0;


    if(b == 0) return "0";
    if(b == 1) return "1";

}

string base(int a){

    if (a == 0){
        return "0";
    }
    if (a == 1){
        return "1";
    }
    return(modul(a) + base(divide(a)));

}

string invert(string a){

    string b;
    b = "";

    for( int x = 1; x <= a.length(); x++){

        b += a[a.length()-x];

    }

    return b;

}

int main(){

    int a;

    while(cin >> a){
        cout << a << ": " << invert(base(a)) << endl;
    }

}
