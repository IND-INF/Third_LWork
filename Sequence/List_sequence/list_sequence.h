#ifndef _LIST_SEQUENCE_H_
#define _LIST_SEQUENCE_H_

#include "../sequence.h"
#include "../linked_list.h"

template <class T, class Derived>
class ListSequence : public Sequence<T>{
    protected:
        LinkedList<T> *list;
        ListSequence(LinkedList<T> *list);
        virtual Derived* Instance() = 0;
    public:

        class Enumerator : public IEnumerable<T>::IEnumerator{
            private:
                typename IEnumerable<T>::IEnumerator* innerEnumerator;
                Enumerator();
            public:

                Enumerator(const ListSequence<T,Derived> &listSequence);

                const T& Current() const override;

                bool HasNext() const override;
                bool MoveNext() override;

                bool HasPrev() const override;
                bool MovePrev() override;

        };
    
        ListSequence(const T *items, std::size_t count);
        ListSequence();
        ListSequence(const LinkedList<T> &list);
        ListSequence(const ListSequence<T,Derived> &listSequence);
        virtual ~ListSequence();

        const T& GetFirst() const override;
        const T& GetLast() const override;
        const T& Get(std::size_t index) const override;
        Sequence<T>* GetSubsequence(std::size_t startIndex, std::size_t endIndex) const override;
        std::size_t GetCount() const override;
        Sequence<T>* Copy() const override;

        Derived* DirectGetSubsequence(std::size_t startIndex, std::size_t endIndex) const;
        Derived* DirectCopy() const;

        Sequence<T>* Append(const T &item) override;
        Sequence<T>* Prepend(const T &item) override;
        Sequence<T>* InsertAt(const T &item, std::size_t index) override;
        Sequence<T>* Concat(const Sequence<T> *list) const override;
        
        Derived* DirectAppend(const T &item);
        Derived* DirectPrepend(const T &item);
        Derived* DirectInsertAt(const T &item, std::size_t index);
        Derived* DirectConcat(const Sequence<T> *list) const;

        template <class T2, class Derived2, class Func>
        Derived2* Map(Func func) const;
        
        template <class Func>
        Derived* Where(Func func) const;
        
        template <class T2, class Func>
        T2 Reduce(Func func, const T2 &initial) const;
        
        typename IEnumerable<T>::IEnumerator* GetEnumerator() const override;

};

#include "list_sequence.tpp"

#endif //_LIST_SEQUENCE_H_