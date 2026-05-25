#ifndef _MUTABLE_LIST_SEQUENCE_H_
#define _MUTABLE_LIST_SEQUENCE_H_

#include "list_sequence.h"

template <class T>
class MutableListSequence : public ListSequence<T,MutableListSequence<T>>{
    protected:
        MutableListSequence(LinkedList<T> *list);
        MutableListSequence<T>* Instance() override;
    public:

        template<class> friend class MutableListSequence;
        template<class,class> friend class ListSequence;

        MutableListSequence(const T *items, const std::size_t &count);
        MutableListSequence();
        MutableListSequence(const LinkedList<T> &list);
        MutableListSequence(const MutableListSequence<T> &listSequence);
        
};

#include "mutable_list_sequence.tpp"

#endif //_MUTABLE_LIST_SEQUENCE_H_