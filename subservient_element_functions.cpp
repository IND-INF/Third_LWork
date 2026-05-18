#include "subservient_element_functions.h"

double SubservFuncs::ModulusSquare(int value){
    return value*value;
}

double SubservFuncs::ModulusSquare(double value){
    return value*value;
}

double SubservFuncs::ModulusSquare(Complex value){
    return value.real*value.real + value.imag*value.imag;
}

template <class T>
T SubservFuncs::Zero(){}

template <>
int SubservFuncs::Zero<int>(){
    return 0;
}
template int SubservFuncs::Zero<int>();

template <>
double SubservFuncs::Zero<double>(){
    return 0;
}
template double SubservFuncs::Zero<double>();

static const Complex complexZero(0, 0);
template <>
Complex SubservFuncs::Zero<Complex>(){
    return complexZero;
}
template Complex SubservFuncs::Zero<Complex>();