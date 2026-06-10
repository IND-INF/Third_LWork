template <class T>
MutableArraySequence<T>::MutableArraySequence(DynamicArray<T> *dynamicArray)
            : ArraySequence<T,MutableArraySequence<T>>(dynamicArray){}

template <class T>
MutableArraySequence<T>* MutableArraySequence<T>::Instance(){
    return this;
}

template <class T>
MutableArraySequence<T>::MutableArraySequence(const T *items, std::size_t count)
            : ArraySequence<T,MutableArraySequence<T>>(items, count){}

template <class T>
MutableArraySequence<T>::MutableArraySequence() : ArraySequence<T,MutableArraySequence<T>>(){}

template <class T>
MutableArraySequence<T>::MutableArraySequence(const DynamicArray<T> &dynamicArray)
            : ArraySequence<T,MutableArraySequence<T>>(dynamicArray){}

template <class T>
MutableArraySequence<T>::MutableArraySequence(const MutableArraySequence<T> &arraySequence)
            : ArraySequence<T,MutableArraySequence<T>>(arraySequence){}