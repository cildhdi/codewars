#include "common.h"

template <int x>
struct factorial {
  static constexpr unsigned long long value = x * factorial<x - 1>::value;
};

template <int x>
constexpr unsigned long long factorial<x>::value;

template <>
struct factorial<0> {
  static constexpr unsigned long long value = 1;
};

constexpr unsigned long long factorial<0>::value;

Describe(compile_time_factorial_test_example){
  It(sample){
    static_assert(factorial<4>::value == 24, "");
    Assert::That(factorial<3>::value, Equals(6));
    Assert::That(factorial<4>::value, Equals(24));
}};