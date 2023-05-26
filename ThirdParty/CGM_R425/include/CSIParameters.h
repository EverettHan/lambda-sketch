#ifndef CSIParameters_H
#define CSIParameters_H

#include "CSICommandBinderModule.h"
#include "CSIParametersIterator.h"
//#include "CSITemplateExport.h"
#include "CSITypeid.h"
#include "EKBinary.h"
#include "CATSysErrorDef.h"
#include "DSUnicodeString.h"

#include <initializer_list>
#include <memory>
#include <stddef.h>
#include <stdint.h>
#include <string>
#include <vector>

// Somehow extern template declaration breaks SMAHvsDriver compilation
// To be investigated

//namespace CSI
//{
//class Parameters;
//}
//
//extern template class TemplateDeclExport std::unique_ptr<CSI::Parameters>;
//extern template class TemplateDeclExport std::vector<CSI::Parameters*>;

namespace CSI
{
  class ParametersImpl;
  class Commands;
  class Types;
  class TypesImpl;

  /* Parameters class.
    Use to write or read a set of basic or custom parameters.
  */
  class ExportedByCSIBinderModule Parameters
  {
  public:
    explicit Parameters(const Commands& commands);
    explicit Parameters(const Types& types);

    Parameters(const Commands& commands, const EK::Binary& binary);
    Parameters(const Types& types, const EK::Binary& binary);

    ~Parameters();

    Parameters(const Parameters&);
    Parameters& operator=(const Parameters&);

    /** take ownership of given parameter internals, do not use given parameter after use*/
    // noexcept is redundant but would cause a compilation error if for some reason the generated operators were
    // not noexcept (internal member with no noexcept move constructor, ...)
    Parameters(Parameters&&) noexcept;
    Parameters& operator=(Parameters&&) noexcept;

    /** Return the current binary size of the Parameters */
    size_t GetBinarySize() const;

    /** Binary serialization */
    EK::Binary ToBinary(bool includeDefaultValue = false) const;
    HRESULT FromBinary(const EK::Binary& binary);

    /** String serialization */
    CATUnicodeString ExportToString() const;
    bool ImportFromString(const CATUnicodeString& str);

    /** Dump to JSON string */
    HRESULT ToJSONWithType(CATUnicodeString& jsonValue) const;
    HRESULT Stringify(CATUnicodeString& jsonValue) const;

    /** Check if the parameters contains properties
      \return true if at least one property exists, false otherwise
    */
    bool IsEmpty() const;

    /** Check if a property exists
      \param name property name
      \return true if specified property exists, false otherwise
    */
    bool Exists(const char* name) const;
    bool Exists(const CATUnicodeString& name) const;

    /** Check if a property exists and returns its type
      \param name property name
      \param type [out] property type
      \return true if specified property exists and type will contains its type, false otherwise
    */
    bool Exists(const char* name, CATUnicodeString& type) const;
    bool Exists(const char* name, std::string& type) const;
    bool Exists(const CATUnicodeString& name, CATUnicodeString& type) const;

    /** Check if a property exists for the specified type
      \param name property name
      \param type property type
      \return true if specified property with the specified type exists, false otherwise
    */
    bool ExistsWithType(const char* name, const CATUnicodeString& type) const;
    bool ExistsWithType(const CATUnicodeString& name, const CATUnicodeString& type) const;

    //[[deprecated("CSI COMMAND BINDER - DEPRECATED - 2020/04/14 - Useless method, will be removed in a futur version")]]
    bool HasOwnCSIProperty(const CATUnicodeString& name) const;

    [[deprecated("CSI COMMAND BINDER - DEPRECATED - 2020/04/14 - Useless method, will be removed in a futur version")]]
    bool HasOwnCSIPropertyWithType(const CATUnicodeString& name, const CATUnicodeString& type) const;

    /** Remove the specified property
      \param name property name
      \return true if specified property has been found and removed, false otherwise
    */
    bool RemoveProperty(const char* name);
    bool RemoveProperty(const CATUnicodeString& name);

    /** Override parameters with properties of the specified parameters
      Existing properties in the current parameters will be replaced, missing will be added
      Properties only in current parameters will be kept
      Default values of the input parameters will not be copied
      \param fromParameters parameters from which properties will be copied
      \return S_FALSE if no property has been overridden, S_OK if at least one property has been overridden, E_FAIL on error,
      for instance if you try to override a parameter declare as Point with another parameters declare as parameters or square
    */
    HRESULT OverrideWith(const Parameters& fromParameters);

