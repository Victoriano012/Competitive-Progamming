#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){

    int a, b;
    cin >> a >> b;

    vector <vector <int> > vec(a, vector<int>(b, 0));

    for(int x = 0; x < a; x++){
        for(int y = 0; y < b; y++){
            cin >> vec[x][y];
        }
    }

    string s;
    int r, c;
    while(cin >> s){
        if(s == "row"){
            cin >> r;
            cout << "row " << r << ":";
            r--;
            for(int y = 0; y < b; y++){
                cout << " ";
                cout << vec[r][y];
            }
            cout << endl;
        } else if(s == "column"){
            cin >> c;
            cout << "column " << c << ":";
            c--;
            for(int x = 0; x < a ; x++){
                cout << " " << vec[x][c];
            }
            cout << endl;
        } else {
            cin >> r >> c;
            cout << "element " << r << " " << c << ": ";
            r--;
            c--;
            cout << vec[r][c] << endl;
        }
    }
}