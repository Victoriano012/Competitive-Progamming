#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, k; cin >> n >> k;
    vector<int> height(n, k);
    for(int x = 0; x < 50; ++x){
        vector<pair<int, int>> current;
        for(int i = 0; i < n; ++i){
            int a;
            cin >> a;
            if(a != 0) current.push_back(make_pair(a, i));
        }

        double max_h = 0, count = 0;
        for(int i = 0; i < n; ++i){
            if(height[i] == max_h) count++;
            else if(height[i] > max_h) count = 1, max_h = height[i];
        }

        sort(current.begin(), current.end());

        double passed_h = 0, max_punct = -1;
        int nexto = -1;
        double total = current.size();
        for(double i = 0; i < total; ++i){
            if(height[current[i].second] == max_h) passed_h++;
            double punct = min(passed_h/count, 1-(passed_h/count))*(max_h/k) + min((i+1)/total, 1-((i+1)/total))*(total/n);
            if(punct > max_punct){
                nexto = i;
                max_punct = punct;
            }
        }

        cout << current[nexto].first << endl;
        fflush(stdout);

        char c;
        cin >> c;
        if(c == '<'){
            for(int i = 0; i < nexto; ++i){
                --height[current[i].second];
            }
        } else if(c == '>'){
            for(int i = nexto+1; i < total; ++i){
                --height[current[i].second];
            }
        } else break;
        cin >> c;

    }
}