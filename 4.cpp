//
// Created by 79096 on 13.07.2022.
//
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

template <typename T>
class Polynom {
    int degree;//степень полинома
    vector<T> koef; //вектор с коэффициентами перед степенями

    void is_degree_right() {
        int resdeg = degree;
        for (int i = degree - 1; i >= 0; i--) {
            if (koef[i] != 0.0)
                break;
            else
                resdeg--;
        }
        degree = resdeg;
    }

public:
    Polynom() = default;

    explicit Polynom<T>(int degree_): degree(degree_) {

        koef.resize(degree);
        for (int i = 0; i < degree; i++) {
            koef[i] = T(0);
        }
    }

    Polynom<T>(int deg, vector<T> k) : degree(deg) {

        koef.resize(degree);

        for (int i = 0; i < deg; i++) {
            koef[i] = k[i]; //создали коэффициенты перед степенями
        }

    }

    //  копирование
    Polynom<T>(const Polynom<T> &other) {
        assert(other.degree == degree);
        for (int i = 0; i < degree; i++) {
            koef[i] = other.koef[i];
        }
        degree = other.degree;
    }

    T operator[](size_t i) const {
        if (i >= koef.size()) {
            return T(0);
        } else {
            return koef[i];
        }
    }

    long long Degree() const {
        if (koef.empty()) {
            return -1;
        } else return static_cast<int>(koef.size()) - 1;
    }

    Polynom<T> operator+(const Polynom<T> &other) {
        Polynom<T> sum_polynom;

        //если степень нового > степени старого
        if (other.degree >= degree) {

            for (size_t i = 0; i < degree; i++) {
                sum_polynom.koef[i] = sum_polynom.koef[i] + koef[i];
            }
        }
            //иначе
        else {
            for (size_t i = 0; i < other.degree; i++) {
                sum_polynom.koef[i] = sum_polynom.koef[i] + other.koef[i];
            }
        }

        return sum_polynom;
    }

    Polynom<T> &operator-=(const Polynom<T> &other) {
        koef.resize(std::max(other.data.size(), koef.size()), T(0));
        for (size_t i = 0; i != std::min(koef.size(), other.data.size()); ++i) {
            koef[i] -= other.data[i];
        }
        is_degree_right();
        return *this;
    }

    //присваивание
    Polynom<T> &operator=(const Polynom<T> &other) {

        degree = other.degree;
        koef.clear();
        koef.shrink_to_fit();

        for (int i = 0; i < other.degree; i++) {
            koef[i] = other.koef[i];
        }
        return *this;
    }

    //равенство
    bool operator==(const Polynom<T> &other) const {
        bool is_equal = true;
        for (auto i: koef)
            for (auto j: other.koef) {
                if (i != j || degree != other.degree) {
                    is_equal = false;
                }
            }

        return is_equal;
    }

    bool operator!=(const Polynom<T> &other) const {
        return !(*this == other);
    }


    Polynom<T> operator/(const Polynom<T> &other) {
        assert(degree > other.degree);
        Polynom<T> p1(other.degree, other.koef);
        Polynom<T> p2(degree, koef);
        int delta = p2.degree - p1.degree + 1;
        Polynom<T> res(delta);
        for (int i = 0; i < delta; i++) {
            res.koef[delta - i - 1] = p2.koef[p2.degree - i - 1] / p1.koef[p1.degree - 1];
            for (int j = 0; j < p1.degree; j++) {
                p2.koef[p2.degree - j - i - 1] -= p1.koef[p1.degree - j - 1] * res.koef[delta - i - 1];
            }
        }
        p2.is_degree_right();
        return res;
    }

    Polynom<T> &operator%=(const Polynom<T> &other) {
        Polynom<T> res = *this / other;
        *this -= other * res;
        return *this;
    }


    //взятие производной
    Polynom<T> &derivative() {

        for (int i = 0; i < degree; i++) {
            koef[i] = koef[i] * i;
        }
        for (int i = 0; i < degree; i++) {
            koef[i] = koef[i + 1];
        }
        degree--;

        return *this;
    }

    //первообразная
    Polynom<T> &integral() {

        for (int i = 0; i < degree; i++) {

            koef[i] = koef[i] / (i + 1);
        }
        for (int i = degree; i > 0; i--) {

            koef[i] = koef[i - 1];

        }
        degree++;
        koef[0] = 0;

        return *this;
    }

    //умножение на число
    Polynom<T> &operator*=(const double k) {

        for (int i = 0; i < degree; i++) {
            koef[i] = k * koef[i];
        }
        return *this;
    }

    Polynom<T> operator*(const double k) const {

        Polynom polynom;
        polynom.operator*=(k);
        return polynom;

    }

    Polynom<T> &operator*=(const Polynom<T> &other) {
        vector<T> res(degree + other.degree, T(0));
        for (size_t i = 0; i != degree; ++i) {
            for (size_t j = 0; j != other.degree; ++j) {
                res[i + j] += koef[i] * other.data[j];
            }
        }

        *this = Polynom(degree + other.degree, res);
        return *this;
    }

    friend std::ostream &operator<<(std::ostream &out, const Polynom<T> &p) {

        for (int i = p.degree - 1; i > 0; i--){
            cout << " + " << p.koef[i] << "x^" << i;
            if (i == 0){
                cout << p.koef[0];
            }
        }
        if (p.koef[0] > 0) {
            cout << " + " << p.koef[0] << "\n";
        }
            else if (p.koef[0] < 0) {
            cout << " - " << (-1) * p.koef[0] << "\n";
        }
        return out;
    };
};


    int main() {
        vector<int> n = {1, 1};
        vector<int> q = {1, 2, 1};
        Polynom<int> p{3, q};
        Polynom<int> j{2, n};
      // auto res = p.operator/(j);
        p.derivative();
//        p.integral();
//       p.operator*=(2);
        //p.operator=(j);
        // p.operator*(2);
        // p.operator==(j);
//кек
        cout << p;

    }


