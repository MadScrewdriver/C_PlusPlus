//
// Created by Franek on 2018-08-21.
//

#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<pair<int, int> > g[1000005];
int odl[1000005];
int height[1000005];
priority_queue<pair<int, int> > kol;

void dijkstra(int pocz) {
    odl[pocz]=height[pocz];
    for(int i=0; i<g[pocz].size(); i++) {
        if(odl[g[pocz][i].second] > max(-1*g[pocz][i].first, odl[pocz])) {
            kol.push(make_pair(max(-1*g[pocz][i].first, odl[pocz]), g[pocz][i].second));
            odl[g[pocz][i].second] = max(-1*g[pocz][i].first, odl[pocz]);
//            out = max(-1*g[pocz][i].first, out);
        }
    }
    while(!kol.empty()) {
        int v = kol.top().second;
        int v_odl = -1*kol.top().first;
        kol.pop();
        for(int i =0; i<g[v].size(); i++) {
            if(odl[g[v][i].second] > max((-1*g[v][i].first), v_odl)) {
                kol.push(make_pair(-1*max((-1*g[v][i].first), v_odl), g[v][i].second));
                odl[g[v][i].second] = max((-1*g[v][i].first), v_odl);
//                out = max(-1*g[pocz][i].first, out);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i=1;i <=n; i++) {
        odl[i]=1000000000;
    }

    for (int j = 1; j <= n; ++j) {
        cin >> height[j];
    }
    
    for(int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b;
        g[a].push_back(make_pair(-1*max(height[a], height[b]), b));
        g[b].push_back(make_pair(-1*max(height[a], height[b]), a));
    }

//        for (int i = 1; i<= n * 2; i++){
//        cout << i << " ---> ";
//        for (int j = 0; j < g[i].size(); j++) {
//            cout <<"(" << g[i][j].first << "," << g[i][j].second << ")";
//        }
//        cout << "\n";
//    }
    dijkstra(1);

//        for(int i=1; i<=n * 2; i++) {
//        cout << i << " - " << odl[i] << "\n";
//    }
    cout << odl[n];
}

