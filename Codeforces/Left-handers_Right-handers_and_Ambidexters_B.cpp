//http://codeforces.com/problemset/problem/950/A
// Created by Franek on 2018-03-09.
//solved

#include <iostream>
using namespace std;

int main(){
    int l, r, a;
    cin >> l >> r >> a;
    int low = min(l, r);
    int high = max(l, r);
    if (high - low > a)
        cout << (low + a) * 2;
    else
        cout << ((a - (high - low)) / 2) * 2 + high * 2;
}


