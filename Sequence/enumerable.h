#ifndef _ENUMERABLE_H_
#define _ENUMERABLE_H_

template <class T>
class IEnumerable{
    public:
    
        class IEnumerator{
            public:

                virtual ~IEnumerator();

                virtual const T& Current() const = 0;

                virtual bool HasNext() const = 0;
                virtual bool MoveNext() = 0;

                virtual bool HasPrev() const = 0;
                virtual bool MovePrev() = 0;

        };

        virtual ~IEnumerable();

        virtual IEnumerator* GetEnumerator() const = 0;

};

#include "enumerable.tpp"

#endif //_ENUMERABLE_H_