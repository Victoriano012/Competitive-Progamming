#include <iostream>
#include <fstream>
#include <map>
#include <vector>

using namespace std;

int sum(string s){
    int Ans = 0;
    for(int i = 0; i < 3; i++){
        Ans += s[i] - '0';
    }
    return Ans;
}

int main(){
    map<int, vector<string>> a1, a2, t1, t2;

    ifstream file1;
    file1.open ("input.txt");
    int n, m;
    file1 >> n >> m;
    string s;
    for(int i = 0; i < n; i++){
        file1 >> s;
        a1[sum(s.substr(0, 3))].push_back(s);
        a2[sum(s.substr(3))].push_back(s);
    }
    for(int i = 0; i < m; i++){
        file1 >> s;
        t1[sum(s.substr(0, 3))].push_back(s);
        t2[sum(s.substr(3))].push_back(s);
    }
    file1.close();

    int Ans = 0;
    vector<vector<string>> Answer;

    auto it1 = a1.begin();
    auto it2 = t2.begin();
    while(it1 != a1.end() && it2 != t2.end()){
        if(it1->first < it2->first) it1++;
        else if(it1->first > it2->first) it2++;
        else{
            int l = min(it1->second.size(), it2->second.size());
            for(int i = 0; i < l; i++){
                vector<string> v;
                v.push_back("AT");
                v.push_back(it1->second[i]);
                v.push_back(it2->second[i]);
                Answer.push_back(v);
                Ans++;
            }
            ++it1;
            ++it2;
        }
    }

    it1 = t1.begin();
    it2 = a2.begin();
    while(it1 != t1.end() && it2 != a2.end()){
        if(it1->first < it2->first) it1++;
        else if(it1->first > it2->first) it2++;
        else{
            int l = min(it1->second.size(), it2->second.size());
            for(int i = 0; i < l; i++){
                vector<string> v;
                v.push_back("TA");
                v.push_back(it1->second[i]);
                v.push_back(it2->second[i]);
                Answer.push_back(v);
                Ans++;
            }
            ++it1;
            ++it2;
        }
    }


    ofstream file2;
    file2.open ("output.txt");
    file2 << Ans << endl;
    for(vector<string> v: Answer){
        file2 << v[0] << ' ' << v[1] << ' ' << v[2] << endl;
    }
    file2.close();
}