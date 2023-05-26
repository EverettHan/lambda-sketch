// COPYRIGHT DASSAULT SYSTEMES 1996
// ===================================================================
//
// CATIObjectToContainer: 
//    retrieve the container of the current object
//     
//
// ===================================================================
// Usage notes: 
//  
// must be implemented for all objects including containers
// ===================================================================
// March. 1993. Creation                                      jnm
// ===================================================================

#ifndef CATIObjectToContainer_h
#define CATIObjectToContainer_h

/**
 * @level Protected 
 * @usage U3
 */

#include "CATBaseUnknown.h"
#include "CATIContainer.h"

#include "AD0XXBAS.h"
extern ExportedByAD0XXBAS IID IID_CATIObjectToContainer ;

class ExportedByAD0XXBAS CATIObjectToContainer : public CATBaseUnknown
{
  CATDeclareInterface;

 public:

  virtual CATIContainer_var	GetContainer() = 0;
  
};

CATDeclareHandler(CATIObjectToContainer,CATBaseUnknown);

#endif

