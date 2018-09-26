//
// Created by Franek on 2018-08-29.
//

#include <bits/stdc++.h>
using namespace std;

vector<int> graph[(int) 1e6+5];
bool processed[(int) 1e6+5];
int post[(int) 1e6+5];
int n, m, h, s = 0, licznik=0, size_of_table=2;
int tree[(1 << 21) + 5];
bool zrodlo[(int) 1e6+5];

void _dfs(int start){

    processed[start] = true;

    for (int i = 0; i < graph[start].size(); ++i) {
        if (!processed[graph[start][i]]){
            _dfs(graph[start][i]);
        }
    }

    if (post[start] == 0){
        post[start] = licznik;
        licznik--;}
}

int _reed(int where){
    int ret = 0;
    where = where + size_of_table - 1;
    ret += tree[where];

    where /= 2;

    while (where >= 1){
        ret += tree[where];
        where /= 2;
    }

    return ret;
}

int _change(int pocz, int kon, int a, int b, int where){
    if (pocz > b || kon < a)
        return 0;
    if (pocz >= a && kon <= b){
        tree[where] += 1;
        return 0;
    }

    _change(pocz, (pocz + kon) / 2, a, b, where * 2);
    _change((pocz + kon) / 2 + 1, kon, a, b, where * 2 + 1);
    return 0;
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
        zrodlo[b] = true;
        graph[a].push_back(b);
    }

    for (int k = 1; k <= n; ++k) {
        if (!zrodlo[k]){
            s = k;
            break;}
    }

    while (size_of_table < n)
        size_of_table *= 2;

    licznik = n;
    _dfs(s);

    cin >> h;

    for (int j = 0; j < h; ++j) {
        cin >> syg >> from;

        if (syg == "syg"){
            _change(1, size_of_table, post[from], n, 1);
        }

        else{
            cout << _reed(from) << "\n";
        }
    }
}
