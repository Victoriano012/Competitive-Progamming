#include <iostream>
#include <vector>
#include <map>
#include <math.h>

using namespace std;

int main(){
    int x, y;
    long long n;
    while(cin >> x >> y >> n){
        map<int, int> nums;
        bool b = true;
        int c = 0, Ans;
        while(b){
            if(n%2 == 0){
                n = n/2 + x;
            } else {
                n = 3*n + y;
            }
            if(n > pow(10, 8)){
                b = false;
                cout << n << endl;
            } else {
                if(nums.count(n)){
                    cout << c-nums[n] << endl;
                    b = false;
                } else nums[n] = c;
                c++;
            }
        }
    }
    return 1;
}