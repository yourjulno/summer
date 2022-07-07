//
// Created by 79096 on 02.07.2022.
//
#include <iostream>
#include <ctime>
template <unsigned  int N >
constexpr unsigned int factorial(){

    return  N * factorial<N-1>();
}
template<>
constexpr unsigned int factorial<1>(){
    return 1;
}
int main(){
   // auto start_time = clock();
    std::cout << factorial<3>() << std::endl;
   // std::cout<< clock() - start_time;
}


