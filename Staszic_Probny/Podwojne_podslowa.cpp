//
// Created by Franek on 2018-08-26.
//

#include <bits/stdc++.h>
using namespace std;

long long int p = 977, MOD = (int) 1e9+7;
long long int powers[(int) 1e6+5];
long long int hasze_word[(int) 1e6+5];
string word;
int n, m, start, stop;

void fill_powers(){
    powers[0]=1;
    for (int i = 1; i < (int) 1e6; ++i) {
        powers[i] = ((powers[i-1]) * p) % MOD;
    }
}

void haszuj(){
    hasze_word[0] = word[0];

    for (int j = 1; j < word.size(); ++j) {
        hasze_word[j] = ((hasze_word[j - 1]) * p + word[j]) % MOD;
    }
}

int hash_fragmentu_worda(int a, int b){
    if (a == 0){
        return hasze_word[b];
    }

    return (hasze_word[b] - (hasze_word[a-1] * powers[b+1-a]) % MOD + MOD) % MOD;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> m >> word >> n;
    fill_powers();
    haszuj();

    for (int i = 0; i < n; ++i) {
        cin >> start >> stop;
        start--;
        stop--;

        if(hash_fragmentu_worda(start, ((start + stop) / 2)) ==
           hash_fragmentu_worda(((start + stop) / 2) + 1, stop))
            cout << "TAK\n";
        else cout << "NIE\n";
    }
}
