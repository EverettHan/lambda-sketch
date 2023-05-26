/* -*-c++-*- */
// COPYRIGHT Dassault Systemes 2004
/**
* @level Protected
* @usage U3
*/
#ifndef CATIPLMIntegRecordRead_H
#define CATIPLMIntegRecordRead_H

#include "CATPLMIntegrationInterfaces.h"
#include "CATBaseUnknown.h"
#include "CATCollec.h"

class CATUnicodeString;
class CATComponentId;
class CATIPLMAttrRead;
class CATVVSUrl;
class CATString;
class _SEQUENCE_octet;
class CATPLMSemanticRelationData;
class CATListValCATString;
class CATIPLMError;
class CATPLMStreamDescriptor;
class CATListPtrCATPLMStreamDescriptor;
class CATPLMTypeId;
class CATLISTV(CATPLMTypeId);
class CATIPLMRecordRead;
class CATPLMPathDataH;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMIntegrationInterfaces IID IID_CATIPLMIntegRecordRead;
#else
extern "C" const IID IID_CATIPLMIntegRecordRead;
#endif

/**
* This integration interface is dedicated to be exposed to the application factories. Its purpose
* is to encapsulate the behavior described in the @href CATPLMServices.CATIPLMRecordRead interface 
* to expose elements through their @href CATComponentId.
* WARNING:JBB:29042004: Major code duplication.
* The two interfaces @href CATIPLMIntegRecordRead and @href CATIPLMRecordRead should inherit from 
* a common abstract class to avoid re-defining the same protocol methods.
*/
class ExportedByCATPLMIntegrationInterfaces CATIPLMIntegRecordRead: public CATBaseUnknown
{
  CATDeclareInterface;

public:

  /** 
  * Retrieve the component associated to the record.
  * @param oCompId
  *   The component associated to the record. QueryObjectInSession on this component may fail.
  * @return 
  * <br><b>Legal values</b>
  *   <dt>S_OK</dt>  
  *   <dd>The component the record deals with an allocated cell in the associated dataspace.</dd>
  *   <dt>S_FALSE</dt>  
  *   <dd>The component the record deals with is not available in the associated dataspace. </dd>
  *   <dt>E_FAIL</dt>  
  *   <dd>System error</dd>
  * <br>
  */
  virtual HRESULT GetComponentId( CATComponentId & oCompId ) = 0;

  /**
  * @deprecated V5R202
  * @use CATIPLMIntegRecordRead#GetAttributeAccess
  */
  virtual HRESULT GetAttributeAccess( const CATString * iApplication, CATIPLMAttrRead ** oAttrAccess ) = 0;

  /**
  * @see CATPLMServices.CATIPLMRecordRead#GetAttributeAccess
  * @param  oAttrAccess [out, CATBaseUnknown#Release]
  * @param  iExtension [in]
  *   Provide CATPLMTypeId_Null if not an extension. 
  */
  virtual HRESULT GetAttributeAccess( CATIPLMAttrRead ** oAttrAccess, const CATPLMTypeId & iExtension ) = 0;

  /**
  * @see CATPLMServices.CATIPLMRecordRead#GetStreamAccess
  */
  virtual HRESULT GetStreamAccess( CATPLMStreamDescriptor * iStreamDesc, CATVVSUrl ** oUrl ) = 0;

  /**
  * @see CATPLMServices.CATIPLMRecordRead#ListStreamDescriptors
  */
  virtual HRESULT ListStreamDescriptors( CATListPtrCATPLMStreamDescriptor * oStreamDescList ) = 0;

  /**
  * @see CATPLMServices.CATIPLMRecordRead#GetAssociatedObject
  */
  virtual HRESULT GetAssociatedObject( const CATString * iAttrType, CATComponentId & oRelatedObject ) = 0;

  /**
  * @see CATPLMServices.CATIPLMRecordRead#SemanticRelationCount
  */
  virtual HRESULT SemanticRelationCount( int * oNbRelations ) = 0;

  /**
  * @see CATPLMServices.CATIPLMRecordRead#GetSemanticRelation
  * @param  oRelationData [out, CATBaseUnknown#Release]
  */
  virtual HRESULT GetSemanticRelation( int iIndex, CATComponentId & oCID, CATPLMSemanticRelationData ** oRelationData ) = 0;

  /**
  * @see CATPLMServices.CATIPLMRecordRead#ListExtensionTypes
  */
  virtual HRESULT ListExtensionTypes( CATLISTV(CATPLMTypeId) & oExtensions ) = 0;

  virtual HRESULT GetRecord(CATIPLMRecordRead*& oRecord);
};

#endif
