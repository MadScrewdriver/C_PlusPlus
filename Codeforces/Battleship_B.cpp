// http://codeforces.com/contest/965/problem/B
// Created by Franek on 2018-05-01.
// Solved

#include <iostream>
using namespace std;

bool check(int x1, int y1, int x2, int y2, string field[]){
    if (y1 == y2){
        for (int j = x1; j <= x2; ++j){
            if (field[y1][j] == '#'){
                return false;
            }
        }
        return true;
    }

    else{
        for (int j = y1; j <= y2; ++j){
            if (field[j][x1] == '#'){
                return false;
            }
        }
        return true;
    }
}

int main() {
    int k, n; cin >> k >> n;
    string field[k];
    for (int i = 0; i < k; i++){
        cin >> field[i];
    }

    int out_x = 0, out_y = 0, mm = 0, m = 0;
    for (int y = 0; y < k; ++y) {
        for (int x = 0; x < k; ++x) {
            if (field[y][x] == '.') {
//                cout << "----------------\n" << '(' << x << ',' << y << ')' << "\n----------------\n" ;
                m = 0;
                n -= 1;
                for (int a = 0; a < k; ++a) {
                    for (int b = 0; b < k; ++b) {

                        //LEFT TO RIGHT
                        if (a == y && b <= x && b + n < k && b + n >= x) {
//                            cout << '(' << b << ',' << a << ')';
                            if (check(b, a, b + n, a, field)){
//                                cout << " True";
                                m += 1;
                            }
//                            cout << "\n";
                        }

                        //UP TO DOWN
                        if (b == x && a <= y && a + n < k && a + n >= y){
//                            cout << '(' << b << ',' << a << ')';
                            if (check(b, a, b, a + n, field)) {
//                                cout << " True";
                                m += 1;
                            }
//                            cout << "\n";
                        }
                    }
                }

//                cout << "mm = " << mm << " m = " << m << endl;
                if (m > mm){
                    mm = m;
                    out_x = x;
                    out_y = y;

                }
                n += 1;
            }
        }
    }

    cout << out_y + 1  << " " << out_x + 1;
}



