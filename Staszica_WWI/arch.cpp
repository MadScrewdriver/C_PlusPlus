#include <iostream>
#include<string>
using namespace std;

int main(){
    char _char=' ';
    char c;

    while(_char < 65){
        _char=getchar_unlocked();
        if (_char == 'U' || _char == 'u')
            _char = 'V';

        if (_char != ' '){
            c = toupper(_char);
            cout << c;}

    }

    while(_char >= 32){
        _char=getchar_unlocked();
        if (_char == 'U' || _char == 'u')
            _char = 'V';

        if (_char != ' '){
            c = toupper(_char);
            cout << c;}

    }
}
