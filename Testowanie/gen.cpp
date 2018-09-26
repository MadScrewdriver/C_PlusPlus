#include <iostream>
#include <random>
using namespace std;
int mod = 10000;

int main(){
    int seed;
    cin >> seed;
    srand(seed);

    int a = rand() % mod + 1;
    int b = rand() % mod + 1;

    cout << " " << a << " " << b;
}