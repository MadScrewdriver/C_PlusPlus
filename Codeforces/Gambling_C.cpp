//
// Created by Franek on 2018-03-20.
// http://codeforces.com/contest/1038/problem/C

#include <bits/stdc++.h>
using namespace std;

priority_queue<int> first;
priority_queue<int> secend;
int n, a;
long long  s_a = 0, s_b = 0;
bool turn = false;

int main(){
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> a;
        first.push(a);
    }

    for (int i = 0; i < n; ++i) {
        cin >> a;
        secend.push(a);
    }

    while (!first.empty() || !secend.empty()){
        if (!turn){
            if (secend.empty()){
                s_a += first.top();
                first.pop();
            }
            else if (first.empty()){
                secend.pop();
            }

            else{
                if (first.top() > secend.top()){
                    s_a += first.top();
                    first.pop();
                } else secend.pop();
            }

            turn = true;
        }

        else{
            if (first.empty()){
                s_b += secend.top();
                secend.pop();
            }
            else if (secend.empty()){
                first.pop();
            }

            else{
                if (secend.top() > first.top()){
                    s_b += secend.top();
                    secend.pop();
                } else first.pop();
            }

            turn = false;
        }
    }

    cout << s_a - s_b;
}
