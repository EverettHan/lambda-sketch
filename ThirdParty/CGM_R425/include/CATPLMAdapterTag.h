// COPYRIGHT Dassault Systemes 2010
//===================================================================
//
// CATPLMAdapterTag.h
//
//===================================================================
//
// Usage notes:
//
//  May 2010  Creation: LEC
//===================================================================
#ifndef CATPLMAdapterTag_H
#define CATPLMAdapterTag_H

#include "CATOmxSharable.h"

#include "CATPLMServicesItf.h"

#include "CATUnicodeString.h"
#include "CATOmxList.h"
#include "CATOmxIter.h"


/**
* @level Protected
* @usage U2
*/

/** Acces to tags returned by providers during a PLMAdapter query. */
class ExportedByCATPLMServicesItf CATPLMAdapterTag : public CATOmxSharable
{
public:

  class CATPLMTagValue : public CATOmxSharable
  {
  public:
    CATUnicodeString _Value;
    int _Count;
  };

  enum TagType
  {
    Unset = -1
   ,Implicit = 1
   ,Explicit = 2
  };

  /** 
  * Create a tag with a input defintion.
  */
  CATPLMAdapterTag(const CATUnicodeString & iSixwStr, const CATUnicodeString & iDataType, 
                   const CATUnicodeString &iFieldName, TagType iType );
  virtual ~CATPLMAdapterTag();

  /** 
   * Add a value to a Tag.
   * Note : No duplicate check
   * @return
   *     E_FAIL : if iCountOfValue <= 0
  */
  HRESULT AddValue ( const CATUnicodeString & iTagValue, int iCountOfValue );


  /** 
  * Get tag definition.
  */
  HRESULT GetTagDefinition (CATUnicodeString & oSixwStr, CATUnicodeString & oDataType, 
                            CATUnicodeString &oFieldName, TagType &oType ) const;


  /** 
  * Get an iterator on values of this tag.
  */
  HRESULT GetValueIterator ( CATOmxIter <CATPLMAdapterTag::CATPLMTagValue> &oValueIterator) const;

private:
  CATUnicodeString _SixwStr, _DataType, _FieldName;
  CATOmxList <CATPLMAdapterTag::CATPLMTagValue> _Values;
  TagType _Type;
};

#endif
