// http://codeforces.com/problemset/problem/955/A
// Created by Franek on 2018-03-24.
// solved


#include <iostream>
using namespace std;

int main(){
    long hh, mm, H, D, C, N, n2 = 0;
    float n1 = 0;
    cin >> hh >> mm >> H >> D >> C >> N;
    n1 = H / N;
    if (H % N != 0)
        n1++;
    if (hh >= 20)
        cout << n1 * (0.8 * C);
    else{
        n1 *= C;
        if (((H + (((60 - mm) + (20 - hh - 1) * 60) * D)) % N) != 0)
            n2 ++;

        n2 += int((H + (((60 - mm) + (20 - hh - 1) * 60) * D)) / N);

        n2 *= (0.8 * C);
        if (n1 < n2)
            cout << n1;
        else
            cout << n2;
    }

}

