#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int a, b, c;
    while(cin >> a >> b && (a!=0 || b!= 0)){
        vector <int> v;
        for (int x = 0; x < b; x++){
            cin >> c;
            v.push_back(c);
        }
        sort(v.begin(), v.end());
        int x = 0, y = v.size() - 1;
        while(x < y){
            if(v[x]+v[y] < a){
                x++;
            } else if (v[x]+v[y] > a){
                y--;
            } else{
                y = -5;
                cout << "married" << endl;
            }
        }
        if(y != -5){
            cout << "single" << endl;
        }
    }
}
