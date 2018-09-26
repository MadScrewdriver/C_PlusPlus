#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

const int inf = (int)1e9+9;
const int MAXM = 1e6;
const int MAXN = 1e6;

#define dokad first
#define dlugosc second

vector<pair<int, int>> graf[MAXN];

int odl[MAXN];

struct Porownaj {
  bool operator () (int a, int b) {
    if (odl[a] == odl[b])
      return a < b;
    return odl[a] < odl[b];
  } 
};

set<int, Porownaj> kolejka;

void dijkstra(int start, int n, map<int, int > &que,  map<int, int > &parents) {
  odl[start] = 0;
  for (int i = 1; i <= n; i++)
    kolejka.insert(i);
  while (!kolejka.empty()) {
    int prop = *kolejka.begin();
    kolejka.erase(kolejka.begin());
    for (auto kraw : graf[prop]) {
      if (odl[kraw.dokad] > odl[prop] + kraw.dlugosc + que[prop -  1]) {
        kolejka.erase(kraw.dokad);
        odl[kraw.dokad] = odl[prop] + kraw.dlugosc + que[prop - 1];
        kolejka.insert(kraw.dokad);
        parents[kraw.first - 1] = prop - 1;
      }
    }    
  }
}


int read_input() {
  int _integer=0;
  char _char=0;

  while(_char<48){
    _char=getchar_unlocked();
  }

  while(_char>=48) {
    _integer=10*_integer+_char-48;
    _char=getchar_unlocked();
  }

  return _integer;
}


int main() {
    map<int, int > que;
    map<int, int > parents;
    int n = read_input(), m = read_input(), a = read_input(), b = read_input(), from, to, trav;

    if (a == b){
        cout << 0;
        return 0;
    }

    for (int k = 0; k < n; k++){
        que[k] = read_input();
    }

    int skad, dokad, dlugosc;
    for (int i = 0 ; i < m; i++) {
        cin >> skad >> dokad >> dlugosc;
        graf[skad].push_back({dokad, dlugosc});
        graf[dokad].push_back({skad, dlugosc});
    }

    for (int j = 0; j < n; j++){
        parents[j] = -1;
    }

    for(auto &c : graf[a - 1]){
        parents[c.first] = a - 1;
    }

    for (int i = 1; i <= n; i++) {
        odl[i] = inf;
    }
    dijkstra(1, n, que, parents);


    int nod = b - 1, max_que = 0;

    while (parents[nod] != -1){
        nod = parents[nod];
        max_que = max(max_que, que[nod]);
    }

    if (nod != a - 1)
        cout << "NIE";
    else
        cout << odl[b] - max_que;
}