    /** Copy the specified property from current parameters into another parameters
      \param fromName name of the property to copy
      \param toParameters parameters in which property will be copied
      \param toName name of the copied property in the destination parameters
      \return S_OK if specified property has been found in the current parameters, E_FAIL otherwise
    */
    HRESULT Extract(const char* fromName, Parameters& toParameters, const char* toName) const;
    HRESULT Extract(const CATUnicodeString& fromName, Parameters& toParameters, const CATUnicodeString& toName) const;

    //[[deprecated("CSI COMMAND BINDER - DEPRECATED - 2020/04/14 - Useless method, will be removed in a futur version")]]
    HRESULT ExtractWithDefaultValue(const CATUnicodeString& FromName, Parameters& to, const CATUnicodeString& toName) const;

    /** Read a property as a basic type
      \param name name of the property to read
      \param value [out] read value if property with the right type has been found
      \return S_OK if the specified property with the right basic type has been found, E_FAIL otherwise
    */
    HRESULT ReadString(const char* name, CATUnicodeString& value) const;
    HRESULT ReadString(const CATUnicodeString& name, CATUnicodeString& value) const;

    HRESULT ReadString(const char* name, std::string& value) const;

    HRESULT ReadBool(const char* name, bool& value) const;
    HRESULT ReadBool(const CATUnicodeString& name, bool& value) const;

    HRESULT ReadInt8(const char* name, int8_t& value) const;
    HRESULT ReadInt8(const CATUnicodeString& name, int8_t& value) const;

    HRESULT ReadUint8(const char* name, uint8_t& value) const;
    HRESULT ReadUint8(const CATUnicodeString& name, uint8_t& value) const;

    HRESULT ReadInt16(const char* name, int16_t& value) const;
    HRESULT ReadInt16(const CATUnicodeString& name, int16_t& value) const;

    HRESULT ReadUint16(const char* name, uint16_t& value) const;
    HRESULT ReadUint16(const CATUnicodeString& name, uint16_t& value) const;

    HRESULT ReadInt32(const char* name, int32_t& value) const;
    HRESULT ReadInt32(const CATUnicodeString& name, int32_t& value) const;

    HRESULT ReadUint32(const char* name, uint32_t& value) const;
    HRESULT ReadUint32(const CATUnicodeString& name, uint32_t& value) const;

    HRESULT ReadInt64(const char* name, int64_t& value) const;
    HRESULT ReadInt64(const CATUnicodeString& name, int64_t& value) const;

    HRESULT ReadUint64(const char* name, uint64_t& value) const;
    HRESULT ReadUint64(const CATUnicodeString& name, uint64_t& value) const;

    HRESULT ReadFloat(const char* name, float& value) const;
    HRESULT ReadFloat(const CATUnicodeString& name, float& value) const;

    HRESULT ReadDouble(const char* name, double& value) const;
    HRESULT ReadDouble(const CATUnicodeString& name, double& value) const;

    // About ReadBuffer, DO NOT DELETE retrieved buffer, otherwise process will crash
    HRESULT ReadBuffer(const char* name, const void*& buffer, size_t& size) const;
    HRESULT ReadBuffer(const char* name, EK::Binary& bin) const;
    HRESULT ReadBuffer(const CATUnicodeString& name, const void*& buffer, size_t& size) const;
    HRESULT ReadBuffer(const CATUnicodeString& name, EK::Binary& bin) const;

    /** Read a property as a sub parameters with a specified declarative type
      Will read the property as a parameters and check its content is compliant with the specified declarative type
      Use "Parameters" as type to retrieve a parameters with any declarative type
      \param name name of the property to read
      \param type declarative type of the parameters
      \param value [out] parameters with sub properties content if found and type is compliant
      \return S_OK if the property with the specified declarative type has been found, E_FAIL otherwise
    */
    HRESULT ReadParameters(const char* name, const CATUnicodeString& type, Parameters& value) const;
    HRESULT ReadParameters(const char* name, const CATUnicodeString& type, std::unique_ptr<Parameters>& value) const;
    HRESULT ReadParameters(const CATUnicodeString& name, const CATUnicodeString& type, Parameters& value) const;
    HRESULT ReadParameters(const CATUnicodeString& name, const CATUnicodeString& type, std::unique_ptr<Parameters>& value) const;

