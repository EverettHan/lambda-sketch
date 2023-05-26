// COPYRIGHT DASSAULT SYSTEMES 2016
//=============================================================================
//
// CATCDSMapSpecializations:
//
// DO NOT INCLUDE DIRECTLY, USE CATCDSMap
//
// Auxiliary functions and template classes for CATCDSMap partial specialization.
// CATCDSMap is specialized when Key or Value is an integer, a floating point number or a pointer type
// to share the same implementation.
//
//=============================================================================
//  Jan 2016  Creation                         TE9
//=============================================================================

#ifndef CATCDSMapSpecializations_h
#define CATCDSMapSpecializations_h

#include "CATCDSDataType.h"
#include "CATCDSAssert.h"

CATCDSStaticAssert(sizeof(float) == 4, "float is not 4 bytes")
CATCDSStaticAssert(sizeof(double) == 8, "double is not 8 bytes")
CATCDSStaticAssert(sizeof(long long) == 8, "float is not 8 bytes")
CATCDSStaticAssert(sizeof(unsigned long long) == 8, "float is not 8 bytes")

namespace CDSMapUtilities {  
  template<class T, class StorageType>
  CATCDSInline T CastFromStorage(StorageType  data)
  {
    return reinterpret_cast<T>(data);
  }

  // Conversion from UInt64 to type
  // bool
  template<>
  CATCDSInline bool CastFromStorage<bool, std::uint64_t>(std::uint64_t data)
  {
    return !!data;
  }

  // Signed integers
  template<>
  CATCDSInline char CastFromStorage<char, std::uint64_t>(std::uint64_t data)
  {
    return static_cast<char>((std::int64_t)data);
  }

  template<>
  CATCDSInline short CastFromStorage<short, std::uint64_t>(std::uint64_t data)
  {
    return static_cast<short>((std::int64_t)data);
  }

  template<>
  CATCDSInline int CastFromStorage<int, std::uint64_t>(std::uint64_t data)
  {
    return static_cast<int>((std::int64_t)data);
  }

  template<>
  CATCDSInline long CastFromStorage<long, std::uint64_t>(std::uint64_t data)
  {
    return static_cast<long>((std::int64_t)data);
  }

  template<>
  CATCDSInline long long CastFromStorage<long long, std::uint64_t>(std::uint64_t data)
  {
    return static_cast<long long>((std::int64_t)data);
  }

  // Unsigned integers
  template<>
  CATCDSInline unsigned char CastFromStorage<unsigned char, std::uint64_t>(std::uint64_t data)
  {
    return static_cast<unsigned char>(data);
  }

  template<>
  CATCDSInline unsigned short CastFromStorage<unsigned short, std::uint64_t>(std::uint64_t data)
  {
    return static_cast<unsigned short>(data);
  }

  template<>
  CATCDSInline unsigned int CastFromStorage<unsigned int, std::uint64_t>(std::uint64_t data)
  {
    return static_cast<unsigned int>(data);
  }

  template<>
  CATCDSInline unsigned long CastFromStorage<unsigned long, std::uint64_t>(std::uint64_t data)
  {
    return static_cast<unsigned long>(data);
  }

  template<>
  CATCDSInline unsigned long long CastFromStorage<unsigned long long, std::uint64_t>(std::uint64_t data)
  {
    return static_cast<unsigned long long>(data);
  }

  // Float and double
  template<>
  CATCDSInline float CastFromStorage<float, std::uint64_t>(std::uint64_t data)
  {
    std::uint32_t data32 = static_cast<std::uint32_t>(data);
    return *reinterpret_cast<float*>(&data32);
  }

  template<>
  CATCDSInline double CastFromStorage<double, std::uint64_t>(std::uint64_t data)
  {
    return *reinterpret_cast<double*>(&data);
  }

  // Conversion from type to UInt64
  template<class T>
  CATCDSInline std::uint64_t CastToStorage(T *data)
  {
    return static_cast<std::uint64_t>(reinterpret_cast<std::uintptr_t>(data));
  }

  // bool
  CATCDSInline std::uint64_t CastToStorage(bool data)
  {
    return data;
  }

  // Signed integers
  CATCDSInline std::uint64_t CastToStorage(char data)
  {
    return (std::uint64_t)static_cast<std::int64_t>(data);
  }

  CATCDSInline std::uint64_t CastToStorage(short data)
  {
    return (std::uint64_t)static_cast<std::int64_t>(data);
  }

  CATCDSInline std::uint64_t CastToStorage(int data)
  {
    return (std::uint64_t)static_cast<std::int64_t>(data);
  }

  CATCDSInline std::uint64_t CastToStorage(long data)
  {
    return (std::uint64_t)static_cast<std::int64_t>(data);
  }

