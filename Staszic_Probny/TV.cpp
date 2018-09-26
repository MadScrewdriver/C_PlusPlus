//
// Created by Franek on 2018-08-24.
//

#include <bits/stdc++.h>
using namespace std;

short n;
int out = 0;
vector<pair<int , int> > cor;

struct edge{
    short a, b;
    int c;
};

vector<edge> vec_of_edges;
int representant[5005];

int find(short from){
    if(representant[from] == from)
        return from;

    representant[from] = find(representant[from]);
    return representant[from];
}

bool onion(short a, short b){
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
    cin >> n;

    for (short i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;

        cor.push_back(make_pair(a, b));
    }

    for (short j = 1; j <= n; ++j) {
        for (short i = j + 1; i <= n; ++i) {
            vec_of_edges.emplace_back(edge{j, i, (int) ceil(sqrt(pow((cor[i - 1].first - cor[j - 1].first), 2) +
                                                                 pow((cor[i - 1].second - cor[j - 1].second), 2)))});
//            cout << "(" << vec_of_edges[vec_of_edges.size()-1].a <<  "," <<
// vec_of_edges[vec_of_edges.size()-1].b << "," << vec_of_edges[vec_of_edges.size()-1].c << ")\n";
        }
    }

//    for (int i = 0; i< vec_of_edges.size(); i++){
//        cout <<"(" << vec_of_edges[i].a <<  "," << vec_of_edges[i].b << "," << vec_of_edges[i].c << ")\n";
//    }

    for (short i = 1; i <= n; ++i) {
        representant[i] = i;
    }

    sort(vec_of_edges.begin(), vec_of_edges.end(), comp_c);

    for(auto e: vec_of_edges){
        if (onion(e.a, e.b)){
            out = max(e.c, out);
        }
    }

    cout <<out * (n-1);
}