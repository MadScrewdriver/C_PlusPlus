// http://codeforces.com/problemset/problem/474/A
// Created by Franek on 2018-04-02.
// Solved

#include <iostream>
using namespace std;

int main(){
    string a = "qwertyuiopasdfghjkl;zxcvbnm,./";
    char d; cin >> d;
    string l; cin >> l;

    for (char& i : l){
        if (d == 'L')
            cout << a[a.find(i) + 1];
        else
            cout << a[a.find(i) - 1];
    }
}