  CATCDSInline std::uint64_t CastToStorage(long long data)
  {
    return (std::uint64_t)static_cast<std::int64_t>(data);
  }

  // Unsigned integers
  CATCDSInline std::uint64_t CastToStorage(unsigned char data)
  {
    return static_cast<std::uint64_t>(data);
  }

  CATCDSInline std::uint64_t CastToStorage(unsigned short data)
  {
    return static_cast<std::uint64_t>(data);
  }

  CATCDSInline std::uint64_t CastToStorage(unsigned int data)
  {
    return static_cast<std::uint64_t>(data);
  }

  CATCDSInline std::uint64_t CastToStorage(unsigned long data)
  {
    return static_cast<std::uint64_t>(data);
  }

  CATCDSInline std::uint64_t CastToStorage(unsigned long long data)
  {
    return static_cast<std::uint64_t>(data);
  }

  // Float and double
  CATCDSInline std::uint64_t CastToStorage(float data)
  {
    return static_cast<std::uint64_t>(*reinterpret_cast<std::uint32_t*>(&data));
  }

  CATCDSInline std::uint64_t CastToStorage(double data)
  {
    return *reinterpret_cast<std::uint64_t*>(&data);
  }
}

template<class Value>
class CATCDSUInt64Reference
{
public:
  CATCDSUInt64Reference(std::uint64_t &iData) : _data(iData) {}

  operator Value() const
  {
    return CDSMapUtilities::CastFromStorage<Value, std::uint64_t>(_data);
  }

  Value operator->()
  {
    return CDSMapUtilities::CastFromStorage<Value, std::uint64_t>(_data);
  }

  CATCDSUInt64Reference& operator=(Value value)
  {
    _data = CDSMapUtilities::CastToStorage(value);
    return *this;
  }

  CATCDSUInt64Reference& operator+=(Value value)
  {
    _data = CDSMapUtilities::CastToStorage(CDSMapUtilities::CastFromStorage<Value, std::uint64_t>(_data) + value);
    return *this;
  }

  CATCDSUInt64Reference& operator-=(Value value)
  {
    _data = CDSMapUtilities::CastToStorage(CDSMapUtilities::CastFromStorage<Value, std::uint64_t>(_data) - value);
    return *this;
  }

  CATCDSUInt64Reference& operator*=(Value value)
  {
    _data = CDSMapUtilities::CastToStorage(CDSMapUtilities::CastFromStorage<Value, std::uint64_t>(_data) * value);
    return *this;
  }

  CATCDSUInt64Reference& operator/=(Value value)
  {
    _data = CDSMapUtilities::CastToStorage(CDSMapUtilities::CastFromStorage<Value, std::uint64_t>(_data) / value);
    return *this;
  }

  CATCDSUInt64Reference& operator%=(Value value)
  {
    _data = CDSMapUtilities::CastToStorage(CDSMapUtilities::CastFromStorage<Value, std::uint64_t>(_data) % value);
    return *this;
  }

  CATCDSUInt64Reference& operator++()
  {
    _data = CDSMapUtilities::CastToStorage(CDSMapUtilities::CastFromStorage<Value, std::uint64_t>(_data) + 1);
    return *this;
  }

  CATCDSUInt64Reference& operator++(int)
  {
    _data = CDSMapUtilities::CastToStorage(CDSMapUtilities::CastFromStorage<Value, std::uint64_t>(_data) + 1);
    return *this;
  }

  std::uint64_t & _data;
};


template<class Value>
class CATCDSUInt64ConstReference
{
public:
  CATCDSUInt64ConstReference(std::uint64_t const &iData) : _data(iData) {}

  operator Value() const
  {
    return CDSMapUtilities::CastFromStorage<Value, std::uint64_t>(_data);
  }

  Value operator->()
  {
    return CDSMapUtilities::CastFromStorage<Value, std::uint64_t>(_data);
  }

  std::uint64_t const & _data;
};

// Add here any type needed
template<class T>
struct CDSStorageType {
  typedef T type;
  typedef T & ref;
  typedef T const & const_ref;

  static CATCDSInline const_ref CastToStorage(const_ref e)
  {
    return e;
  }
};

template<class T>
struct CDSStorageType<T*> {
  typedef std::uint64_t type;
  typedef CATCDSUInt64Reference<T*> ref;
  typedef CATCDSUInt64ConstReference<T*> const_ref;

  static CATCDSInline std::uint64_t CastToStorage(T * const & e)
  {
    return CDSMapUtilities::CastToStorage(e);
  }
};

// bool
template<>
struct CDSStorageType<bool> {
  typedef std::uint64_t type;
  typedef CATCDSUInt64Reference<bool> ref;
  typedef CATCDSUInt64ConstReference<bool> const_ref;

