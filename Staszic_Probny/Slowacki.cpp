//
// Created by Franek on 2018-08-22.
//


#include <bits/stdc++.h>
using namespace std;

int n, between_a, between_b, inf = (int) 1e13+5;
vector<pair<int, int>> graph[(int) 1e6+5];
int pre[(int) 1e6+5];
int post[(int) 1e6+5];
int jp[(int) 1e6+5][22];
int licznik = 1;
long long int costs[(long long int) 1e6+5];

bool check_if_ancestor(int a, int b){
    return pre[a] <= pre[b] && post[a] >= post[b];
}

void fill_jp(){
    for (int i = 1; i < 21; ++i) {
        for (int j = 1; j <= n; ++j) {
            jp[j][i] = jp[jp[j][i - 1]][i-1];
        }
    }
}

void dfs(int start, int father, int c){
    costs[start] = costs[father] + c;
    pre[start] = licznik++;
    jp[start][0] = father;
    for (int i = 0; i < graph[start].size(); ++i) {
        if (graph[start][i].second != father){
            dfs(graph[start][i].second, start, graph[start][i].first);
        }
    }

    post[start] = licznik;
}


int lca(int a, int b){
    if (check_if_ancestor(a, b)){
        return a;
    }

    else if (check_if_ancestor(b, a)){
        return b;
    }

    int v = a;

    for (int i = 20; i >= 0; --i) {
        if(!check_if_ancestor(jp[v][i], b)){
            v = jp[v][i];
        }
    }

    return jp[v][0];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;

    for (int i = 1; i <= n - 1; ++i) {
        int a, b, c;
        cin >> a >> b >> c;

        graph[a].push_back(make_pair(c, b));
        graph[b].push_back(make_pair(c, a));
        costs[i] = inf;
    }

    costs[n] = inf;

    costs[1] = 0;
    dfs(1, 1, 0);
    fill_jp();

//    for (int j = 1; j <= n; ++j) {
//        cout << j << " ----> " << costs[j] << "\n";
//    }

    cin >> between_a;

    while (between_a != -1){
        cin >> between_b;
        int l = lca(between_a, between_b);
        cout << (costs[between_a] - costs[l]) + (costs[between_b] - costs[l]) << "\n";
        cin >> between_a;
    }
}