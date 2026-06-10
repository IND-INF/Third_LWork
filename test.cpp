#include "test.h"
#include <numbers>
#include <iostream>

#define TEST_CONDITION_MACRO(condition) \
do{                                     \
    if(!(condition)) fail = true;       \
}while(0);

#define TEST_EXCEPTION_MACRO(functionUnderTest, exceptionType)  \
do{                                                             \
    try{                                                        \
        (functionUnderTest);                                    \
        fail = true;                                            \
    }                                                           \
    catch(const exceptionType&){}                               \
    catch(...){                                                 \
        fail = true;                                            \
    }                                                           \
}while(0);

#define TEST_OUT_OF_RANGE_MACRO(functionUnderTest, entered, minimal, maximal)   \
do{                                                                             \
    try{                                                                        \
        (functionUnderTest);                                                    \
        fail = true;                                                            \
    }                                                                           \
    catch(const IndexOutOfRange &exc){                                          \
        if(exc.GetEnteredIndex() != (entered)) fail = true;                     \
        if(exc.GetMinimalLimit() != (minimal)) fail = true;                     \
        if(exc.GetMaximalLimit() != (maximal)) fail = true;                     \
    }                                                                           \
    catch(...){                                                                 \
        fail = true;                                                            \
    }                                                                           \
}while(0);

#define TEST_INCOMPATIBLE_VECTORS_MACRO(functionUnderTest, firstSize, secondSize)   \
do{                                                                                 \
    try{                                                                            \
        (functionUnderTest);                                                        \
        fail = true;                                                                \
    }                                                                               \
    catch(const IncompatibleVectors &exc){                                          \
        if(exc.GetFirstSize() != (firstSize)) fail = true;                          \
        if(exc.GetSecondSize() != (secondSize)) fail = true;                        \
    }                                                                               \
    catch(...){                                                                     \
        fail = true;                                                                \
    }                                                                               \
}while(0);

#define TEST_TOO_LITTLE_GAP_MACRO(functionUnderTest, actualGap, minimalGap) \
do{                                                                         \
    try{                                                                    \
        (functionUnderTest);                                                \
        fail = true;                                                        \
    }                                                                       \
    catch(const TooLittleGap &exc){                                         \
        if(exc.GetActualGap() != (actualGap)) fail = true;                  \
        if(exc.GetMinimalGap() != (minimalGap)) fail = true;                \
    }                                                                       \
    catch(...){                                                             \
        fail = true;                                                        \
    }                                                                       \
}while(0);

#define TEST_COUNTER_MACRO(testName)                            \
do{                                                             \
    if(!(testName())) ++count;                                  \
    else std::cout << #testName << " not passed" << std::endl;  \
}while(0);

bool TestComplexFullCtor(){

    bool fail = false;

    Complex c(1.5, -2.5);

    TEST_CONDITION_MACRO(c.GetReal() == 1.5)
    TEST_CONDITION_MACRO(c.GetImag() == -2.5)

    return fail;

}

bool TestComplexDefaultCtor(){

    bool fail = false;

    Complex c;

    TEST_CONDITION_MACRO(c.GetReal() == 0)
    TEST_CONDITION_MACRO(c.GetImag() == 0)

    return fail;

}

bool TestComplexCopyCtor(){

    bool fail = false;

    Complex src(3.0, 4.0);
    Complex c(src);

    TEST_CONDITION_MACRO(&c != &src)
    TEST_CONDITION_MACRO(c.GetReal() == 3.0)
    TEST_CONDITION_MACRO(c.GetImag() == 4.0)

    return fail;

}

bool TestComplexGetReal(){

    bool fail = false;

    Complex c(2.75, -1.25);

    TEST_CONDITION_MACRO(c.GetReal() == 2.75)

    return fail;

}

bool TestComplexGetImag(){

    bool fail = false;

    Complex c(2.75, -1.25);

    TEST_CONDITION_MACRO(c.GetImag() == -1.25)

    return fail;

}

bool TestComplexSetReal(){

    bool fail = false;

    Complex c;
    Complex &ref = c.SetReal(5.5);

    TEST_CONDITION_MACRO(c.GetReal() == 5.5)
    TEST_CONDITION_MACRO(&ref == &c)

    return fail;

}

