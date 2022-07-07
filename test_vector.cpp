//
// Created by aleksandr on 02.07.22.
//
#include <iostream>
#include <array>
#include <vector>
#include <initializer_list>
#include <cmath>
using namespace std;
template <typename Type, int N>
class Vector {
    static_assert(N >= 0);
    std::array<Type, N> data_;

public:
    constexpr Vector() = default;
    constexpr Vector(const Vector<Type, N>& other){
        for (int i = 0; i < N; i ++){
             data_[i] = other[i] ;
        }
    }
    constexpr Vector(std::initializer_list<Type>);

    const Type& operator[](unsigned int i) const{
        return this->data_[i];
    }
    Type& operator[](unsigned int i){
        return data_[i];
    }
    Type norm() const{

    }

    Vector<Type, N> operator*=(Type num){
        for (int i = 0; i < N; i ++){
            data_[i] = data_[i] * num;
        }
        return *this;
    }
    Vector<Type, N> operator/=(Type num){
        for (int i = 0; i < N; i ++){
            data_[i] = data_[i] / num;
        }
        return *this;
    }
    Vector<Type, N> operator+=(const Vector<Type, N>& other){
        for (int i = 0; i < N; i ++){
            data_[i] = data_[i] + other.data_[i];
        }
        return *this;
    }
    Vector<Type, N> operator-=(const Vector<Type, N>& other){
        for (int i = 0; i < N; i ++){
            data_[i] = data_[i] - other.data_[i];
        }
        return *this;
    }

    Vector<Type, N> operator*(Type num) const{
        Vector<Type, N> vec;
        for (int i = 0; i < N; i++){
            vec.data_[i] = vec.data_[i] * num;
        }
        return vec;
    }
    Vector<Type, N> operator/(Type num) const{
        Vector<Type, N> vec;
        for (int i = 0; i < N; i++){
            vec.data_[i] = vec.data_[i] / num;
        }
        return vec;
    }

    Vector<Type, N> operator+(const Vector<Type, N>& other) const{
        Vector<Type, N> vec;
        for (int i = 0; i < N; i++){
            vec.data_[i] = vec.data_[i] + other.data_[i];
        }
        return vec;
    }

    Vector<Type, N> operator-(const Vector<Type, N>& other) const{
        Vector<Type, N> vec;
        for (int i = 0; i < N; i++){
            vec.data_[i] = vec.data_[i] - other.data_[i];
        }
        return vec;
    }
    bool operator<(const Vector<Type, N>& other){
        double b = 0;
        for (int i = 0; i < N; i++){
            b = b + (data_[i]*data_[i] - other.data_[i]*other.data_[i]);
        }
        if (b < 0) {
            return true;
        } else {
            return false;
        }
    }

    template <typename X, int P>
    friend Vector<Type, N> operator*(Type num, const Vector<X, P>& vec);
    template <typename X, int P>
    friend std::ostream operator<<(std::ostream& out,  const Vector<X, P>& vec);
};
template <typename Type, int N>
std::ostream& operator<<(std::ostream& os, const Vector<Type, N>& a1){
    for (int i = 0; i < N; i++){
        os << a1.operator[](i) << " ";
    }
    return os;
}
//кек
//class
template <typename Type, int N>
Vector<Type, N> operator*(Type num, const Vector<Type, N>& vec){
    Vector<Type, N> vec1(N);
    for (int i = 0; i < N; i++){
        vec1.operator[](i) = num * vec.data_[i];
    }
    return vec1;
}

constexpr int Dynamic = -1;

template <typename Type>
class Vector<Type, Dynamic> {
    std::vector<Type> data_;
    int size_;

public:
    constexpr Vector() = default;
    constexpr Vector(const Vector<Type, Dynamic>& other){
        for (int i = 0; i < size_; i ++){
            other[i] = data_[i];
        }
    }
    constexpr Vector(std::initializer_list<Type>);
    const Type& operator[](unsigned int i) const{ //вернуть этот же элемент
        return this->data_[i];
    }
    Type& operator[](unsigned int i){
        return data_[i];
    }
    Type norm() const;

    Vector<Type, Dynamic> operator*=(Type num){
        for (int i = 0; i < size_; i ++){
            data_[i] = data_[i] * num;
        }
        return *this;
    }
    Vector<Type, Dynamic> operator/=(Type num){
        for (int i = 0; i < size_; i ++){
            data_[i] = data_[i] / num;
        }
        return *this;
    }
    Vector<Type, Dynamic> operator+=(const Vector<Type, Dynamic>& other){
        for (int i = 0; i < size_; i ++){
            data_[i] = data_[i] + other.data_[i];
        }
        return *this;
    }
    Vector<Type, Dynamic> operator-=(const Vector<Type, Dynamic>& other){
        for (int i = 0; i < size_; i ++){
            data_[i] = data_[i] - other.data_[i];
        }
        return *this;
    }

    Vector<Type, Dynamic> operator*(Type num) const{
        Vector<Type, Dynamic> vec;
        for (int i = 0; i < size_; i++){
            vec.data_[i] = vec.data_[i] * num;
        }
        return vec;
    }
    Vector<Type, Dynamic> operator/(Type num) const{
        Vector<Type, Dynamic> vec;
        for (int i = 0; i < size_; i++){
            vec.data_[i] = vec.data_[i] / num;
        }
        return vec;
    }
    Vector<Type, Dynamic> operator+(const Vector<Type, Dynamic>& other) const{
        Vector<Type, Dynamic> vec;
        for (int i = 0; i < size_; i++){
            vec.data_[i] = vec.data_[i] + other.data_[i];
        }
        return vec;
    }
    Vector<Type, Dynamic> operator-(const Vector<Type, Dynamic>& other) const{
        Vector<Type, Dynamic> vec;
        for (int i = 0; i < size_; i++){
            vec.data_[i] = vec.data_[i] - other.data_[i];
        }
        return vec;
    }
    template <typename X>
    friend Vector<Type, Dynamic> operator*(Type num, const Vector<X, Dynamic>& vec);
    template <typename X>
    friend std::ostream operator<<(std::ostream& out,  const Vector<Type, Dynamic>& vec);
};
template <typename Type>
std::ostream& operator<<(std::ostream& os, const Vector<Type, Dynamic>& vec){
    for (auto i = 0; i < vec.size_; i++){
        os << vec[i] << " ";
    }
    return os;
}
template <typename Type>
Vector<Type, Dynamic> operator*(Type num, const Vector<Type, Dynamic>& vec){
    Vector<Type, Dynamic> vec1;
    for (int i = 0; i < vec.size_; i++){
        vec1 = vec.data_[i] * num;
    }
    return vec1;
}
int main(){
    Vector<int, 8> a;
    //Vector<int, -5> a2;
   // Vector<int, 8> a1(a);
//    for (int i = 0; i < 8; i++){
//        cout << a1.operator[](i) << " ";
//    }
    cout << endl;
    a.operator*(4);
    for (int i = 0; i < 8; i++){

        cout << a.operator[](i) << " ";
    }
    a.operator*=(4);
    cout << endl;
    for (int i = 0; i < 8; i++){

        cout << a.operator[](i) << " ";
    }
}