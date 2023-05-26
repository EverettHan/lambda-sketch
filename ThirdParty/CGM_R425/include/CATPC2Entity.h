#ifndef CATPC2Entity_H
#define CATPC2Entity_H

/**
 * @level Protected
 * @usage U3
 */

#include "CATBaseUnknown.h"

class CATUnicodeString;
class CATOmxAny;
class CATOmxKeyString;

/** @see SetValueAt */
#define PC2_APPEND (-28112018)

/**
 * Access to the attributes of PC2 (PLM Client Core) object.
 */
class CATPC2Entity : public CATBaseUnknown
{
public:
  /**
   * Retrieve the value of a "simple" attribute (multi-valuated or not)
   * @param iKey
   *   the name of the attribute
   *   in .metadata files there are sections looking like
   *      <Simple Name="xxx" ... />
   *   iKey must match this "xxx"
   * @param oValue
   *   the value or an empty CATOmxAny in case of failure
   *   you can test for empty CATOmxAny with expressions 'xxx.Kind() == omx_void' or alternatively 'xxx == CATOmxAny()'
   *   depending on the type of your attribute, the value can be extracted using the following means:
   *     1) mono-valuated
   *       - Boolean                => CATOmxAny::TryGetBoolean
   *       - Integer (except enum)  => CATOmxAny::TryGetInt
   *       - Double                 => CATOmxAny::TryGetDouble
   *       - String                 => CATOmxAny::TryGetString
   *       - Date                   => CATOmxAny::TryGetDate (returns actually a time_t)
   *       - Enum                   => CATOmxAny::TryGetEnum (notice that enum are declared as Integer in .metadata files)
   *       - Binary                 => CATPC2Utils::UnboxBinary
   *     2) multi-valuated
   *       - Integer (except enum)  =>
   *           CATOmxAny::operator>>(const CATOmxAny& in, CATOmxArray<int>& out) from CATOmxAnyArrayConvert.h
   *           CATOmxAny::operator>>(const CATOmxAny& in, CATRawCollint&    out) from CATOmxAnyConvert.h
   *       - Double
   *           CATOmxAny::operator>>(const CATOmxAny& in, CATOmxArray<double>& out) from CATOmxAnyArrayConvert.h
   *           CATOmxAny::operator>>(const CATOmxAny& in, CATRawColldouble& out)    from CATOmxAnyConvert.h
   *       - String
   *           CATOmxAny::operator>>(const CATOmxAny& in, CATOmxArray<CATUnicodeString>& out) from CATOmxAnyArrayConvert.h
   *           CATOmxAny::operator>>(const CATOmxAny& in, CATListValCATUnicodeString& out)    from CATOmxAnyConvert.h
   *       - other types are unused and not worth mentioning
   * @return
   *   S_OK
   *   E_TOS_UNSET:    attribute is unset
   *   E_KEYNOTFOUND:  the object type doesnot define this attribute
   *   E_NOLOCALVALUE: the attribute is not present on this instance
   *   E_ACCESSDENIED: the password is incorrect
   *   ...
   *
   * does not work on 'link' attributes (use CATIPC2Component::GetLink/CATIPC2Component::GetLinkAt)
   *
   * If the attribute is described with the property
   *    Protection="Internal"
   * in .metadata file then the modeler password (@see CATIPC2Object::SetPassword) is required
   */
  virtual CATOmxAny GetValue(const CATOmxKeyString& iKey) const = 0;
  virtual HRESULT GetValue(const CATOmxKeyString& iKey, CATOmxAny& oValue) const = 0;

  /**
   * Retrieve the value of an attribute at a given index.
   * @param iKey
   *   @see GetValue
   * @param iIndex
   *   the index to return
   *   it must be within [1,GetSize()] range
   *   iIndex == 1 is autorized for single (not multi-valuated) attributes
   *
   * @see GetValue for more details.
   */
  virtual CATOmxAny GetValueAt(const CATOmxKeyString& iKey, int iIndex) const = 0;

  /**
  * Retrieve the size of an attribute value
  * @param iKey
  *    @see GetValue
  * @return
  *   the size, negative in case of failure
  *   notice that for a mono-valuated it returns 1, not the size of the underlying string or binary
  *
  * notice that this method works also on 'link' attributes (@see CATIPC2Component::GetLink)
  * and that GetSize will return 0 for an unset mono-valuated link attribute
  */
  virtual int GetSize(const CATOmxKeyString& iKey) const = 0;

  /**
  * Set the value of a "simple" attribute (multi-valuated or not)
  * @param iKey
  *   @see GetValue
  * @param iValue
  *   the new value
  *   depending on the type of your attribute, the input value can be built using the following means:
  *     1) mono-valuated
  *       - Boolean                => CATOmxAny::CreateBoolean
  *       - Integer (except enum)  => CATOmxAny::CreateInt
  *       - Double                 => CATOmxAny::CreateDouble
  *       - String                 => CATOmxAny::CreateString
  *       - Date                   => CATOmxAny::CreateTime
  *       - Enum                   => CATOmxAny::CreateEnum or CATOmxAny::CreateString
  *       - Binary                 => CATPC2Utils::BoxBinary
  *     2) multi-valuated
  *       - Integer (except enum):
  *           CATOmxAny::operator<<(CATOmxAny& out, const CATOmxArray<int>& in) from CATOmxAnyArrayConvert.h
  *           CATOmxAny::operator<<(CATOmxAny& out, const CATRawCollint&    in) from CATOmxAnyConvert.h
  *       - Double:
  *           CATOmxAny::operator<<(CATOmxAny& out, CATOmxArray<double>& in) from CATOmxAnyArrayConvert.h
  *           CATOmxAny::operator<<(CATOmxAny& out, CATRawColldouble&    in) from CATOmxAnyConvert.h
  *       - String:
  *           CATOmxAny::operator<<(CATOmxAny& out, const CATOmxArray<CATUnicodeString>& in) from CATOmxAnyArrayConvert.h
  *           CATOmxAny::operator<<(CATOmxAny& out, const CATListValCATUnicodeString&    in) from CATOmxAnyConvert.h
  *       - other types are unused and not worth mentioning
  *
  * @return
  *   S_OK on success
  *   E_* on failure (failure return codes are unspecified and provided for debugging purpose)
  *
  * does not work on 'link' attributes (use CATIPC2Object::GetLink/CATIPC2Object::GetLinkAt)
  *
  * @see GetValue for more details.
  */
  virtual HRESULT SetValue(const CATOmxKeyString& iKey, const CATOmxAny& iValue) = 0;

  /**
  * Set the value of a "simple" attribute (multi-valuated or not) at a given position
  * @param iKey
  *   @see GetValue
  * @param iIndex
  *   the position to modify
  *   - for a mono-valuated attribute it must 1
  *   - for a multi-valuated attribute it must be
  *       in order to update an existing position, iIndex must be within [1, GetSize() ] range,.
  *       in order to append an element at the end of the list, use PC2_APPEND or alternatively GetSize()+1.
  * @param iValue
  *   @see SetValue
  * @return
  *   @see SetValue
  *
  * @see GetValue & SetValue for more details.
  */
  virtual HRESULT SetValueAt(const CATOmxKeyString& iKey, int iIndex, const CATOmxAny& iValue) = 0;

  //this is not an OM interface !
  static CATMetaClass* __stdcall MetaObject() = delete;
  static const CLSID& __stdcall ClassId() = delete;
};

#endif
