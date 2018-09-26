// http://codeforces.com/contest/545/problem/E
// Created by Franek on 2018-09-13.
// Solved

#include <bits/stdc++.h>
using namespace std;

int n, m;
const long long inf = (long long)1e18 + 10;
pair<long long, int > odl[(int) 1e6+5];
vector<vector<long long>> graph[(int) 1e6+5];
priority_queue<vector<long long>> kolejka;
int used[(int) 1e6+5];
int sor[(int) 1e6+5];
long long s = 0;

void dik(int start){
    odl[start].first = 0;
    odl[start].second = 0;

    for (int i = 0; i < graph[start].size(); ++i) {
        if (odl[graph[start][i][1]].first > -graph[start][i][0]){
            kolejka.push(graph[start][i]);
            odl[graph[start][i][1]].first = -graph[start][i][0];
            odl[graph[start][i][1]].second = odl[start].second + 1;
            used[graph[start][i][1]] = graph[start][i][2];
            s += sor[used[graph[start][i][1]]];
        }
    }

    while (!kolejka.empty()){
        long long cost = -kolejka.top()[0];
        int value = kolejka.top()[1];
        kolejka.pop();

        for (int i = 0; i < graph[value].size(); ++i) {
            if (odl[graph[value][i][1]].first > cost + -graph[value][i][0]){

                vector<long long> temp;
                temp.resize(3);
                temp[0] = -(cost + -graph[value][i][0]);
                temp[1] = graph[value][i][1];
                temp[2] = graph[value][i][2];
                kolejka.emplace(temp);
                odl[graph[value][i][1]].first = cost + -graph[value][i][0];

                if (used[temp[1]] == -1){
                    used[temp[1]] = temp[2];
                }

                else{
                    s -= sor[used[temp[1]]];
                    used[temp[1]] = temp[2];
                }


                s += sor[used[temp[1]]];
            }

            else if ((odl[graph[value][i][1]].first == cost + -graph[value][i][0]) &&
                     (s > (s - sor[used[graph[value][i][1]]] +  sor[graph[value][i][2]]))){

                vector<long long> temp;
                temp.resize(3);
                temp[0] = -(cost + -graph[value][i][0]);
                temp[1] = graph[value][i][1];
                temp[2] = graph[value][i][2];
                kolejka.emplace(temp);
                s = s - sor[used[graph[value][i][1]]] +  sor[graph[value][i][2]];
                used[temp[1]] = temp[2];
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int k = 1; k <= n; ++k) {
        odl[k].first = inf;
        odl[k].second = -1;
        used[k] = -1;
    }

    for (int i = 1; i <= m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        vector<long long > temp;
        temp.resize(3);
        temp[0] = -c;
        temp[1] = b;
        temp[2] = i;

        graph[a].emplace_back(temp);
        temp[1] = a;
        graph[b].emplace_back(temp);
        sor[i] = c;
    }

    int start;
    cin >> start;

    dik(start);

//    for (int j = 1; j <= n; ++j) {
//        cout << "Cost to " << j << " ----> " << odl[j].first << "\n";
//    }

//    s = 0;
//    for (int j = 1; j <= n; ++j) {
//        s += sor[used[j]];
//    }

    cout << s << "\n";
    for (int j = 1; j <= n; ++j) {
        if (j != start)
            cout << used[j] << " ";
    }
}


