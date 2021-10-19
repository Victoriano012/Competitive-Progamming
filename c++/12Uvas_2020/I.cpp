#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	long long n;
	while(cin >> n){
		vector<long long> Ans((n+1)/2);
		long long a;
		for(long long i = 0; i < (n+1)/2; ++i){
			for(long long j = 0; j < i; ++j){
				cin >> a;
				Ans[j] += a;
			}
			for(long long j = 0; j < n-2*i; ++j){
				cin >> a;
				Ans[i] += a;
			}
			for(long long j = i-1; j >= 0; --j){
				cin >> a;
				Ans[j] += a;
			}
		}
		for(long long i = n/2-1; i >= 0; --i){
			for(long long j = 0; j < i; ++j){
				cin >> a;
				Ans[j] += a;
			}
			for(long long j = 0; j < n-2*i; ++j){
				cin >> a;
				Ans[i] += a;
			}
			for(long long j = i-1; j >= 0; --j){
				cin >> a;
				Ans[j] += a;
			}
		}
		for(long long i = (n+1)/2-1; i > 0; --i){
			cout << Ans[i] << ' ';
		}
		cout << Ans[0] << endl;
	}
}