    /** Read a property as a sub parameters
      Will read the property as a parameters
      Same behaviour as ReadParameters(const char* name, "Parameters", Parameters& value)
      \param name name of the property to read
      \param value [out] parameters with sub properties content if found
      \return S_OK if the property has been found, E_FAIL otherwise
    */
    HRESULT ReadParameters(const char* name, Parameters& value) const;
    HRESULT ReadParameters(const char* name, std::unique_ptr<Parameters>& value) const;
    HRESULT ReadParameters(const CATUnicodeString& name, Parameters& value) const;
    HRESULT ReadParameters(const CATUnicodeString& name, std::unique_ptr<Parameters>& value) const;

    /** Read a property as an array of basic type
      \param name name of the property to read
      \param values [out] array of read values if property with the right type has been found
      \return S_OK if the specified property with the right basic type has been found, E_FAIL otherwise
    */
    HRESULT ReadStringArray(const char* name, std::vector<CATUnicodeString>& values) const;
    HRESULT ReadStringArray(const CATUnicodeString& name, std::vector<CATUnicodeString>& values) const;

    HRESULT ReadStringArray(const char* name, std::vector<std::string>& values) const;

    HRESULT ReadBoolArray(const char* name, std::vector<bool>& values) const;
    HRESULT ReadBoolArray(const CATUnicodeString& name, std::vector<bool>& values) const;

    HRESULT ReadInt8Array(const char* name, std::vector<int8_t>& values) const;
    HRESULT ReadInt8Array(const CATUnicodeString& name, std::vector<int8_t>& values) const;

    HRESULT ReadUint8Array(const char* name, std::vector<uint8_t>& values) const;
    HRESULT ReadUint8Array(const CATUnicodeString& name, std::vector<uint8_t>& values) const;

    HRESULT ReadInt16Array(const char* name, std::vector<int16_t>& values) const;
    HRESULT ReadInt16Array(const CATUnicodeString& name, std::vector<int16_t>& values) const;

    HRESULT ReadUint16Array(const char* name, std::vector<uint16_t>& values) const;
    HRESULT ReadUint16Array(const CATUnicodeString& name, std::vector<uint16_t>& values) const;

    HRESULT ReadInt32Array(const char* name, std::vector<int32_t>& values) const;
    HRESULT ReadInt32Array(const CATUnicodeString& name, std::vector<int32_t>& values) const;

    HRESULT ReadUint32Array(const char* name, std::vector<uint32_t>& values) const;
    HRESULT ReadUint32Array(const CATUnicodeString& name, std::vector<uint32_t>& values) const;

    HRESULT ReadInt64Array(const char* name, std::vector<int64_t>& values) const;
    HRESULT ReadInt64Array(const CATUnicodeString& name, std::vector<int64_t>& values) const;

    HRESULT ReadUint64Array(const char* name, std::vector<uint64_t>& values) const;
    HRESULT ReadUint64Array(const CATUnicodeString& name, std::vector<uint64_t>& values) const;

    HRESULT ReadFloatArray(const char* name, std::vector<float>& values) const;
    HRESULT ReadFloatArray(const CATUnicodeString& name, std::vector<float>& values) const;

    HRESULT ReadDoubleArray(const char* name, std::vector<double>& values) const;
    HRESULT ReadDoubleArray(const CATUnicodeString& name, std::vector<double>& values) const;

    HRESULT ReadBufferArray(const char* name, std::vector<EK::Binary>& values) const;
    HRESULT ReadBufferArray(const CATUnicodeString& name, std::vector<EK::Binary>& values) const;

    /** Read a property as an array of sub parameters with a specified declarative type
      Will read the property as an array of parameters and check each sub parameters is compliant with the specified declarative type
      Use "Parameters" as type to retrieve an array of parameters with any declarative type
      \param name name of the property to read
      \param type declarative type for each parameters element of the array
      \param values [out] array of parameters if property found and each parameters element type is compliant with the specified one
      \return S_OK if the property has been found and each parameters element it compliant with the specified declarative type, E_FAIL otherwise
    */
    HRESULT ReadParametersArray(const char* name, const CATUnicodeString& type, std::vector<Parameters>& values) const;
    HRESULT ReadParametersArray(const char* name, const CATUnicodeString& type, std::vector<std::unique_ptr<Parameters>>& values) const;
    HRESULT ReadParametersArray(const CATUnicodeString& name, const CATUnicodeString& type, std::vector<Parameters>& values) const;
    HRESULT ReadParametersArray(const CATUnicodeString& name, const CATUnicodeString& type, std::vector<std::unique_ptr<Parameters>>& values) const;

