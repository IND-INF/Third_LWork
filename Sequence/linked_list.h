#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

#include "sequence_exceptions.h"
#include "collection.h"
#include "enumerable.h"

template <class T>
class LinkedList : public ICollection<T>, public IEnumerable<T>{
    private:

        typedef struct struct_Node{
            T value;
            struct_Node *prev;
            struct_Node *subs;
        } Node;

        Node *firstN;
        Node *lastN;
        std::size_t length;

    public:

        class Enumerator : public IEnumerable<T>::IEnumerator{
            private:

                Node *pointer;
                Node *startPointer;
                Node *endPointer;

                Enumerator();
                
            public:

                Enumerator(const LinkedList<T> &linkedList);

                const T& Current() const override;

                bool HasNext() const override;
                bool MoveNext() override;

                bool HasPrev() const override;
                bool MovePrev() override;

        };

        LinkedList(const T *items, std::size_t count);
        LinkedList();
        LinkedList(const LinkedList<T> &list);
        ~LinkedList();
        
        const T& GetFirst() const;
        const T& GetLast() const;
        const T& Get(std::size_t index) const override;
        LinkedList<T>* GetSubList(std::size_t startIndex, std::size_t endIndex) const;
        std::size_t GetCount() const override;
        LinkedList<T>* Copy() const;

        void Append(const T &item);
        void Prepend(const T &item);
        void InsertAt(const T &item, std::size_t index);
        LinkedList<T>* Concat(const LinkedList<T> *list) const;

        typename IEnumerable<T>::IEnumerator* GetEnumerator() const override;

};

#include "linked_list.tpp"

#endif //_LINKED_LIST_H_