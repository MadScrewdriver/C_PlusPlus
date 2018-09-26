//
// Created by Franek on 2018-09-12.
//

#include <bits/stdc++.h>
using namespace std;

int n, m;
const long long inf = (long long)1e10+5;
long long odl[(int) 1e6+5];
vector<pair<int, int>> graph[(int) 1e6+5];
priority_queue<pair<int, int>> kolejka;


void dik(int start){
    odl[start] = 0;

    for (int i = 0; i < graph[start].size(); ++i) {
        if (odl[graph[start][i].second] > -graph[start][i].first){
            kolejka.push(graph[start][i]);
            odl[graph[start][i].second] = -graph[start][i].first;
        }
    }

    while (!kolejka.empty()){
        int cost = -kolejka.top().first;
        int value = kolejka.top().second;
        kolejka.pop();

        for (int i = 0; i < graph[value].size(); ++i) {
            if (odl[graph[value][i].second] > cost + -graph[value][i].first){
                kolejka.push(make_pair(-(cost + -graph[value][i].first), graph[value][i].second));
                odl[graph[value][i].second] = cost + -graph[value][i].first;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int k = 1; k <= n; ++k) {
        odl[k] = inf;
    }

    for (int i = 1; i <= m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;

        graph[a].push_back(make_pair(-c, b));
        graph[b].push_back(make_pair(-c, a));
    }

    dik(1);

    for (int j = 1; j <= n; ++j) {
        cout << "Cost to " << j << " ----> " << odl[j] << "\n";
    }
}
