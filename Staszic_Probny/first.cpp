#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n, m, parent;
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    long long int in[n][m];
    long long int empty[n][m];

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> in[i][j];
        }
    }

    long long int last = in[0][0];
    empty[0][0] = last;

    for (int o = 1; o < m; o++){
        empty[0][o] = in[0][o] + last;
        last = empty[0][o];
    }

    last = in[0][0];
    for (int p = 1; p < n; p++){
        empty[p][0] = in[p][0] + last;
        last = empty[p][0];
    }

    for (int r = 1; r < n; r++){
        for (int a = 1; a < m; a++){
            empty[r][a] = in[r][a] + max(empty[r][a - 1], empty[r - 1][a]);
        }
    }

    if (empty[n - 1][m - 1] < 0)
        cout << 0;
    else
        cout << empty[n - 1][m - 1];
}

