#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

    int n; cin >> n;
    vector<long double> x(n+1), y(n+1);
    for(int i = 0; i <= n; ++i) cin >> x[i] >> y[i];
    long double r = 0;
    for(int k = 1; k < n; ++k){
        long double lambda = (y[k+1]-y[k])/(x[k+1]-x[k]) - (y[k]-y[k-1])/(x[k]-x[k-1]);
        r += lambda*(x[n]-x[k]);
        // cout << lambda /2 << endl;
    }
    // cout << r << endl;
    long double p = 1e-7;
    if(n > 10) p = 1e-5;
    if(abs(r/2-y[n]) > p or abs((y[n]-y[n-1])/(x[n]-x[n-1])+(y[1]-y[0])/(x[1]-x[0])) > p){
        cout << "No" << endl;
    } else cout << "Yes" << endl;
}