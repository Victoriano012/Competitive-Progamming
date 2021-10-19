#include <iostream>
#include <vector>

using namespace std;

int maxim(int a, int b, int c);

int input(){
    int n;
    char c;
    cin >> c;
    if(c == '+') return input() + input();
    if(c == '-') return -input();
    if(c == 'm') return maxim(input(), input(), input());
    return c-48;
}

int maxim(int a, int b, int c){
    if(a > b){
        if(a > c) return a;
        return c;
    }
    if(b > c) return b;
    return c;
}

int main(){
    while(true) cout << input() << endl;
    return 1;
}