bool TestComplexSetImag(){

    bool fail = false;

    Complex c;
    Complex &ref = c.SetImag(-3.5);

    TEST_CONDITION_MACRO(c.GetImag() == -3.5)
    TEST_CONDITION_MACRO(&ref == &c)

    return fail;

}

bool TestComplexOperatorEqual(){

    bool fail = false;

    Complex src(3.0, 4.0);
    Complex c;
    Complex &ref = (c = src);

    TEST_CONDITION_MACRO(c.GetReal() == 3.0)
    TEST_CONDITION_MACRO(c.GetImag() == 4.0)
    TEST_CONDITION_MACRO(&ref == &c)

    return fail;

}

bool TestComplexOperatorUnaryMinus(){

    bool fail = false;

    Complex c(1.0, 2.0);
    Complex res = -c;

    TEST_CONDITION_MACRO(res.GetReal() == -1.0)
    TEST_CONDITION_MACRO(res.GetImag() == -2.0)

    return fail;

}

bool TestComplexOperatorPlus(){

    bool fail = false;

    Complex c1(1.0, 2.0);
    Complex c2(3.0, 4.0);
    Complex res = c1 + c2;

    TEST_CONDITION_MACRO(res.GetReal() == 4.0)
    TEST_CONDITION_MACRO(res.GetImag() == 6.0)

    return fail;

}

bool TestComplexOperatorBinaryMinus(){

    bool fail = false;

    Complex c1(1.0, 2.0);
    Complex c2(3.0, 4.0);
    Complex res = c1 - c2;

    TEST_CONDITION_MACRO(res.GetReal() == -2.0)
    TEST_CONDITION_MACRO(res.GetImag() == -2.0)

    return fail;

}

bool TestComplexOperatorAsterisk(){

    bool fail = false;

    Complex c1(1.0, 2.0);
    Complex c2(3.0, 4.0);
    Complex res = c1 * c2;

    TEST_CONDITION_MACRO(res.GetReal() == -5.0)
    TEST_CONDITION_MACRO(res.GetImag() == 10.0)

    return fail;

}

bool TestComplexOperatorSlash(){

    bool fail = false;

    Complex c1(1.0, 2.0);
    Complex c2(2.0, 2.0);
    Complex res = c1 / c2;

    TEST_CONDITION_MACRO(res.GetReal() == (3.0/4.0))
    TEST_CONDITION_MACRO(res.GetImag() == (1.0/4.0))

    return fail;

}

bool TestComplexOperatorDoubleEqual(){

    bool fail = false;

    Complex c0(3.0, -4.0);
    Complex c1(3.0, -4.0);
    Complex c2(3.0, -4.1);

    TEST_CONDITION_MACRO(c0 == c1)
    TEST_CONDITION_MACRO(!(c0 == c2))

    return fail;

}

bool TestComplexOperatorNotEqual(){

    bool fail = false;

    Complex c0(1.0, 2.0);
    Complex c1(2.0, 1.0);
    Complex c2(1.0, 2.0);

    TEST_CONDITION_MACRO(c0 != c1)
    TEST_CONDITION_MACRO(!(c0 != c2))

    return fail;

}

bool TestComplexOperatorPlusEqual(){

    bool fail = false;

    Complex c1(1.0, 2.0);
    Complex c2(3.0, 4.0);
    Complex &ref = (c1 += c2);

    TEST_CONDITION_MACRO(c1.GetReal() == 4.0)
    TEST_CONDITION_MACRO(c1.GetImag() == 6.0)
    TEST_CONDITION_MACRO(&ref == &c1)

    return fail;

}

bool TestComplexOperatorMinusEqual(){

    bool fail = false;

    Complex c1(5.0, 6.0);
    Complex c2(1.0, 2.0);
    Complex &ref = (c1 -= c2);

    TEST_CONDITION_MACRO(c1.GetReal() == 4.0)
    TEST_CONDITION_MACRO(c1.GetImag() == 4.0)
    TEST_CONDITION_MACRO(&ref == &c1)

    return fail;

}

bool TestComplexOperatorAsteriskEqual(){

    bool fail = false;

    Complex c1(1.0, 2.0);
    Complex c2(3.0, 4.0);
    Complex &ref = (c1 *= c2);

    TEST_CONDITION_MACRO(c1.GetReal() == -5.0)
    TEST_CONDITION_MACRO(c1.GetImag() == 10.0)
    TEST_CONDITION_MACRO(&ref == &c1)

    return fail;

}

