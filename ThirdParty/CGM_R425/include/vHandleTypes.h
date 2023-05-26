#pragma once
  
#include "vKernelDefines.h"
#include <cstddef>
#include <cstdint>


struct vUnion32
{
  explicit V_INLINE
  vUnion32(std::int32_t iValue)
      : dataInt32(iValue)
  {}

  explicit V_INLINE
  vUnion32(std::uint32_t iValue)
      : dataUint32(iValue)
  {}

  explicit V_INLINE
  vUnion32(float iValue)
      : dataFloat(iValue)
  {}

  union
  {
    std::uint32_t dataUint32;
    std::int32_t dataInt32;
    float dataFloat;
  };
};

struct vUnion64
{
  explicit V_INLINE
  vUnion64(std::int64_t iValue)
      : dataInt64(iValue)
  {}

  explicit V_INLINE
  vUnion64(std::uint64_t iValue)
      : dataUint64(iValue)
  {}

  explicit V_INLINE
  vUnion64(double iValue)
      : dataDouble(iValue)
  {}

  union
  {
    std::uint64_t dataUint64;
    std::int64_t dataInt64;
    double dataDouble;
  };
};

template <class T, typename U = std::uint32_t, U const null_value = 0>
struct handletd
{
  static constexpr U null = null_value;

  handletd() = default;
  //  handletd(const handletd& iOther) {_reserved = iOther._reserved;}
  handletd(U v) { _reserved = v; }

  bool operator==(const handletd& iOther) const { return _reserved == iOther._reserved; }
  bool operator!=(const handletd& iOther) const { return _reserved != iOther._reserved; }

  operator U() const { return _reserved; }
  U _reserved = null;
};

template <class T>
using handletq = handletd<T, std::uint64_t>;

template <typename T>
struct handlep
{
  handlep() = default;
  explicit handlep(void const* iAddress) { m_reserved = reinterpret_cast<std::uint8_t const*>(iAddress); }

  bool operator==(const handlep& iOther) const { return m_reserved == iOther.m_reserved; }
  bool operator!=(const handlep& iOther) const { return m_reserved != iOther.m_reserved; }

  operator const void*() const { return m_reserved; }
  const std::uint8_t* m_reserved = nullptr;
};
