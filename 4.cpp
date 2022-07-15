//
// Created by 79096 on 13.07.2022.
//
#include <iostream>
#include <array>
#include <utility>
#include <vector>
#include <list>
#include <cmath>
#include <cassert>
using namespace std;

class Polynom {
    int degree;//степень полинома
    vector<double> koef; //вектор с коэффициентами перед степенями
    vector<double> ost; //остаток от деления

public:
    Polynom() {

    }

    Polynom(unsigned int deg, vector<double> k) {
        degree = deg;
        koef.resize(degree);
        vector<int> degrees(deg - 1);
        for (int i = 0; i < deg; i++) {
            koef[i] = k[i]; //создали коэффициенты перед степенями
        }
        for (int i = 0; i < deg; i++) {
            degrees[i] = i; //заполнили показатели степеней
        }

    }

    //  копирование
    Polynom(const Polynom &other) {
        assert(other.degree == degree);
        for (int i = 0; i < degree; i++) {
            koef[i] = other.koef[i];
            degree = other.degree;
        }
    }

    Polynom operator+(const Polynom &other) {
        Polynom sum_polynom;

        //если степень нового > степени старого
        if (other.degree >= degree) {

            for (int i = 0; i < degree; i++) {
                sum_polynom.koef[i] = sum_polynom.koef[i] + koef[i];
            }
        }
            //иначе
        else {
            for (int i = 0; i < other.degree; i++) {
                sum_polynom.koef[i] = sum_polynom.koef[i] + other.koef[i];
            }
        }

        return sum_polynom;
    }

    //присваивание
    Polynom &operator=(const Polynom &other) {
        assert(degree == other.degree);
        degree = other.degree;
        koef.clear();
        koef.shrink_to_fit();

        for (int i = 0; i < other.degree; i++) {
            koef[i] = other.koef[i];
        }
        return *this;
    }

    //равенство
    bool operator==(const Polynom &other) {
        bool is_equal = true;
        for (auto i: koef)
            for (auto j: other.koef) {
                if (i != j || degree != other.degree) {
                    is_equal = false;
                }
            }
        //cout << is_equal;
        return is_equal;
    }

//    Polynom operator/(const Polynom &other) {
//        if (degree == other.degree) {
//
//        }
//    }

    //взятие производной
    Polynom &derivative() {
        //degree --;
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
    Polynom &integral() {

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

        Polynom &operator*=(const double k) {

            for (int i = 0; i < degree; i++) {
                koef[i] = k * koef[i];
            }
            return *this;
        }

        Polynom operator*(const double k) const {

            Polynom polynom;
            polynom.operator*=(k);
            return polynom;

        }


        void OutputPolynom() {
            cout << koef[degree - 1] << "x^" << degree - 1;

            for (int i = degree - 2; i > 0; i--) {
//            if (koef[i] > 0) {
//                if (koef[i] == 1)
//                    cout << " + " << "X^" << i;
//                else
//                if (i == 0){
//
//                cout << koef[0]
                cout << " + " << koef[i] << "x^" << i;
//            } else if (koef[i] < 0)
//                if (koef[i] == -1)
//                    cout << " - " << "X^" << i;
//                else
//                    cout << " - " << (-1) * koef[i] << "X^" << i;
            }

            if (koef[0] > 0)
                cout << " + " << koef[0] << "\n";
            else if (koef[0] < 0)
                cout << " - " << (-1) * koef[0] << "\n";
        }
    };


    int main() {
        vector<double> q = {2, 3, 4}, n = {5, 6, 8, 9};
        Polynom p{3, q};
        Polynom j{4, n};
        //p.InputPolynom();
//        p.derivative();
//        p.integral();
//       p.operator*=(2);
        //p.operator=(j);
        // p.operator*(2);
        // p.operator==(j);

        p.OutputPolynom();

    }


