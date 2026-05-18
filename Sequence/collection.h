#ifndef _COLLECTION_H_
#define _COLLECTION_H_

#include <cstddef>

template <class T>
class ICollection{
    public:

        virtual ~ICollection();

        virtual const T& Get(std::size_t index) const = 0;
        virtual std::size_t GetCount() const = 0;
        virtual ICollection<T>* Copy() const = 0;

};

#include "collection.tpp"

#endif //_COLLECTION_H_