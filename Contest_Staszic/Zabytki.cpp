//
// Created by Franek on 2018-08-29.
//

#include <bits/stdc++.h>
#include <memory.h>
using namespace std;
vector<int> graph[(int) 1e6+5];
pair<int,int> edge[(int) 1e6+5];
bool processed[(int) 1e6+5];
int n, m, h;
bool r;


bool dfs(int start, int main){
    processed[start] = true;

    for (int i = 0; i < graph[start].size(); ++i) {
        if (graph[start][i] == main){
            return true;
        }

        if (!processed[graph[start][i]]){
            return dfs(graph[start][i], main);
        }
    }

    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;

    int a, b;

    for (int i = 1; i <= m; ++i) {
        cin >> a >> b;
        edge[i] = {a, b};
    }

    int pocz = 0, kon = m+1, srd;

    while (kon - pocz > 1){
        r = false;
        srd = (kon + pocz) / 2;

        for (int k = 1; k <= n; ++k) {
            processed[k] = false;
        }

        for (int i = 1; i <= srd; ++i) {
            graph[edge[i].first].push_back(edge[i].second);
        }

        for (int j = 1; j <= n; ++j) {
            if (!processed[j]){
                bool r = dfs(j, j);
            }

            if(r)
                break;
        }

        if(!r){
            pocz = srd;
        } else kon = srd;

        for (int i = 1; i <= srd; ++i) {
            graph[i].clear();
        }
    }

    if (kon>m)
        cout << "NIE";
    else cout << kon;

}
