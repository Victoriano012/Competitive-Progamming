#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	long long n, obj;
	while(cin >> n >> obj && n != 0){
		vector<long long> v(n);
		for(long long i = 0; i < n; ++i) cin >> v[i];
		long long last = 0, sum = 0;
		while(sum < obj && last < n){
			sum += v[last];
			++last;
		}
		if(sum < obj){
			cout << "IMPOSSIBLE" << endl;
			continue;
		}
		long long curr = 0;
		if(last == n){
			while(sum - v[curr] >= obj){
				sum -= v[curr];
				++curr;
			}
		}
		long long best = sum;
		while(last < n && best != obj){
			sum += v[last];
			++last;
			while(sum - v[curr] >= obj){
				sum -= v[curr];
				++curr;
			}
			best = min(best, sum);
		}
		cout << best << endl;
	}
}
