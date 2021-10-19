#include <iostream>

using namespace std;

int main(){
    freopen("auxiliary.in", "r", stdin);
    freopen("auxiliary.out", "w", stdout);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);

    int n;
    cin >> n;
    if(n%3 == 0) cout << n/3*7;
    else if(n%3 == 1) cout << n/3*7-3;
    else cout << n/3*7+1;
    cout << endl;
}