#include "common.h"

using integer = unsigned long long;

constexpr char get_digit(integer n) {
  return n < 10 ? '0' + static_cast<char>(n) : 'a' + static_cast<char>(n) - 10;
}

template <integer X, integer Base = 10, char... Cs>
struct itoaxx : public itoaxx<X / Base, Base, get_digit(X % Base), Cs...> {};

template <integer Base, char... Cs>
struct itoaxx<0, Base, Cs...> {
  static constexpr char value[] = {Cs..., 0};
};

template <integer Base, char... Cs>
constexpr char itoaxx<0, Base, Cs...>::value[];

template <integer X, integer Base = 10>
struct itoax : public itoaxx<X, Base> {};

template <integer Base>
struct itoax<0, Base> {
  static constexpr char value[] = {'0', 0};
};

template <integer Base>
constexpr char itoax<0, Base>::value[];

Describe(itoax_test_example){
    It(should_work){Assert::That(itoax<10>::value, Equals("10"));
Assert::That(itoax<10, 2>::value, Equals("1010"));
Assert::That(itoax<10, 8>::value, Equals("12"));
Assert::That(itoax<10, 16>::value, Equals("a"));
}
}
;