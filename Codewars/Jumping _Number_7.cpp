// https://www.codewars.com/kata/jumping-number-special-numbers-series-number-4-1/train/cpp
// Created by Franek on 2018-04-22.
// Solved

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string jumpingNumber(int n)
{
    string number;
    stringstream ss; ss << n; ss >> number;

    for (int i = 0; i < number.size() - 1; ++i){
        if ((int) max(number[i], number[i + 1]) - min(number[i], number[i + 1]) != 1)
            return "Not!!";
   }

   return "Jumping!!";
}