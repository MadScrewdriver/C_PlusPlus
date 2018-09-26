// http://codeforces.com/problemset/problem/957/A
// Created by Franek on 2018-04-02.
// Solved

#include <iostream>
using namespace std;

int main(){
    int n; cin >> n;
    string s; cin >> s;
    bool two = false;
    for (int i = 0; i < n - 1; i++){

        if (s[i] == s[i + 1] && s[i] != '?'){
            cout << "NO";
            return 0;
        }

        if (s[i] == '?' && s[i + 1] == '?')
            two = true;

        if (i != 0){
            if (s[i] == '?' && s[i - 1] == s[i + 1])
                two = true;
        }

        if (s[0] == '?' || s[n - 1] == '?'){
            two = true;
        }

    }

    if (two || (n == 1 && s[0] == '?'))
        cout << "YES";
    else
        cout << "NO";
}
