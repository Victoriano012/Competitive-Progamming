#include <bits/stdc++.h>
using namespace std;
using qi = queue<int>;
using vqi = vector<qi>;

struct street {
  int starts_at;
  int ends_at;
  string name;
  int L;
};


int I, V, S, D, F;
vqi routes;
vector<street> city;

/* lights diu per cada interseccio l'ordre dels carrers (en numero) i quant
   temps esta cada carrer */
int puntuar(vector<vector<pair<int, int>>> lights) {
  vector<queue<int>> street_end(S); // coches acumulados en cada final de carrer
  vector<bool> can_pass(S, true);   // si pot passar un coche en aquest turn
  vector<int> time_at_end(V, 0);    // segon d'arribada al seguent cruze
  vector<int> car_street(V);     // carrer de cada cotxe
  vector<bool> is_moving(S, false);
  vector<int> cambiar_carrers;
  vector<bool> green(S,
                     false); // diu si el semafor al final del carrer esta verd

  for (int car = 0; car < V; ++car) {
    car_street[car] = routes[car].front();
    routes[car].pop();
  }
  for (vector<pair<int, int>> v : lights) {
    if(v.size() == 0) continue;
    green[v[0].first] = true;
  }

  int puntuacio = 0;

  for (int second = 0; second <= D; ++second) {
    for (int car = 0; car < V; ++car) {
      if (time_at_end[car] == second) {
        street_end[car_street[car]].push(car);
      }
      if (street_end[car_street[car]].front() == car &&
          can_pass[car_street[car]] && green[car_street[car]]) {
        car_street[car] = routes[car].front(); // routes es vqs
        routes[car].pop();
        if (routes[car].empty()) {
          puntuacio += F + D - second;
        }
        time_at_end[car] = second + city[car_street[car]].L;
        can_pass[car_street[car]] = false;
        cambiar_carrers.push_back(car_street[car]);
      }
    }
    for (int k : cambiar_carrers)
      can_pass[k] = true;
    for (vector<pair<int, int>> v : lights) {
      if(v.size() == 0) continue;
      int r = 0;
      for (auto p : v)
        r += p.second;
      int sec2 = second % r;
      if (sec2 == 0) {
        green[v[0].first] = true;
        green[v[v.size() - 1].first] = false;
      }
      sec2 -= v[0].second;
      for (int k = 0; k < (int)v.size() && sec2 >= 0; ++k) {
        if (sec2 == 0) {
          green[v[k].first] = true;
          green[v[k - 1].first] = false;
        }
        sec2 -= v[k].second;
      }
    }
  }
  return puntuacio;
}

int main() {
  cin >> D >> I >> S >> V >> F;

  unordered_map<string, int> carrers;
  int a,b,c; string name;
  for(int k = 0; k < S; ++k) {
    cin >> a >> b >> name >> c;
    carrers[name] = k;
    city.push_back({a,b,name,c});
  }

  int size_of_route;
  string line;
  for (int i = 0; i < V; ++i) {
    cin >> size_of_route;
    qi temp; string s;
    for (int i = 0; i < size_of_route; ++i) {
      cin >> s;
      temp.push(carrers[s]);
    }
    routes.push_back(temp);
  }




  int time, size_of_intersection;
  string str;
  vector<pair<int, int>> intersection;
  vector<vector<pair<int,int>>> lights;

  while (cin >> size_of_intersection) {
    for (int i = 0; i < size_of_intersection; ++i) {
      cin >> str >> time;
      intersection.push_back(make_pair(carrers[str], time));
    }
    lights.push_back(intersection);
    intersection.clear();
  }
  cout << puntuar(lights) << endl;
  int n = 0;
}
