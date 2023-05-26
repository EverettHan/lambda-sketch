#ifndef CSIParametersIterator_H
#define CSIParametersIterator_H

#include "CSICommandBinderModule.h"
#include "CATSysErrorDef.h"
#include <stddef.h>
#include <string>

class CATUnicodeString;

namespace CSI
{
class ParametersImpl;
class ParametersIteratorImpl;

class ExportedByCSIBinderModule ParametersIterator
{
public:
   ParametersIterator() = default;
   ParametersIterator(const ParametersImpl& param, bool begin);
  ~ParametersIterator();

  ParametersIterator(const ParametersIterator& rhs);
  ParametersIterator& operator=(const ParametersIterator& rhs);

  bool operator==(const ParametersIterator& rhs) const;
  bool operator!=(const ParametersIterator& rhs) const;
  ParametersIterator& operator++();
  ParametersIterator operator++(int);
  ParametersIterator& operator*();

  /** return name of current property */
  CATUnicodeString GetName() const;
  const std::string& GetNameAsString() const;

  /** return size of internal EK::Binary*/
  uint64_t GetSize() const;

  /** return type of current property */
  CATUnicodeString GetType() const;
  std::string GetTypeAsString() const;

  /** return true if current property is an object */
  bool IsObject() const;

  /** return start iterator on current Object property
  valid only if current property is an object.
  (check with Parameters::IsObject())
  */
  ParametersIterator ObjectBegin() const;

  /** return end iterator on current Object property
  valid only if current property is an object.
  (check with Parameters::IsObject())
  */
  ParametersIterator ObjectEnd() const;

  /** return true if current property is an object array*/
  bool IsObjectArray() const;

  bool CheckType(const std::string& rootType, bool isArray) const;

  HRESULT GetValueAsString(CATUnicodeString& value) const;
  HRESULT GetValueAsString(CATUnicodeString& value, const CATUnicodeString& stringDelimiter) const;

private:
  ParametersIteratorImpl* impl_ = nullptr;
};
}

#endif
