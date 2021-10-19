#include <iostream>
#include <vector>

using namespace std;

typedef vector<double> vd;
typedef vector<vd> vvd;

int main(){
    cout.setf(ios::fixed);
    cout.precision(4);
    int t;
    cin >> t;
    for(int r = 0; r < t; r++){
        vvd probs(3, vd(3));
        vd Ans(3, 0);
        for(int i= 0; i< 3; i++){
            for(int j= 0; j< 3; j++){
                cin >> probs[i][j];
            }
        }
        double a = probs[0][1];
        double b = probs[1][2];
        double c = probs[2][0];
        double d = (1-(1-a)*(1-b)*(1-c));
        Ans[0] += a*b*(1-c) / d;
        Ans[1] += (1-a)*b*c / d;
        Ans[2] += a*(1-b)*c / d;
        
        double t = (1-a)*b*(1-c) / d;
        double x = probs[0][1];
        double y = probs[1][0];
        Ans[0] += t*x*(1-y)/(1-(1-x)*(1-y));
        Ans[1] += t*(1-x)*y/(1-(1-x)*(1-y));

        t = (1-a)*(1-b)*c / d;
        x = probs[1][2];
        y = probs[2][1];
        Ans[1] += t*x*(1-y)/(1-(1-x)*(1-y));
        Ans[2] += t*(1-x)*y/(1-(1-x)*(1-y));

        t = a*(1-b)*(1-c) / d;
        x = probs[0][2];
        y = probs[2][0];
        Ans[0] += t*x*(1-y)/(1-(1-x)*(1-y));
        Ans[2] += t*(1-x)*y/(1-(1-x)*(1-y));

        cout << Ans[0] << ' ' << Ans[1] << ' ' << Ans[2] << endl;
    }
}