#include <bits/stdc++.h>

using namespace std;

void add_num(long long &u, int k) {
    u *= 10;
    u += k;
}

long long get_ans(vector<int> nums, long long big, long long low, int total){
    while(total>0){
        for(int i = 0; i < 10; ++i){
            if(nums[i] > 0){
                add_num(big, i);
                --nums[i];
                --total;
                break;
            }
        }
        for(int i = 9; i >= 0; --i){
            if(nums[i] > 0){
                add_num(low, i);
                --nums[i];
                --total;
                break;
            }
        }
    }
    cout << big << endl << low << endl;
    return big-low;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

    int t;
    cin >> t;
    for(int c = 1; c <= t; ++c){
        long long ans;
        string s;
        cin >> s;
        vector<int> nums(10, 0);
        for(char c: s) ++nums[c-'0'];
        int total = 0;
        for(int i = 0; i < 10; ++i){
            total += nums[i];
        }
        long long low = 0;
        long long big = 0;
        if(total%2 == 0){
            bool t = true;
            bool w = true;
            while(w){
                w = false;
                for(int i = 0; i < 10; ++i){
                    if(t && i == 0) continue;
                    if(nums[i] > 1){
                        add_num(big, i);
                        add_num(low, i);
                        nums[i] -= 2;
                        total -= 2;
                        t = false;
                        w = true;
                        break;
                    }
                }
            }
            for(int j = 1; j < 10; ++j){
                bool b = false;
                long long ans = 0;
                for(int i = 0; i < 10-j; ++i){
                    if(t && i == 0) continue;
                    if(nums[i] > 0 && nums[i+j] > 0){
                        add_num(big, i+j);
                        add_num(low, i);
                        nums[i]--;
                        nums[i+j]--;
                        total -= 2;
                        b = true;
                        ans = max(ans, get_ans(nums, big, low, total));
                        big %= 10;
                        low %= 10;
                        nums[i]++;
                        nums[i+j]++;
                        total += 2;
                    }
                }
                if(b){
                    cout << "Case " << c << ": " << ans << endl;
                    break;
                }
            }
        } else {
            for(int i = 1; i < 10; ++i){
                if(nums[i] > 0){
                    add_num(big, i);
                    --nums[i];
                    --total;
                    break;
                }
            }
            cout << big << endl << low << endl;
            cout << "Case " << c << ": " << get_ans(nums, big, low, total) << endl;
        }
    }
}