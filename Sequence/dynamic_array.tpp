template <class T>
DynamicArray<T>::Enumerator::Enumerator(const DynamicArray<T> &dynamicArray){

    if(!(dynamicArray.size)) throw EnumeratorCtorError();

    pointer = startPointer = dynamicArray.items;
    endPointer = (dynamicArray.items)+(dynamicArray.size - 1);

}

template <class T>
DynamicArray<T>::Enumerator::Enumerator(const DynamicArray<T> &dynamicArray, std::size_t index){

    if(!(dynamicArray.size)) throw EnumeratorCtorError();
    if(index >= dynamicArray.size) throw IndexOutOfRange(index, 0, dynamicArray.size - 1);

    pointer = startPointer = dynamicArray.items;
    endPointer = (dynamicArray.items)+index;

}

template <class T>
const T& DynamicArray<T>::Enumerator::Current() const{
    return *pointer;
}

template <class T>
bool DynamicArray<T>::Enumerator::HasNext() const{
    return (pointer != endPointer);
}

template <class T>
bool DynamicArray<T>::Enumerator::MoveNext(){

    if(pointer == endPointer) return 0;

    pointer++;
    return 1;

}

template <class T>
bool DynamicArray<T>::Enumerator::HasPrev() const{
    return (pointer != startPointer);
}

template <class T>
bool DynamicArray<T>::Enumerator::MovePrev(){
    
    if(pointer == startPointer) return 0;

    pointer--;
    return 1;

}

template <class T>
DynamicArray<T>::DynamicArray(const T *items, std::size_t count){
    if(!count){
        this->items = nullptr;
        size = 0;
    }else{

        this->items = new T[count];
        size = count;

        if(items){
            for(std::size_t number = 0; number < count; number++){
                this->items[number] = items[number];
            }
        }

    }
}

template <class T>
DynamicArray<T>::DynamicArray(std::size_t size) : DynamicArray(nullptr, size){}

template <class T>
DynamicArray<T>::DynamicArray(const DynamicArray<T> &dynamicArray) :
            DynamicArray(dynamicArray.items, dynamicArray.size){}

template <class T>
DynamicArray<T>::~DynamicArray(){
    delete []items;
}

template <class T>
const T& DynamicArray<T>::GetFirst() const{
    if(!size) throw EmptySequence();
    return items[0];
}

template <class T>
const T& DynamicArray<T>::GetLast() const{
    if(!size) throw EmptySequence();
    return items[size-1];
}

template <class T>
const T& DynamicArray<T>::Get(std::size_t index) const{
    if(index >= size) throw IndexOutOfRange(index, 0, size - 1);
    return items[index];
}

template <class T>
std::size_t DynamicArray<T>::GetCount() const{
    return size;
}

template <class T>
DynamicArray<T>* DynamicArray<T>::Copy() const{
    return new DynamicArray<T>(*this);
}

template <class T>
void DynamicArray<T>::Set(std::size_t index, const T &value){
    if(index >= size) throw IndexOutOfRange(index, 0, size - 1);
    items[index] = value;
}

template <class T>
void DynamicArray<T>::Resize(std::size_t newSize){

    T *newItems = new T[newSize];
    for(std::size_t number = 0; number < size && number < newSize; number++){
        newItems[number] = items[number];
    }

    delete []items;
    items = newItems;

    size = newSize;

}

template <class T>
typename IEnumerable<T>::IEnumerator* DynamicArray<T>::GetEnumerator() const{
    return new typename DynamicArray<T>::Enumerator(*this);
}