#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
    
    int n = 1e7;
    vector<int> possible_Ans = {200, 400, 800, 1600, 3200, 6300, 12800, 25600, 51200, 102400, 204800, 409600, 719200, 1438400, 2676800};
    int min_ans = 0, max_ans = 14;
    int pedidos = 0;
    while(max_ans- min_ans > 1){
        int check = (min_ans+max_ans)/2;
        int times = 0;
        for(int i = 0; i < 9; ++i) cout << "test " << n/(2*possible_Ans[check]) << endl;
        int a;
        for(int i = 0; i < 9; ++i){
            cin >> a;
            times += a;
        }
        pedidos += 5;
        if(times >= 4) min_ans = check;
        else max_ans = check;
    }
    int pide = n/(2*possible_Ans[min_ans]*1.4);
    int times = 0;
    for(int i = pedidos; i <= 50; ++i){
        cout << "test " << pide << endl;
        int a; cin >> a;
        times += a;
    }
    cout << "estimate " << (max_ans*times+min_ans*(50-pedidos-times))/(50-pedidos) << endl;
}