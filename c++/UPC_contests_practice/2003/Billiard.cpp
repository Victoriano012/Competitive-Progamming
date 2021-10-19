#include <iostream>

using namespace std;

int main(){
    int w, d;
    long long l;
    while(cin >> l >> w >> d){
        if(d == 0){
            while(w%2 == 0 && l %2 == 0) w/= 2, l /= 2;
            if(l%2 == 0) cout << "lower ";
            else cout << "upper ";
            if(w % 2 == 0) cout << "left" << endl;
            else cout << "right" << endl;
        } else {
            int l2 = l%w;
            bool t = true;
            for(int i = 1; i < w; i++){
                if(i*l2 % w == w-d){
                    if(((l*i+d)/w)%2 == 0) cout << "lower ";
                    else cout << "upper ";
                    if(i % 2 == 0) cout << "left" << endl;
                    else cout << "right" << endl;
                    t = false;
                    break;
                }
            }
            if(t) cout << "never" << endl;
        }
    }
}