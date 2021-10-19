#include <iostream>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	long long n;
	while(cin >> n && n != 0){
		long long maxim = 0;
		long long Ans = 0;
		for(long long i = 0; i < n; ++i){
			long long a;
			cin >> a;
			if(a > maxim){
				Ans += (a-maxim)*i;
				maxim = a;
			} else Ans += maxim-a;
		}
		cout << Ans << endl;
	}

}