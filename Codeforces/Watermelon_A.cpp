// Created by Franek on 2018-02-28.
// http://codeforces.com/problemset/problem/4/A
// solved

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    if ((n % 2) == 0 && n != 2)
        cout << "YES";

    else
        cout << "NO";
}
