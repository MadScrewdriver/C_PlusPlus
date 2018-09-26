// http://codeforces.com/problemset/problem/946/A
// Created by Franek on 2018-03-06.
// solved

#include <iostream>
using namespace std;

int main() {
    int c = 0, b = 0, n = 0, a = 0;
    cin >> a;

    for (int i = 0; i < a; ++i){
        cin >> n;

        if (n < 0)
            c += n;
        else
            b += n;

    }

    cout << b - c;
}



