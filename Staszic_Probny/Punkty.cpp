//
// Created by Franek on 2018-08-23.
//

#include <bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>> store;

int main(){
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int a,b,c;
        vector<int> t;
        cin >> a >> b >> c;

        t.push_back(a);
        t.push_back(b);
        t.push_back(c);
        store.push_back(t);
    }

    sort(store.begin(), store.end());

    for (int j = 0; j < n; ++j) {
        cout << store[j][0] << " " << store[j][1] << " " << store[j][2] << "\n";
    }
}
