#ifndef vAtomicImpl_H_
#define vAtomicImpl_H_

#include <atomic>
#include <cstdint>

#include <vKernelDefines.h>

namespace VKL
{
  // this is to make sure if we transition to
  // std::atomic<type>, we can implement the change
  // here and not modify everywhere
  template <typename T>
  struct vAtomicTraits
  {
    typedef T Type;
    typedef std::atomic<T> InternalType;
  };
  

  // Make sure the right internal atomic type is used
  // so that if someone uses something like vAtomic<short>, 
  // we end up using the fastest possible representation
  // This workaround is necessary because we are wrapping around
  // the actual implementation.
  
  template <>
  struct vAtomicTraits<std::int8_t>
  {
    typedef std::atomic_int_fast8_t InternalType;
    typedef std::int_fast8_t Type;
  };

  template <>
  struct vAtomicTraits<std::uint8_t>
  {
    typedef std::atomic_uint_fast8_t InternalType;
    typedef std::uint_fast8_t Type;
  };

  template <>
  struct vAtomicTraits<std::int16_t>
  {
    typedef std::atomic_int_fast16_t InternalType;
    typedef std::int_fast16_t Type;
  };

  template <>
  struct vAtomicTraits<std::uint16_t>
  {
    typedef std::atomic_uint_fast16_t InternalType;
    typedef std::uint_fast16_t Type;
  };

  template <>
  struct vAtomicTraits<std::int32_t>
  {
    typedef std::atomic_int_fast32_t InternalType;
    typedef std::int_fast32_t Type;
  };

  template <>
  struct vAtomicTraits<std::uint32_t>
  {
    typedef std::atomic_uint_fast32_t InternalType;
    typedef std::uint_fast32_t Type;
  };

  template <>
  struct vAtomicTraits<std::int64_t>
  {
    typedef std::atomic_int_fast64_t InternalType;
    typedef std::int_fast64_t Type;
  };

  template <>
  struct vAtomicTraits<std::uint64_t>
  {
    typedef std::atomic_uint_fast64_t InternalType;
    typedef std::uint_fast64_t Type;
  };


}

#endif //vAtomicImpl_H_
