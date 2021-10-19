#include <iostream>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	long long n;
	cin >> n;
	long long a, b;
	for(long long i = 0; i < n; ++i){
		cin >> a >> b;
        a -= (a+b)/2;
		cout << a*100/(a+b) << endl;
	}
}