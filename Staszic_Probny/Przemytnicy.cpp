//
// Created by Franek on 2018-08-21.
//

#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<pair<int, int> > g[1000005];
int odl[1000005];
priority_queue<pair<int, int> > kol;
int cost[1000005];

void dijkstra(int pocz) {
    odl[pocz]=0;
    for(int i=0; i<g[pocz].size(); i++) {
        if(odl[g[pocz][i].second] > -1*g[pocz][i].first) {
            kol.push(g[pocz][i]);
            odl[g[pocz][i].second] = -1*g[pocz][i].first;
        }
    }
    while(!kol.empty()) {
        int v = kol.top().second;
        int v_odl = -1*kol.top().first;
        kol.pop();
        for(int i =0; i<g[v].size(); i++) {
            if(odl[g[v][i].second] > v_odl+(-1*g[v][i].first)) {
                kol.push(make_pair(-1*(v_odl+(-1*g[v][i].first)), g[v][i].second));
                odl[g[v][i].second] = v_odl+(-1*g[v][i].first);
            }
        }
    }
}

int main() {
    cin >> n;
    for(int i=1;i <=n; i++) {
        odl[i]=1000000000;
        odl[i + n]=1000000000;
        cin >> cost[i];
        g[i].push_back(make_pair(-1*cost[i] / 2, i + n));
    }
    cin >> m;
    for(int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back(make_pair(-1*c, b));
        g[a + n].push_back(make_pair(-1*c, b + n));
    }

//    for (int i = 1; i<= n * 2; i++){
//        cout << i << " ---> ";
//        for (int j = 0; j < g[i].size(); j++) {
//            cout <<"(" << g[i][j].first << "," << g[i][j].second << ")";
//        }
//        cout << "\n";
//    }

    dijkstra(1);
//    for(int i=1; i<=n * 2; i++) {
//        cout << i << " - " << odl[i] << "\n";
//    }
    cout << odl[1 + n];
}
