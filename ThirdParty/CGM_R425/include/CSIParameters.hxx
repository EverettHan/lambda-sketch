#include "CSITraits.h"

#include <algorithm>
#include <memory>
#include <vector>

namespace CSI
{
template <class T>
HRESULT Parameters::ReadObject(const CATUnicodeString& name, const CATUnicodeString& type, std::unique_ptr<T>& value) const
{
  T* pVal = nullptr;
  HRESULT rc = ReadObject(name, type, pVal);
  value.reset(pVal);
  return rc;
}

template <class T>
HRESULT Parameters::ReadObject(const CATUnicodeString& name, const CATUnicodeString& type, T*& value) const
{
  static_assert(CSI::is_class_v<T>, "T must be a class");

  Parameters tmp = CreateEmptyParameters();
  if (FAILED(ReadParameters(name, type, tmp)))
    return E_FAIL;
  value = Unserialize<T>(tmp, type);
  if (! value)
  {
    PublishError("Unserialize Error in Parameters::ReadObject() property <" + name + "> type <" + type + ">");
    return E_FAIL;
  }
  return S_OK;
}

template <class T>
HRESULT Parameters::ReadObjectArray(const CATUnicodeString& name, const CATUnicodeString& type, std::vector<std::unique_ptr<T>>& value) const
{
  std::vector<T*> vecTmp;
  HRESULT rc = ReadObjectArray(name, type, vecTmp);

  auto pushToUniqueVec = [&value](T* pParam) { value.emplace_back(pParam); };

  value.reserve(vecTmp.size());
  std::for_each(vecTmp.begin(), vecTmp.end(), pushToUniqueVec);

  return rc;
}

template <class T>
HRESULT Parameters::ReadObjectArray(const CATUnicodeString& name, const CATUnicodeString& type, std::vector<T*>& value) const
{
  static_assert(CSI::is_class_v<T>, "T must be a class");

  std::vector<std::unique_ptr<Parameters>> tmpArray;
  if (FAILED(ReadParametersArray(name, type, tmpArray)))
    return E_FAIL;
  for (size_t i = 0; i < tmpArray.size(); ++i)
  {
    CSI::Parameters& tmp = *tmpArray[i];
    T* subValue = Unserialize<T>(tmp, type);
    if (! subValue)
      return PublishError("Unserialize Error in Parameters::ReadObjectArray() property <" + name + "> type <" + type + ">");
    value.push_back(subValue);
  }
  return S_OK;
}

template <class T>
HRESULT Parameters::WriteObject(const CATUnicodeString& name, const CATUnicodeString& type, T const& value)
{
  static_assert(CSI::is_class_v<T>, "T must be a class");

  Parameters tmp = CreateEmptyParameters();
  if (SUCCEEDED(Serialize(value, type, tmp)))
    return WriteObjectPrivate(name, type, tmp);

  return PublishError("Serialize Error in Parameters::WriteObject() property <" + name + "> type <" + type + ">");
}

template <class T>
HRESULT Parameters::WriteAsObject(const CATUnicodeString &type, T const &value)
{
  static_assert(CSI::is_class_v<T>, "T must be a class");
  HRESULT status = Serialize(value, type, *this);
  if (! SUCCEEDED(status))
  {
    PublishError("Serialize Error in Parameters::WriteObject() type <" + type + ">");
  }
  return status;
}

template <typename CustomTypeIt>
HRESULT Parameters::WriteObjectArray(const CATUnicodeString& name, const CATUnicodeString& type, CustomTypeIt first, CustomTypeIt last)
{
  std::vector<std::unique_ptr<CSI::Parameters>> tmpArray;

  for (; first != last; ++first)
  {
    CSI::Parameters* pTmp = NewEmptyParameters();
    tmpArray.emplace_back(pTmp);

    if (! *first || FAILED(Serialize(**first, type, *pTmp)))
    {
      return E_FAIL;
    }
  }

  return WriteObjectArrayPrivate(name, type, tmpArray);
}

template <class T>
HRESULT Parameters::WriteObjectArray(const CATUnicodeString& name, const CATUnicodeString& type, const std::vector<std::unique_ptr<T>>& value)
{
  return WriteObjectArray(name, type, value.begin(), value.end());
}

template <class T>
HRESULT Parameters::WriteObjectArray(const CATUnicodeString& name, const CATUnicodeString& type, const std::vector<T*>& value)
{
  static_assert(CSI::is_class_v<T>, "T must be a class");
  return WriteObjectArray(name, type, value.begin(), value.end());
}

template <class T>
HRESULT Parameters::WriteObjectArray(const CATUnicodeString& name, const CATUnicodeString& type, T** value, size_t length)
{
  static_assert(CSI::is_class_v<T>, "T must be a class");
  return WriteObjectArray(name, type, value, value + length);
};

template <class T>
T* Parameters::ReadAsObject(const CATUnicodeString& type) const
{
  static_assert(CSI::is_class_v<T>, "T must be a class");

  T* value = Unserialize<T>(*this, type);
  if (value)
    return value;

  PublishError("Parameters::ReadAsObject() unserialization failed type <" + type + ">");
  return nullptr;
}

template <class T>
HRESULT Parameters::WriteObjectAsReference(const CATUnicodeString& name, const CATUnicodeString& type, const T& value)
{
  static_assert(! CSI::is_pointer_v<T>, "T must not be a pointer");
  return WriteObjectAsReferencePrivate(name, type, const_cast<T*>(&value));
}

template <class T>
HRESULT Parameters::ReadObjectAsReference(const CATUnicodeString& name, const CATUnicodeString& type, T*& value) const
{
  static_assert(! CSI::is_pointer_v<T>, "T must not be a pointer");
  return ReadObjectAsReferencePrivate(name, type, (void*&)value);
}

template <class T>
HRESULT Parameters::WriteObjectAsReference(const char* name, const CATUnicodeString& type, const T& value)
{
  static_assert(! CSI::is_pointer_v<T>, "T must not be a pointer");
  return WriteObjectAsReferencePrivate(name, type, const_cast<T*>(&value));
}

template <class T>
HRESULT Parameters::ReadObjectAsReference(const char* name, const CATUnicodeString& type, T*& value) const
{
  static_assert(! CSI::is_pointer_v<T>, "T must not be a pointer");
  return ReadObjectAsReferencePrivate(name, type, (void*&)value);
}

template <class T>
HRESULT Parameters::Serialize(T const& value, const CATUnicodeString& type, Parameters& parameters) const
{
  static_assert(CSI::is_class_v<T>, "T must be a class");

  auto typeID = type_id<T>();
  void* func = GetSerializeFunction(type, typeID);
  if (! func)
    return E_FAIL;

  auto serializeFunc = reinterpret_cast<HRESULT (*)(Parameters&, T&)>(func);
  return serializeFunc(parameters, const_cast<T&>(value));
}

template <class T>
T* Parameters::Unserialize(const Parameters& parameters, const CATUnicodeString& type) const
{
  static_assert(CSI::is_class_v<T>, "T must be a class");

  auto typeID = type_id<T>();
  void* func = GetUnserializeFunction(parameters, type, typeID);
  if (! func)
    return nullptr;

  auto unserializeFunc = reinterpret_cast<T* (*)(const Parameters&)>(func);
  return unserializeFunc(parameters);
}
}
