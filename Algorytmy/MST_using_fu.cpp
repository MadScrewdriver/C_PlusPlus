//
// Created by Franek on 2018-08-23.
//

#include <bits/stdc++.h>
using namespace std;

struct edge{
    int a, b, c;
};

vector<edge> vec_of_edges;
int representant[(int) 1e6+5];
vector<pair<int, int> > graph[(int) 1e6+5];
int n, m;

int find(int from){
    if(representant[from] == from)
        return from;

    representant[from] = find(representant[from]);
    return representant[from];
}

bool onion(int a, int b){
    a = find(a);
    b = find(b);
    
    if(a == b)
        return false;
    
    representant[b] = a;
    return true;
}

bool comp_c(edge e_a, edge e_b){
    return e_a.c < e_b.c;
}

int main(){
    cin >> n >> m;

    for (int j = 0; j < m; ++j) {
        int a, b, c;
        cin >> a >> b >> c;
        vec_of_edges.emplace_back(edge{a, b, c});
    }

    for (int i = 1; i <= n; ++i) {
        representant[i] = i;
    }
    
    sort(vec_of_edges.begin(), vec_of_edges.end(), comp_c);

    for(auto e: vec_of_edges){
        if (onion(e.a, e.b)){
            graph[e.a].push_back(make_pair(e.c, e.b));
            graph[e.b].push_back(make_pair(e.c, e.a));
        }
    }

    for (int i = 1; i<= n; i++){
        cout << i << " ---> ";
        
        for (int j = 0; j < graph[i].size(); j++) {
            cout <<"(" << graph[i][j].first << "," << graph[i][j].second << ")";
        }
        
        cout << "\n";
    }


}