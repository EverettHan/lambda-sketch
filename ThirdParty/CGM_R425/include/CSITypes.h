#ifndef CSITypes_H
#define CSITypes_H

#include "CSICommandBinderModule.h"

#include "CSIParameters.h"
#include "CSITraits.h"
#include "CSITypeid.h"

#include "DSUnicodeString.h"

#include "DSYExport.h"

#define CSI_SERIALIZE_TYPE(typeName, serialize, unserialize) \
extern "C" \
{ \
  DSYExport HRESULT DT_##typeName(CSI::Types& csiTypes) \
  { \
    return csiTypes.DeclareType(#typeName, serialize, unserialize, CSI::strongTypingTag); \
  } \
}

namespace EK
{
class Context;
}

namespace CSI
{
const struct StrongTypingTag {} strongTypingTag;

class ExportedByCSIBinderModule Types
{
public:
  explicit Types(const EK::Context& ekContext);
  Types(const EK::Context& ekContext, const CATUnicodeString& declarativeFilesPaths);
  Types(const EK::Context& ekContext, const Types& types);
  ~Types();

  Types(const Types&) = delete;
  Types& operator=(const Types&) = delete;

  /** Register a Client or Server Parameter Serializer and Unserializer functions
  \param parameterType parameter type
  \param serializeFunc parameter's serializer function
  \param unserializeFunc parameter's unserializer function
  \param strongTypingTag: dispatch tag used to activate strong typing
  \  By using strong typing an error will be raised if (Un)Serialization functions are called for typeName with a C++ type different from T
  \
  \return S_OK if successful, E_FAIL otherwise
  \
  \examples:
  \       HRESULT mySerializeFunction(Parameters& param, MyCustomClass& value);
  \       MyCustomClass* myUnserializeFunction(Parameters& param);
  \
  \  1) Explicit instantiation:
  \       types.DeclareType<MyCustomClass>("MyCustomName", mySerializeFunction, myUnserializeFunction, CSI::strongTypingTag);
  \  2) Or implicit instantiation
  \       types.DeclareType("MyCustomName", mySerializeFunction, myUnserializeFunction, CSI::strongTypingTag);
  */
  template <class T>
  HRESULT DeclareType(const CATUnicodeString& typeName, HRESULT (*serializeFunc)(Parameters&, T& value), T* (*unserializeFunc)(Parameters&), StrongTypingTag tag = strongTypingTag);

  /** Create a Parameters from a registered type
  \param parameterType: parameter type
  \param value: object to serialize
  \return serialized object as Parameters
  \
  \examples:
  \       CSI::Parameters param = types.CreateParameters("MyCustomName", myCustomObj);
  */
  template <class T>
  Parameters CreateParameters(const CATUnicodeString& type, const T& value) const;

private:
  HRESULT DeclareTypePrivate(const CATUnicodeString& type, const type_id_t& typeIdx, void* serializeFunc, void* unserializeFunc);
  void* GetSerializeFunction(const CATUnicodeString& type, const type_id_t& typeIdx) const;
  void PublishError(const CATUnicodeString& message) const;

private:
  friend TypesImpl& getImpl(const Types& Types);

private:
  // Notes: Types being an exported class it is preferable to not use std::unique_ptr as data members to avoid warning C4251
  TypesImpl* impl_;
};

template <class T>
HRESULT Types::DeclareType(const CATUnicodeString& typeName, HRESULT (*serializeFunc)(Parameters&, T& value), T* (*unserializeFunc)(Parameters&), StrongTypingTag)
{
  static_assert(CSI::is_class_v<T>, "T must be a class");
  auto typeID = type_id<T>();
  return DeclareTypePrivate(typeName, typeID, reinterpret_cast<void*>(serializeFunc), reinterpret_cast<void*>(unserializeFunc));
}

template <class T>
Parameters Types::CreateParameters(const CATUnicodeString& type, T const& value) const
{
  static_assert(CSI::is_class_v<T>, "T must be a class");

  auto typeID = type_id<T>();
  void* func = GetSerializeFunction(type, typeID);
  if (! func)
    return Parameters(*this);

  Parameters parameters(*impl_, type);
  auto serializeFunc = reinterpret_cast<HRESULT (*)(Parameters&, T&)>(func);
  if (FAILED(serializeFunc(parameters, const_cast<T&>(value))))
  {
    PublishError("CreateParameters(const CATUnicodeString& type, T const& value) serialization failed with type <" + type + ">");
    return Parameters(*this);
  }
  return parameters;
}
}

#endif
