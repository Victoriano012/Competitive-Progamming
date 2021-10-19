#include <iostream>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i){
		int a, b, c;
		cin >> a >> b >> c;
		if(a > b*c) cout << "ENCENDIDOS" << endl;
		else if(a < b*c) cout << "HORAS" << endl;
		else cout << "AMBAS" << endl;
	}
}