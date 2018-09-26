//
// Created by Franek on 2018-08-22.
//


#include <bits/stdc++.h>
using namespace std;

int n, between_a, between_b;
vector<int> graph[(int) 1e6+5];
int pre[(int) 1e6+5];
int post[(int) 1e6+5];
int jp[(int) 1e6+5][22];
int licznik = 1;

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

void dfs(int start, int father){
    pre[start] = licznik++;
    jp[start][0] = father;
    for (int i = 0; i < graph[start].size(); ++i) {
        if (graph[start][i] != father){
            dfs(graph[start][i], start);
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
    cin >> n;

    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1, 1);
    fill_jp();

    cin >> between_a >> between_b;
    cout << lca(between_a, between_b);

}