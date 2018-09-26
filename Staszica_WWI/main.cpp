#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <iterator>
#include <bits/stdc++.h>
using namespace std;

int read_input() {
    int _integer=0;
    char _char=0;

    while(_char<48){
        _char=getchar_unlocked();}

    while(_char>=48)
    {_integer=10*_integer+_char-48;
        _char=getchar_unlocked();}
    return _integer;
}

int main(){
    int M = read_input();
    int L = read_input();
    int films[M][1002];
    vector<int >skip;
    skip.push_back(-1);
    int out = 0, m = 0, t = 0, p = 0, time;

    for (int i=0; i < M; ++i) {
        films[i][0] = read_input();
        films[i][1] = read_input();
        t = films[i][0];

        for (int j = 2; j < films[i][1] + 2; ++j) {
            films[i][j] = read_input();
            p = films[i][0];

            if (films[i][j] == 0 && p > m) {
                m = p;
                skip[0] = i;
                out++;
            }

        }
    }
    t = m;


    while (t < L){
        skip.push_back(-1);
        m = 0;
        for (int i=0; i < M; ++i) {
            int size = skip.size();

            if (!(find(skip.begin(), skip.end(), i) != skip.end())) {
                time = films[i][0];
                for (int j = 2; j + 2 < films[i][1]; ++j) {
                    p = films[i][j];

                    if (p <= t && p + time > m) {
                        m = p + time;
                        skip.pop_back();
                        skip.push_back(i);
                    }
                }
            }
        }

        if (m == 0){
            cout << -1;
            return 0;
        }

        t += m;
        out ++;
    }


    cout << out;
}
