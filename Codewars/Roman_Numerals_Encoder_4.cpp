// https://www.codewars.com/kata/roman-numerals-encoder/solutions/cpp
// Created by Franek on 2018-04-26.
// Solved

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string solution(int n){
    string o, i; stringstream ss; ss << n; ss >> i;

    if (i.size() == 4){
        int num_of_M = i[0] - '0';
        o.append(num_of_M, 'M');
        i.erase(0, 1);
    }


    if (i.size() == 3){
        int num_of_H = i[0] - '0';

        if(num_of_H == 9){
            o += "CM";
        }

        else if(num_of_H >= 5){
            o += "D";
            o.append(num_of_H - 5, 'C');
        }

        else if (num_of_H == 4) {
            o += "CD";
        }

        else if(num_of_H != 0)
            o.append(num_of_H, 'C');


        i.erase(0, 1);
    }

    if (i.size() == 2){
        int num_of_T = i[0] - '0';

        if(num_of_T == 9){
            o += "XC";
        }

        else if(num_of_T >= 5){
            o += 'L';
            o.append(num_of_T - 5, 'X');
        }

        else if (num_of_T == 4) {
            o += "XL";
        }

        else if(num_of_T != 0)
            o.append(num_of_T, 'X');

        i.erase(0, 1);
    }


    int num_of_U = i[0] - '0';

    if (num_of_U == 9)
        o += "IX";

    else if (num_of_U >= 5) {
        o += 'V';
        o.append(num_of_U - 5, 'I');
    }

    else if (num_of_U == 4) {
        o += "IV";
    }

    else if(num_of_U != 0)
        o.append(num_of_U, 'I');



    return o;
}
