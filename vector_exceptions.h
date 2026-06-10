#ifndef _VECTOR_EXCEPTIONS_H_
#define _VECTOR_EXCEPTIONS_H_

#include <cstddef>
#include <exception>
#include <string>

class IncompatibleVectors : public std::exception{
    private:

        std::size_t firstSize;
        std::size_t secondSize;

        std::string message;

        IncompatibleVectors();

    public:

        IncompatibleVectors(std::size_t firstSize, std::size_t secondSize);

        const char* what() const noexcept override;
        std::size_t GetFirstSize() const;
        std::size_t GetSecondSize() const;
        
};

class TooLittleGap : public std::exception{
    private:

        double actualGap;
        double minimalGap;

        std::string message;

        TooLittleGap();

    public:

        TooLittleGap(double actualGap, double minimalGap);

        const char* what() const noexcept override;
        double GetActualGap() const;
        double GetMinimalGap() const;

};

#endif //_VECTOR_EXCEPTIONS_H_