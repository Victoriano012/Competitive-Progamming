#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(){
    int n, p;
    char c;
    cin >> n >> c >> p;
    if(c == 't'){
        int k = 0;
        for(int i = pow(10, n-1); k < p; i++){
            string s = to_string(i);
            for(int j = 1; j < n-1; j++){
                if(s[j] == '0' && (s[j+1] == '0' || s[j-1] > '2')){
                    i += pow(10, n-j-2);
                    s = to_string(i);
                }
            }
            cout << i << endl;
            k++;
        }
    } else {
        int k = 0;
        for(int i = pow(10, n-1); k < p; i++){
            string s = to_string(i);
            for(int j = 1; j < n-1; j++){
                if(s[j] == '0' && (s[j+1] == '0' || s[j-1] > '2')){
                    i += pow(10, n-j-2);
                    s = to_string(i);
                }
            }
            for(int j = n-1; j >= 0; j--){
                if(j != n){
                    if(s[j] == '1' && s[j+1] > '0'){
                        if(j > 0) s = s.substr(0,j) + "20" + s.substr(j+1, s.length() - j - 2);
                        else s = "20" + s.substr(j+1, s.length() - j - 2);
                    } if(s[j] == '2' && s[j+1] <= '6' && s[j+1] > '0'){
                        if(j > 0) s = s.substr(0,j) + "27" + s.substr(j+1, s.length() - j - 2);
                        else s = "27" + s.substr(j+1, s.length() - j - 2);
                    }
                }
            }
            i = stoi(s);
            cout << i << endl;
            k++;
        }
    }
    return 1;
    return 1;
}