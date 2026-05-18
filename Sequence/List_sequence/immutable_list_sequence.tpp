template <class T>
ImmutableListSequence<T>::ImmutableListSequence(LinkedList<T> *list)
            : ListSequence<T,ImmutableListSequence<T>>(list){}

template <class T>
ImmutableListSequence<T>* ImmutableListSequence<T>::Instance(){
    return this->DirectCopy();
}

template <class T>
ImmutableListSequence<T>::ImmutableListSequence(const T *items, const std::size_t &count)
            : ListSequence<T,ImmutableListSequence<T>>(items, count){}

template <class T>
ImmutableListSequence<T>::ImmutableListSequence() : ListSequence<T,ImmutableListSequence<T>>(){}

template <class T>
ImmutableListSequence<T>::ImmutableListSequence(const LinkedList<T> &list)
            : ListSequence<T,ImmutableListSequence<T>>(list){}

template <class T>
ImmutableListSequence<T>::ImmutableListSequence(const ImmutableListSequence<T> &listSequence)
            : ListSequence<T,ImmutableListSequence<T>>(listSequence){}