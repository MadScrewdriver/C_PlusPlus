//
// Created by Franek on 2018-08-25.
//

#include <bits/stdc++.h>
using namespace std;

long long int p = 977, MOD = (int) 1e9+7;
long long int powers[(int) 1e6+5];
long long int hasze_pattern[(int) 1e6+5];
long long int hasze_word[(int) 1e6+5];
string word;
string pattern;

void fill_powers(){
    powers[0]=1;
    for (int i = 1; i < (int) 1e6; ++i) {
        powers[i] = ((long long)(powers[i-1]) * p) % MOD;
    }
}

void haszuj(){
    hasze_pattern[0] = pattern[0];
    hasze_word[0] = word[0];

    for (int i = 1; i < pattern.size(); ++i) {
        hasze_pattern[i] = ((hasze_pattern[i - 1]) * p + pattern[i]) % MOD;
    }

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
//    cout << -1%9 << " " << -2%9 << " " << -3%9  << " " << -11%9 << "\n";
    cin >> pattern >> word;
    fill_powers();
    haszuj();

    for (int i = 0; i + pattern.size() - 1 < word.size(); ++i) {
        int j = i + pattern.size() - 1;

        if(hash_fragmentu_worda(i, j) == hasze_pattern[pattern.size() - 1]){
            cout << "Index w ktorym zaczyna sie " << pattern << " w slowie " << word << " -----> " << i << "\n";
        }
    }
}