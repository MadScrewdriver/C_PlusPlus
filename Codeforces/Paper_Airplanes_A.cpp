// http://codeforces.com/contest/965/problem/A
// Created by Franek on 2018-04-29.
// Solved

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    double k, n, s, p, i; cin >> k >> n >> s >> p;
    i = ceil((ceil(n / s) * k) / p);
    cout << fixed << setprecision(0) << i;
}
