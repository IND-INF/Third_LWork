#ifndef _COMPLEX_NUMBER_H_
#define _COMPLEX_NUMBER_H_

class Complex{
    private:
        double real;
        double imag;
    public:

        Complex(double real, double imag);
        Complex();
        Complex(const Complex &complexNum);

        double GetReal() const;
        double GetImag() const;

        Complex& SetReal(double value);
        Complex& SetImag(double value);

        Complex& operator=(const Complex &rhv){
            real = rhv.real;
            imag = rhv.imag;
            return *this;
        }
        
        friend Complex operator-(const Complex &x);
        friend Complex operator+(const Complex &lhs, const Complex &rhs);
        friend Complex operator-(const Complex &lhs, const Complex &rhs);
        friend Complex operator*(const Complex &lhs, const Complex &rhs);
        friend Complex operator/(const Complex &lhs, const Complex &rhs);

        friend bool operator==(const Complex &lhs, const Complex &rhs);
        friend bool operator!=(const Complex &lhs, const Complex &rhs);

        friend Complex& operator+=(Complex &lhs, const Complex &rhs);
        friend Complex& operator-=(Complex &lhs, const Complex &rhs);
        friend Complex& operator*=(Complex &lhs, const Complex &rhs);
        friend Complex& operator/=(Complex &lhs, const Complex &rhs);

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