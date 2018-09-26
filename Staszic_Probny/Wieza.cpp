#include <bits/stdc++.h>
using namespace std;

int n, m;
long long int in, v = 0;
long long int stairs_to_bit[500005];
int visitor;

int bit_serch(int a){
    int pocz = 0, kon = n, srd;

    while (kon - pocz > 1){
        srd = (kon + pocz) / 2;

        if(stairs_to_bit[srd] < a){
            pocz = srd;
        } else kon = srd;
    }

    return pocz;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        cin >> in;

        if (in > v){
            v = in;
        }

        stairs_to_bit[i] = v;
    }

    for (int j = 1; j <= m; ++j) {
        cin >> visitor;

        if (stairs_to_bit[n] < visitor){
            cout << n << " ";
        }

        else if (stairs_to_bit[1] >= visitor){
            cout << 0 << " ";
        }

        else cout << bit_serch(visitor) << " ";
    }
}