    /** Write a property with a basic type
      \param name name of the property to write
      \param value value to write
      \return S_OK but E_FAIL in case no more memory
    */
    HRESULT WriteString(const char* name, const char* value);
    HRESULT WriteString(const char* name, const std::string& value);
    HRESULT WriteString(const char* name, const CATUnicodeString& value);
    HRESULT WriteString(const CATUnicodeString& name, const char* value);
    HRESULT WriteString(const CATUnicodeString& name, const CATUnicodeString& value);

    HRESULT WriteBool(const char* name, bool value);
    HRESULT WriteBool(const CATUnicodeString& name, bool value);

    HRESULT WriteInt8(const char* name, int8_t value);
    HRESULT WriteInt8(const CATUnicodeString& name, int8_t value);

    HRESULT WriteUint8(const char* name, uint8_t value);
    HRESULT WriteUint8(const CATUnicodeString& name, uint8_t value);

    HRESULT WriteInt16(const char* name, int16_t value);
    HRESULT WriteInt16(const CATUnicodeString& name, int16_t value);

    HRESULT WriteUint16(const char* name, uint16_t value);
    HRESULT WriteUint16(const CATUnicodeString& name, uint16_t value);

    HRESULT WriteInt32(const char* name, int32_t value);
    HRESULT WriteInt32(const CATUnicodeString& name, int32_t value);

    HRESULT WriteUint32(const char* name, uint32_t value);
    HRESULT WriteUint32(const CATUnicodeString& name, uint32_t value);

    HRESULT WriteInt64(const char* name, int64_t value);
    HRESULT WriteInt64(const CATUnicodeString& name, int64_t value);

    HRESULT WriteUint64(const char* name, uint64_t value);
    HRESULT WriteUint64(const CATUnicodeString& name, uint64_t value);

    HRESULT WriteFloat(const char* name, float value);
    HRESULT WriteFloat(const CATUnicodeString& name, float value);

    HRESULT WriteDouble(const char* name, double value);
    HRESULT WriteDouble(const CATUnicodeString& name, double value);

    HRESULT WriteBuffer(const char* name, const void* buffer, size_t size);
    HRESULT WriteBuffer(const char* name, const EK::Binary& binary);
    HRESULT WriteBuffer(const CATUnicodeString& name, const void* buffer, size_t size);
    HRESULT WriteBuffer(const CATUnicodeString& name, const EK::Binary& binary);

    /** Write a property with a sub parameters of a specified declarative type
      Will write the property as a parameters and check its content is compliant with the specified declarative type
      Use "Parameters" as type to write the sub parameters with no check of the declarative type
      \param name name of the property to write
      \param type declarative type of the parameters to write
      \param value sub parameters to write
      \return S_OK if the parameters to write is compliante with the specified declarative, E_FAIL otherwise
    */
    HRESULT WriteParameters(const char* name, const CATUnicodeString& type, const Parameters& value);
    HRESULT WriteParameters(const CATUnicodeString& name, const CATUnicodeString& type, const Parameters& value);

    /** Write a property with a sub parameters
      Will write the property as a parameters
      Same behaviour as WriteParameters(const char* name, "Parameters", const Parameters& value)
      \param name name of the property to write
      \param value sub parameters to write
      \return S_OK if the parameters to write is compliante with the specified declarative, E_FAIL otherwise
    */
    HRESULT WriteParameters(const char* name, const Parameters& value);
    HRESULT WriteParameters(const CATUnicodeString& name, const Parameters& value);

    /** Write a property with an array of basic type
      \param name name of the property to write
      \param values array of values to write
      \return S_OK but E_FAIL in case no more memory
    */
    HRESULT WriteStringArray(const char* name, std::initializer_list<std::string> values);
    HRESULT WriteStringArray(const char* name, const std::vector<std::string>& values);
    HRESULT WriteStringArray(const char* name, const std::vector<CATUnicodeString>& values);
    HRESULT WriteStringArray(const char* name, CATUnicodeString* values, size_t length);
    HRESULT WriteStringArray(const CATUnicodeString& name, std::initializer_list<std::string> values);
    HRESULT WriteStringArray(const CATUnicodeString& name, const std::vector<std::string>& values);
    HRESULT WriteStringArray(const CATUnicodeString& name, const std::vector<CATUnicodeString>& values);
    HRESULT WriteStringArray(const CATUnicodeString& name, CATUnicodeString* values, size_t length);

