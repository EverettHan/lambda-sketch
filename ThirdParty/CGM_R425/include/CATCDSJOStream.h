//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2020/10/21
//===================================================================

#ifndef CATCDSJOStream_H
#define CATCDSJOStream_H

#include "CATCDSJSON.h"

#include "CATCDSEscaper.h"

#include <string>
#include <vector>

#include "CATCDSString.h"

#ifdef _AIX_SOURCE
#include <sstream>
#endif

template <typename T>
class CATCDSValueToStringHelper;

class CATCDSJImpl;

class ExportedByJSON CATCDSJOStream
{
public:
   CATCDSJOStream();
   ~CATCDSJOStream();

public:
  CATCDSJOStream(const CATCDSJOStream& rhs);
  CATCDSJOStream& operator=(const CATCDSJOStream& rhs);

public:
  std::string Stringify() const;
  bool WriteFile(std::string const &filename) const;

  void AddNullValue(std::string const &key);

  void Add(std::string const &key, char const *value);

  template<class T>
  void Add(std::string const &key, T const &value);

  void AddRawString(std::string const &key, std::string const &value);

private:
  template <typename T>
  static std::string valueToString(const T& value);

private:
  CATCDSJImpl* json_;

private:

  template <typename T>
  friend class CATCDSValueToStringHelper;
};

template <typename T>
class CATCDSValueToStringHelper
{
public:
  std::string operator()(const T& value) const;
};

template <>
class ExportedByJSON CATCDSValueToStringHelper<bool>
{
public:
  std::string operator()(bool value) const;
};

template <>
class ExportedByJSON CATCDSValueToStringHelper<double>
{
public:
  std::string operator()(double value) const;
};

template <>
class CATCDSValueToStringHelper<char const *>
{
public:
  std::string operator()(char const *value) const;
};

template <>
class CATCDSValueToStringHelper<std::string>
{
public:
  std::string operator()(std::string const &value) const;
};

template <>
class CATCDSValueToStringHelper<CATCDSString>
{
public:
  std::string operator()(CATCDSString const &value) const;
};

template <>
class CATCDSValueToStringHelper<CATCDSJOStream>
{
public:
  std::string operator()(CATCDSJOStream const &value) const;
};

template <typename T>
class CATCDSValueToStringHelper<std::vector<T> >
{
public:
  std::string operator()(std::vector<T> const &values) const;
};

template<class T>
void CATCDSJOStream::Add(std::string const &key, T const &value)
{
  AddRawString(key, valueToString(value));
}

template <typename T>
std::string CATCDSJOStream::valueToString(const T& value)
{
  return CATCDSValueToStringHelper<T>()(value);
}

template <typename T>
std::string CATCDSValueToStringHelper<T>::operator()(const T& value) const
{
#ifdef _AIX_SOURCE
  std::stringstream ss;
  ss << value;
  return ss.str();
#else
  return std::to_string(value);
#endif
}

inline std::string CATCDSValueToStringHelper<char const *>::operator()(char const *value) const
{
  return "\"" + std::string(value) + "\"";
}

inline std::string CATCDSValueToStringHelper<std::string>::operator()(std::string const &value) const
{
  return "\"" + value + "\"";
}

inline std::string CATCDSValueToStringHelper<CATCDSString>::operator()(CATCDSString const &value) const
{
  return "\"" + std::string(value.str()) + "\"";
}

inline std::string CATCDSValueToStringHelper<CATCDSJOStream>::operator()(CATCDSJOStream const &value) const
{
  return value.Stringify();
}

template <typename T>
std::string CATCDSValueToStringHelper<std::vector<T> >::operator()(std::vector<T> const &values) const
{
  std::string content;
  CATCDSEscaper escaper(content);
  typename std::vector<T>::const_iterator begin = values.begin();
  for (typename std::vector<T>::const_iterator it = begin, end = values.end(); it != end; ++it)
  {
    if (it != begin)
      content.append(",");
    escaper.EscapeString(CATCDSJOStream::valueToString(*it));
  }
  return "[" + content + "]";
}

template <typename T>
CATCDSJOStream make_json(std::string const &key, const T& value)
{
  return CATCDSJOStream() << jpair(key, value);
}

#endif /*CATCDSJOStream_H*/
