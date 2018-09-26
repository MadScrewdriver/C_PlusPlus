//
// Created by Franek on 2018-08-26.
//

#include <bits/stdc++.h>
using namespace std;

int size_of_table = 1, q;
int d[(1<<18)+10][6];
string order;
int p, c, a, b, k, t;

void put(int where, int valu){
    where = where + size_of_table - 1;
    d[where][0] += valu;
    if (d[where][0] % 2 == 0) d[where][2] = 1; else d[where][2] = 0;
    if (d[where][0] % 3 == 0) d[where][3] = 1; else d[where][3] = 0;
    if (d[where][0] % 4 == 0) d[where][4] = 1; else d[where][4] = 0;
    if (d[where][0] % 5 == 0) d[where][5] = 1; else d[where][5] = 0;

    where /= 2;

    while (where >= 1){
        d[where][1] = d[where*2][1] + d[where*2 + 1][1];
        d[where][2] = d[where*2][2] + d[where*2 + 1][2];
        d[where][3] = d[where*2][3] + d[where*2 + 1][3];
        d[where][4] = d[where*2][4] + d[where*2 + 1][4];
        d[where][5] = d[where*2][5] + d[where*2 + 1][5];
        where /= 2;
    }
}

int read(int pocz, int kon, int a, int b, int where, int k){
    if (pocz > b || kon < a)
        return 0;
    if (pocz >= a && kon <= b)
        return d[where][k];

    return  (read(pocz, (pocz + kon) / 2, a, b, where * 2, k) +
             read((pocz + kon) / 2 + 1, kon, a, b, where * 2 + 1, k));
}
//
//void draw_tree(){
//    for(int i=1; i<2*size_of_table; i++) {
//        if(__builtin_popcount(i)==1) cout << "\n";
//        cout << "(" << d[i][0] << " " << d[i][1] << " " << d[i][2] << " " << d[i][3] << " " << d[i][4] << " " << d[i][5] << ")";
//    }
//}

int main() {
    cin >> t >> q;

    while (size_of_table < t){
        size_of_table *= 2;
    }

    for (int j = size_of_table; j < size_of_table * 2; ++j) {
        if(j < size_of_table + t){
            d[j][1] = 1;
            d[j][2] = 1;
            d[j][3] = 1;
            d[j][4] = 1;
            d[j][5] = 1;
        }
    }

    for (int j = size_of_table - 1; j > 0; --j) {
        d[j][1] = d[j*2][1] + d[j*2 + 1][1];
        d[j][2] = d[j*2][2] + d[j*2 + 1][2];
        d[j][3] = d[j*2][3] + d[j*2 + 1][3];
        d[j][4] = d[j*2][4] + d[j*2 + 1][4];
        d[j][5] = d[j*2][5] + d[j*2 + 1][5];
    }

    for (int i = 1; i <= q; ++i) {
        cin >> order;
//        cout << "\n";
//        draw_tree();
//        cout << "\n";

        if (order == "DODAJ"){
            cin >> p >> c;
            put(p, c);
        }

        else{
            cin >> a >> b >> k;
            cout << read(1, size_of_table, a, b, 1, k) << "\n";
        }

    }

}