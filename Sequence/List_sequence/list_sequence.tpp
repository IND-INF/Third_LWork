template <class T, class Derived>
ListSequence<T,Derived>::ListSequence(LinkedList<T> *list){
    this->list = list;
}

template <class T, class Derived>
ListSequence<T,Derived>::Enumerator::Enumerator(const ListSequence<T,Derived> &listSequence){
    innerEnumerator = listSequence.list->GetEnumerator();
}

template <class T, class Derived>
const T& ListSequence<T,Derived>::Enumerator::Current() const{
    return innerEnumerator->Current();
}

template <class T, class Derived>
bool ListSequence<T,Derived>::Enumerator::HasNext() const{
    return innerEnumerator->HasNext();
}

template <class T, class Derived>
bool ListSequence<T,Derived>::Enumerator::MoveNext(){
    return innerEnumerator->MoveNext();
}

template <class T, class Derived>
bool ListSequence<T,Derived>::Enumerator::HasPrev() const{
    return innerEnumerator->HasPrev();
}

template <class T, class Derived>
bool ListSequence<T,Derived>::Enumerator::MovePrev(){
    return innerEnumerator->MovePrev();
}

template <class T, class Derived>
ListSequence<T,Derived>::ListSequence(const T *items, std::size_t count){
    list = new LinkedList<T>(items, count);
}

template <class T, class Derived>
ListSequence<T,Derived>::ListSequence(){
    list = new LinkedList<T>();
}

template <class T, class Derived>
ListSequence<T,Derived>::ListSequence(const LinkedList<T> &list){
    this->list = new LinkedList<T>(list);
}

template <class T, class Derived>
ListSequence<T,Derived>::ListSequence(const ListSequence<T,Derived> &listSequence){
    this->list = new LinkedList<T>(*(listSequence.list));
}

template <class T, class Derived>
ListSequence<T,Derived>::~ListSequence(){
    delete list;
}

template <class T, class Derived>
const T& ListSequence<T,Derived>::GetFirst() const{
    return list->GetFirst();
}

template <class T, class Derived>
const T& ListSequence<T,Derived>::GetLast() const{
    return list->GetLast();
}

template <class T, class Derived>
const T& ListSequence<T,Derived>::Get(std::size_t index) const{
    return list->Get(index);
}

template <class T, class Derived>
Sequence<T>* ListSequence<T,Derived>::GetSubsequence(std::size_t startIndex, std::size_t endIndex) const{
    return static_cast<Sequence<T>*>(DirectGetSubsequence(startIndex, endIndex));
}

template <class T, class Derived>
std::size_t ListSequence<T,Derived>::GetCount() const{
    return list->GetCount();
}

template <class T, class Derived>
Sequence<T>* ListSequence<T,Derived>::Copy() const{
    return static_cast<Sequence<T>*>(DirectCopy());
}

template <class T, class Derived>
Derived* ListSequence<T,Derived>::DirectGetSubsequence(std::size_t startIndex, std::size_t endIndex) const{
    
    LinkedList<T> *subList = list->GetSubList(startIndex, endIndex);

    Derived *subSeq = new Derived(subList);

    return subSeq;

}

template <class T, class Derived>
Derived* ListSequence<T,Derived>::DirectCopy() const{
    return new Derived(*(static_cast<const Derived*>(this)));
}

template <class T, class Derived>
Sequence<T>* ListSequence<T,Derived>::Append(const T &item){
    return static_cast<Sequence<T>*>(DirectAppend(item));
}

template <class T, class Derived>
Sequence<T>* ListSequence<T,Derived>::Prepend(const T &item){
    return static_cast<Sequence<T>*>(DirectPrepend(item));
}

template <class T, class Derived>
Sequence<T>* ListSequence<T,Derived>::InsertAt(const T &item, std::size_t index){
    return static_cast<Sequence<T>*>(DirectInsertAt(item, index));
}

template <class T, class Derived>
Sequence<T>* ListSequence<T,Derived>::Concat(const Sequence<T> *list) const{
    return static_cast<Sequence<T>*>(DirectConcat(list));
}

template <class T, class Derived>
Derived* ListSequence<T,Derived>::DirectAppend(const T &item){
    Derived *instance = Instance();
    instance->list->Append(item);
    return instance;
}

template <class T, class Derived>
Derived* ListSequence<T,Derived>::DirectPrepend(const T &item){
    Derived *instance = Instance();
    instance->list->Prepend(item);
    return instance;
}

template <class T, class Derived>
Derived* ListSequence<T,Derived>::DirectInsertAt(const T &item, std::size_t index){

    if(index > list->GetCount()) throw IndexOutOfRange(index, 0, list->GetCount());

    Derived *instance = Instance();
    instance->list->InsertAt(item, index);
    return instance;

}

template <class T, class Derived>
Derived* ListSequence<T,Derived>::DirectConcat(const Sequence<T> *list) const{

    const Derived *listSeq = dynamic_cast<const Derived*>(list);
    if(!listSeq) throw BadCollectionCast();

    LinkedList<T> *newList = this->list->Concat(listSeq->list);

    Derived *newSeq = new Derived(newList);

    return newSeq;

}

template <class T, class Derived>
template <class T2, class Derived2, class Func>
Derived2* ListSequence<T,Derived>::Map(Func func) const{

    LinkedList<T2> *mapList = new LinkedList<T2>;

    if(list->GetCount()){
        typename IEnumerable<T>::IEnumerator *enumerator = list->GetEnumerator();
        while(enumerator->HasNext()){
            mapList->Append(func(enumerator->Current()));
            enumerator->MoveNext();
        }
        mapList->Append(func(enumerator->Current()));
    }

    Derived2 *mapSeq = new Derived2(mapList);

    return mapSeq;
    
}

template <class T, class Derived>
template <class Func>
Derived* ListSequence<T,Derived>::Where(Func func) const{

    LinkedList<T> *whereList = new LinkedList<T>;

    if(list->GetCount()){
        typename IEnumerable<T>::IEnumerator *enumerator = list->GetEnumerator();
        while(enumerator->HasNext()){
            if(func(enumerator->Current())){
                whereList->Append(enumerator->Current());
            }
            enumerator->MoveNext();
        }
        if(func(enumerator->Current())){
            whereList->Append(enumerator->Current());
        }
    }

    Derived *whereSeq = new Derived(whereList);

    return whereSeq;

}

template <class T, class Derived>
template <class T2, class Func>
T2 ListSequence<T,Derived>::Reduce(Func func, const T2 &initial) const{

    T2 res = initial;

    if(list->GetCount()){
        typename IEnumerable<T>::IEnumerator *enumerator = list->GetEnumerator();
        while(enumerator->HasNext()){
            res = func(res, enumerator->Current());
            enumerator->MoveNext();
        }
        res = func(res, enumerator->Current());
    }

    return res;

}

template <class T, class Derived>
typename IEnumerable<T>::IEnumerator* ListSequence<T,Derived>::GetEnumerator() const{
    return new typename ListSequence<T,Derived>::Enumerator(*this);;
}