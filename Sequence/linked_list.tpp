template <class T>
LinkedList<T>::Enumerator::Enumerator(const LinkedList<T> &linkedList){
    if(!(linkedList.length)) throw EnumeratorCtorError();
    pointer = startPointer = linkedList.firstN;
    endPointer = linkedList.lastN;
}

template <class T>
const T& LinkedList<T>::Enumerator::Current() const{
    return pointer->value;
}

template <class T>
bool LinkedList<T>::Enumerator::HasNext() const{
    return (pointer != endPointer);
}

template <class T>
bool LinkedList<T>::Enumerator::MoveNext(){

    if(pointer == endPointer) return 0;

    pointer = pointer->subs;
    return 1;
    
}

template <class T>
bool LinkedList<T>::Enumerator::HasPrev() const{
    return (pointer != startPointer);
}

template <class T>
bool LinkedList<T>::Enumerator::MovePrev(){
    
    if(pointer == startPointer) return 0;

    pointer = pointer->prev;
    return 1;

}

template <class T>
LinkedList<T>::LinkedList(const T *items, std::size_t count){

    if(!items && count) throw ListCtorError();

    firstN = nullptr;
    lastN = nullptr;
    length = 0;

    for(std::size_t number = 0; number < count; number++){
        Append(items[number]);
    }
        
}

template <class T>
LinkedList<T>::LinkedList() : LinkedList(nullptr, 0){}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T> &list){

    firstN = nullptr;
    lastN = nullptr;
    length = 0;

    Node *current = list.firstN;

    if(current){
        while(current != list.lastN){
            Append(current->value);
            current = current->subs;
        }
        Append(current->value);
    }

}

template <class T>
LinkedList<T>::~LinkedList(){
    if(firstN && lastN){

        Node *current = firstN;

        while(current != lastN){
            current = current->subs;
            delete current->prev;
        }
        delete current;

    }
}

template <class T>
const T& LinkedList<T>::GetFirst() const{
    if(!length) throw EmptySequence();
    return firstN->value;
}

template <class T>
const T& LinkedList<T>::GetLast() const{
    if(!length) throw EmptySequence();
    return lastN->value;
}

template <class T>
const T& LinkedList<T>::Get(std::size_t index) const{
    if(index >= length) throw IndexOutOfRange(index, 0, length - 1);
    if(index > (length-1)/2){

        Node *current = lastN;

        for(std::size_t dist = length-1 - index; dist > 0; dist--){
            current = current->prev;
        }

        return current->value;

    }else{

        Node *current = firstN;

        for(std::size_t dist = index; dist > 0; dist--){
            current = current->subs;
        }

        return current->value;

    }
}

template <class T>
LinkedList<T>* LinkedList<T>::GetSubList(std::size_t startIndex, std::size_t endIndex) const{

    if(startIndex >= length) throw IndexOutOfRange(startIndex, 0, length - 1);
    if(endIndex > length) throw IndexOutOfRange(endIndex, 0, length);

    LinkedList<T> *subList = new LinkedList<T>;

    if(endIndex > startIndex){

        Node *current = firstN;
        for(std::size_t dist = startIndex; dist > 0; dist--){
            current = current->subs;
        }

        for(std::size_t number = 0; number < endIndex - startIndex; number++){
            subList->Append(current->value);
            current = current->subs;
        }

    }

    return subList;

}

template <class T>
std::size_t LinkedList<T>::GetCount() const{
    return length;
}

template <class T>
LinkedList<T>* LinkedList<T>::Copy() const{
    return new LinkedList<T>(*this);
}

template <class T>
void LinkedList<T>::Append(const T &item){

    if(!length){
        lastN = new Node;
        lastN->prev = nullptr;
        firstN = lastN;
    }else{
        lastN->subs = new Node;
        lastN->subs->prev = lastN;
        lastN = lastN->subs;
    }

    lastN->subs = nullptr;

    lastN->value = item;
    length++;

}

template <class T>
void LinkedList<T>::Prepend(const T &item){

    if(!length){
        firstN = new Node;
        firstN->subs = nullptr;
        lastN = firstN;
    }else{
        firstN->prev = new Node;
        firstN->prev->subs = firstN;
        firstN = firstN->prev;
    }

    firstN->prev = nullptr;

    firstN->value = item;
    length++;

}

template <class T>
void LinkedList<T>::InsertAt(const T &item, std::size_t index){
    if(index > length) throw IndexOutOfRange(index, 0, length);
    if(index == 0){
        Prepend(item);
    }else if(index == length){  
        Append(item);
    }else{

        Node *currentSubs;
        Node *currentPrev;

        if(index > (length-1)/2 + 1){
            
            currentSubs = lastN;

            for(std::size_t dist = length-1 - index; dist > 0; dist--){
                currentSubs = currentSubs->prev;
            }
            currentPrev = currentSubs->prev;

        }else{

            currentPrev = firstN;

            for(std::size_t dist = index - 1; dist > 0; dist--){
                currentPrev = currentPrev->subs;
            }
            currentSubs = currentPrev->subs;

        }

        currentPrev->subs = new Node;
        currentPrev->subs->prev = currentPrev;
        currentPrev = currentPrev->subs;

        currentSubs->prev = currentPrev;
        currentPrev->subs = currentSubs;

        currentPrev->value = item;
        length++;

    }
}

template <class T>
LinkedList<T>* LinkedList<T>::Concat(const LinkedList<T> *list) const{
    
    LinkedList<T> *concatList = new LinkedList<T>(*this);
    Node *current = list->firstN;

    if(current){
        while(current != list->lastN){
            concatList->Append(current->value);
            current = current->subs;
        }
        concatList->Append(current->value);
    }

    return concatList;
    
}

template <class T>
typename IEnumerable<T>::IEnumerator* LinkedList<T>::GetEnumerator() const{
    return new typename LinkedList<T>::Enumerator(*this);
}