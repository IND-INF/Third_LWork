#ifndef _IMMUTABLE_ARRAY_SEQUENCE_H_
#define _IMMUTABLE_ARRAY_SEQUENCE_H_

#include "array_sequence.h"

template <class T>
class ImmutableArraySequence : public ArraySequence<T,ImmutableArraySequence<T>>{
    protected:
        ImmutableArraySequence(DynamicArray<T> *dynamicArray);
        ImmutableArraySequence<T>* Instance() override;
    public:

        template<class> friend class ImmutableArraySequence;
        template<class,class> friend class ArraySequence;

        ImmutableArraySequence(const T *items, std::size_t count);
        ImmutableArraySequence();
        ImmutableArraySequence(const DynamicArray<T> &dynamicArray);
        ImmutableArraySequence(const ImmutableArraySequence<T> &arraySequence);
        
};

#include "immutable_array_sequence.tpp"

#endif //_IMMUTABLE_ARRAY_SEQUENCE_H_