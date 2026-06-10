#ifndef _SEQUENCE_EXEPTIONS_H_
#define _SEQUENCE_EXEPTIONS_H_

#include <cstddef>
#include <exception>
#include <string>

class IndexOutOfRange : public std::exception{
    private:
    
        std::size_t enteredIndex;
        std::size_t minimalLimit;
        std::size_t maximalLimit;

        std::string message;

        IndexOutOfRange();

    public:

        IndexOutOfRange(std::size_t enteredIndex, std::size_t minimalLimit, std::size_t maximalLimit);

        const char* what() const noexcept override;
        std::size_t GetEnteredIndex() const;
        std::size_t GetMinimalLimit() const;
        std::size_t GetMaximalLimit() const;

};

class EnumeratorCtorError : public std::exception{
    public:
        const char* what() const noexcept override;
};

class ListCtorError : public std::exception{
    public:
        const char* what() const noexcept override;
};

class EmptySequence : public std::exception{
    public:
        const char* what() const noexcept override;
};

class BadCollectionCast : public std::exception{
    public:
        const char* what() const noexcept override;
};

#endif //_SEQUENCE_EXEPTIONS_H_