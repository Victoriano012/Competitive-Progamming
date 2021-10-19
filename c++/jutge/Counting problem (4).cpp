#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    int Ans = 0;
    while(cin >> n){
        int c = 0;
        vector <int> v (n);
        for(int x = 0; x < n; x++){
            cin >> v[x];
        }
        for(int x = 0; x < n; x++){
            int a = 0;
            int b = 0;
            for(int y = 0; y < x; y++){
                if(v[x] < v[y]){
                    a++;
                } else if(v[x] > v[y]){
                    b++;
                }
            }
            if (a == b) c++;
        }
        cout << c << endl;
    }
}

