//http://codeforces.com/contest/953/problem/A
// Created by Franek on 2018-03-20.
//solved

#include <iostream>
#include <cmath>
using namespace std;

int main(){
    double k,l,o = 0;
    cin >> k >> l;
    for (int i = 0; i <= 30; ++i) {
        for (int j = 0; j <= 30; ++j) {
            if ((pow(2, i) * pow(3, j)) <= l && (pow(2, i) * pow(3, j)) >= k){
                o++;
            }
        }
    }
    cout << o;
}

