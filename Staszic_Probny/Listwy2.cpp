//
// Created by Franek on 2018-08-27.
//

#include <bits/stdc++.h>
using namespace std;

int size_of_table = 1, n, k, q, in, change, w;
vector<int> tree[(int) 1e6+5];
int ordered_tree[(1 << 21) + 5];
int pre[(int) 1e6+5];
int post[(int) 1e6+5];
int licznik = 0;

void dfs(int start, int father) {

    pre[start] = licznik++;

    for (int i = 0; i < tree[start].size(); ++i) {
        if (tree[start][i] != father) {
            dfs(tree[start][i], start);
        }
    }

    post[start] = licznik - 1;
}

int put_and_read(int pocz, int kon, int a, int b, int where){
    if (pocz > b || kon < a)
        return 0;
    if (pocz >= a && kon <= b){
        if (ordered_tree[where] > 0)
            ordered_tree[where] = 0;
        else
        if (pocz == kon)
            ordered_tree[where] = 1;
        else
            ordered_tree[where] = ordered_tree[where * 2] + ordered_tree[where * 2 + 1];

        w = where;
        w /= 2;

        while (w >= 1 && ordered_tree[w] != 0){
            ordered_tree[w] = ordered_tree[w*2] + ordered_tree[w*2 + 1];
            w /= 2;
        }

        return 0;
    }

    put_and_read(pocz, (pocz + kon) / 2, a, b, where * 2);
    put_and_read((pocz + kon) / 2 + 1, kon, a, b, where * 2 + 1);
}

void draw_tree(){
    for(int i=1; i<2*size_of_table; i++) {
        if(__builtin_popcount(i)==1) cout << "\n";
        cout << ordered_tree[i] << " ";
    }
}

int main() {
    cin >> n >> k;

    for (int i = 1; i <= n; ++i) {
        cin >> in;
        if (in < 0){
            tree[i].push_back(0);
            tree[0].push_back(i);
        }

        else{
            tree[i].push_back(in);
            tree[in].push_back(i);
        }
    }

    dfs(0, 0);

    while (size_of_table < n)
        size_of_table *= 2;

    for (int j = size_of_table; j <= size_of_table * 2 - 1; ++j) {
        if(j < size_of_table + n)
            ordered_tree[j] = 1;
    }

    for (int i = size_of_table - 1; i > 0; --i) {
        ordered_tree[i] = ordered_tree[i * 2] + ordered_tree[i * 2 + 1];
    }

    cin >> q;
    draw_tree();

    for (int j = 1; j <= q; j++) {
        cin >> change;
        put_and_read(1, size_of_table, pre[change], post[change], 1);
        draw_tree();
        cout << "\n\n" << ordered_tree[1] << "\n\n";
    }

}