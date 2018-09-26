// http://codeforces.com/contest/1042/problem/B
// Created by Franek on 2018-09-17.
// Solved

#include <bits/stdc++.h>
using namespace std;
int inf = (int) 1e6+5;
int n, A = inf, B = inf, C = inf, AB = inf, AC = inf, BC = inf, ABC = inf, out = inf;
vector<pair<int, string>> t;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; ++i) {
        int temp_n;
        string temp_s;

        cin >> temp_n >> temp_s;
        t.push_back(make_pair(temp_n, temp_s));
    }

    sort(t.begin(), t.end());

    for(auto i: t){
        if (i.second == "A" && A == inf)
            A = i.first;
        if (i.second == "B" && B == inf)
            B = i.first;
        if (i.second == "C" && C == inf)
            C = i.first;
        if ((i.second == "AB" || i.second == "BA") && AB > i.first)
            AB = i.first;
        if ((i.second == "AC" || i.second == "CA") && AC > i.first)
            AC = i.first;
        if ((i.second == "BC" || i.second == "CB") && BC > i.first)
            BC = i.first;
        if ((i.second == "ABC" || i.second == "ACB" || i.second == "BAC" || i.second == "BCA" || i.second == "CBA" ||
             i.second == "CAB") && ABC > i.first)

            ABC = i.first;
    }

    if ((A == inf && AB == inf && AC == inf && ABC == inf) || (B == inf && AB == inf && BC == inf && ABC == inf) ||
        (C == inf && BC == inf && AC == inf && ABC == inf)){
        cout << -1;
        return 0;
    }

    else{
//        int n, A = inf, B = inf, C = inf, AB = inf, AC = inf, BC = inf, ABC = inf, out = inf;

        vector<int> k = {AB + AC, AB + C, AB + BC, AC + BC, AC + B, BC + A, A + B + C, ABC};

        for(auto p:k){
            if (p < out)
                out = p;
        }

        cout << out;
    }
}

