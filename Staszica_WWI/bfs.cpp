#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;


int shortest(map<int, vector<int>> &graph, int target, map<int, bool> &city, bool f, int n, int fn){
    vector<int> kolejka = graph[target];
    map<int, bool> proccesed;

    for(int l = 1; l <= n; ++l){
        proccesed[l] = true;
    }

    int skok = 0;
    kolejka.push_back(-1);
    proccesed[target] = false;
    int main_dis = 1;
    int fabric_dis = 0;
    int fabric_name = target;
    int first;
    int u = 0;


    while (kolejka.size() > skok + 1){
        first = kolejka[skok];
        skok += 1;


        if (first == -1){
            kolejka.push_back(-1);
            main_dis++;
            continue;
        }

        else{

            u++;

            if (u >= fn - 1){
                if (city[first]) {
                    fabric_dis = main_dis;
                    fabric_name = first;
                }
            }

            for (int o = 0; o < graph[first].size(); o++) {
                if (proccesed[graph[first][o]]) {
                    kolejka.push_back(graph[first][o]);
                }
            }

            proccesed[first] = false;

        }}

    if (f){
        return fabric_name;
    }

    else{
        return fabric_dis;
    }
}


int read_input() {
    int _integer=0;
    char _char=0;

    while(_char<48){
        _char=getchar_unlocked();
    }

    while(_char>=48) {
        _integer=10*_integer+_char-48;
        _char=getchar_unlocked();
    }

    return _integer;
}


int main(){
    map<int, vector<int>> graph;
    map<int, bool> city;
    vector<int> fabric;
    int n = 0, f = 0, l = 0, r = 0, out = 0;
    n = read_input();
    f = read_input();

    if (n == 1){
        cout << 0;
        return 0;
    }

    for (int i = 0; i < n - 1; ++i){
        l = read_input();
        r = read_input();
        graph[l].push_back(r);
        graph[r].push_back(l);
    }


    for (int j = 0; j < f; j++){
        int b = 0;
        b = read_input();
        fabric.push_back(b);
    }

    sort(fabric.begin(), fabric.end());

    int last = 1;

    for (int &c : fabric) {
        vector <int> temp;
        for (int la = last; la < c; la++){

            temp.push_back();
            v.at(COLUMN).push_back(i);
        }
        city[c] = true;
        last = c + 1;
    }

    for (int la = last; la <= n; la++){
        city[la] = false;
    }

    int firstout = shortest(graph, 1, city, true, n, f);
    int secendout = shortest(graph, firstout, city, false,n, f);

    cout << secendout;
}