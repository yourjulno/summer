//
// Created by 79096 on 13.07.2022.
//
#include <iostream>
#include <array>
#include <utility>
#include <vector>
#include <list>
#include <cmath>
class Polynom{
    std::vector <int> degree;
    int x;
    double sum;
public:
   explicit Polynom() = default;

   explicit Polynom(std::vector<int> deg):degree(std::move(deg)){
       for (auto i : degree){
           sum = sum + pow(x, i);
       }
   }

   Polynom& operator+(const Polynom& other){

   }

}
