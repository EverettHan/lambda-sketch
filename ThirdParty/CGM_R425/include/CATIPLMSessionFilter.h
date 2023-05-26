//===================================================================
// COPYRIGHT Dassault Systemes 2009
//===================================================================
//
// CATIPLMSessionFilter
//
//===================================================================
//
//
//===================================================================
//
// 2012 Creation FBN
// 
//===================================================================

/**
* @level Protected
* @usage U1
*/

#ifndef CATIPLMSessionFilter_H
#define CATIPLMSessionFilter_H

#include "CATPLMIntegrationInterfaces.h"

#include "CATBaseUnknown.h"
#include "CATIAV5Level.h"

class CATIPLMQueryFilter;
class CATError;
template<typename T> class CATOmxList;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMIntegrationInterfaces IID IID_CATIPLMSessionFilter;
#else
extern "C" const IID IID_CATIPLMSessionFilter;
#endif

class ExportedByCATPLMIntegrationInterfaces CATIPLMSessionFilter : public CATBaseUnknown
{
  CATDeclareInterface;
public:
  /**
  * @DEPRECATED. Use GetFilterWithErrors instead.
  */
  virtual HRESULT GetFilter(CATIPLMQueryFilter *&oFilter) = 0;

  /**
  * @nodoc
  */
  virtual HRESULT GetFilterWithErrors(CATIPLMQueryFilter *&oFilter, CATOmxList<CATError> &oErrors) = 0;

  /**
  * @nodoc
  */
  virtual HRESULT SetFilter(CATIPLMQueryFilter *iFilter) = 0;
};
#endif
