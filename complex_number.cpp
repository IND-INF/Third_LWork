#include "complex_number.h"

Complex::Complex(double real, double imag) : real(real), imag(imag){}

Complex::Complex() : real(0), imag(0){}

Complex::Complex(const Complex &complexNum) : real(complexNum.real), imag(complexNum.imag){}

Complex operator-(const Complex &x){
    Complex res(-x.real, -x.imag);
    return res;
}

Complex operator+(const Complex &lhs, const Complex &rhs){
    Complex res(lhs.real + rhs.real, lhs.imag + rhs.imag);
    return res;
}

Complex operator-(const Complex &lhs, const Complex &rhs){
    Complex res(lhs.real - rhs.real, lhs.imag - rhs.imag);
    return res;
}

Complex operator*(const Complex &lhs, const Complex &rhs){
    Complex res(lhs.real*rhs.real - lhs.imag*rhs.imag, lhs.imag*rhs.real + lhs.real*rhs.imag);
    return res;
}

Complex operator/(const Complex &lhs, const Complex &rhs){
    double rhsMod = rhs.real*rhs.real + rhs.imag*rhs.imag;
    Complex res((lhs.real*rhs.real + lhs.imag*rhs.imag)/rhsMod, (lhs.imag*rhs.real - lhs.real*rhs.imag)/rhsMod);
    return res;
}

bool operator==(const Complex &lhs, const Complex &rhs){
    return (lhs.real == rhs.real && lhs.imag == rhs.imag);
}

bool operator!=(const Complex &lhs, const Complex &rhs){
    return (lhs.real != rhs.real || lhs.imag != rhs.imag);
}

Complex& operator+=(Complex &lhs, const Complex &rhs){
    lhs.real += rhs.real;
    lhs.imag += rhs.imag;
    return lhs;
}

Complex& operator-=(Complex &lhs, const Complex &rhs){
    lhs.real -= rhs.real;
    lhs.imag -= rhs.imag;
    return lhs;
}

Complex& operator*=(Complex &lhs, const Complex &rhs){

    double oldLhsReal = lhs.real;

    lhs.real *= rhs.real;
    lhs.real -= lhs.imag*rhs.imag;

    lhs.imag *= rhs.real;
    lhs.imag += oldLhsReal*rhs.imag;

    return lhs;

}

Complex& operator/=(Complex &lhs, const Complex &rhs){

    double rhsMod = rhs.real*rhs.real + rhs.imag*rhs.imag;
    double oldLhsReal = lhs.real;

    lhs.real *= rhs.real;
    lhs.real += lhs.imag*rhs.imag;
    lhs.real /= rhsMod;

    lhs.imag *= rhs.real;
    lhs.imag -= oldLhsReal*rhs.imag;
    lhs.imag /= rhsMod;

    return lhs;
    
}