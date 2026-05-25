template <class T>
MutableListSequence<T>::MutableListSequence(LinkedList<T> *list)
            : ListSequence<T,MutableListSequence<T>>(list){}

template <class T>
MutableListSequence<T>* MutableListSequence<T>::Instance(){
    return this;
}

template <class T>
MutableListSequence<T>::MutableListSequence(const T *items, const std::size_t &count)
            : ListSequence<T,MutableListSequence<T>>(items, count){}

template <class T>
MutableListSequence<T>::MutableListSequence() : ListSequence<T,MutableListSequence<T>>(){}

template <class T>
MutableListSequence<T>::MutableListSequence(const LinkedList<T> &list)
            : ListSequence<T,MutableListSequence<T>>(list){}

template <class T>
MutableListSequence<T>::MutableListSequence(const MutableListSequence<T> &listSequence)
            : ListSequence<T,MutableListSequence<T>>(listSequence){}