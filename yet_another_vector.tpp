template <class T>
Vector<T>::Vector(ImmutableArraySequence<T> *sequence){
    items = sequence;
}

template <class T>
Vector<T>::Enumerator::Enumerator(const Vector<T> &vect){
    innerEnumerator = vect.items->GetEnumerator();
}

template <class T>
const T& Vector<T>::Enumerator::Current() const{
    return innerEnumerator->Current();
}

template <class T>
bool Vector<T>::Enumerator::HasNext() const{
    return innerEnumerator->HasNext();
}

template <class T>
bool Vector<T>::Enumerator::MoveNext(){
    return innerEnumerator->MoveNext();
}

template <class T>
bool Vector<T>::Enumerator::HasPrev() const{
    return innerEnumerator->HasPrev();
}

template <class T>
bool Vector<T>::Enumerator::MovePrev(){
    return innerEnumerator->MovePrev();
}

template <class T>
Vector<T>::Vector(const T *items, std::size_t count){
    this->items = new ImmutableArraySequence<T>(items, count);
}

template <class T>
Vector<T>::Vector(){
    items = new ImmutableArraySequence<T>();
}

template <class T>
Vector<T>::Vector(const Vector<T> &vect){
    items = new ImmutableArraySequence<T>(*(vect.items));
}

template <class T>
Vector<T>::~Vector(){
    delete items;
}

template <class T>
const T& Vector<T>::Get(std::size_t index) const{
    return items->Get(index);
}

template <class T>
std::size_t Vector<T>::GetCount() const{
    return items->GetCount();
}

template <class T>
Vector<T>* Vector<T>::Copy() const{
    return new Vector<T>(*this);
}

template <class T>
Vector<T> operator+(const Vector<T> &lhv, const Vector<T> &rhv){

    if(lhv.GetCount() != rhv.GetCount()) throw IncompatibleVectors(lhv.GetCount(), rhv.GetCount());
    
    typename IEnumerable<T>::IEnumerator *rEnum;
    try{
        rEnum = rhv.GetEnumerator();
    }
    catch(const EnumeratorCtorError&){
        Vector<T> res(lhv.items->Copy());
        return res;
    }
    
    ImmutableArraySequence<T> *resItems = lhv.items->template Map<T,ImmutableArraySequence<T>>([&rEnum](const T &x){
        const T &rCurrent = rEnum->Current();
        rEnum->MoveNext();
        return x + rCurrent;
    });
    Vector<T> res(resItems);

    return res;

}

template <class T>
Vector<T> operator*(const T &lhv, const Vector<T> &rhv){

    ImmutableArraySequence<T> *resItems = rhv.items->template Map<T,ImmutableArraySequence<T>>([&lhv](const T &x){
        return x * lhv;
    });
    Vector<T> res(resItems);

    return res;

}

template <class T>
Vector<T> operator*(const Vector<T> &lhv, const T &rhv){

    ImmutableArraySequence<T> *resItems = lhv.items->template Map<T,ImmutableArraySequence<T>>([&rhv](const T &x){
        return x * rhv;
    });
    Vector<T> res(resItems);

    return res;

}

template <class T>
T operator*(const Vector<T> &lhv, const Vector<T> &rhv){

    if(lhv.GetCount() != rhv.GetCount()) throw IncompatibleVectors(lhv.GetCount(), rhv.GetCount());
    
    typename IEnumerable<T>::IEnumerator *rEnum;
    try{
        rEnum = rhv.GetEnumerator();
    }
    catch(const EnumeratorCtorError&){
        return SubservFuncs::Zero<T>();
    }
    
    return lhv.items->template Reduce<T>([&rEnum](const T &initial, const T &x){
        const T &rCurrent = rEnum->Current();
        rEnum->MoveNext();
        return initial + x*rCurrent;
    }, SubservFuncs::Zero<T>());

}

template <class T>
Vector<T>& operator+=(Vector<T> &lhv, const Vector<T> &rhv){

    if(lhv.GetCount() != rhv.GetCount()) throw IncompatibleVectors(lhv.GetCount(), rhv.GetCount());
    
    typename IEnumerable<T>::IEnumerator *rEnum;
    try{
        rEnum = rhv.GetEnumerator();
    }
    catch(const EnumeratorCtorError&){
        return lhv;
    }
    
    ImmutableArraySequence<T> *newItems = lhv.items->template Map<T,ImmutableArraySequence<T>>([&rEnum](const T &x){
        const T &rCurrent = rEnum->Current();
        rEnum->MoveNext();
        return x + rCurrent;
    });

    delete lhv.items;
    lhv.items = newItems;

    return lhv;

}

template <class T>
Vector<T>& operator*=(Vector<T> &lhv, const T &rhv){

    ImmutableArraySequence<T> *newItems = lhv.items->template Map<T,ImmutableArraySequence<T>>([&rhv](const T &x){
        return x * rhv;
    });

    delete lhv.items;
    lhv.items = newItems;

    return lhv;
    
}

template <class T>
double Vector<T>::GetNorm() const{
    double normSq = items->template Reduce<double>([](double initial, const T &x){
        return initial + SubservFuncs::ModulusSquare(x);
    }, 0);
    return std::sqrt(normSq);
}

template <class T>
typename IEnumerable<T>::IEnumerator* Vector<T>::GetEnumerator() const{
    return new Vector<T>::Enumerator(*this);
}