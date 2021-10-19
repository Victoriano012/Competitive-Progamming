#include <iostream>
using namespace std;
#include <vector>

int position(double x, const vector<double>& v, int left, int right){

    if((left > right) || (x < v[left]) || (x > v[right])) return (-1);

    int mi, ma;
    mi = left;
    ma = right+1;

    while( ma - mi > 1){
        int n = (ma + mi)/2;
        if(x > v[n]){
            mi = n + 1;
        } else if (x < v[n]){
            ma = n;
        } else return(n);

    }

    if(x == v[mi]){
        return(mi);
    } else {
        return -1;
    }

}

int main(){

    vector <double> v(10);
    v[0] = 10;
    v[1] = 25;
    v[2] = 30;
    v[3] = 40;
    v[4] = 50;
    v[5] = 60;
    v[6] = 70;
    v[7] = 80;
    v[8] = 90;
    v[9] = 100;

    cout << position(100, v, 0, 9);

    return 0;

}
