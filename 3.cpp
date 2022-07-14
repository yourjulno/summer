#include <iostream>
#include <vector>
#include <cstring>
#include <cassert>
#include <random>
#include <chrono>
#include <iterator>
template<typename T, int N>
class Vector_G{
private:
    T coordinates[N]{};
    size_t capacity = N;
public:
    void f(size_t u) {
        unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
        std::mt19937 gen(seed);
        std::uniform_int_distribution<unsigned> distrib(0, 10);
        for (unsigned i = 0; i < N; i++) {
            coordinates[i] = distrib(gen);
        }
    }

    void print(){
        for(auto& it: coordinates)
            std::cout<<it<<" ";
        std::cout<<"\n";
    }

    Vector_G<T,N> operator+(Vector_G<T,N> const &v2){
        Vector_G<T,N> new_v;
        for(unsigned i=0; i<N;i++){
            new_v.coordinates[i] = coordinates[i]+v2.coordinates[i];
        }
        return new_v;
    }
    Vector_G<T,N> operator-(Vector_G<T,N> const &v2){
        Vector_G<T,N> new_v;
        for(unsigned i=0; i<N;i++){
            new_v.coordinates[i] = coordinates[i]-v2.coordinates[i];
        }
        return new_v;
    }

    Vector_G<T,N>& operator*(T num){
        for(auto& item:coordinates){
            item*=num;
        }
        return *this;
    }
    bool operator<(Vector_G<T,N> const &v2){
        long answ=0;
        for(unsigned i=0;i<N;i++){
            answ+=coordinates[i]*coordinates[i]-v2.coordinates[i]*v2.coordinates[i];
        }
        if(answ<0){
            return true;
        }
        else{
            return false;
        }
    }
    bool operator <= (Vector_G<T,N> const &v2){
        long answ=0;
        for(unsigned i=0;i<N;i++){
            answ+=coordinates[i]*coordinates[i]-v2.coordinates[i]*v2.coordinates[i];
        }
        if(answ<=0){
            return true;
        }
        else{
            return false;
        }
    }
    bool operator>(Vector_G<T,N> const &v2){
        return !(*this <= v2);
    }
    bool operator >=(Vector_G<T,N> const &v2){
        return !(*this< v2);
    }
    Vector_G<T,N>& operator= (const Vector_G<T,N> &v2){
        if(this == &v2){
            return *this;
        }
        memcpy(coordinates, v2.coordinates, N* sizeof(T));
        return *this;
    }

};
template<typename T>
class Vector_G<T, -1>{
private:
    T* coordinates;
    size_t capacity = 0;
public:
    void print(){
        for(unsigned i = 0; i<capacity; i++)
            std::cout<<coordinates[i]<<" ";
        std::cout<<"\n";
    }
    Vector_G() = default;
    explicit Vector_G(size_t N):coordinates(new T[N]), capacity(N){};
    Vector_G(size_t N, int): coordinates(new T[N]), capacity(N){
        unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
        std::mt19937 gen(seed);
        std::uniform_int_distribution<unsigned >distrib(0,10);
        for(unsigned i=0; i<N; i++){
            coordinates[i] = distrib(gen);
        }
    }
    Vector_G operator+(Vector_G const &v2){
        assert(v2.capacity==capacity);
        Vector_G<T,-1> new_v(v2.capacity);
        for(unsigned i=0; i<v2.capacity;i++){
            new_v.coordinates[i] = coordinates[i]+v2.coordinates[i];
        }
        return new_v;
    }
    Vector_G operator-(Vector_G const &v2){
        assert(v2.capacity==capacity);
        Vector_G<T,-1> new_v(v2.capacity);
        for(unsigned i=0; i<v2.capacity;i++){
            new_v.coordinates[i] = coordinates[i]-v2.coordinates[i];
        }
        return new_v;
    }

    Vector_G& operator*(T num){
        for(auto& item:coordinates){
            item*=num;
        }
        return *this;
    }
    bool operator<(Vector_G const &v2){
        assert(v2.capacity==capacity);
        long answ=0;
        for(unsigned i=0;i<v2.capacity;i++){
            answ+=coordinates[i]*coordinates[i]-v2.coordinates[i]*v2.coordinates[i];
        }
        if(answ<0){
            return true;
        }
        else{
            return false;
        }
    }
    bool operator <= (Vector_G const &v2){
        assert(v2.capacity==capacity);
        long answ=0;
        for(unsigned i=0;i<v2.capacity;i++){
            answ+=coordinates[i]*coordinates[i]-v2.coordinates[i]*v2.coordinates[i];
        }
        if(answ<=0){
            return true;
        }
        else{
            return false;
        }
    }
    bool operator>(Vector_G const &v2){
        return !(*this <= v2);
    }
    bool operator >=(Vector_G const &v2){
        return !(*this< v2);
    }




    Vector_G& operator= (const Vector_G &v2){
        if(this == &v2){
            return *this;
        }
        delete[] coordinates;
        T* new_coord = new T[v2.capacity];
        memcpy(new_coord, v2.coordinates, v2.capacity* sizeof(T));
        coordinates = new_coord;
        return *this;
    }


    void resize(size_t size){
        T* new_coord = new T[size]{};
        memcpy(coordinates, new_coord, size* sizeof(T));
        delete[] coordinates;
        coordinates = new_coord;
    }
    ~Vector_G(){
        delete[] coordinates;
    }
};
int main() {
    Vector_G<int, 5>a{};
    Vector_G<int,5>a1;
    a1.f(4);
    a1.print();
    a.f(4);
    a.print();
    Vector_G<int, -1> b(5, 2);
    Vector_G<int, -1> b1(5, 2);
    b.print();
    Vector_G<int, 5>sum ;
    bool flag = b1<=b;
    std::cout<<"\n"<<flag<<"\n";
    sum.print();
    return 0;
}