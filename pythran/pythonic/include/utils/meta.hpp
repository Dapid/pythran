#ifndef PYTHONIC_INCLUDE_UTILS_META_HPP
#define PYTHONIC_INCLUDE_UTILS_META_HPP

namespace pythonic
{

  namespace utils
  {

    template <bool... V>
    struct all_of;

    template <>
    struct all_of<> : std::true_type {
    };

    template <bool V0, bool... V>
    struct all_of<V0, V...> {
      static PYTHONIC_CONSTEXPR bool value = V0 and all_of<V...>::value;
    };

    template <bool V0>
    struct all_of<V0> {
      static PYTHONIC_CONSTEXPR bool value = V0;
    };

    template <bool... V>
    struct any_of;

    template <>
    struct any_of<> : std::false_type {
    };

    template <bool V0, bool... V>
    struct any_of<V0, V...> {
      static PYTHONIC_CONSTEXPR bool value = V0 or any_of<V...>::value;
    };

    template <bool V0>
    struct any_of<V0> {
      static PYTHONIC_CONSTEXPR bool value = V0;
    };

    template <class T0, class... T>
    struct front {
      using type = T0;
    };

    template <size_t... N>
    struct max_element;

    template <size_t N0, size_t... N>
    struct max_element<N0, N...> {
      static PYTHONIC_CONSTEXPR size_t _value = max_element<N...>::value;
      static PYTHONIC_CONSTEXPR size_t _index = max_element<N...>::index;
      static PYTHONIC_CONSTEXPR size_t value = N0 > _value ? N0 : _value;
      static PYTHONIC_CONSTEXPR size_t index = N0 == value ? 0 : 1 + _index;
    };

    template <size_t V0>
    struct max_element<V0> {
      static PYTHONIC_CONSTEXPR size_t value = V0;
      static PYTHONIC_CONSTEXPR size_t index = 0;
    };
  }
}

#endif
