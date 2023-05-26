
#pragma once
#include <cstdint>
#include <cstddef>

using byte_t = std::uint8_t;


template <class T>
struct remove_member_pointer
{
  typedef T type;
};

template <class Parent, class T>
struct remove_member_pointer<T Parent::*>
{
  typedef T type;
};

