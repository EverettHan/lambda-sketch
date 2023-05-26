#ifndef PLMIReplaceBridge_H
#define PLMIReplaceBridge_H

// Copyright Dassault Systemes 2012

/**
* @level Protected
* @usage U1
*/

#include "CATPLMModelerBaseInterfaces.h"
#include "CATBaseUnknown.h"

class CATListPtrCATBaseUnknown;
class CATUFOServiceOutput;

/**
* This class provides the bridge for the replace operator
*/
class ExportedByCATPLMModelerBaseInterfaces PLMIReplaceBridge
{
public:
  /**
  * Execute and log a Replace
  * @see PLMReplaceOperator::Replace
  */
  virtual HRESULT Replace(CATListPtrCATBaseUnknown const & iListOfInstanceToReplace,
    CATBaseUnknown* ipiRepresentationOrReferenceToInstanciate,
    CATListPtrCATBaseUnknown & oListOfNewInstance,
    CATUFOServiceOutput *& opOutputParameters) = 0;
};

#endif
