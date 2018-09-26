//
// Created by Franek on 2018-08-21.
//

#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> g[3000005];
long long int odl[3000005];
priority_queue<pair<long long int, int> > kol;
int que[3000005];
int n, m, a, b;
long long int inf = (long long) 1e18;


void dijkstra(int pocz) {
    odl[pocz]=0;
    for(int i=0; i<g[pocz].size(); i++) {

        if (g[pocz][i].second > n){
            if(odl[g[pocz][i].second]  > -1*(g[pocz][i].first)) {
                kol.push(g[pocz][i]);
                odl[g[pocz][i].second] = -1*(g[pocz][i].first);
            }
        }

        else{
            if(odl[g[pocz][i].second]  > -1*(g[pocz][i].first) + que[pocz]) {
                kol.push(make_pair(g[pocz][i].first - que[pocz], g[pocz][i].second));
                odl[g[pocz][i].second] = -1*(g[pocz][i].first) + que[pocz];
            }
        }
    }
    while(!kol.empty()) {
        int v = kol.top().second;
        long long int v_odl = -1*kol.top().first;
//        cout << v << "\n";
//        cout << v_odl << "\n";
        kol.pop();
        for(int i =0; i<g[v].size(); i++) {
//            cout << "check --> " << g[v][i].second;
            if (g[v][i].second > n && v <= n){
//                cout << "  pierwszy if \n";
                if(odl[g[v][i].second] > v_odl+(-1*g[v][i].first)) {
                    kol.push(make_pair(-1*(v_odl+(-1*g[v][i].first)), g[v][i].second));
                    odl[g[v][i].second] = v_odl+(-1*g[v][i].first );                }

            }

            else{
//                cout << " drugi if \n";
                if(odl[g[v][i].second] > v_odl+(-1*g[v][i].first) + que[v]) {
                    kol.push(make_pair(-1*(v_odl+(-1*g[v][i].first) + que[v]), g[v][i].second));
//                    cout << g[v][i].second << " = " << v_odl << " " << -1*g[v][i].first << " " <<  que[v] << "\n";
                    odl[g[v][i].second] = v_odl+(-1*g[v][i].first + que[v]);
                }
            }
        }

//        for (int j = 1; j <= n*2; ++j) {
//            cout << j << " ---> " << odl[j] << "\n";
//        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> a >> b;

    for(int i=1;i <=n; i++) {
        odl[i]=inf;
        odl[i + n]=inf;

        cin >> que[i];
        que[i + n] = que[i];
    }

    for(int i=0; i<m; i++) {
        int d, e, f;
        cin >> d >> e >> f;
//        cout << d << e << f << "\n";

        g[d].push_back(make_pair(-1*f, e));
        g[e].push_back(make_pair(-1*f, d));
        g[d + n].push_back(make_pair(-1*f, e + n));
        g[e + n].push_back(make_pair(-1*f, d + n));
        g[d].push_back(make_pair(-1*f, e + n));
        g[e].push_back(make_pair(-1*f, d + n));
    }

    if (a == b){
        cout << 0;
        return 0;
    }

//    for (int i = 1; i<= n * 2; i++){
//        cout << i << " ---> ";
//        for (int j = 0; j < g[i].size(); j++) {
//            cout <<"(" << g[i][j].first << "," << g[i][j].second << ")";
//        }
//        cout << "\n";
//    }

    dijkstra(a);
//    for(int i=1; i<=n * 2; i++) {
//        cout << i << " - " << odl[i] << "\n";
//    }

    if (odl[b + n] != inf)
        cout << odl[b + n];
    else
        cout << "NIE";
}
