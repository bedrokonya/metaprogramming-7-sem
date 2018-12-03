#ifndef FibonacciNumber_h
#define FibonacciNumber_h

template<unsigned int index>
struct FibonacciNumber;

template<>
struct FibonacciNumber<0> {
    enum { value = 1 };
};

template<>
struct FibonacciNumber<1> {
    enum { value = 1 };
};

template<unsigned int i>
struct FibonacciNumber {
    enum { value = FibonacciNumber<i - 1>::value + FibonacciNumber<i - 2>::value };
};
#endif
