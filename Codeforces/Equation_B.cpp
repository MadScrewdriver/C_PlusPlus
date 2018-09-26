// http://codeforces.com/problemset/problem/20/B
// Created by Franek on 2018-04-14.
// solved

#include <iostream>
#include <cmath>
using namespace std;

int main(){
    double a, b, c; cin >> a >> b >> c;

    if (a == b && b == c && c == 0)
        cout << -1;

    else if ((pow(b, 2) - 4 * a * c) < 0)
        cout << 0;

    else if ((pow(b, 2) - 4 * a * c) == 0 || pow(a, 2) == c)
        cout << 1 << endl << (-b + sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);

    else {
        cout << 2 << endl;
        cout << (-b - sqrt(pow(b, 2) - 4 * a * c)) / (2 * a) << endl;
        cout << (-b + sqrt(pow(b, 2) - 4 * a * c)) / (2 * a) << endl;
    }
}


