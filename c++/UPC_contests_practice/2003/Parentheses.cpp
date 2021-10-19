#include <iostream>
#include <stack>

using namespace std;

int main(){
    string line;
    while(cin >> line){
        cout << line << " : ";
        char next = '(';
        int Ans = 0, p = 0;
        bool rubbish = false, end = false;
        stack<int> pos;
        for(char c: line){
            if(end == true){
                rubbish = true;
                break;
            }
            if(c == 'z'){
                if(next == ')'){
                    rubbish = true;
                    break;
                }
                next = ')';
            } else if(c == '(' or c == ')'){
                if(c != next) Ans++;
                if(next == '('){
                    pos.push(1);
                    p++;
                }
                else{
                    p--;
                    if(p < 0){
                        rubbish = true;
                        break;
                    }
                    pos.pop();
                }
            } else if(c == '+'){
                if(pos.empty()){
                    rubbish = true;
                    break;
                }
                pos.top()++;
                if(next == '(' || pos.top() == 3){
                    rubbish = true;
                    break;
                }
                next = '(';
            }
            if(p == 0) end = true;
        }
        if(rubbish || p != 0 || next == '(') cout << "this is rubbish" << endl;
        else if (Ans == 0) cout << "this is a CME" << endl;
        else cout << Ans << " flip(s)" << endl;
    }
}