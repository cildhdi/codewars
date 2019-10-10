#include "common.h"

template <int m, int n>
struct ackermann {
  static constexpr int value =
      ackermann<m - 1, ackermann<m, n - 1>::value>::value;
};
template <int m, int n>
constexpr int ackermann<m, n>::value;

template <int n>
struct ackermann<0, n> {
  static constexpr int value = n + 1;
};

template <int m>
struct ackermann<m, 0> {
  static constexpr int value = ackermann<m - 1, 1>::value;
};

template <>
struct ackermann<0, 0> {
  static constexpr int value = 1;
};

Describe(ackermann_example_test){
  It(tests){
    static_assert(ackermann<2, 2>::value == 7, "");
    Assert::That(ackermann<2, 2>::value, Equals(7));
    Assert::That(ackermann<0, 0>::value, Equals(1));
}};