//
// Created by Franek on 2018-08-25.
//

#include <bits/stdc++.h>
using namespace std;
vector<int> pref_suf;
string to_find, text_to_kmp, to_find_in;
int inde = -10000;
int n;

void kmp(){

    for(int i=2; i < pref_suf.size(); i++){
        int poz = pref_suf[i-1];

        while (poz != 0 && text_to_kmp[poz + 1] != text_to_kmp[i]){
            poz = pref_suf[poz];
        }

        if (text_to_kmp[poz + 1] == text_to_kmp[i])
            pref_suf[i] = poz + 1;
    }
}

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> to_find;
        cin >> to_find_in;
        bool out = false;

        for (int l = 0; l < 1e6; ++l) {

        }
        for (int j = 0; j < to_find.size(); ++j) {
            bool p = false;
            if (to_find[j] != '*') text_to_kmp += to_find[j];

            if ((to_find[j] == '*' || j == to_find.size() - 1) && !text_to_kmp.empty()){

//                if(j == to_find.size() - 1 && to_find[j] != '*'){
//                    text_to_kmp += to_find[j];
//                }

                int s = text_to_kmp.size();
                text_to_kmp = '$' + text_to_kmp + '#' + to_find_in;
                pref_suf.resize(text_to_kmp.size());
//                cout << text_to_kmp << "\n";
                kmp();

                for (int k = s + 2; k < text_to_kmp.size(); ++k) {
                    if(pref_suf[k] == s){
                        if(inde < (long long) (k - 1 - 2*s)){
                            inde = (k - 2 - s);
                            p = true;
                            break;
                        }
                    }

                }

                if (!p){
                    out = true;
                    break;}

                text_to_kmp.clear();
                pref_suf.clear();

            }
        }

        if(!out){
            cout << "Jest.\n";
        } else cout << "Nie ma go.\n";

        text_to_kmp.clear();
        pref_suf.clear();
        inde = -10000;
    }

//    for (int i = 1; i < pref_suf.size(); ++i) {
//        cout << pref_suf[i] << " ";
//    }
}
