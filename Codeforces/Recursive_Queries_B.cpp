// Created by Franek on 2018-02-28.
// http://codeforces.com/contest/932/problem/B
// unsolved

#include <iostream>
using namespace std;

int f(int n) {
    int out = 1;
    for (char i: to_string(n)) {
        if (i != '0'){
            int j = i - '0';
            out *= j;
        }
    }

    return out;
}

int g(int n) {
    if (n < 10)
        return n;
    else
        return g(f(n));
}

int main() {
    int n;
    cin >> n;

    for (int inp = 0; inp < n; inp++) {
        int o = 0;
        int l, r, k;

        cin >> l >> r >> k;

        for (l; l <= r; l++) {
            int m = g(l);
            if (m == k)
                o ++;
        }
        cout << o << endl;
    }

}

