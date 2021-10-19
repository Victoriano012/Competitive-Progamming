#include <iostream>
#include <map>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	long long maxim, n;
	while(cin >> maxim >> n){
		map<long long, long long> m;
		long long a;
		for(long long i = 0; i < n; ++i){
			cin >> a;
			++m[a];
		}
		long long gasto = 0, umbral = 0, gente = n;
		bool t = true;
		for(pair<long long, long long> p: m){
			if(gasto + gente*(p.first-umbral) < maxim){
				gasto += gente*(p.first-umbral);
				umbral = p.first;
				gente -= p.second;
			} else {
				t = false;
				break;
			}
		}
		if(t) cout << umbral << endl;
		else{
			long long Ans = (maxim-gasto)/gente + umbral;
			cout << Ans << endl;
		}
	}

}