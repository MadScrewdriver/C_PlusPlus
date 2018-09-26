// http://codeforces.com/problemset/problem/939/B
// Created by Franek on 2018-03-11.
// solved

#include <iostream>
using namespace std;

int main(){
    long long n = 0, k = 0, j = 0, l = 1, t = 0;
    long long m = 1000000000000000000;

    cin >> n >> k;

    for (long long i = 1; i <= k; ++i) {
        cin >> j;

        if (n % j < m){
            m = n % j;
            t = n / j;
            l = i;
        }
    }
    cout << l << " " << t;
}