  static CATCDSInline std::uint64_t CastToStorage(bool e)
  {
    return CDSMapUtilities::CastToStorage(e);
  }
};

// Signed integers
template<>
struct CDSStorageType<char> {
  typedef std::uint64_t type;
  typedef CATCDSUInt64Reference<char> ref;
  typedef CATCDSUInt64ConstReference<char> const_ref;

  static CATCDSInline std::uint64_t CastToStorage(char e)
  {
    return CDSMapUtilities::CastToStorage(e);
  }
};

template<>
struct CDSStorageType<short> {
  typedef std::uint64_t type;
  typedef CATCDSUInt64Reference<short> ref;
  typedef CATCDSUInt64ConstReference<short> const_ref;

  static CATCDSInline std::uint64_t CastToStorage(short e)
  {
    return CDSMapUtilities::CastToStorage(e);
  }
};

template<>
struct CDSStorageType<int> {
  typedef std::uint64_t type;
  typedef CATCDSUInt64Reference<int> ref;
  typedef CATCDSUInt64ConstReference<int> const_ref;

  static CATCDSInline std::uint64_t CastToStorage(int e)
  {
    return CDSMapUtilities::CastToStorage(e);
  }
};

template<>
struct CDSStorageType<long> {
  typedef std::uint64_t type;
  typedef CATCDSUInt64Reference<long> ref;
  typedef CATCDSUInt64ConstReference<long> const_ref;

  static CATCDSInline std::uint64_t CastToStorage(long e)
  {
    return CDSMapUtilities::CastToStorage(e);
  }
};

template<>
struct CDSStorageType<long long> {
  typedef std::uint64_t type;
  typedef CATCDSUInt64Reference<long long> ref;
  typedef CATCDSUInt64ConstReference<long long> const_ref;

  static CATCDSInline std::uint64_t CastToStorage(long long e)
  {
    return CDSMapUtilities::CastToStorage(e);
  }
};

// Unsigned integers
template<>
struct CDSStorageType<unsigned char> {
  typedef std::uint64_t type;
  typedef CATCDSUInt64Reference<unsigned char> ref;
  typedef CATCDSUInt64ConstReference<unsigned char> const_ref;

  static CATCDSInline std::uint64_t CastToStorage(unsigned char e)
  {
    return CDSMapUtilities::CastToStorage(e);
  }
};

template<>
struct CDSStorageType<unsigned short> {
  typedef std::uint64_t type;
  typedef CATCDSUInt64Reference<unsigned short> ref;
  typedef CATCDSUInt64ConstReference<unsigned short> const_ref;

  static CATCDSInline std::uint64_t CastToStorage(unsigned short e)
  {
    return CDSMapUtilities::CastToStorage(e);
  }
};

template<>
struct CDSStorageType<unsigned int> {
  typedef std::uint64_t type;
  typedef CATCDSUInt64Reference<unsigned int> ref;
  typedef CATCDSUInt64ConstReference<unsigned int> const_ref;

  static CATCDSInline std::uint64_t CastToStorage(unsigned int e)
  {
    return CDSMapUtilities::CastToStorage(e);
  }
};

template<>
struct CDSStorageType<unsigned long> {
  typedef std::uint64_t type;
  typedef CATCDSUInt64Reference<unsigned long> ref;
  typedef CATCDSUInt64ConstReference<unsigned long> const_ref;

  static CATCDSInline std::uint64_t CastToStorage(unsigned long e)
  {
    return CDSMapUtilities::CastToStorage(e);
  }
};

template<>
struct CDSStorageType<unsigned long long> {
  typedef std::uint64_t type;
  typedef CATCDSUInt64Reference<unsigned long long> ref;
  typedef CATCDSUInt64ConstReference<unsigned long long> const_ref;

  static CATCDSInline std::uint64_t CastToStorage(unsigned long long e)
  {
    return CDSMapUtilities::CastToStorage(e);
  }
};

// Float and double
template<>
struct CDSStorageType<float> {
  typedef std::uint64_t type;
  typedef CATCDSUInt64Reference<float> ref;
  typedef CATCDSUInt64ConstReference<float> const_ref;

  static CATCDSInline std::uint64_t CastToStorage(float e)
  {
    return CDSMapUtilities::CastToStorage(e);
  }
};

template<>
struct CDSStorageType<double> {
  typedef std::uint64_t type;
  typedef CATCDSUInt64Reference<double> ref;
  typedef CATCDSUInt64ConstReference<double> const_ref;

  static CATCDSInline std::uint64_t CastToStorage(double e)
  {
    return CDSMapUtilities::CastToStorage(e);
  }
};

#endif
