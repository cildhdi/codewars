#include "common.h"

template <char... C>
struct make_string {
  static constexpr char value[sizeof...(C) + 1] = {C..., '\0'};
};

template <char... C>
constexpr char make_string<C...>::value[sizeof...(C) + 1];

Describe(make_string_test_example){
  It(not_difficult_at_all){
    using Hi = make_string<'H', 'i'>;
    static_assert(Hi::value[0] == 'H' && Hi::value[1] == 'i' &&
                  Hi::value[2] == '\0',
              "");
    Assert::That(Hi::value, Equals("Hi"));
}};