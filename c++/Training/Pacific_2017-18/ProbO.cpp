#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main(){
    int n;
    while(cin >> n){
        vector<string> input(n);
        for(int i = 0; i < n; i++) cin >> input[i];
        map<char, bool> global, local;
        bool t = false;
        for(int j = 0; j < n; j++){
            if(global[input[0][j]]){
                cout << "No" << endl;
                t = true;
                break;
            }
            global[input[0][j]] = true;
        }
        if(t) continue;
        for(int i = 1; i < n; i++){
            local.clear();
            for(int j = 0; j < n; j++){
                if(!global[input[i][j]] || local[input[i][j]]){
                    cout << "No" << endl;
                    t = true;
                    break;
                }
                local[input[i][j]] = true;
            }
            if(t) break;
        }
        if(t) continue;
        for(int j = 0; j < n; j++){
            local.clear();
            for(int i = 0; i < n; i++){
                if(!global[input[i][j]] || local[input[i][j]]){
                    cout << "No" << endl << endl << endl;
                    t = true;
                    break;
                }
                local[input[i][j]] = true;
            }
            if(t) break;
        }
        if(t) continue;
        for(int i = 1; i < n; i++){
            if(input[0][i] < input[0][i-1] || input[i][0] < input[i-1][0]){
                cout << "Not Reduced" << endl;
                t = true;
                break;
            }
        }
        if(t) continue;
        cout << "Reduced" << endl;
    }
}