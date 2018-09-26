#include <bits/stdc++.h>
using namespace std;

int shortest(map<int, vector<int>> &graph, int target, vector<int> &city, int f){
    vector<int> kolejka = graph[target];
    int dis = 1;
    int node = kolejka[0];
    int d = 0;
    int out = 0;
    kolejka.push_back(-1);

    while (node != -11){

        if (node == -1){
            dis ++;
            d++;
            node = kolejka[d];
            kolejka.push_back(-1);

            if (d == kolejka.size())
                break;
            else
                continue;
        }

        if (d - dis < f - 1){
            if(find(city.begin(), city.end(), node) != city.end()) {
                out = d;
            }
        }


        kolejka.reserve(graph[node].size());
        kolejka.insert(kolejka.end(), graph[node].begin(), graph[node].end());
        node = kolejka[d];
        d++;

    }

    return out;
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
    vector<int> fabric;
    int n = 0, f = 0, l = 0, r = 0, out = 0;
    n = read_input();
    f = read_input();


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


    int firstout = shortest(graph, 1, fabric, f);
    int secendout = shortest(graph, secendout, fabric, f);

    cout << secendout;
}

