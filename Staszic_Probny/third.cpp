//
// Created by Franek on 2018-08-21.
//

#include <algorithm>
#include <bits/stdc++.h>
#include <vector>

using namespace std;
const int inf = INT_MAX;

int read_input() {
    int _integer=0;
    char _char=0;

    while(_char<48){
        _char=getchar_unlocked();
    }

    while(_char>=48) {
        _integer=10*_integer+_char-48;
        _char=getchar_unlocked();
    }

    return _integer;
}

int LowestCostNode(map<int, long long> &costs, map<int, bool> &pro){
    int lowest_cost_name = -1;
    int lowest_cost_valu = inf;

    for (auto &n : costs ){

        if (n.second < lowest_cost_valu && !pro[n.first]){
            lowest_cost_valu = n.second;
            lowest_cost_name = n.first;
        }
    }

    return lowest_cost_name;
}

int main(){
    map<int, bool> pro;
    map<int, map<int, int >> graph;
    map<int, long long > costs;
    map<int, int > neighbors;
    map<int, int > que;
    int  n = read_input(), m = read_input(), a = read_input(), b = read_input(), from, to, trav;
    long long new_cost;


    for (int k = 0; k < n; k++){
        que[k] = read_input();
        que[k + n] = que[k];
        costs[k] = inf;
        costs[k + n] = inf;
        if (k != n - 1)
            graph[k][k + n] = -que[k] * 2;
    }

    for (int p = 0; p < m; p++){
        from = read_input(); to = read_input(); trav = read_input();
        from--;
        to--;
        graph[from][to] = trav;
        graph[to][from] = trav;
        graph[from + n][to + n] = trav;
        graph[to + n][from + n] = trav;
    }


    costs[a - 1] = que[a - 1];
    for(auto &c : graph[a - 1]){
        if (c.second < 0)
            costs[c.first] = c.second;
        else
            costs[c.first] = c.second + costs[a - 1];
    }



    int node = LowestCostNode(costs, pro);

    while (node != -1){
        long long cost = costs[node];
        neighbors = graph[node];

        for (auto &no : neighbors){
            new_cost = cost + no.second + que[node];

            if(costs[no.first] > new_cost){
                costs[no.first] = new_cost;
            }
        }

        pro[node] = true;
        node = LowestCostNode(costs, pro);
    }

    int nod = b - 1, max_que = 0;


    if (costs[b + n - 1] == inf)
        cout << "NIE";
    else
        cout << costs[b + n - 1];

}