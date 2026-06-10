#ifndef _SUBSERVIENT_ELEMENT_FUNCTIONS_H_
#define _SUBSERVIENT_ELEMENT_FUNCTIONS_H_

#include "complex_number.h"

namespace SubservFuncs{

    double ModulusSquare(int value);
    double ModulusSquare(double value);
    double ModulusSquare(Complex value);

    template <class T>
    T Zero();
    
}

#endif //_SUBSERVIENT_ELEMENT_FUNCTIONS_H_