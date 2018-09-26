//
// Created by Franek on 2018-08-26.
//

#include <bits/stdc++.h>
using namespace std;

int d[(1<<20)+10];
int w = (1<<4);

int main() {
    for(int i=1; i<2*w; i++) {
        if(__builtin_popcount(i)==1) cout << "\n";
        cout << d[i] << " ";
    }
}