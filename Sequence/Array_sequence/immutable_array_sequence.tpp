template <class T>
ImmutableArraySequence<T>::ImmutableArraySequence(DynamicArray<T> *dynamicArray)
            : ArraySequence<T,ImmutableArraySequence<T>>(dynamicArray){}

template <class T>
ImmutableArraySequence<T>* ImmutableArraySequence<T>::Instance(){
    return this->DirectCopy();
}

template <class T>
ImmutableArraySequence<T>::ImmutableArraySequence(const T *items, std::size_t count)
            : ArraySequence<T,ImmutableArraySequence<T>>(items, count){}

template <class T>
ImmutableArraySequence<T>::ImmutableArraySequence() : ArraySequence<T,ImmutableArraySequence<T>>(){}

template <class T>
ImmutableArraySequence<T>::ImmutableArraySequence(const DynamicArray<T> &dynamicArray)
            : ArraySequence<T,ImmutableArraySequence<T>>(dynamicArray){}

template <class T>
ImmutableArraySequence<T>::ImmutableArraySequence(const ImmutableArraySequence<T> &arraySequence)
            : ArraySequence<T,ImmutableArraySequence<T>>(arraySequence){}