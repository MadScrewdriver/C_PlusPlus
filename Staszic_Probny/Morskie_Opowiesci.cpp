//
// Created by Franek on 2018-08-24.
//

#include <bits/stdc++.h>
using namespace std;

int n, m, k;
short inf = -1;
vector<int> graph[(int) 1e6+5];
queue<int> kolejka;
short check[5005][10010];

void bfs(int start){
    check[start][start] = 0;

    for(auto v: graph[start]){
        if(check[start][v] == inf){
            check[start][v] = 1;
            kolejka.push(v);
        }
    }

    int v;
    while (!kolejka.empty()){
        v = kolejka.front();
        kolejka.pop();

        for(auto j: graph[v]){
            if(check[start][j] == inf){
                check[start][j] = check[start][v]+ (short) 1;
                kolejka.push(j);
            }
        }
    }
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> k;
    for(int i = 0; i < m; i++){
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to + n);
        graph[to].push_back(from + n);
        graph[from + n].push_back(to);
        graph[to + n].push_back(from);
    }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n * 2; ++j) {
            check[i][j] = inf;
        }
        bfs(i);
    }

    for (int l = 1; l <= k; ++l) {
        int a, b, c;
        cin >> a >> b >> c;

        if (graph[a].empty() || graph[b].empty()){
            if (a == b && c == 0){
                cout << "TAK\n";
            } else cout << "NIE\n";
        }

        else if (c % 2 == 1){
            if(check[a][b + n] <= c && check[a][b + n] > inf){
                cout << "TAK\n";
            } else cout << "NIE\n";
        }

        else{
            if(check[a][b] <= c && check[a][b] > inf){
                cout << "TAK\n";
            } else cout << "NIE\n";
        }
    }


//    for (int j = 1; j <= n * 2; ++j) {
//        cout << "Dystans do " << j << " = " << costs[j] << "\n";
//    }
}

