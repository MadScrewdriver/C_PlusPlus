#include <iostream>
#include <random>
using namespace std;
int mod = 105;

int main(){
    int seed;
    cin >> seed;
    srand(seed);

    int n = rand() % mod + 1;
    int m = n + rand() % mod;
    m=min(n+n-1,m);
    cout << n + 1 << " " << m << "\n";

    for (int i = 1; i <= n; ++i) {
        cout << i << " " << i+1 << "\n";
    }

    for (int k = 1; k <= m - n; ++k) {
        cout << k << " " << k + (rand() % (n - k) + 1) << "\n";
    }

    int g = rand() % mod + 1;
    cout << g << "\n";

    for (int j = 0; j < g; ++j) {
        int t = rand() % 2 + 1;

        if (t == 1){
            cout << "syg" << " " << rand() % n + 1 << "\n";
        } else cout << "ile" << " " << rand() % n + 1 << "\n";
    }
}