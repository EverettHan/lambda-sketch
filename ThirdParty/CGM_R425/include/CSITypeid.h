#ifndef CSITypeid_H
#define CSITypeid_H

#ifndef _IOS_SOURCE
#include <typeindex>
#include <typeinfo>
#else
#include "CSICommandBinderModule.h"
#include <string>
#endif

#ifndef _IOS_SOURCE
namespace CSI
{
using type_id_t = std::type_index;

template <typename T>
type_id_t type_id()
{
  return type_id_t(typeid(T));
}
} // namespace CSI
#else
namespace CSI
{
// helper functions to print class name without rtti on iOS
// https://stackoverflow.com/questions/8001207/compile-time-typeid-without-rtti-with-gcc
ExportedByCSIBinderModule std::string extract_type_name(const char* s);

template <typename T>
const char* type_name()
{
  // https://gcc.gnu.org/onlinedocs/gcc/Function-Names.html
  static std::string strTypeName = extract_type_name(__PRETTY_FUNCTION__);
  return strTypeName.c_str();
}

//-------------------------------------------------------------------------------------------------
// static typeid like behavior without rtti
// inspired from: https://stackoverflow.com/questions/51361606/stdany-without-rtti-how-does-it-work
//-------------------------------------------------------------------------------------------------

class id_gen
{
private:
  static auto getUniqueID()
  {
    static std::size_t nextid;
    return ++nextid; //globally unique
  };

public:
  id_gen() = delete;
  id_gen(id_gen const&) = delete;

  template <typename T>
  static std::size_t get()
  {
    static const std::size_t tid = getUniqueID(); //classwide unique
    return tid;
  };
};

// wrapper on id_gen mimicking std::type_index
class type_id_t
{
public:

  type_id_t(const type_id_t&) = default;
  type_id_t(type_id_t&&) noexcept = default;

  type_id_t& operator=(const type_id_t&) = default;
  type_id_t& operator=(type_id_t&&) = default;

  std::size_t getID() { return id_; }

  bool operator==(const type_id_t& rhs) const { return id_ == rhs.id_; }
  bool operator!=(const type_id_t& rhs) const { return id_ != rhs.id_; }
  bool operator<(const type_id_t& rhs) const { return id_ < rhs.id_; }

  std::size_t hash_code() const { return std::hash<std::size_t>{}(id_); };

  const char* name() const { return name_.c_str(); };

private:
  type_id_t(std::size_t id) noexcept
    : id_(id)
  {
  }

  type_id_t(const std::string& name, std::size_t id) noexcept
    : name_(name)
    , id_(id)
  {
  }

  template <typename T>
  friend type_id_t type_id();

  std::string name_;
  std::size_t id_;
};

template <typename T>
type_id_t type_id()
{
  return type_id_t(type_name<T>(), id_gen::get<T>());
}
} // namespace CSI

namespace std
{
template <>
struct hash<CSI::type_id_t>
{
  std::size_t operator()(const CSI::type_id_t& elem) const
  {
    return elem.hash_code();
  }
};

} // namespace std
#endif // _IOS_SOURCE

#endif
