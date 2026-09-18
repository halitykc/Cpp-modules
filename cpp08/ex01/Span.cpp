

#include "Span.hpp"
#include <algorithm>
#include <climits>

Span::Span() : _size(0) {}

Span::Span(unsigned int n) : _size(n) {}

Span::Span(const Span &other) : _size(other._size), _vector(other._vector) {}

Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
        _size = other._size;
        _vector = other._vector;
    }
    return *this;
}

Span::~Span() {}


void Span::addNumber(int n)
{
    if (_vector.size() >= _size)
        throw SpanFullException();
    _vector.push_back(n);
}

unsigned int Span::shortestSpan() const
{
    if (_vector.size() < 2)
        throw NotEnoughNumbersException();

    std::vector<int> sortedVector = _vector;
    std::sort(sortedVector.begin(), sortedVector.end());

    unsigned int minSpan = UINT_MAX;
    for (size_t i = 1; i < sortedVector.size(); ++i)
    {
        unsigned int span = sortedVector[i] - sortedVector[i - 1];
        if (span < minSpan)
            minSpan = span;
    }
    return minSpan;
}

unsigned int Span::longestSpan() const
{
    if (_vector.size() < 2)
        throw NotEnoughNumbersException();

    int minVal = *std::min_element(_vector.begin(), _vector.end());
    int maxVal = *std::max_element(_vector.begin(), _vector.end());

    return static_cast<unsigned int>(maxVal - minVal);
}

const char* Span::SpanFullException::what() const throw()
{
    return "Span is full.";
}

const char* Span::NotEnoughNumbersException::what() const throw()
{
    return "Not enough numbers in span.";
}

