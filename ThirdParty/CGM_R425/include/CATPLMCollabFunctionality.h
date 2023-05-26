/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2011
/**
 * @level Protected
 * @usage U1
 */
#ifndef CATPLMCollabFunctionality_H
#define CATPLMCollabFunctionality_H

#include "CATPLMIntegrationBase.h"
#include "CATPLMFunctionalityAvailability.h"
#include "CATBaseUnknown.h"
#include "CATComponentId.h"
class CATPLMTypeH;

class ExportedByCATPLMIntegrationBase CATPLMCollabFunctionality: public CATPLMFunctionalityAvailability
{
public:
  CATPLMCollabFunctionality( const CATComponentId & iComponent );
  virtual ~CATPLMCollabFunctionality();
  HRESULT AnalyzeType( const CATPLMTypeH & iPLMType );

private:
  CATPLMCollabFunctionality( const CATPLMCollabFunctionality & );
  CATPLMCollabFunctionality & operator =( const CATPLMCollabFunctionality & );

  CATComponentId _Component;
};
#endif
