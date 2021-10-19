#include <iostream>
#include <fstream>

using namespace std;

bool cosa(char a, char b){
    if(a != 'N' && a != 'S') return false;
    if(b != 'E' && b != 'W') return false;
    return true;
}

int mod = 1e9+7;

int main(){
    ifstream file1;
    file1.open ("input.txt");
    string s;
    file1 >> s;
    file1.close();


    int Ans = 1;
    for(int i = 0; i < s.length()-1; i++){
        if(cosa(s[i], s[i+1])){
            Ans *= 2;
            Ans %= mod;
            i++;
        }
    }

    ofstream file2;
    file2.open ("output.txt");
    file2 << Ans << endl;
    file2.close();
    
}