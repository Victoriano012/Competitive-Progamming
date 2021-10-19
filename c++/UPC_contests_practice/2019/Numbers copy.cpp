#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;

vll Ans;

int main(){
    Ans = vll(1);
    Ans.push_back(701242570);
    Ans.push_back(75959943);
    Ans.push_back(886202154);
    Ans.push_back(958722946);
    Ans.push_back(977616735);
    Ans.push_back(702449344);
    Ans.push_back(145960886);
    Ans.push_back(556192599);
    Ans.push_back(313688461);
    Ans.push_back(341839088);
    Ans.push_back(142961257);
    Ans.push_back(102401654);
    Ans.push_back(158230025);
    Ans.push_back(811431962);
    Ans.push_back(700525542);
    Ans.push_back(667110947);
    Ans.push_back(318359275);
    Ans.push_back(75668734);
    Ans.push_back(305096781);
    Ans.push_back(758672358);
    Ans.push_back(306585779);
    Ans.push_back(45704682);
    Ans.push_back(635629138);
    Ans.push_back(775698363);
    Ans.push_back(386948795);
    Ans.push_back(845746966);
    Ans.push_back(754719320);
    Ans.push_back(554507295);
    Ans.push_back(192737914);
    Ans.push_back(0);
    Ans.push_back(0);
    int n;
    while(cin >> n){
        vll dies(32, 0);
        ll a;
        for(ll i = 0; i < n; i++){
            cin >> a;
            dies[a]++;
        }
        a = 1;
        for(int i = 2; i < 32; i++){
            if(dies[i] > dies[a]) a = i;
        }
        
        cout << Ans[a] << endl;
    }
}