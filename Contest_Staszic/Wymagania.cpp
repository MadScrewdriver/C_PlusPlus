//
// Created by Franek on 2018-08-29.
//

#include <bits/stdc++.h>
using namespace std;
priority_queue<pair<int, int>> que;
int store[(int) 1e6+5];
int n, m, a, x, v;
long long int siz;

void print(){
    while (que.top().first != store[que.top().second]){
        que.pop();
    }

    if (siz % 2 == 0 && que.top().first*2 <= siz){
        cout << "TAK\n";
    } else cout << "NIE\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;

    for (int k = 1; k <= n; ++k) {
        cin >> a;
        que.push(make_pair(a, k));
        store[k] = a;
        siz += a;
    }
    print();

    for (int i = 1; i <= m; ++i) {
        cin >> x >> v;
        que.push(make_pair(v, x));
        siz -= store[x];
        siz += v;
        store[x] = v;
        print();
    }
}
