#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;

int read_input() {
    int _integer=0;
    char _char=0;

    while(_char<48){
        _char=getchar_unlocked();}

    while(_char>=48)
    {_integer=10*_integer+_char-48;
        _char=getchar_unlocked();}
    return _integer;
}


int main(){
    vector<vector<int>> plan;
    int c = read_input();
    for (int i = 0; i < c; ++i){
        int t = 0;
        plan.clear();
        int d = read_input();
        for (int j = 0; j < d; ++j){
            int a = read_input();
            int b = read_input();
            plan.push_back(vector<int> {a, b});

        }

        bool yes = false;
        sort(plan.begin(), plan.end());
        for (int k = 0; k < plan.size(); ++k){
            if (t > plan[k][0]){
                cout << "NIE\n";
                yes = true;
                break;
            }
            t = plan[k][1];
        }
        if (!(yes))
            cout << "TAK\n";
    }
}