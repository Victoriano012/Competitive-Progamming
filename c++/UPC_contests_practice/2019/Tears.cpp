#include <iostream>
#include <cmath>

using namespace std;

double k(double x){ return x*x; }

int main(){
    cout.setf(ios::fixed);
    cout.precision(4);
    double r, s, x, y;
    while(cin >> r >> x >> y >> s){
        pair<double, double> t;
        t.second = sqrt(k(x) + k(y)) + r;
        t.first = abs(t.second - 2*r) / s;
        t.second /= s;
        if(k(r*cos(t.first)-x) + k(r*sin(t.first)-y) > k(t.first*s) ) swap(t.first, t.second);
        while(round(t.first*10000) != round(t.second*10000)){
            double new_t = (t.first+t.second) / 2;
            if(k(r*cos(new_t)-x) + k(r*sin(new_t)-y) < k(new_t*s) ){
                t.first = new_t;
            } else {
                t.second = new_t;
            }
        }
        cout << t.first << endl;
    }
}