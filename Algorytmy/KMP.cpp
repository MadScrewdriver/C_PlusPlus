//
// Created by Franek on 2018-08-25.
//

#include <bits/stdc++.h>
using namespace std;
vector<int> pref_suf;
string text, text_in, to_kmp;

void kmp(){

    for(int i=2; i < pref_suf.size(); i++){
        int poz = pref_suf[i-1];

        while (poz != 0 && to_kmp[poz + 1] != to_kmp[i]){
            poz = pref_suf[poz];
        }

        if (to_kmp[poz + 1] == to_kmp[i])
            pref_suf[i] = poz + 1;
    }
}

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> text >> text_in;
    to_kmp = "$" + text + "#" + text_in;
    pref_suf.resize(to_kmp.size());

    kmp();

    for (int i = text.size() + 2; i < pref_suf.size(); ++i) {
        if (pref_suf[i] == text.size()){
            cout << "Index w ktorym zaczyna sie " << text << " w slowie " << text_in << " -----> " << i - text.size()*2 - 1 << "\n";
        }
    }
}

