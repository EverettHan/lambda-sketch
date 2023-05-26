#ifndef PLMReplaceOperator_H
#define PLMReplaceOperator_H

// Copyright Dassault Systemes 2012

/**
* @level Protected
* @usage U1
*/

#include "CATPLMModelerBaseInterfaces.h"
#include "CATBaseUnknown.h"
#include "CATOmxSR.h"

class PLMIReplaceBridge;
class CATListPtrCATBaseUnknown;
class CATUFOServiceOutput;

/**
* This class provides a Replace operator
*/
class ExportedByCATPLMModelerBaseInterfaces PLMReplaceOperator
{
public:
  PLMReplaceOperator() {}
  ~PLMReplaceOperator() {}


  /**
  * Replace instances or repinstances of a reference or representation
  * by instances or repinstances of another reference or representation
  *
  * @param iListOfInstanceToDuplicate
  *     List of pointer on Instances or RepInstances (to be replaced).
  *
  * @param ipiRepresentationOrReferenceToInstanciate
  *     Pointer on the Representation or Reference that will be instanciated.
  *
  * @param oListOfNewInstance
  *     List of pointer on newly created Instances or RepInstances.
  *
  * @param opOutputParameters  [out, CATBaseUnknown#Release]
  *   Output information for reroute
  *
  * @return
  *    <li> S_OK new Instance(s) or RepInstance(s) created
  *    <li> E_FAIL otherwise
  */
  HRESULT Replace(const CATListPtrCATBaseUnknown& iListOfInstanceToReplace, CATBaseUnknown *& ipiRepresentationOrReferenceToInstanciate, CATListPtrCATBaseUnknown & oListOfNewInstance, CATUFOServiceOutput *& opOutputParameters);
  static HRESULT Replace(CATBaseUnknown* iInstanceToReplace, CATBaseUnknown* iReferenceToInstanciate, CATOmxSR<CATBaseUnknown>& oNewInstance);
  static HRESULT Replace(CATBaseUnknown* iInstanceToReplace, CATBaseUnknown* iReferenceToInstanciate, CATOmxSR<CATBaseUnknown>& oNewInstance, CATOmxSR<CATUFOServiceOutput>& oUFOServiceOutput);
private:
  PLMReplaceOperator(PLMReplaceOperator &) = delete;
  PLMReplaceOperator& operator=(PLMReplaceOperator&) = delete;
};


#endif