bool TestComplexOperatorSlashEqual(){

    bool fail = false;

    Complex c1(1.0, 2.0);
    Complex c2(2.0, 2.0);
    Complex &ref = (c1 /= c2);

    TEST_CONDITION_MACRO(c1.GetReal() == (3.0/4.0))
    TEST_CONDITION_MACRO(c1.GetImag() == (1.0/4.0))
    TEST_CONDITION_MACRO(&ref == &c1)

    return fail;

}

bool TestModulusSquareInt(){

    bool fail = false;

    int z = 5;
    double res = SubservFuncs::ModulusSquare(z);

    TEST_CONDITION_MACRO(res == 25.0)

    return fail;

}

bool TestModulusSquareDouble(){

    bool fail = false;

    double r = 2.5;
    double res = SubservFuncs::ModulusSquare(r);

    TEST_CONDITION_MACRO(res == 6.25)

    return fail;

}

bool TestModulusSquareComplex(){

    bool fail = false;
    
    Complex c(3.0, 4.0);
    double res = SubservFuncs::ModulusSquare(c);

    TEST_CONDITION_MACRO(res == 25.0)

    return fail;

}

bool TestZeroInt(){

    bool fail = false;

    int z = SubservFuncs::Zero<int>();

    TEST_CONDITION_MACRO(z == 0)

    return fail;

}

bool TestZeroDouble(){

    bool fail = false;

    double r = SubservFuncs::Zero<double>();

    TEST_CONDITION_MACRO(r == 0.0)

    return fail;

}

bool TestZeroComplex(){

    bool fail = false;

    Complex c = SubservFuncs::Zero<Complex>();

    TEST_CONDITION_MACRO(c.GetReal() == 0.0)
    TEST_CONDITION_MACRO(c.GetImag() == 0.0)

    return fail;

}

bool TestVectorFullCtor(){

    bool fail = false;

    int items[] = {1, 2, 3};
    Vector<int> v(items, 3);

    TEST_CONDITION_MACRO(v.GetCount() == 3)
    TEST_CONDITION_MACRO(v.Get(0) == 1)
    TEST_CONDITION_MACRO(v.Get(1) == 2)
    TEST_CONDITION_MACRO(v.Get(2) == 3)

    return fail;

}

bool TestVectorDefaultCtor(){

    bool fail = false;

    Vector<int> v;

    TEST_CONDITION_MACRO(v.GetCount() == 0)

    return fail;

}

bool TestVectorCopyCtor(){

    bool fail = false;

    int items[] = {7, 8, 9};
    Vector<int> src(items, 3);
    Vector<int> v(src);

    TEST_CONDITION_MACRO(&v != &src)
    TEST_CONDITION_MACRO(v.GetCount() == 3)
    TEST_CONDITION_MACRO(v.Get(0) == 7)
    TEST_CONDITION_MACRO(v.Get(1) == 8)
    TEST_CONDITION_MACRO(v.Get(2) == 9)

    return fail;

}

bool TestVectorGet(){

    bool fail = false;

    int items[] = {10, 20};
    Vector<int> v(items, 2);

    TEST_CONDITION_MACRO(v.Get(0) == 10)
    TEST_CONDITION_MACRO(v.Get(1) == 20)

    return fail;

}

bool TestVectorGetCount(){

    bool fail = false;

    int items[] = {5, 15, 25};
    Vector<int> v(items, 3);

    TEST_CONDITION_MACRO(v.GetCount() == 3)
    
    return fail;

}

bool TestVectorCopy(){

    bool fail = false;

    int items[] = {4, 5, 6};
    Vector<int> src(items, 3);
    Vector<int>* v = src.Copy();

    TEST_CONDITION_MACRO(v != &src)
    TEST_CONDITION_MACRO(v->GetCount() == 3)
    TEST_CONDITION_MACRO(v->Get(0) == 4)
    TEST_CONDITION_MACRO(v->Get(1) == 5)
    TEST_CONDITION_MACRO(v->Get(2) == 6)

    delete v;
    return fail;

}

