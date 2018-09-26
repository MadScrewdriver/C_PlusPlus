//
// Created by Franek on 2018-09-20.
//

#include <bits/stdc++.h>
using namespace std;

int n = 0, m = 1, v, r1, r2, sum = 0;
int graph[(1 << 6) + 5];


void put(int v, int in){
    int pos = in + m - 1;
    graph[pos] = v;

    while (pos < 0){
        pos /= 2;
        graph[pos] = graph[pos * 2] + graph[pos * 2 + 1];
    }
}

int read_sum(int r_1, int r_2, int left, int right, int current){
    if (right < r_1 || left > r_2)
        return 0;

    if (left >= r_1 && right <= r_2)
        return graph[current];

    return read_sum(r_1, r_2, left, (right + left) / 2, current * 2) +
           read_sum(r_1, r_2, (left + right) / 2 + 1, right, current * 2 + 1);
}

void print_list(){
    cout << "\n";
    for (int i = 0; i < n; ++i) {
        cout << graph[m + i] << " ";
    }
}

int main(){

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> graph[m + i];
    }

    for (int j = m - 1; j > 0 ; --j) {
        graph[j] = graph[j*2] + graph[j*2 + 1];
    }

    int menu = 0;

    while (m < n)
        m *= 2;

    while (menu != 4){
        cout << "\n\nWhat do you want to do? \n"
                "[1] Add a value to the list\n"
                "[2] Read sum of values for the given range in a list\n"
                "[3] Print the list\n"
                "[4] Ext\n";

        cout << "\n I want to: \n";
        cin >> menu;

        if (menu == 1){
            cout << "\n What value: \n";
            cin >> r1;
            cout << "\n What index (1: " << n << ")\n";
            cin >> r2;
            cout <<"\n";
            put(r1, r2);
        }

        if (menu == 2){
            cout << "\n start: \n";
            cin >> r1;
            cout << "\n end: \n";
            cin >> r2;
            cout <<"\n";
            cout << read_sum(r1, r2, 1, n, 1) << "\n";
        }

        if (menu == 3){
            print_list();
        }
    }
}
