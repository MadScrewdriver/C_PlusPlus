// https://www.codewars.com/kata/special-number-special-numbers-series-number-5/train/cpp
// Created by Franek on 2018-04-22.
// Solved

#include <string>
#include <iostream>
#include <sstream>
using namespace std;

string specialNumber (int n)
{
    string number; stringstream ss; ss << n; ss >> number;

    for (char& i: number){
        if(i != '0' && i != '1' && i != '2' && i != '3' && i != '4' && i != '5')
            return "NOT!!";
        }

    return "Special!!";
}