    HRESULT WriteBoolArray(const char* name, const std::vector<bool>& values);
    HRESULT WriteBoolArray(const char* name, bool* values, size_t length);
    HRESULT WriteBoolArray(const CATUnicodeString& name, const std::vector<bool>& values);
    HRESULT WriteBoolArray(const CATUnicodeString& name, bool* values, size_t length);

    HRESULT WriteInt8Array(const char* name, const std::vector<int8_t>& values);
    HRESULT WriteInt8Array(const char* name, int8_t* values, size_t length);
    HRESULT WriteInt8Array(const CATUnicodeString& name, const std::vector<int8_t>& values);
    HRESULT WriteInt8Array(const CATUnicodeString& name, int8_t* values, size_t length);

    HRESULT WriteUint8Array(const char* name, const std::vector<uint8_t>& values);
    HRESULT WriteUint8Array(const char* name, uint8_t* values, size_t length);
    HRESULT WriteUint8Array(const CATUnicodeString& name, const std::vector<uint8_t>& values);
    HRESULT WriteUint8Array(const CATUnicodeString& name, uint8_t* values, size_t length);

    HRESULT WriteInt16Array(const char* name, const std::vector<int16_t>& value);
    HRESULT WriteInt16Array(const char* name, int16_t* value, size_t length);
    HRESULT WriteInt16Array(const CATUnicodeString& name, const std::vector<int16_t>& value);
    HRESULT WriteInt16Array(const CATUnicodeString& name, int16_t* value, size_t length);

    HRESULT WriteUint16Array(const char* name, const std::vector<uint16_t>& values);
    HRESULT WriteUint16Array(const char* name, uint16_t* values, size_t length);
    HRESULT WriteUint16Array(const CATUnicodeString& name, const std::vector<uint16_t>& values);
    HRESULT WriteUint16Array(const CATUnicodeString& name, uint16_t* values, size_t length);

    HRESULT WriteInt32Array(const char* name, const std::vector<int32_t>& values);
    HRESULT WriteInt32Array(const char* name, int32_t* values, size_t length);
    HRESULT WriteInt32Array(const CATUnicodeString& name, const std::vector<int32_t>& values);
    HRESULT WriteInt32Array(const CATUnicodeString& name, int32_t* values, size_t length);

    HRESULT WriteUint32Array(const char* name, const std::vector<uint32_t>& values);
    HRESULT WriteUint32Array(const char* name, uint32_t* values, size_t length);
    HRESULT WriteUint32Array(const CATUnicodeString& name, const std::vector<uint32_t>& values);
    HRESULT WriteUint32Array(const CATUnicodeString& name, uint32_t* values, size_t length);

    HRESULT WriteInt64Array(const char* name, const std::vector<int64_t>& values);
    HRESULT WriteInt64Array(const char* name, int64_t* values, size_t length);
    HRESULT WriteInt64Array(const CATUnicodeString& name, const std::vector<int64_t>& values);
    HRESULT WriteInt64Array(const CATUnicodeString& name, int64_t* values, size_t length);

    HRESULT WriteUint64Array(const char* name, const std::vector<uint64_t>& values);
    HRESULT WriteUint64Array(const char* name, uint64_t* values, size_t length);
    HRESULT WriteUint64Array(const CATUnicodeString& name, const std::vector<uint64_t>& values);
    HRESULT WriteUint64Array(const CATUnicodeString& name, uint64_t* values, size_t length);

    HRESULT WriteFloatArray(const char* name, const std::vector<float>& values);
    HRESULT WriteFloatArray(const char* name, float* values, size_t length);
    HRESULT WriteFloatArray(const CATUnicodeString& name, const std::vector<float>& values);
    HRESULT WriteFloatArray(const CATUnicodeString& name, float* values, size_t length);

    HRESULT WriteDoubleArray(const char* name, const std::vector<double>& values);
    HRESULT WriteDoubleArray(const char* name, double* values, size_t length);
    HRESULT WriteDoubleArray(const CATUnicodeString& name, const std::vector<double>& values);
    HRESULT WriteDoubleArray(const CATUnicodeString& name, double* values, size_t length);

