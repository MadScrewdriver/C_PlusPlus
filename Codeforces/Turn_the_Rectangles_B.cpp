// http://codeforces.com/problemset/problem/1008/B
// Created by Franek on 2018-07-23.
// Solved

#include <iostream>
#include <cmath>
using namespace std;

int main(){
    double n, now = pow(10, 10);
    cin >> n;

    for (int i = 0; i < n; ++i){
        int a, b;
        cin >> a >> b;

        if (a <= now && b <= now)
            now = max(a, b);

        else if (a <= now)
            now = a;

        else if (b <= now)
            now = b;

        else{
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
}

