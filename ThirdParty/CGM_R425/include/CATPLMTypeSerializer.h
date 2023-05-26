/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2011
/**
 * @level Protected
 * @usage U1
 */
#ifndef CATPLMTypeSerializer_H
#define CATPLMTypeSerializer_H

#include "CATPLMIntegrationBase.h"
#include "CATPLMTypeH.h"
#include "CATBaseUnknown.h"
class CATUnicodeString;

/**
 * Class enabling to manage the serialization of a PLMType.
 *
 * <br><b>Role</b>: Given a PLM type, this class enables to compute its serialization or build a PLMType from its key.
 */
class ExportedByCATPLMIntegrationBase CATPLMTypeSerializer
{
public:
  CATPLMTypeSerializer( const CATPLMTypeH & iPLMType );
  CATPLMTypeSerializer();
  virtual ~CATPLMTypeSerializer();

/**
 * @ nodoc
 */
  HRESULT SerializeType( CATUnicodeString & oPLMTypeKey );
  HRESULT BuildFromSerialized( const CATUnicodeString & iPLMTypeKey );

  HRESULT GetPLMType( CATPLMTypeH & oPLMType );

private:
  CATPLMTypeSerializer( const CATPLMTypeSerializer & );
  CATPLMTypeSerializer & operator =( const CATPLMTypeSerializer & );

private:
  CATPLMTypeH _PLMType;
};
#endif
