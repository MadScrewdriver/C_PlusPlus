//
// Created by Franek on 2018-08-29.
//

#include <bits/stdc++.h>
using namespace std;
int how_m[(int) 1e6+5];
vector<int> graph[(int) 1e6+5];
bool processed[(int) 1e6+5];
int n, m, h;

void dfs(int start){
    processed[start] = true;
    how_m[start]++;

    for (int i = 0; i < graph[start].size(); ++i) {
        if (!processed[graph[start][i]]){
            dfs(graph[start][i]);
        }
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;

    int a, b, from;
    string syg;

    for (int i = 1; i <= m; ++i) {
        cin >> a >> b;
        graph[a].push_back(b);
    }

    cin >> h;

    for (int j = 0; j < h; ++j) {
        cin >> syg >> from;

        if (syg == "syg"){
            dfs(from);
            for (int i = 1; i <= n; ++i) {
                processed[i] = false;
            }
        } else cout << how_m[from] <<"\n";
    }

}