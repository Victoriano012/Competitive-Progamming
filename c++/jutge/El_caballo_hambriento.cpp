#include <iostream>
#include <vector>

using namespace std;

int main(){
    int f, c;
    while(cin >> f >> c){
        vector<vector<char>> coses(f, vector<char>(c));
        for(int i = 0; i < f; i++) for(int j = 0; j < c; j++) cin >> coses[i][j];
        vector<vector<int>> passos(f, vector<int>(c, -1));
        vector<pair<int, int>> vell(1, make_pair(0,0)), nou;
        cin >> vell[0].first >> vell[0].second;
        vell[0].first--;
        vell[0].second--;
        passos[vell[0].first][vell[0].second] = 0;
        int n = 0;
        bool b1 = true;
        bool b2 = true;
        while(b1){
            b1 = false;
            for(pair<int, int> p: vell){
                int i = p.first, j = p.second;
                if(i + 2 < f){
                    if(j + 1 < c){
                        if(coses[i+2][j+1] == '.' && passos[i+2][j+1] == -1){
                            passos[i+2][j+1] = n;
                            b1 = true;
                            nou.push_back(make_pair(i+2,j+1));
                        }
                        if(coses[i+2][j+1] == 'z'){
                            b2 = false;
                            b1 = false;
                            break;
                        }
                    }
                    if(j - 1 >= 0){
                        if(coses[i+2][j-1] == '.' && passos[i+2][j-1] == -1){
                            passos[i+2][j-1] = n;
                            b1 = true;
                            nou.push_back(make_pair(i+2,j-1));
                        } else if(coses[i+2][j-1] == 'z'){
                            b2 = false;
                            b1 = false;
                            break;
                        }
                    }
                }
                if(i + 1 < f){
                    if(j + 2 < c){
                        if(coses[i+1][j+2] == '.' && passos[i+1][j+2] == -1){
                            passos[i+1][j+2] = n;
                            b1 = true;
                            nou.push_back(make_pair(i+1,j+2));
                        } else if(coses[i+1][j+2] == 'z'){
                            b2 = false;
                            b1 = false;
                            break;
                        }
                    }
                    if(j - 2 >= 0){
                        if(coses[i+1][j-2] == '.' && passos[i+1][j-2] == -1){
                            passos[i+1][j-2] = n;
                            b1 = true;
                            nou.push_back(make_pair(i+1,j-2));
                        } else if(coses[i+1][j-2] == 'z'){
                            b2 = false;
                            b1 = false;
                            break;
                        }
                    }
                }
                if(i - 1 >= 0){
                    if(j + 2 < c){
                        if(coses[i-1][j+2] == '.' && passos[i-1][j+2] == -1){
                            passos[i-1][j+2] = n;
                            b1 = true;
                            nou.push_back(make_pair(i-1,j+2));
                        } else if(coses[i-1][j+2] == 'z'){
                            b2 = false;
                            b1 = false;
                            break;
                        }
                    }
                    if(j - 2 >= 0){
                        if(coses[i-1][j-2] == '.' && passos[i-1][j-2] == -1){
                            passos[i-1][j-2] = n;
                            b1 = true;
                            nou.push_back(make_pair(i-1,j-2));
                        } else if(coses[i-1][j-2] == 'z'){
                            b2 = false;
                            b1 = false;
                            break;
                        }
                    }
                }
                if(i - 2 >= 0){
                    if(j + 1 < c){
                        if(coses[i-2][j+1] == '.' && passos[i-2][j+1] == -1){
                            passos[i-2][j+1] = n;
                            b1 = true;
                            nou.push_back(make_pair(i-2,j+1));
                        } else if(coses[i-2][j+1] == 'z'){
                            b2 = false;
                            b1 = false;
                            break;
                        }
                    }
                    if(j - 1 >= 0){
                        if(coses[i-2][j-1] == '.' && passos[i-2][j-1] == -1){
                            passos[i-2][j-1] = n;
                            b1 = true;
                            nou.push_back(make_pair(i-2,j-1));
                        } else if(coses[i-2][j-1] == 'z'){
                            b2 = false;
                            b1 = false;
                            break;
                        }
                    }
                }
            }
            vell = nou;
            nou.clear();
            n++;
        }
        if(b2) cout << "no" << endl;
        else cout << n << endl;
    }
    return 1;
}