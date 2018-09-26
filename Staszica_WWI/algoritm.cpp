#include <iostream>
using namespace std;

int main() {
    long long int x, y, s = 0;
    cin >> x >> y;
    while (x != y){
        if (max(x, y) / min(x,y) > 1){
            s += max(x, y) / min(x,y) - 1;
            if(x < y)
                y -= x * (y / x - 1);
            else
                x -= y * (x / y - 1);
        }
        else{
            if(x < y)
                y -= x;
            else
                x -= y;
            s ++;
        }
    }
    cout << s;

}