bool TestVectorOperatorPlus(){

    bool fail = false;

    int items1[] = {1, 2, 3};
    int items2[] = {4, 5, 6};
    Vector<int> v1(items1, 3);
    Vector<int> v2(items2, 3);
    Vector<int> res = v1 + v2;

    TEST_CONDITION_MACRO(res.GetCount() == 3)
    TEST_CONDITION_MACRO(res.Get(0) == 5)
    TEST_CONDITION_MACRO(res.Get(1) == 7)
    TEST_CONDITION_MACRO(res.Get(2) == 9)

    return fail;

}

bool TestVectorOperatorAsteriskLeft(){

    bool fail = false;

    int items[] = {3, -2};
    Vector<int> v(items, 2);
    Vector<int> res = 3 * v;

    TEST_CONDITION_MACRO(res.GetCount() == 2)
    TEST_CONDITION_MACRO(res.Get(0) == 9)
    TEST_CONDITION_MACRO(res.Get(1) == -6)

    return fail;

}

bool TestVectorOperatorAsteriskRight(){

    bool fail = false;

    int items[] = {2, -1};
    Vector<int> v(items, 2);
    Vector<int> res = v * 2;

    TEST_CONDITION_MACRO(res.GetCount() == 2)
    TEST_CONDITION_MACRO(res.Get(0) == 4)
    TEST_CONDITION_MACRO(res.Get(1) == -2)

    return fail;

}

bool TestVectorOperatorAsteriskDotProduct(){

    bool fail = false;

    int items1[] = {1, 2, 3};
    int items2[] = {4, 5, 6};
    Vector<int> v1(items1, 3);
    Vector<int> v2(items2, 3);

    TEST_CONDITION_MACRO(v1 * v2 == 1*4 + 2*5 + 3*6)

    return fail;

}

bool TestVectorOperatorPlusEqual(){

    bool fail = false;

    int items1[] = {1, 2, 3};
    int items2[] = {4, 5, 6};
    Vector<int> v1(items1, 3);
    Vector<int> v2(items2, 3);
    Vector<int> &ref = (v1 += v2);

    TEST_CONDITION_MACRO(v1.GetCount() == 3)
    TEST_CONDITION_MACRO(v1.Get(0) == 5)
    TEST_CONDITION_MACRO(v1.Get(1) == 7)
    TEST_CONDITION_MACRO(v1.Get(2) == 9)
    TEST_CONDITION_MACRO(&ref == &v1)

    return fail;

}

bool TestVectorOperatorAsteriskEqual(){

    bool fail = false;

    int items[] = {3, -2};
    Vector<int> v(items, 2);
    Vector<int> &ref = (v *= 3);

    TEST_CONDITION_MACRO(v.GetCount() == 2)
    TEST_CONDITION_MACRO(v.Get(0) == 9)
    TEST_CONDITION_MACRO(v.Get(1) == -6)
    TEST_CONDITION_MACRO(&ref == &v)

    return fail;

}

bool TestVectorGetNorm(){

    bool fail = false;

    int items[] = {5, -3};
    Vector<int> v(items, 2);

    TEST_CONDITION_MACRO(v.GetNorm() == std::sqrt(34.0))

    return fail;

}

bool TestVectorOperatorEqual(){

    bool fail = false;

    int items[] = {1, 2, 3, 4};
    Vector<int> src(items, 4);
    Vector<int> v;
    Vector<int> &ref = (v = src);

    TEST_CONDITION_MACRO(v.GetCount() == 4)
    TEST_CONDITION_MACRO(v.Get(0) == 1)
    TEST_CONDITION_MACRO(v.Get(1) == 2)
    TEST_CONDITION_MACRO(v.Get(2) == 3)
    TEST_CONDITION_MACRO(v.Get(3) == 4)
    TEST_CONDITION_MACRO(&ref == &v)

    return fail;

}

bool TestVectorGetEnumerator(){
    
    bool fail = false;

    int items[] = {1, 2, 3};
    Vector<int> v(items, 3);
    IEnumerable<int>::IEnumerator *e = v.GetEnumerator();
    
    TEST_CONDITION_MACRO(e->Current() == 1)
    e->MoveNext();
    TEST_CONDITION_MACRO(e->Current() == 2)
    e->MoveNext();
    TEST_CONDITION_MACRO(e->Current() == 3)

    delete e;
    return fail;

}