    HRESULT WriteBufferArray(const char* name, const std::vector<EK::Binary>& values);
    HRESULT WriteBufferArray(const CATUnicodeString& name, const std::vector<EK::Binary>& values);

    HRESULT WriteParametersArray(const char* name, const CATUnicodeString& type, const std::vector<Parameters>& values);
    HRESULT WriteParametersArray(const char* name, const CATUnicodeString& type, const std::vector<std::unique_ptr<Parameters>>& values);
    HRESULT WriteParametersArray(const CATUnicodeString& name, const CATUnicodeString& type, const std::vector<Parameters>& values);
    HRESULT WriteParametersArray(const CATUnicodeString& name, const CATUnicodeString& type, const std::vector<std::unique_ptr<Parameters>>& values);

    [[deprecated("CSI COMMAND BINDER - DEPRECATED - 2020/04/14 - Use methods with std::vector<Parameters>& or std::vector<std::unique_ptr<Parameters>>& signature instead [2019/06/05]")]]
    HRESULT WriteParametersArray(const CATUnicodeString& name, const std::vector<Parameters*>& values);

    /** Read & Write Methods for user custom types
      You must delete all pointers returned by Read method after use
    */
    template <class T>
    HRESULT ReadObject(const CATUnicodeString& name, const CATUnicodeString& type, std::unique_ptr<T>& value) const;
    template <class T>
    HRESULT ReadObject(const CATUnicodeString& name, const CATUnicodeString& type, T*& value) const;
    template <class T>
    HRESULT ReadObjectArray(const CATUnicodeString& name, const CATUnicodeString& type, std::vector<std::unique_ptr<T>>& value) const;
    template <class T>
    HRESULT ReadObjectArray(const CATUnicodeString& name, const CATUnicodeString& type, std::vector<T*>& value) const;
    template <class T>
    HRESULT WriteObject(const CATUnicodeString& name, const CATUnicodeString& type, T const& value);
    template <class T>
    HRESULT WriteAsObject(const CATUnicodeString &type, T const &value);
    template <class T>
    HRESULT WriteObjectArray(const CATUnicodeString& name, const CATUnicodeString& type, const std::vector<std::unique_ptr<T>>& value);
    template <class T>
    HRESULT WriteObjectArray(const CATUnicodeString& name, const CATUnicodeString& type, const std::vector<T*>& value);
    template <class T>
    HRESULT WriteObjectArray(const CATUnicodeString& name, const CATUnicodeString& type, T** value, size_t length);

    /** Read a property as a reference on an object of a specified type
      Read a reference of an object allocated in the heap of the current process
      The reference will only be retrieved if the write method has been called in the same process
      The type will use to check written reference is from the same type
      \param name name of the property to read
      \param type name of the type to read
      \param value reference on the read object
      \return S_OK if the property has been found and the reference of the specified object type has been written in the same process, E_FAIL otherwise
    */
    template <class T>
    HRESULT ReadObjectAsReference(const char* name, const CATUnicodeString& type, T*& value) const;
    template <class T>
    HRESULT ReadObjectAsReference(const CATUnicodeString& name, const CATUnicodeString& type, T*& value) const;

    /** Write a property as a reference on an object of a specified type
      Write a reference of an object allocated in the heap of the current process
      The reference will only be retrieved if the read method is called in the same process
      \param name name of the property to write
      \param type name of the type to write
      \param value reference on the object to write
      \return S_OK
    */
    template <class T>
    HRESULT WriteObjectAsReference(const char* name, const CATUnicodeString& type, const T& value);
    template <class T>
    HRESULT WriteObjectAsReference(const CATUnicodeString& name, const CATUnicodeString& type, const T& value);

    /** Return the declarative type of this parameters
      \return name of the declarative type, "Parameters" otherwise
    */
    CATUnicodeString GetObjectType() const;

    /** Unserialize this parameters to return an object
      Will use unserialize method of the specified declarative type
      Unserialize method must be defined for the specified type
      \param type name of the declarative type to unserialize the parameters
      \return pointer on the unserialized object if succeeded, nullptr otherwise
    */
    template <class T>
    T* ReadAsObject(const CATUnicodeString& type) const;

    /** Set the declarative type for this parameters
      Will set a type name to this Parameters after checking the content is compliant with the specified type
      \param type name of the type to define for this parameters
      \return S_OK if the parameters content is compliant with the specified type, E_FAIL othewise
    */
    HRESULT DeclareAsObject(const CATUnicodeString& type);

