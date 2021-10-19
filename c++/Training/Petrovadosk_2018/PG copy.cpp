#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

    int n; cin >> n;
    vector<int> x(n+1), y(n+1);
    for(int i = 0; i <= n; ++i) cin >> x[i] >> y[i];
    ll r_n = 0, r_d = 1;
    for(int k = 1; k < n; ++k){
        ll lambda_n = (y[k+1]-y[k])*(x[k]-x[k-1]) - (y[k]-y[k-1])*(x[k+1]-x[k]);
        ll lambda_d = (x[k]-x[k-1])*(x[k+1]-x[k]); 
        r_n += lambda_n/lambda_d*(x[n]-x[k]);
    }
    r_d *= 2;
    if(abs(r_n/2-y[n]) > 1e-6 or abs((y[n]-y[n-1])/(x[n]-x[n-1])+(y[1]-y[0])/(x[1]-x[0])) > 1e-6){
        cout << "No" << endl;
    } else cout << "Yes" << endl;
}