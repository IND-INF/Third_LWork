#ifndef _YET_ANOTHER_VECTOR_H_
#define _YET_ANOTHER_VECTOR_H_

#include "Sequence/Array_sequence/immutable_array_sequence.h"
#include "vector_exceptions.h"
#include "subservient_element_functions.h"
#include <cmath>

template <class T> class Vector;

template <class T> Vector<T> operator+(const Vector<T> &lhv, const Vector<T> &rhv);
template <class T> Vector<T> operator*(const T &lhv, const Vector<T> &rhv);
template <class T> Vector<T> operator*(const Vector<T> &lhv, const T &rhv);
template <class T> T operator*(const Vector<T> &lhv, const Vector<T> &rhv);

template <class T> Vector<T>& operator+=(Vector<T> &lhv, const Vector<T> &rhv);
template <class T> Vector<T>& operator*=(Vector<T> &lhv, const T &rhv);

template <class T>
class Vector : public ICollection<T>, public IEnumerable<T>{
    private:
        ImmutableArraySequence<T> *items;
        Vector(ImmutableArraySequence<T> *sequence);
    public:

        class Enumerator : public IEnumerable<T>::IEnumerator{
            private:
                typename IEnumerable<T>::IEnumerator* innerEnumerator;
                Enumerator();
            public:

                Enumerator(const Vector<T> &vect);
                Enumerator(const Enumerator &enumerator);
                ~Enumerator();

                const T& Current() const override;

                bool HasNext() const override;
                bool MoveNext() override;

                bool HasPrev() const override;
                bool MovePrev() override;

        };

        Vector(const T *items, std::size_t count);
        Vector();
        Vector(const Vector<T> &vect);
        ~Vector();

        const T& Get(std::size_t index) const override;
        std::size_t GetCount() const override;
        Vector<T>* Copy() const override;
        
        friend Vector<T> operator+<T>(const Vector<T> &lhv, const Vector<T> &rhv);
        friend Vector<T> operator*<T>(const T &lhv, const Vector<T> &rhv);
        friend Vector<T> operator*<T>(const Vector<T> &lhv, const T &rhv);
        friend T operator*<T>(const Vector<T> &lhv, const Vector<T> &rhv);

        friend Vector<T>& operator+=<T>(Vector<T> &lhv, const Vector<T> &rhv);
        friend Vector<T>& operator*=<T>(Vector<T> &lhv, const T &rhv);
        
        double GetNorm() const;

        typename IEnumerable<T>::IEnumerator* GetEnumerator() const override;

        Vector<T>& operator=(const Vector<T> &rhv){

            delete items;
            items = rhv.items->DirectCopy();

            return *this;

        }

};

#include "yet_another_vector.tpp"

#endif //_YET_ANOTHER_VECTOR_H_