    /** Unset the type name for this parameters
      Will removed the previously defined type name
    */
    void DeclareAsParameters();

    /** Begin iterator to parse properties */
    ParametersIterator Begin() const;
    ParametersIterator begin() const;

    /** End iterator to parse properties */
    ParametersIterator End() const;
    ParametersIterator end() const;

    /** Create an empty parameters */
    Parameters CreateEmptyParameters() const;
    Parameters* NewEmptyParameters() const;

    bool operator==(const Parameters& rhs) const;

    explicit Parameters(const TypesImpl& typesImpl);
    Parameters(const TypesImpl& typesImpl, const CATUnicodeString& typeName);

  private:
    HRESULT WriteObjectAsReferencePrivate(const CATUnicodeString& name, const CATUnicodeString& type, void* value);
    HRESULT ReadObjectAsReferencePrivate(const CATUnicodeString& name, const CATUnicodeString& type, void*& value) const;
    HRESULT WriteObjectPrivate(const CATUnicodeString& name, const CATUnicodeString& type, const Parameters& value);

    template <typename CustomTypeIt>
    HRESULT WriteObjectArray(const CATUnicodeString& name, const CATUnicodeString& type, CustomTypeIt first, CustomTypeIt last);
    HRESULT WriteObjectArrayPrivate(const CATUnicodeString& name, const CATUnicodeString& type, const std::vector<std::unique_ptr<CSI::Parameters>>& value);

    void* GetSerializeFunction(const CATUnicodeString& type, const type_id_t& typeIdx) const;
    void* GetUnserializeFunction(const Parameters& parameters, const CATUnicodeString& type, const type_id_t& typeIdx) const;

    template <class T>
    HRESULT Serialize(T const& value, const CATUnicodeString& type, Parameters& parameters) const;
    template <class T>
    T* Unserialize(const Parameters& parameters, const CATUnicodeString& type) const;

    HRESULT PublishError(const CATUnicodeString& str) const;

  private:
    ParametersImpl* pImpl_;

    friend ParametersImpl& getImpl(const Parameters& parameters);
  };
}

#include "CSIParameters.hxx"

// TO REVIEW TVS 2017/06: FIXME remove those includes when test user are cleaned
#ifndef CSITypes_H // TO REVIEW TVS 2017/06: this define is here to prevent incomplete Types type under linux, when a file directly includes CSITypes.h
#include "CSINode.h"
#include "EKLib.h"
#endif

// - GEOBorehole/GEOBorConverters.m/src/GEOBorConvertToCSI.cpp
// - SMADdaAppService/SMADdaAppService.m/LocalInterfaces/SMAEDdaCSIMsgShare.h
// - SWXCSSheetMetalCommandServices/ProtectedInterfaces/SWXCSSmOperation.h
// - SWXCSSheetMetalCommandServices/ProtectedInterfaces/SWXCSSmWallCommonOperation.h
// - SWXCSTopology/SWXCSTpServices.m/src/SWXCSLoadCaseManagerOperation.cpp
// - SWXCSCommandServices/SWXMoFeatureCommands.m/src/SWXCSConvertToSketchOperation.cpp
// - SWXCSCommandServices/SWXSketchCommands.m/LocalInterfaces/SWXSkServiceUpdateSketch.h
// - SWXCSXFrame/PrivateInterfaces/SWXCSXfCreateSectionOperation.h
// - CSISceneManager.tst/CSISceneServiceTestCmds.m/src/CSISceneDebug_Internal_CompareParamsWithJsonFile.cpp
// - SMAMpsInterfaces.tst/MPMSModule.m/src/MPMSDataModelTools.cpp
// - SMACfdCsiSamples.tst/SMACfdCsiSampleCosimService.m/LocalInterfaces/SMACfdCsiSampleCosimPoolData.h
// - SMADdaAppService.tst/SMADdaCSICommandTstBatch.m/LocalInterfaces/SMAEDdaCSIAppServiceTest.h
// - SMADdaAppService.tst/SMADdaCSICommandTstBatch.m/LocalInterfaces/SMAEDdaOpenSimulationTest.h
// - SMAPiaModel.tst/SMAPiaCSIWrapper.m/LocalInterfaces/SMAPiaCSIWrapperMembers.h
#include <map>
using DummyCSIParametersMap = std::map<int, int>; // Silence EKLint

#endif
