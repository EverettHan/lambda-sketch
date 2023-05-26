#ifndef CATPLMNavServices_H
#define CATPLMNavServices_H

#include "CATPLMComponentInterfaces.h"
#include "CATBaseUnknown.h"
class CATIPLMNavEntity;
class CATListPtrCATIPLMNavReference;
class CATListPtrCATIPLMNavEntity;

class ExportedByCATPLMComponentInterfaces CATPLMNavServices
{
public:
  /**
	* Returns (rep)Instances of a (rep)Reference that are instanciated aggregated under provided roots
	* @param iRoots 
  *        (Rep)Instances are searched aggregated under these roots. Aggregation may be direct or indirect
  * @param iRef
  *        (Rep)Instances of this (Rep)reference are returned
  * @param ioInstancesList
  *        Returned list of (Rep)Instances. Ptr should be released by caller.
  *        If calling the API with a non empty list, returned instances are added to list, controling unicity
  */

  static HRESULT ListInstancesOfRefUnder(CATListPtrCATIPLMNavReference& iRoots, CATIPLMNavEntity* iRef, CATListPtrCATIPLMNavEntity & ioInstancesList) ;

};
#endif
