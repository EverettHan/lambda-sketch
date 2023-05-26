#ifndef CATIPLMAttributeBlockWriter_h
#define CATIPLMAttributeBlockWriter_h

/**
* @level Protected
* @usage U3
*/
#include "CATPLMServicesItf.h"
#include "CATBaseUnknown.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMServicesItf IID IID_CATIPLMAttributeBlockWriter;
#else
extern "C" const IID IID_CATIPLMAttributeBlockWriter ;
#endif

class CATOmxKeyValueBlock;
class CATString;
class CATPLMTypeId;

class ExportedByCATPLMServicesItf CATIPLMAttributeBlockWriter : public CATBaseUnknown
{
  CATDeclareInterface;
public:
    /**
    * Sets the block of attribute.
    * @param iAttrBlock [in]
    *   The block of attributes.
    * @param iPLMExtension [in]
    *   The extension on which the block should be set. If NULL, the block is the main attribute block.
    * @return
    *   <code>S_OK</code> if everything ran ok, otherwise E_FAIL.     
    */
    virtual HRESULT SetAttributeBlock ( const CATOmxKeyValueBlock & iAttrBlock, const CATString * iPLMExtension = NULL ) = 0;

    /**
    * Sets the block of attribute.
    * @param iAttrBlock [in]
    *   The block of attributes.
    * @param iPLMExtension [in]
    *   The extension on which the block should be accessed. If CATPLMTypeId_Null, the block is the main attribute block.
    * @return
    *   <code>S_OK</code> if everything ran ok, otherwise E_FAIL.     
    */
    virtual HRESULT SetAttributeBlock ( const CATOmxKeyValueBlock & iAttrBlock , const CATPLMTypeId &iPLMExtension ) = 0;
};
CATDeclareHandler(CATIPLMAttributeBlockWriter, CATBaseUnknown);
#endif
