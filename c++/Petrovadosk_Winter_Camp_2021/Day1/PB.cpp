#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(4);
    
    int z, n, m;
    cin >> z;
    for(int w = 0; w < z; ++w){
        cin >> n >> m;
        vector<int> a(n), b(n), c(n);
        for(int i = 0; i < n; ++i) cin >> a[i] >> b[i] >> c[i];
        if(n > 2) cout << "100.000000%" << endl;
        else {
            double Ans;
            if(n == 1){
                
            } else {
                if(a[1]*b[0]-a[0]*b[1] == 0) cout << "100.000000%" << endl;
                else{
                    double y = double(c[1]*a[0]-c[0]*a[1])/double(a[1]*b[0]-a[0]*b[1]);
                    double x = -(b[0]*y+c[0])/a[0];
                    if(y <= 0 || y >= m || x <= 0 || x >= m) cout << "100.000000%" << endl;
                    else{
                        
                    }
                }
            }
        }
    }
}