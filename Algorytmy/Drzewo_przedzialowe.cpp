//
// Created by Franek on 2018-08-26.
//

#include <bits/stdc++.h>
using namespace std;

int size_of_table;
int d[(1<<20)+10];

void put(int where, int valu){
    where = where + size_of_table - 1;
    d[where] = valu;
    where /= 2;

    while (where >= 1){
        d[where] = d[where*2] + d[where*2 + 1];
        where /= 2;
    }
}

int read(int pocz, int kon, int a, int b, int where){
    if (pocz > b || kon < a)
        return 0;
    if (pocz >= a && kon <= b)
        return d[where];

    return  (read(pocz, (pocz + kon) / 2, a, b, where * 2) + read((pocz + kon) / 2 + 1, kon, a, b, where * 2 + 1));
}

//void put_on_seq(int pocz, int kon, int a, int b, int where){
//    if (pocz <= a && kon <= b)
//        d[where] += ;
//    ;
//}

void draw_tree(){
    for(int i=1; i<2*size_of_table; i++) {
        if(__builtin_popcount(i)==1) cout << "\n";
        cout << d[i] << " ";
    }
}

int main() {
    cin >> size_of_table;

    for (int j = size_of_table; j <= size_of_table * 2 - 1; ++j) {
        cin >> d[j];
    }

    for (int i = size_of_table - 1; i > 0; --i) {
        d[i] = d[i * 2] + d[i * 2 + 1];
    }

    draw_tree();
    cout << "\n\n" << read(1, size_of_table, 2, 6, 1) << "\n";
    put(5, 9);
    draw_tree();
    cout << "\n\n" << read(1, size_of_table, 2, 6, 1);

}