bool TestVectorEnumeratorFullCtor(){

    bool fail = false;

    int items[] = {1, 2, 3};
    Vector<int> v(items, 3);
    Vector<int>::Enumerator e(v);

    TEST_CONDITION_MACRO(e.Current() == 1)
    e.MoveNext();
    TEST_CONDITION_MACRO(e.Current() == 2)
    e.MoveNext();
    TEST_CONDITION_MACRO(e.Current() == 3)

    return fail;

}

bool TestVectorEnumeratorCopyCtor(){

    bool fail = false;

    int items[] = {4, 5};
    Vector<int> v(items, 2);
    Vector<int>::Enumerator src(v);
    Vector<int>::Enumerator e(src);

    TEST_CONDITION_MACRO(&e != &src)
    TEST_CONDITION_MACRO(e.Current() == 4)
    e.MoveNext();
    TEST_CONDITION_MACRO(e.Current() == 5)

    return fail;

}

bool TestVectorEnumeratorCurrent(){

    bool fail = false;

    int items[] = {5, 3, 1};
    Vector<int> v(items, 3);
    Vector<int>::Enumerator e(v);

    TEST_CONDITION_MACRO(e.Current() == 5)
    e.MoveNext();
    TEST_CONDITION_MACRO(e.Current() == 3)
    e.MoveNext();
    TEST_CONDITION_MACRO(e.Current() == 1)

    return fail;

}

bool TestVectorEnumeratorMoveNext(){

    bool fail = false;

    int items[] = {7, 11, 12, 0};
    Vector<int> v(items, 4);
    Vector<int>::Enumerator e(v);

    TEST_CONDITION_MACRO(e.MoveNext() == true)
    TEST_CONDITION_MACRO(e.Current() == 11)
    TEST_CONDITION_MACRO(e.MoveNext() == true)
    TEST_CONDITION_MACRO(e.Current() == 12)
    TEST_CONDITION_MACRO(e.MoveNext() == true)
    TEST_CONDITION_MACRO(e.Current() == 0)
    TEST_CONDITION_MACRO(e.MoveNext() == false)

    return fail;

}

bool TestVectorEnumeratorHasNext(){

    bool fail = false;

    int items[] = {1, 3, 11, 9};
    Vector<int> v(items, 4);
    Vector<int>::Enumerator e(v);

    TEST_CONDITION_MACRO(e.HasNext() == true)
    e.MoveNext();
    TEST_CONDITION_MACRO(e.HasNext() == true)
    e.MoveNext();
    TEST_CONDITION_MACRO(e.HasNext() == true)
    e.MoveNext();
    TEST_CONDITION_MACRO(e.HasNext() == false)

    return fail;

}

bool TestVectorEnumeratorMovePrev(){

    bool fail = false;

    int items[] = {9, 10, 15};
    Vector<int> v(items, 3);
    Vector<int>::Enumerator e(v);
    e.MoveNext();
    e.MoveNext();

    TEST_CONDITION_MACRO(e.MovePrev() == true)
    TEST_CONDITION_MACRO(e.Current() == 10)
    TEST_CONDITION_MACRO(e.MovePrev() == true)
    TEST_CONDITION_MACRO(e.Current() == 9)
    TEST_CONDITION_MACRO(e.MovePrev() == false)

    return fail;

}

bool TestVectorEnumeratorHasPrev(){

    bool fail = false;

    int items[] = {1, 5, 9};
    Vector<int> v(items, 3);
    Vector<int>::Enumerator e(v);

    TEST_CONDITION_MACRO(e.HasPrev() == false)
    e.MoveNext();
    TEST_CONDITION_MACRO(e.HasPrev() == true)
    e.MoveNext();
    TEST_CONDITION_MACRO(e.HasPrev() == true)
    
    return fail;

}

