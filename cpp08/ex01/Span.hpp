

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <exception>
#include <iterator>


class Span
{
    private:
        unsigned int _size;
        std::vector<int> _vector;
    public:

        Span();
        Span(unsigned int n);
        Span(const Span &other);
        Span &operator=(const Span &other);
        ~Span();

        void addNumber(int n);

        template <typename IT>
        void addNumber(IT begin, IT end)
        {
            unsigned int dist = std::distance(begin, end);
            if (_vector.size() + dist > _size)
                throw SpanFullException();
            _vector.insert(_vector.end(), begin, end);
        }

        unsigned int shortestSpan() const;
        unsigned int longestSpan() const;

        class SpanFullException : public std::exception
        {
            public:
                const char *what() const throw();
        };

        class NotEnoughNumbersException : public std::exception
        {
            public:
                const char *what() const throw();
        };


};

#endif
