#include "sequence_exceptions.h"

IndexOutOfRange::IndexOutOfRange(std::size_t enteredIndex, std::size_t minimalLimit, std::size_t maximalLimit) :
            enteredIndex(enteredIndex), minimalLimit(minimalLimit), maximalLimit(maximalLimit), message(
            "The entered index is " + std::to_string(enteredIndex) +  ", though it can be only between " +
            std::to_string(minimalLimit) + " and " + std::to_string(maximalLimit) + ", inclusive."){}

const char* IndexOutOfRange::what() const noexcept{
    return message.c_str();
}

std::size_t IndexOutOfRange::GetEnteredIndex() const{
    return enteredIndex;
}

std::size_t IndexOutOfRange::GetMinimalLimit() const{
    return minimalLimit;
}

std::size_t IndexOutOfRange::GetMaximalLimit() const{
    return maximalLimit;
}

const char* EnumeratorCtorError::what() const noexcept{
    return "The sequence is empty, so the enumerator can't be constructed.";
}

const char* ListCtorError::what() const noexcept{
    return "The list items can't be created since the passed items pointer is a nullptr.";
}

const char* EmptySequence::what() const noexcept{
    return "The sequence is empty, so the element does not exist.";
}

const char* BadCollectionCast::what() const noexcept{
    return "Cannot convert the collection pointer to the appropriate type.";
}