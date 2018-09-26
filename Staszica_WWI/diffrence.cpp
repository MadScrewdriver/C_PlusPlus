#include <iostream>
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


int main() {
    int n, max = -1, min = 2000000, in;
    n = read_input();

    for (int i=0; i < n; i++){
        in = read_input();
        if (in < min)
            min = in;

        if (in > max)
            max = in;
    }
    cout << max - min;
}