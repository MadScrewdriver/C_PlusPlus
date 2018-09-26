// http://codeforces.com/contest/1042/problem/C
// Created by Franek on 2018-09-17.
// Solved

#include <bits/stdc++.h>


int n, minus = 0, zero = 0,  mi = -1000000001, index_mi = 0;
int arr[(int) 1e6+5];
std::vector<int> ze;
bool y[(int)1e6+5];

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    std::cin >> n;

    for (int i = 1; i <= n; ++i) {
        std::cin >> arr[i];

        if (arr[i] < 0){
            minus += 1;
            if (arr[i] > mi){
                mi = arr[i];
                index_mi = i;
            }
        }

        if (arr[i] == 0){
            zero ++;
            ze.push_back(i);
            y[i] = true;
        }
    }

    if (zero >= 1){
        for (int j = 1; j < ze.size(); ++j) {
            std::cout << 1 << " " << ze[j] << " " << ze[0] << "\n";
        }

        if(minus % 2 == 1){
            std::cout << 1 << " " << index_mi << " " << ze[0] << "\n";
            if(ze.size() != n-1)
                std::cout << 2 << " " << ze[0] << "\n";
        }

        else if(ze.size() != n)
            std::cout << 2 << " " << ze[0] << "\n";

        for (int k = 1; k <= n; ++k) {
            if(!y[k] && (k != index_mi || (minus % 2 == 0))){
                for (int i = k + 1; i <= n; ++i) {
                    if(!y[i] && (i != index_mi || (minus % 2 == 0)))
                        std::cout << 1 << " " << i << " " << k << "\n";
                }
                return 0;
            }
        }
    }


    else {
        if (minus % 2 == 1){
            std::cout << 2 << " " << index_mi << "\n";
        }

        for (int j = 1; j <= n; ++j) {
            if (j != index_mi || !(minus % 2)){
                for (int i = j + 1; i <= n; ++i) {
                    if (i != index_mi || !(minus % 2))
                        std::cout << 1 << " " << i << " " << j << "\n";
                }

                return 0;
            }
        }
    }
}

