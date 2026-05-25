#ifndef _SEQUENCE_H_
#define _SEQUENCE_H_

#include "collection.h"
#include "enumerable.h"

template <class T>
class Sequence : public ICollection<T>, public IEnumerable<T>{
    public:

        virtual ~Sequence();

        virtual const T& GetFirst() const = 0;
        virtual const T& GetLast() const = 0;
        virtual Sequence<T>* GetSubsequence(std::size_t startIndex, std::size_t endIndex) const = 0;

        virtual Sequence<T>* Append(const T &item) = 0;
        virtual Sequence<T>* Prepend(const T &item) = 0;
        virtual Sequence<T>* InsertAt(const T &item, std::size_t index) = 0;
        virtual Sequence<T>* Concat(const Sequence<T> *list) const = 0;
        
};

#include "sequence.tpp"

#endif //_SEQUENCE_H_