bool TestRegisterThrower(){

    bool fail = false;
    const double epsilon = 1e-9;
    const double gravitation = 10;

    MutableListSequence<Registering::ModulusAngleTraj> *res =
                Registering::RegisterThrower(1000, 1001, 60, gravitation);
    double resModulus = res->GetLast().modulus;

    TEST_CONDITION_MACRO(resModulus < 120 + epsilon)
    TEST_CONDITION_MACRO(resModulus > 120 - epsilon)

    double resAngle = res->GetLast().angle;
    double displacement = resModulus*resModulus*sin(2*resAngle)/gravitation;

    TEST_CONDITION_MACRO(displacement < 1001 + epsilon)
    TEST_CONDITION_MACRO(displacement > 1000 - epsilon)

    Registering::Trajectory *resTraj = res->GetLast().traj;
    Registering::Trajectory::Enumerator trajEn(*resTraj);
    double time = 0;
    double xDisplacement;
    double yDisplacement;

    while(trajEn.HasNext()){

        xDisplacement = resModulus*cos(resAngle)*time;
        yDisplacement = resModulus*sin(resAngle)*time - gravitation*time*time/2;

        TEST_CONDITION_MACRO(trajEn.Current().Get(0) < xDisplacement + epsilon);
        TEST_CONDITION_MACRO(trajEn.Current().Get(0) > xDisplacement - epsilon);
        TEST_CONDITION_MACRO(trajEn.Current().Get(1) < yDisplacement + epsilon);
        TEST_CONDITION_MACRO(trajEn.Current().Get(1) > yDisplacement - epsilon);

        ++time;
        trajEn.MoveNext();

    }
    TEST_CONDITION_MACRO(trajEn.Current().Get(0) < displacement + epsilon);
    TEST_CONDITION_MACRO(trajEn.Current().Get(0) > displacement - epsilon);
    TEST_CONDITION_MACRO(trajEn.Current().Get(1) < epsilon);
    TEST_CONDITION_MACRO(trajEn.Current().Get(1) > -epsilon);

    MutableListSequence<Registering::ModulusAngleTraj>::Enumerator resEn(*res);
    do{
        delete resEn.Current().traj;
    }while(resEn.MoveNext());
    delete res;

    return fail;

}

bool TestExceptionsVectorGet(){

    bool fail = false;

    int items[] = {10, 20};
    Vector<int> v(items, 2);

    TEST_OUT_OF_RANGE_MACRO(v.Get(2), 2, 0, 1)
    TEST_OUT_OF_RANGE_MACRO(v.Get(10), 10, 0, 1)

    return fail;
    
}

bool TestExceptionsVectorGetEnumerator(){

    bool fail = false;

    Vector<int> v(nullptr, 0);

    TEST_EXCEPTION_MACRO(v.GetEnumerator(), EnumeratorCtorError)

    return fail;

}

bool TestExceptionsVectorOperatorPlus(){

    bool fail = false;

    int items1[] = {1, 2};
    int items2[] = {4, 5, 6};
    Vector<int> v1(items1, 2);
    Vector<int> v2(items2, 3);
    
    TEST_INCOMPATIBLE_VECTORS_MACRO(v1 + v2, 2, 3);

    return fail;

}

bool TestExceptionsVectorOperatorAsteriskDotProduct(){

    bool fail = false;

    int items1[] = {3, 4};
    int items2[] = {5, 7, 6};
    Vector<int> v1(items1, 2);
    Vector<int> v2(items2, 3);
    
    TEST_INCOMPATIBLE_VECTORS_MACRO(v1 * v2, 2, 3);

    return fail;

}

bool TestExceptionsVectorOperatorPlusEqual(){

    bool fail = false;

    int items1[] = {10, 11};
    int items2[] = {12, 13, 14};
    Vector<int> v1(items1, 2);
    Vector<int> v2(items2, 3);
    
    TEST_INCOMPATIBLE_VECTORS_MACRO(v1 += v2, 2, 3);

    return fail;

}

bool TestExceptionsVectorEnumeratorFullCtor(){

    bool fail = false;

    Vector<int> v(nullptr, 0);

    TEST_EXCEPTION_MACRO(new Vector<int>::Enumerator(v), EnumeratorCtorError)

    return fail;

}

bool TestExceptionsRegisterThrower(){
    
    bool fail = false;

    TEST_TOO_LITTLE_GAP_MACRO(Registering::RegisterThrower(0, 0.000005, 1), 0.000005, 0.0001)

    return fail;

}

