#ifndef CATCDSHashCombine_H
#define CATCDSHashCombine_H

#include <functional>

// hash_combine from boost

template<class T>
void hash_combine(std::size_t& seed, const T& v)
{
  std::hash<T> hasher;
  seed ^= hasher(v) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}

#endif
