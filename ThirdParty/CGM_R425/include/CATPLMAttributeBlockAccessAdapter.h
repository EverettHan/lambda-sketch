// COPYRIGHT Dassault Systemes 2009
//===================================================================
//
// CATPLMAttributeBlockAccessAdapter.h
// Define the CATPLMAttributeBlockAccessAdapter adapter
//
//===================================================================
//
// Usage notes:
//   adapter
//
//===================================================================
//
//  Feb 2009  Creation: EPB
//
//===================================================================

/**
* @level Protected
* @usage U2
*/

#ifndef CATPLMAttributeBlockAccessAdapter_H
#define CATPLMAttributeBlockAccessAdapter_H

#include "CATPLMImplAdapterClass.h"// ExportedByCATPLMImplAdapterClass

#include "CATIPLMAttributeBlockAccess.h"

#include "CATListOfCATString.h"
#include "CATPLMAttribute.h"

class CATOmxKeyValueBlock;
class CATOmxAny;
class CATOmxKeyString;
class CATIPLMRecordRead;
class CATPLMAttribute;
class CATIPLMAttrRead;
class CATIPLMCompMetaDataService;
class CATPLMType;
class CATIPLMAttrWrite;

/**
* gives an adapter to the interface CATIPLMAttributeBlockAccess
* Providers can use this adapter as an implementation base class.
*/
class ExportedByCATPLMImplAdapterClass CATPLMAttributeBlockAccessAdapter : public CATIPLMAttributeBlockAccess
{
public:
  CATPLMAttributeBlockAccessAdapter ( const CATIPLMRecordRead *iRecord);
  virtual ~CATPLMAttributeBlockAccessAdapter();

  virtual HRESULT GetAttributeBlock ( CATOmxKeyValueBlock &oAttrBlock, const CATString * iPLMExtension );

  virtual HRESULT GetAttributeBlock ( CATOmxKeyValueBlock &oAttrBlock , const CATPLMTypeId &iPLMExtension );

  virtual HRESULT GetAttrBlock ( CATOmxKeyValueBlock &oAttrBlock , CATPLMType* iPLMExtension );

  // This method can be used as is, in this case, you should create a CATPLMAttributeBlockAccessAdapter
  // with a NULL iRecord
  virtual HRESULT FillAttrBlock ( CATOmxKeyValueBlock &oAttrBlock, CATIPLMAttrRead *pAttrRead, CATPLMType *iPLMType );

  //virtual HRESULT SetValueToCurrentAttrBlock(CATOmxKeyString &kvKey, CATOmxAny &kvVal, unsigned int &kvMask);

  //virtual HRESULT CreateAttrBlockForExtensionIfNeeded(CATString* iString) ;

private:
  CATPLMAttributeBlockAccessAdapter (CATPLMAttributeBlockAccessAdapter &);
  CATPLMAttributeBlockAccessAdapter& operator=(CATPLMAttributeBlockAccessAdapter&);

  HRESULT FillAttrBlock ( CATOmxKeyValueBlock &oAttrBlock, const CATString *iExtension );
  HRESULT CopyAttribute(CATIPLMAttrRead *iAttrRead, CATPLMType *iPLMType, CATString &iAttr, CATIPLMAttrWrite * iAttrWrite);
  HRESULT GetModelerAttributeType (CATPLMType *iType, CATString &iAttrId, AttrTypes &oType, CATBoolean &oIsMulti, CATBoolean &oIsEnum);

  CATIPLMRecordRead *_pRecord;
  CATListValCATString *_pExtensionName;
  CATOmxKeyValueBlock *_pTbAttrBlock;
};
#endif
