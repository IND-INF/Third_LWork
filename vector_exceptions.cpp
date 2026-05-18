#include "vector_exceptions.h"

IncompatibleVectors::IncompatibleVectors(std::size_t firstSize, std::size_t secondSize) : firstSize(firstSize),
            secondSize(secondSize), message("The vectors are incompatible: the size of the first one is " +
            std::to_string(firstSize) + ", and the size of the second one is " + std::to_string(secondSize) + "."){}

const char* IncompatibleVectors::what() const noexcept{
    return message.c_str();
}

std::size_t IncompatibleVectors::GetFirstSize() const{
    return firstSize;
}

std::size_t IncompatibleVectors::GetSecondSize() const{
    return secondSize;
}