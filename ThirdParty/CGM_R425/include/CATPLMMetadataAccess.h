/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2010
/**
 * @level Protected
 * @usage U1
 */
#ifndef CATPLMMetadataAccess_H
#define CATPLMMetadataAccess_H

#include "CATPLMIntegrationBase.h"
#include "CATErrorDefs.h"
#include "CATPLMType.h"
#include "CATPLMTypeH.h"
class CATString;
class CATPLMTypeId;
class CATPLMRepositoryName;

class ExportedByCATPLMIntegrationBase CATPLMMetadataAccess
{
public:
  CATPLMMetadataAccess( const CATPLMTypeH & iType );
  CATPLMMetadataAccess( const CATPLMType * iPLMType );
  CATPLMMetadataAccess( const CATPLMTypeId & iPLMType, const CATPLMRepositoryName & iRepositoryName=CATPLMRepositoryName_Null );
  virtual ~CATPLMMetadataAccess();

/**
 * @nodoc
 */
  HRESULT HasAttribute( const CATString & iAttributeId );

/**
 * @nodoc
 */
  HRESULT GetPLMType( CATPLMType *& oPLMType );

  /**
   * @nodoc
   */
  static CATPLMType * GetPLMTypeFromTypeId(const CATPLMTypeId & iTypeId, const CATPLMRepositoryName & iRepository=CATPLMRepositoryName_Null, CATBoolean SearchInClient = TRUE);

private:
  CATPLMMetadataAccess( const CATPLMMetadataAccess & );
  CATPLMMetadataAccess & operator =( const CATPLMMetadataAccess & );

private:
  CATPLMType * _Type;
};
#endif
