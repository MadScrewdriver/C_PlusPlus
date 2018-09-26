// http://codeforces.com/problemset/problem/962/A
// Created by Franek on 2018-04-12.
// solved

#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n, a = 0; cin >> n;
    double s = 0;
    int t[n];

    for (int i = 0; i < n; ++i){
        cin >> t[i];
        s += t[i];
    }

    s = ceil(s / 2);

    for (int j = 0; j < n; ++j){
        a += t[j];

        if (a >= s) {
            cout << j + 1;
            return 0;
        }
    }

}


