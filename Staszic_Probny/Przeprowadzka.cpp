//
// Created by Franek on 2018-08-21.
//

#include <bits/stdc++.h>

using namespace std;

int n, m, z;
vector<pair<int, int> > g[1000005];
int odl[1000005];
priority_queue<pair<int, int> > kol;
pair<int, int> s[(int) 1e6+5];
int suma;

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
    cin >> n >> m >> z;

    for(int i=1;i <=n; i++) {
        odl[i]=1000000000;
    }

    for(int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        if (c % 3 == 0){
            g[a].push_back(make_pair(-1*c, b));
            g[b].push_back(make_pair(-1*c, a));
            g[a+n].push_back(make_pair(-1*c, b+n));
            g[b+n].push_back(make_pair(-1*c, a+n));
            g[a+n*2].push_back(make_pair(-1*c, b+n*2));
            g[b+n*2].push_back(make_pair(-1*c, a+n*2));
        }

        else if (c % 3 == 1){
            g[a].push_back(make_pair(-1*c, b + n));
            g[b + n].push_back(make_pair(-1*c, a + 2*n));
            g[a+n].push_back(make_pair(-1*c, b+2*n));
            g[b+2*n].push_back(make_pair(-1*c, a));
            g[a+n*2].push_back(make_pair(-1*c, b));
            g[b].push_back(make_pair(-1*c, a+n));
        }

        else if (c % 3 == 2){
            g[a].push_back(make_pair(-1*c, b + 2*n));
            g[b + 2*n].push_back(make_pair(-1*c, a + n));
            g[a+n].push_back(make_pair(-1*c, b));
            g[b].push_back(make_pair(-1*c, a + 2*n));
            g[a+n*2].push_back(make_pair(-1*c, b + n));
            g[b + n].push_back(make_pair(-1*c, a));
        }
    }

    dijkstra(z);
    for(int i=1; i<=n; i++) {
        suma= odl[i] + odl[i+n] + odl[i+2*n];
        if(i == z)
        {
            suma+=2*min(odl[i+n], odl[i+2*n]);
        }
        else
        {
            suma+=2*min(odl[i],min(odl[i+n], odl[i+2*n]));
        }
        s[i].first = suma;
        s[i].second = i;
    }
    sort(s+1, s +n+1);
    int mini = s[1].first;
    cout<<mini<<endl;
    for (int j = 1; j <= n; ++j) {
        if(s[j].first>mini)
        {
            break;
        }
        cout<<j<<endl;
    }
    return 0;
}