#ifndef _DYNAMIC_ARRAY_H_
#define _DYNAMIC_ARRAY_H_

#include "sequence_exceptions.h"
#include "collection.h"
#include "enumerable.h"

template <class T>
class DynamicArray : public ICollection<T>, public IEnumerable<T>{
    private:
        T *items;
        std::size_t size;

        DynamicArray();

    public:

        class Enumerator : public IEnumerable<T>::IEnumerator{
            private:

                T *pointer;
                T *startPointer;
                T *endPointer;

                Enumerator();
                
            public:

                Enumerator(const DynamicArray<T> &dynamicArray);
                Enumerator(const DynamicArray<T> &dynamicArray, std::size_t index);
                
                const T& Current() const override;

                bool HasNext() const override;
                bool MoveNext() override;

                bool HasPrev() const override;
                bool MovePrev() override;
            
        };
        
        DynamicArray(const T *items, std::size_t count);
        DynamicArray(std::size_t size);
        DynamicArray(const DynamicArray<T> &dynamicArray);
        ~DynamicArray();

        const T& GetFirst() const;
        const T& GetLast() const;
        const T& Get(std::size_t index) const override;
        std::size_t GetCount() const override;
        DynamicArray<T>* Copy() const;

        void Set(std::size_t index, const T &value);
        void Resize(std::size_t newSize);

        typename IEnumerable<T>::IEnumerator* GetEnumerator() const override;

};

#include "dynamic_array.tpp"

#endif //_DYNAMIC_ARRAY_H_