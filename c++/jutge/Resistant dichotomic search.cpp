#include <iostream>
using namespace std;
#include <vector>

bool resistant_search(double x, const vector<double>& v){

    int mi, ma;
    mi = 0;
    ma = v.size();

    if((x < v[0]) || (x > v[ma-1])) return false;

    while( ma - mi > 1){
        int n = (ma + mi)/2;
        if(x > v[n]){
            mi = n + 1;
        } else if (x < v[n]){
            ma = n;
        } else return true;

    }

    if(x == v[mi]){
        return true;
    } else {
        return false;
    }

}
