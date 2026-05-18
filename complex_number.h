#ifndef _COMPLEX_NUMBER_H_
#define _COMPLEX_NUMBER_H_

class Complex{
    public:

        double real;
        double imag;

        Complex(double real, double imag);
        Complex();
        Complex(const Complex &complexNum);

        Complex& operator=(const Complex &rhv){
            real = rhv.real;
            imag = rhv.imag;
            return *this;
        }
        
        explicit operator bool() const{
            return (real || imag);
        }

};

Complex operator-(const Complex &x);
Complex operator+(const Complex &lhs, const Complex &rhs);
Complex operator-(const Complex &lhs, const Complex &rhs);
Complex operator*(const Complex &lhs, const Complex &rhs);
Complex operator/(const Complex &lhs, const Complex &rhs);

bool operator==(const Complex &lhs, const Complex &rhs);
bool operator!=(const Complex &lhs, const Complex &rhs);

Complex& operator+=(Complex &lhs, const Complex &rhs);
Complex& operator-=(Complex &lhs, const Complex &rhs);
Complex& operator*=(Complex &lhs, const Complex &rhs);
Complex& operator/=(Complex &lhs, const Complex &rhs);

#endif //_COMPLEX_NUMBER_H_