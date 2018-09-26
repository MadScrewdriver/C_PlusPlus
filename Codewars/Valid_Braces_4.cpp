// https://www.codewars.com/kata/valid-braces/train/cpp
// Created by Franek on 2018-04-24.
// Solved

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

bool valid_braces(string braces)
{
    int a[3];
    a[0] = 0;
    a[1] = 0;
    a[2] = 0;

    for (int i = 0; i < braces.size(); ++i){

        if (braces[i] == '('){
            a[0] += 1;
        }

        else if (braces[i] == '{'){
            a[1] += 1;
        }

        else if (braces[i] == '['){
            a[2] += 1;
        }

        else if (braces[i] == ')'){
            if (braces[i -1] == '[' || braces[i - 1] == '{')
                return false;
            a[0] -= 1;
        }

        else if (braces[i] == '}'){
            if (braces[i -1] == '[' || braces[i - 1] == '(')
                return false;
            a[1] -= 1;
        }

        else if (braces[i] == ']'){
            if (braces[i -1] == '(' || braces[i - 1] == '{')
                return false;
            a[2] -= 1;
        }

        if (a[0] < 0 || a[1] < 0 || a[2] < 0)
            return false;
    }

    if (a[0] == 0 && a[1] == 0 && a[2] == 0)
        return true;

    else
        return false;
}



