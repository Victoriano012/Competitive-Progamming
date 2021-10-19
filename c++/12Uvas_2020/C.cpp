#include <iostream>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i){
		float a, b;
		cin >> a >> b;
		if(int((a-b/12)/30) == (a-b/12)/30){
			if(int((a-b/12)/30) < 10) cout << '0';
			cout << int((a-b/12)/30) << ':'; 
			if(int(b/6) < 10) cout << '0';
			cout << int(b/6) << endl;
		} else if(int((b-a/12)/30) == (b-a/12)/30){
			if(int((b-a/12)/30) < 10) cout << '0';
			cout << int((b-a/12)/30) << ':';
			if(int(a/6) < 10) cout << '0';
			cout << int(a/6) << endl;
		} else cout << "ERROR" << endl;
	}
}