void DoTest(){

    int count = 0;

    TEST_COUNTER_MACRO(TestComplexFullCtor)
    TEST_COUNTER_MACRO(TestComplexDefaultCtor)
    TEST_COUNTER_MACRO(TestComplexCopyCtor)
    TEST_COUNTER_MACRO(TestComplexGetReal)
    TEST_COUNTER_MACRO(TestComplexGetImag)
    TEST_COUNTER_MACRO(TestComplexSetReal)
    TEST_COUNTER_MACRO(TestComplexSetImag)
    TEST_COUNTER_MACRO(TestComplexOperatorEqual)
    TEST_COUNTER_MACRO(TestComplexOperatorUnaryMinus)
    TEST_COUNTER_MACRO(TestComplexOperatorPlus)
    TEST_COUNTER_MACRO(TestComplexOperatorBinaryMinus)
    TEST_COUNTER_MACRO(TestComplexOperatorAsterisk)
    TEST_COUNTER_MACRO(TestComplexOperatorSlash)
    TEST_COUNTER_MACRO(TestComplexOperatorDoubleEqual)
    TEST_COUNTER_MACRO(TestComplexOperatorNotEqual)
    TEST_COUNTER_MACRO(TestComplexOperatorPlusEqual)
    TEST_COUNTER_MACRO(TestComplexOperatorMinusEqual)
    TEST_COUNTER_MACRO(TestComplexOperatorAsteriskEqual)
    TEST_COUNTER_MACRO(TestComplexOperatorSlashEqual)
    
    TEST_COUNTER_MACRO(TestModulusSquareInt)
    TEST_COUNTER_MACRO(TestModulusSquareDouble)
    TEST_COUNTER_MACRO(TestModulusSquareComplex)
    TEST_COUNTER_MACRO(TestZeroInt)
    TEST_COUNTER_MACRO(TestZeroDouble)
    TEST_COUNTER_MACRO(TestZeroComplex)
    
    TEST_COUNTER_MACRO(TestVectorFullCtor)
    TEST_COUNTER_MACRO(TestVectorDefaultCtor)
    TEST_COUNTER_MACRO(TestVectorCopyCtor)
    TEST_COUNTER_MACRO(TestVectorGet)
    TEST_COUNTER_MACRO(TestVectorGetCount)
    TEST_COUNTER_MACRO(TestVectorCopy)
    TEST_COUNTER_MACRO(TestVectorOperatorPlus)
    TEST_COUNTER_MACRO(TestVectorOperatorAsteriskLeft)
    TEST_COUNTER_MACRO(TestVectorOperatorAsteriskRight)
    TEST_COUNTER_MACRO(TestVectorOperatorAsteriskDotProduct)
    TEST_COUNTER_MACRO(TestVectorOperatorPlusEqual)
    TEST_COUNTER_MACRO(TestVectorOperatorAsteriskEqual)
    TEST_COUNTER_MACRO(TestVectorGetNorm)
    TEST_COUNTER_MACRO(TestVectorOperatorEqual)
    TEST_COUNTER_MACRO(TestVectorGetEnumerator)
    TEST_COUNTER_MACRO(TestVectorEnumeratorFullCtor)
    TEST_COUNTER_MACRO(TestVectorEnumeratorCopyCtor)
    TEST_COUNTER_MACRO(TestVectorEnumeratorCurrent)
    TEST_COUNTER_MACRO(TestVectorEnumeratorMoveNext)
    TEST_COUNTER_MACRO(TestVectorEnumeratorHasNext)
    TEST_COUNTER_MACRO(TestVectorEnumeratorMovePrev)
    TEST_COUNTER_MACRO(TestVectorEnumeratorHasPrev)
    
    TEST_COUNTER_MACRO(TestRegisterThrower)
    
    TEST_COUNTER_MACRO(TestExceptionsVectorGet)
    TEST_COUNTER_MACRO(TestExceptionsVectorGetEnumerator)
    TEST_COUNTER_MACRO(TestExceptionsVectorOperatorPlus)
    TEST_COUNTER_MACRO(TestExceptionsVectorOperatorAsteriskDotProduct)
    TEST_COUNTER_MACRO(TestExceptionsVectorOperatorPlusEqual)
    TEST_COUNTER_MACRO(TestExceptionsVectorEnumeratorFullCtor)

    TEST_COUNTER_MACRO(TestExceptionsRegisterThrower)

    std::cout << count << " of 55 tests passed." << std::endl;

}