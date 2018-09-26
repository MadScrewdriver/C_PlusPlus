//
// Created by Franek on 2018-08-21.
//
#include <bits/stdc++.h>
using namespace std;

int n, m, inf = (int) 1e9+5;
vector<int> graph[(int) 1e6+5];
queue<int> kolejka;
int costs[(int) 1e6+5];

void bfs(int start){
    costs[start] = 0;
    
    for(auto v: graph[start]){
        if(costs[v] == inf){
            costs[v] = 1;
            kolejka.push(v);
        }
    }
    
    int v;
    while (!kolejka.empty()){
        v = kolejka.front();
        kolejka.pop();

        for(auto j: graph[v]){
            if(costs[j] == inf){
                costs[j] = costs[v]+1;
                kolejka.push(j);
            }
        }
    }
}


int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    
    for (int i = 1; i <= n; i++){
        costs[i] = inf;
    }
    
    bfs(1);

    for (int j = 1; j <= n; ++j) {
        cout << "Dystans do " << j << " = " << costs[j] << "\n";
    }
}

