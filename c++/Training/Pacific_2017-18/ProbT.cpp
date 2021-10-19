//Aquest es un programa de merda, en Nistal m'ha dit com fer-lo i la solucio es el T_2

// #include <iostream>
// #include <vector>
// #include <queue>

// using namespace std;

// typedef vector<int> vi;
// typedef vector<vi> vvi;
// typedef vector<vvi> vvvi;
// typedef pair<int, int> pii;
// typedef vector<pii> vpii;
// typedef vector<vpii> vvpii;
// typedef vector<bool> vb;
// typedef vector<vb> vvb;

// vvvi graf;
// vvpii rango;
// int n, m, k, a, b, c, d, s, t;

// vvb conections;

// struct el{
//     int este;
//     el *prev;
//     el *next;
// };

// el *root = new(el);
// el *last = new(el);
// vector<el> meh;

// void compute_conections(){
//     conections = vvb(n, vb(n, false));
//     for(int i = 0; i < n; i++){
//         for(auto p: graf[i]){
//             conections[i][p[0]] = true;
//         }
//     }

//     bool t = true;
//     while(t){
//         t = false;
//         for(int i = 0; i < n; i++){
//             for(int j = 0; j < n; j++){
//                 if(conections[i][j]) continue;
//                 for(int k = 0; k < n; k++){
//                     if(conections[i][k] && conections[k][j]){
//                         conections[i][j] = true;
//                         t = true;
//                         break;
//                     }
//                 }
//             }
//         }
//     }
// }

// vpii unir(vpii a, vpii b){
//     vpii Ans;
//     auto ita = a.begin();
//     auto itb = b.begin();
//     while(ita != a.end() && itb != b.end()){
//         while(ita != a.end() && ita->second < itb->first){
//             Ans.push_back(*ita);
//             ita++;
//         }
//         if(ita == a.end()) break;
//         bool w = false;
//         while(itb != b.end() && itb->second < ita->first){
//             Ans.push_back(*itb);
//             itb++;
//             w = true;
//         }
//         if(w) continue;
//         if(itb == b.end()) break;
//         Ans.push_back(make_pair(min(ita->first, itb->first), max(ita->second, itb->second)));
//         ita++;
//         itb++;
//     }
//     if(ita == a.end()){
//         for(; itb != b.end(); itb++) Ans.push_back(*itb);
//     }
//     if(itb == b.end()){
//         for(; ita != a.end(); ita++) Ans.push_back(*ita);
//     }
//     return Ans;
// }

// vpii intersect(vpii a, pii b){
//     vpii Ans;
//     for(pii w: a){
//         if(w.first > b.second) break;
//         if(w.second <= b.second && w.second >= b.first){
//             w.first = max(w.first, b.first);
//             Ans.push_back(w);
//         } else if(w.first >= b.first){
//             w.second = b.second;
//             Ans.push_back(w);
//         } else if(w.first < b.first && w.second > b.second){
//             Ans.push_back(b);
//         }
//     }
//     return Ans;
// }

// void dfs(){
//     if(root == NULL) return;
//     int x = root->este;
//     root = root->next;
//     root->prev = NULL;
//     for(vi p: graf[x]){
//         if(p[0] == s) continue;
//         auto w = intersect(rango[x], make_pair(p[1], p[2]));
//         auto k = unir(w, rango[p[0]]);
//         if(k != rango[p[0]]){
//             rango[p[0]] = k;
//             if(p[0] != t){
//                 meh.push_back(*last);
//                 last->prev = *meh.rbegin();
//                 last->este = p[0];
//                 el yo = *last;
//                 for(el k = *root; k != yo; k = *(k->next)){
//                     if(!conections[k->este][x] && conections[x][k->este]){
                        
//                     }
//                 }
//             }
//         }
//     }
//     dfs();
// }

// int main(){
//     cin >> n >> m >> k >> s >> t;
//     s--;
//     t--;
//     graf = vvvi(n);
//     for(int i = 0; i < m; i++){
//         cin >> a >> b >> c >> d;
//         graf[a-1].push_back({b-1, c, d});
//     }
//     compute_conections();
//     rango = vvpii(n);
//     rango[s] = vpii(1, {make_pair(1, k)});

//     root->este = s;
//     root->next = NULL;
//     root->prev = NULL;
//     root->este = s;
//     root->next = NULL;
//     root->prev = NULL;

//     dfs();
//     int Ans = 0;
//     for(pii p: rango[t]){
//         Ans += p.second - p.first + 1;
//     }
//     cout << Ans << endl;
// }