//
// Created by Franek on 2018-09-06.
// http://codeforces.com/contest/1038/problem/B

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    long long num = n *(n + 1) / 2;

    if (n == 1 || n == 2){
        cout << "No";
        return 0;
    }

    if (num % 2 == 0){
        cout << "Yes\n";
        cout << 1 << " 2\n" << n - 1 << " ";


        for (int i = 1; i <= n; ++i) {
            if (i != 2){
                cout << i << " ";
            }
        }
        return 0;
    }

    else{
        for (int i = 3; i <= n; ++i) {
            if ((num - i) % i == 0){

                cout << "Yes\n";
                cout << 1 << " " << i << "\n" << n - 1 << " ";

                for (int j = 1; j <= n; ++j) {
                    if (j != i){
                        cout << j << " ";
                    }
                }
                return 0;
            }
        }
    }

    cout << "No";
    return 0;

}
